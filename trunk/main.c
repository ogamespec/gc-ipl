#include <dolphin.h>
#include <string.h>
#include "oslomem.h"

u32 var_76f8;

static double zero = 0.0;

void ClearUnusedBatRegisters (void);
void ClearFPURegisters (void);
void BS2Init (void);
void BS2Main (void);

BOOL AD16Init (void);
BOOL AD16WriteReg (u32 value);
BOOL AD16ReadReg (u32 *value);
BOOL AD16Probe (void);

void __VIInit (VITVMode mode);

asm void ClearUnusedBatRegisters (void)
{
    nofralloc;
    isync;
    li          r4, 0;
    mtspr       DBAT2L, r4;
    mtspr       DBAT2U, r4;
    mtspr       DBAT3L, r4;
    mtspr       DBAT3U, r4;
    mtspr       IBAT1L, r4;
    mtspr       IBAT1U, r4;
    mtspr       IBAT2L, r4;
    mtspr       IBAT2U, r4;
    mtspr       IBAT3L, r4;
    mtspr       IBAT3U, r4;
    isync;       
    blr;
}

asm void ClearFPURegisters (void)
{
    nofralloc;
    lfd         f0, zero;
    fmr         f1, f0;
    fmr         f2, f0;
    fmr         f3, f0;
    fmr         f4, f0;
    fmr         f5, f0;
    fmr         f6, f0;
    fmr         f7, f0;
    fmr         f8, f0;
    fmr         f9, f0;
    fmr         f10, f0;
    fmr         f11, f0;
    fmr         f12, f0;
    fmr         f13, f0;
    fmr         f14, f0;
    fmr         f15, f0;
    fmr         f16, f0;
    fmr         f17, f0;
    fmr         f18, f0;
    fmr         f19, f0;
    fmr         f20, f0;
    fmr         f21, f0;
    fmr         f22, f0;
    fmr         f23, f0;
    fmr         f24, f0;
    fmr         f25, f0;
    fmr         f26, f0;
    fmr         f27, f0;
    fmr         f28, f0;
    fmr         f29, f0;
    fmr         f30, f0;
    fmr         f31, f0;
    blr;
}

void BS2Init (void)
{
    // Clear OS low memory.
    memset ( (void *) (OS_BASE_CACHED | 0x0000), 0, 256 );
    memset ( (void *) (OS_BASE_CACHED | 0x3000), 0, 256 );

    ClearUnusedBatRegisters ();
    __OSPhysMemSize = 24*1024*1024;
    __OSConsoleType = OS_CONSOLE_RETAIL1;
    //__OSConsoleType += ([0xCC00302C] >> 28) & 0xF;
    var_76f8 = 0xFFFFFFFF;

    ClearFPURegisters ();
}

void main()
{
    BS2Init ();
    OSInit ();
    AD16Init ();
    AD16WriteReg (0x08000000);

    DVDInit ();
    AD16WriteReg (0x09000000);

    CARDInit ();
    AD16WriteReg (0x0A000000);

    //sub_81301F0C ();
    __VIInit (VI_TVMODE_PAL_INT);
    VIInit ();
    AD16WriteReg (0x0B000000);

    __OSBusClock = 162000000;
    __OSCoreClock = 486000000;
    //sub_81302034 ();        // BS2SetTime
    //sub_813020C8 ();
    PADSetSpec (PAD_SPEC_5);
    PADInit ();
    AD16WriteReg (0x0C000000);

    BS2Main ();
    OSHalt ("BS2 ERROR >>> SHOULD NEVER REACH HERE");
}