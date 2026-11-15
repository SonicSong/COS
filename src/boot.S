.section ".text.boot"
.global _start

_start:
    // Park all cores except core 0
    mrs     x1, mpidr_el1
    and     x1, x1, #3
    cbz     x1, 2f
1:  wfe
    b       1b
2:
    // x0 = DTB pointer from firmware; we never touch x0 below.

    mrs     x1, CurrentEL
    lsr     x1, x1, #2
    cmp     x1, #2
    b.ne    3f                      // already EL1 (e.g. some QEMU setups)

    // --- EL2 -> EL1 ---
    mov     x1, #(1 << 31)          // HCR_EL2.RW = 1: EL1 is AArch64
    msr     hcr_el2, x1

    mov     x1, #3                  // CNTHCTL_EL2: EL1 may use physical timer/counter
    msr     cnthctl_el2, x1
    msr     cntvoff_el2, xzr

    ldr     x1, =0x30D00800         // SCTLR_EL1: RES1 bits only, MMU/caches off
    msr     sctlr_el1, x1

    mov     x1, #(3 << 20)          // CPACR_EL1.FPEN: allow FP/SIMD at EL1/EL0
    msr     cpacr_el1, x1

    mov     x1, #0x3c5              // SPSR: EL1h, DAIF masked
    msr     spsr_el2, x1
    adr     x1, 3f
    msr     elr_el2, x1
    eret

3:
    // Stack: 512 KiB below the kernel, grows down
    ldr     x1, =_start
    mov     sp, x1

    // Clear BSS (symbols are 16-byte aligned by the linker script)
    ldr     x1, =__bss_start
    ldr     x2, =__bss_end
4:  cmp     x1, x2
    b.hs    5f
    str     xzr, [x1], #8
    b       4b

5:  bl      main
6:  wfe
    b       6b