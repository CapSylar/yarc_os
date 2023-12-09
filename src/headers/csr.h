#ifndef CSR_H_GUARD
#define CSR_H_GUARD

#include "stdint.h"

/* Interrupt causes (minus the high bit) */
#define IRQ_S_SOFT     1
#define IRQ_VS_SOFT    2
#define IRQ_M_SOFT     3
#define IRQ_S_TIMER    5
#define IRQ_VS_TIMER   6
#define IRQ_M_TIMER    7
#define IRQ_S_EXT      9
#define IRQ_VS_EXT     10
#define IRQ_M_EXT      11
#define IRQ_S_GEXT     12
#define IRQ_PMU_OVF    13
#define IRQ_LOCAL_MAX  (IRQ_PMU_OVF + 1)
#define IRQ_LOCAL_MASK GENMASK((IRQ_LOCAL_MAX - 1), 0)

/* Exception causes */
#define EXC_INST_MISALIGNED        0
#define EXC_INST_ACCESS            1
#define EXC_INST_ILLEGAL           2
#define EXC_BREAKPOINT             3
#define EXC_LOAD_MISALIGNED        4
#define EXC_LOAD_ACCESS            5
#define EXC_STORE_MISALIGNED       6
#define EXC_STORE_ACCESS           7
#define EXC_SYSCALL                8
#define EXC_HYPERVISOR_SYSCALL     9
#define EXC_SUPERVISOR_SYSCALL     10
#define EXC_INST_PAGE_FAULT        12
#define EXC_LOAD_PAGE_FAULT        13
#define EXC_STORE_PAGE_FAULT       15
#define EXC_INST_GUEST_PAGE_FAULT  20
#define EXC_LOAD_GUEST_PAGE_FAULT  21
#define EXC_VIRTUAL_INST_FAULT     22
#define EXC_STORE_GUEST_PAGE_FAULT 23

/* PMP configuration */
#define PMP_R       0x01
#define PMP_W       0x02
#define PMP_X       0x04
#define PMP_A       0x18
#define PMP_A_TOR   0x08
#define PMP_A_NA4   0x10
#define PMP_A_NAPOT 0x18
#define PMP_L       0x80

#define HGATP32_MODE_SHIFT 31
#define HGATP32_VMID_SHIFT 22
#define HGATP32_VMID       GENMASK(28, 22)
#define HGATP32_PPN        GENMASK(21, 0)

#define HGATP64_MODE_SHIFT 60 >

#define HGATP_PAGE_SHIFT 12

/* VSIP & HVIP relation */
#define VSIP_TO_HVIP_SHIFT (IRQ_VS_SOFT - IRQ_S_SOFT)
#define VSIP_VALID_MASK                                                        \
  ((_AC(1, UL) << IRQ_S_SOFT) | (_AC(1, UL) << IRQ_S_TIMER) |                  \
   (_AC(1, UL) << IRQ_S_EXT))

/* AIA CSR bits */
#define TOPI_IID_SHIFT  16
#define TOPI_IID_MASK   GENMASK(11, 0)
#define TOPI_IPRIO_MASK GENMASK(7, 0)
#define TOPI_IPRIO_BITS 8

#define TOPEI_ID_SHIFT  16
#define TOPEI_ID_MASK   GENMASK(10, 0)
#define TOPEI_PRIO_MASK GENMASK(10, 0)

#define ISELECT_IPRIO0  0x30
#define ISELECT_IPRIO15 0x3f
#define ISELECT_MASK    GENMASK(8, 0)

#define HVICTL_VTI       BIT(30)
#define HVICTL_IID       GENMASK(27, 16)
#define HVICTL_IID_SHIFT 16
#define HVICTL_DPR       BIT(9)
#define HVICTL_IPRIOM    BIT(8)
#define HVICTL_IPRIO     GENMASK(7, 0)

