#include <dolphin.h>
#include <string.h>
#include "oslomem.h"
#include "ossram.h"

u32 var_76f8;   // unused ?
BOOL CounterBiasModified;       // 7CE4
BOOL SramFlag008Cleared;      // 7CE0

double zero = 0.0;       // 7D60

void ClearUnusedBatRegisters (void);
void ClearFPURegisters (void);
void BS2Init (void);
void BS2Main (void);
void CheckSram (void);
void SetTimeBaseCounter (void);

BOOL AD16Init (void);
BOOL AD16WriteReg (u32 value);
BOOL AD16ReadReg (u32 *value);
BOOL AD16Probe (void);

void __VIInit (VITVMode mode);

BOOL __OSGetRTC ( OSTime * clock );
void __OSSetTime ( OSTime clock );

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
    lfd         fp0, zero;
    fmr         fp1, fp0;
    fmr         fp2, fp0;
    fmr         fp3, fp0;
    fmr         fp4, fp0;
    fmr         fp5, fp0;
    fmr         fp6, fp0;
    fmr         fp7, fp0;
    fmr         fp8, fp0;
    fmr         fp9, fp0;
    fmr         fp10, fp0;
    fmr         fp11, fp0;
    fmr         fp12, fp0;
    fmr         fp13, fp0;
    fmr         fp14, fp0;
    fmr         fp15, fp0;
    fmr         fp16, fp0;
    fmr         fp17, fp0;
    fmr         fp18, fp0;
    fmr         fp19, fp0;
    fmr         fp20, fp0;
    fmr         fp21, fp0;
    fmr         fp22, fp0;
    fmr         fp23, fp0;
    fmr         fp24, fp0;
    fmr         fp25, fp0;
    fmr         fp26, fp0;
    fmr         fp27, fp0;
    fmr         fp28, fp0;
    fmr         fp29, fp0;
    fmr         fp30, fp0;
    fmr         fp31, fp0;
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

    CheckSram ();
    __VIInit (VI_TVMODE_PAL_INT);
    VIInit ();
    AD16WriteReg (0x0B000000);

    __OSBusClock = 162000000;
    __OSCoreClock = 486000000;
    SetTimeBaseCounter ();
    //sub_813020C8 ();
    PADSetSpec (PAD_SPEC_5);
    PADInit ();
    AD16WriteReg (0x0C000000);

    BS2Main ();
    OSHalt ("BS2 ERROR >>> SHOULD NEVER REACH HERE");
}

void CheckSram (void)
{
    OSSram * sram;
    OSTime RealTimeClock;
    OSCalendarTime td;
    s32 counterBias;
    BOOL writeBackSram = FALSE;

    CounterBiasModified = SramFlag008Cleared = FALSE;

    sram = __OSLockSram ();
    
    if ( __OSCheckSram () == FALSE )
    {
        counterBias = sram->counterBias;
        if ( __OSGetRTC (&RealTimeClock) )
        {
            OSTicksToCalendarTime ( OSSecondsToTicks (RealTimeClock) * counterBias, &td );
            if ( td.year < 2000 || td.year > 2007 ) counterBias = 0;
        }
        else counterBias = 0;

        memset ( sram, 0, 20 );
        sram->counterBias = counterBias;
        sram->flags |= 0x10;
        sram->flags |= 0x04;
        CounterBiasModified = TRUE;
        writeBackSram = TRUE;
    }

    if ( (sram->flags & 0x08) == 0 ) SramFlag008Cleared = TRUE;
    
    __OSUnlockSram (writeBackSram);
    if ( writeBackSram ) {
        while ( __OSSyncSram () == 0 ) {}
    }
}

void SetTimeBaseCounter (void)
{
    OSTime RealTimeClock;
    OSSram * sram = __OSLockSram ();
    
    if ( __OSGetRTC (&RealTimeClock) )
    {
        __OSSetTime ( OSSecondsToTicks (RealTimeClock) );
    }

    __OSUnlockSram (FALSE);
}

/*
sub_813020C8 (void)
{
    var_7CD4 = 0x81300968 ();
}

*/