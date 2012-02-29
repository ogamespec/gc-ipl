// OS Global Variables.
// This is private header used only in library code. Usual GC applications
// must not use OS globals.

// 0x80000000...0x800000FF

volatile u32 __OSPhysMemSize AT_ADDRESS(OS_BASE_CACHED | 0x0028);
volatile u32 __OSConsoleType AT_ADDRESS(OS_BASE_CACHED | 0x002C);

volatile OSThread *__OSDefaultThread AT_ADDRESS(OS_BASE_CACHED | 0x00D8);
volatile OSThreadLink __OSLinkActive AT_ADDRESS(OS_BASE_CACHED | 0x00DC);
volatile OSThread *__OSCurrentThread AT_ADDRESS(OS_BASE_CACHED | 0x00E4);

// 0x80003000...0x800030FF
