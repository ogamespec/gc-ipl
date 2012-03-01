typedef struct OSSram
{
    u16     checkSum;           // SRAM byte checksum (discovered by Costis)
    u16     checkSumInv;        // inverted checksum (see YAGCD)
    u32     ead0;
    u32     ead1;
    s32     counterBias;        // now we already know meaning of this one too :)
    s8      displayOffsetH;     // used by VI library
    u8      ntd;
    u8      language;
    u8      flags;
    u8      dummy[44];
} OSSram;

OSSram * __OSLockSram (void);
BOOL __OSCheckSram (void);
void __OSUnlockSram (BOOL writeBack);
BOOL __OSSyncSram (void);
