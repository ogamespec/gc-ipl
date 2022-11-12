// Dolphin BootROM font compress/decompress tool.

#include <stdio.h>
#include <string.h>

#include "CommonDefs.h"
#include "SZP.h"

static void usage (void)
{
    printf ("Compress  : yay -c source dest\n");
    printf ("Decompress: yay -d source dest\n");
}

int main (int argc, char **argv)
{
    printf ("YAY - Dolphin BootROM font compression tool.\n");

    if (argc != 4)
    {
        usage ();
        return 0;
    }

    if (!_stricmp (argv[1], "-c"))
    {
        FileCompress (argv[3], argv[2]);
        return 1;
    }

    if (!_stricmp (argv[1], "-d"))
    {
        FileDecompress (argv[3], argv[2]);
        return 1;
    }

    usage ();
    return 0;
}