/* xENVCFG flags */
#define ENVCFG_STCE       (_AC(1, ULL) << 63)
#define ENVCFG_PBMTE      (_AC(1, ULL) << 62)
#define ENVCFG_CBZE       (_AC(1, UL) << 7)
#define ENVCFG_CBCFE      (_AC(1, UL) << 6)
#define ENVCFG_CBIE_SHIFT 4
#define ENVCFG_CBIE       (_AC(0x3, UL) << ENVCFG_CBIE_SHIFT)
#define ENVCFG_CBIE_ILL   _AC(0x0, UL)
#define ENVCFG_CBIE_FLUSH _AC(0x1, UL)
#define ENVCFG_CBIE_INV   _AC(0x3, UL)
#define ENVCFG_FIOM       _AC(0x1, UL)

/* Smstateen bits */
#define SMSTATEEN0_AIA_IMSIC_SHIFT 58
#define SMSTATEEN0_AIA_IMSIC       (_ULL(1) << SMSTATEEN0_AIA_IMSIC_SHIFT)
#define SMSTATEEN0_AIA_SHIFT       59
#define SMSTATEEN0_AIA             (_ULL(1) << SMSTATEEN0_AIA_SHIFT)
#define SMSTATEEN0_AIA_ISEL_SHIFT  60
#define SMSTATEEN0_AIA_ISEL        (_ULL(1) << SMSTATEEN0_AIA_ISEL_SHIFT)
#define SMSTATEEN0_HSENVCFG_SHIFT  62
#define SMSTATEEN0_HSENVCFG        (_ULL(1) << SMSTATEEN0_HSENVCFG_SHIFT)
#define SMSTATEEN0_SSTATEEN0_SHIFT 63
#define SMSTATEEN0_SSTATEEN0       (_ULL(1) << SMSTATEEN0_SSTATEEN0_SHIFT)

/* symbolic CSR names: */
#define CSR_CYCLE         0xc00
#define CSR_TIME          0xc01
#define CSR_INSTRET       0xc02
#define CSR_HPMCOUNTER3   0xc03
#define CSR_HPMCOUNTER4   0xc04
#define CSR_HPMCOUNTER5   0xc05
#define CSR_HPMCOUNTER6   0xc06
#define CSR_HPMCOUNTER7   0xc07
#define CSR_HPMCOUNTER8   0xc08
#define CSR_HPMCOUNTER9   0xc09
#define CSR_HPMCOUNTER10  0xc0a
#define CSR_HPMCOUNTER11  0xc0b
#define CSR_HPMCOUNTER12  0xc0c
#define CSR_HPMCOUNTER13  0xc0d
#define CSR_HPMCOUNTER14  0xc0e
#define CSR_HPMCOUNTER15  0xc0f
#define CSR_HPMCOUNTER16  0xc10
#define CSR_HPMCOUNTER17  0xc11
#define CSR_HPMCOUNTER18  0xc12
#define CSR_HPMCOUNTER19  0xc13
#define CSR_HPMCOUNTER20  0xc14
#define CSR_HPMCOUNTER21  0xc15
#define CSR_HPMCOUNTER22  0xc16
#define CSR_HPMCOUNTER23  0xc17
#define CSR_HPMCOUNTER24  0xc18
#define CSR_HPMCOUNTER25  0xc19
#define CSR_HPMCOUNTER26  0xc1a
#define CSR_HPMCOUNTER27  0xc1b
#define CSR_HPMCOUNTER28  0xc1c
#define CSR_HPMCOUNTER29  0xc1d
#define CSR_HPMCOUNTER30  0xc1e
#define CSR_HPMCOUNTER31  0xc1f
#define CSR_CYCLEH        0xc80
#define CSR_TIMEH         0xc81
#define CSR_INSTRETH      0xc82
#define CSR_HPMCOUNTER3H  0xc83
#define CSR_HPMCOUNTER4H  0xc84
#define CSR_HPMCOUNTER5H  0xc85
#define CSR_HPMCOUNTER6H  0xc86
#define CSR_HPMCOUNTER7H  0xc87
#define CSR_HPMCOUNTER8H  0xc88
#define CSR_HPMCOUNTER9H  0xc89
#define CSR_HPMCOUNTER10H 0xc8a
#define CSR_HPMCOUNTER11H 0xc8b
#define CSR_HPMCOUNTER12H 0xc8c
#define CSR_HPMCOUNTER13H 0xc8d
#define CSR_HPMCOUNTER14H 0xc8e
#define CSR_HPMCOUNTER15H 0xc8f
#define CSR_HPMCOUNTER16H 0xc90
#define CSR_HPMCOUNTER17H 0xc91
#define CSR_HPMCOUNTER18H 0xc92
#define CSR_HPMCOUNTER19H 0xc93
#define CSR_HPMCOUNTER20H 0xc94
#define CSR_HPMCOUNTER21H 0xc95
#define CSR_HPMCOUNTER22H 0xc96
#define CSR_HPMCOUNTER23H 0xc97
#define CSR_HPMCOUNTER24H 0xc98
#define CSR_HPMCOUNTER25H 0xc99
#define CSR_HPMCOUNTER26H 0xc9a
#define CSR_HPMCOUNTER27H 0xc9b
#define CSR_HPMCOUNTER28H 0xc9c
#define CSR_HPMCOUNTER29H 0xc9d
#define CSR_HPMCOUNTER30H 0xc9e
#define CSR_HPMCOUNTER31H 0xc9f

