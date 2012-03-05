// Originall located in gBase.c (sight from ASSERT macro)

#include <dolphin.h>

static OSHeapHandle                BS2Heap;

void InitHeap (void)
{
    void*   arenaLo;
    void*   arenaHi;
    void*   newArenaLo;

    arenaLo = OSRoundUp32B ( OSGetArenaLo () );
    arenaHi = OSRoundDown32B ( OSGetArenaHi() );

    newArenaLo = OSInitAlloc ( 0x80700000, arenaHi, 2 );
    OSSetArenaLo ( arenaHi );

    BS2Heap = OSCreateHeap ( arenaLo, arenaHi );
    OSSetCurrentHeap ( BS2Heap );

    OSAddToHeap ( BS2Heap, newArenaLo, 0x81100000 );

    DumpHeap ();
}

void DumpHeap (void)
{
    OSDumpHeap ( BS2Heap );
}

void * HeapAlloc ( int amount )
{
    void * ptr = OSAllocFromHeap ( BS2Heap, amount );
    ASSERTMSG ( ptr != NULL, "" );
    return ptr;
}

void HeapFree (void *ptr)
{
    OSFreeToHeap ( BS2Heap, ptr );
}