#define CSR_SSCOUNTOVF 0xda0

#define CSR_SSTATUS    0x100
#define CSR_SIE        0x104
#define CSR_STVEC      0x105
#define CSR_SCOUNTEREN 0x106
#define CSR_SENVCFG    0x10a
#define CSR_SSTATEEN0  0x10c
#define CSR_SSCRATCH   0x140
#define CSR_SEPC       0x141
#define CSR_SCAUSE     0x142
#define CSR_STVAL      0x143
#define CSR_SIP        0x144
#define CSR_SATP       0x180

#define CSR_STIMECMP  0x14D
#define CSR_STIMECMPH 0x15D

/* Supervisor-Level Window to Indirectly Accessed Registers (AIA) */
#define CSR_SISELECT 0x150
#define CSR_SIREG    0x151

/* Supervisor-Level Interrupts (AIA) */
#define CSR_STOPEI 0x15c
#define CSR_STOPI  0xdb0

/* Supervisor-Level High-Half CSRs (AIA) */
#define CSR_SIEH 0x114
#define CSR_SIPH 0x154

#define CSR_VSSTATUS   0x200
#define CSR_VSIE       0x204
#define CSR_VSTVEC     0x205
#define CSR_VSSCRATCH  0x240
#define CSR_VSEPC      0x241
#define CSR_VSCAUSE    0x242
#define CSR_VSTVAL     0x243
#define CSR_VSIP       0x244
#define CSR_VSATP      0x280
#define CSR_VSTIMECMP  0x24D
#define CSR_VSTIMECMPH 0x25D

#define CSR_HSTATUS     0x600
#define CSR_HEDELEG     0x602
#define CSR_HIDELEG     0x603
#define CSR_HIE         0x604
#define CSR_HTIMEDELTA  0x605
#define CSR_HCOUNTEREN  0x606
#define CSR_HGEIE       0x607
#define CSR_HENVCFG     0x60a
#define CSR_HTIMEDELTAH 0x615
#define CSR_HENVCFGH    0x61a
#define CSR_HTVAL       0x643
#define CSR_HIP         0x644
#define CSR_HVIP        0x645
#define CSR_HTINST      0x64a
#define CSR_HGATP       0x680
#define CSR_HGEIP       0xe12

/* Virtual Interrupts and Interrupt Priorities (H-extension with AIA) */
#define CSR_HVIEN    0x608
#define CSR_HVICTL   0x609
#define CSR_HVIPRIO1 0x646
#define CSR_HVIPRIO2 0x647

/* VS-Level Window to Indirectly Accessed Registers (H-extension with AIA) */
#define CSR_VSISELECT 0x250
#define CSR_VSIREG    0x251

/* VS-Level Interrupts (H-extension with AIA) */
#define CSR_VSTOPEI 0x25c
#define CSR_VSTOPI  0xeb0

/* Hypervisor and VS-Level High-Half CSRs (H-extension with AIA) */
#define CSR_HIDELEGH  0x613
#define CSR_HVIENH    0x618
#define CSR_HVIPH     0x655
#define CSR_HVIPRIO1H 0x656
#define CSR_HVIPRIO2H 0x657
#define CSR_VSIEH     0x214
#define CSR_VSIPH     0x254

/* Hypervisor stateen CSRs */
#define CSR_HSTATEEN0  0x60c
#define CSR_HSTATEEN0H 0x61c

#define CSR_MSTATUS  0x300
#define CSR_MISA     0x301
#define CSR_MIDELEG  0x303
#define CSR_MIE      0x304
#define CSR_MTVEC    0x305
#define CSR_MENVCFG  0x30a
#define CSR_MENVCFGH 0x31a

#define CSR_MCOUNTINHIBIT 0x320

#define CSR_MSCRATCH  0x340
#define CSR_MEPC      0x341
#define CSR_MCAUSE    0x342
#define CSR_MTVAL     0x343
#define CSR_MIP       0x344
#define CSR_PMPCFG0   0x3a0
#define CSR_PMPADDR0  0x3b0
#define CSR_MVENDORID 0xf11
#define CSR_MARCHID   0xf12
#define CSR_MIMPID    0xf13
#define CSR_MHARTID   0xf14

/* Machine-Level Window to Indirectly Accessed Registers (AIA) */
#define CSR_MISELECT 0x350
#define CSR_MIREG    0x351

/* Machine-Level Interrupts (AIA) */
#define CSR_MTOPEI 0x35c
#define CSR_MTOPI  0xfb0

/* Virtual Interrupts for Supervisor Level (AIA) */
#define CSR_MVIEN 0x308
#define CSR_MVIP  0x309

/* Machine-Level High-Half CSRs (AIA) */
#define CSR_MIDELEGH 0x313
#define CSR_MIEH     0x314
#define CSR_MVIENH   0x318
#define CSR_MVIPH    0x319
#define CSR_MIPH     0x354

#define CSR_VSTART 0x8
#define CSR_VCSR   0xf
#define CSR_VL     0xc20
#define CSR_VTYPE  0xc21
#define CSR_VLENB  0xc22

__attribute__((always_inline)) inline void write_csr(int csr_num, uint32_t val)
{
  asm volatile("csrw %0, %1" ::"i"(csr_num), "rK"(val));
}

__attribute__((always_inline)) inline uint32_t read_csr(int csr_num)
{
  uint32_t val;
  asm volatile("csrr %0, %1" : "=r"(val) : "i"(csr_num));
  return val;
}

typedef enum
{
  PLVL_U = 0,
  PLVL_S = 1,
  PLVL_M = 3,
} plvl_e;

typedef enum
{
  DIRECT_TRAP = 0,
  VECTORED_TRAP = 1,
} trap_mode_e;

// CSR Struct Definitions
typedef union
{
  struct
  {
    // 0
    uint32_t unused0 : 1;
    // 1
    uint32_t sie : 1;
    // 2
    uint32_t unused1 : 1;
    // 3
    uint32_t mie : 1;
    // 4
    uint32_t unused2 : 1;
    // 5
    uint32_t spie : 1;
    // 6
    uint32_t ube : 1;
    // 7
    uint32_t mpie : 1;
    // 8
    uint32_t spp : 1;
    // 9->10
    uint32_t vs : 2;
    // 11->12
    uint32_t mpp : 2;
    // 13->14
    uint32_t fs : 2;
    // 15->16
    uint32_t xs : 2;
    // 17
    uint32_t mprv : 1;
    // 18
    uint32_t sum : 1;
    // 19
    uint32_t mxr : 1;
    // 20
    uint32_t tvm : 1;
    // 21
    uint32_t tw : 1;
    // 22
    uint32_t tsr : 1;
    // 23->30
    uint32_t unused3 : 8;
    // 31
    uint32_t sd : 1;

  } __attribute__((packed));

  uint32_t val;
} csr_mstatus_t;

typedef union
{
  struct
  {
    // 0->2
    uint32_t unused0 : 3;
    // 3
    uint32_t msip : 1;
    // 4->6
    uint32_t unused1 : 3;
    // 7
    uint32_t mtip : 1;
    // 8->10
    uint32_t unused2 : 3;
    // 11
    uint32_t meip : 1;
    // 12->31
    uint32_t unused3 : 20;
  } __attribute__((packed));

  uint32_t val;
} csr_mie_t;

#endif // CSR_H_GUARD
