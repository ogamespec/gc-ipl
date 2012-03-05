// Original name "BS2Mach.c" (wtf is Mach??)

#include <dolphin.h>

int DvdState;   // 7D58

int DVDStep (void);

// Debug printf
void dprintf (char *fmt, ...)
{
    // empty.
}

int DVDStep (void)
{
    BOOL level;
    
/*

    level = OSDisableInterrupts ();

    switch ( DvdState )
    {
        case 0:
            var_7D48 = 0x800030D4
            DvdState = 1;

        case 1:
813009D0  48062E4D  bl          __OSGetSystemTime 
813009D4  3CA08000  lis         r5, 0x8000
813009D8  80C500F8  lwz         r6, 248 (r5)
813009DC  3CA01062  lis         r5, 0x1062
813009E0  38000000  li          r0, 0
813009E4  54C6F0BE  rlwinm      r6, r6, 30, 2, 31           mask:0x3FFFFFFF
813009E8  38A54DD3  addi        r5, r5, 0x4DD3
813009EC  7CA53016  mulhwu      r5, r5, r6
813009F0  54A5D1BE  rlwinm      r5, r5, 26, 6, 31           mask:0x03FFFFFF
813009F4  1CC50050  mulli       r6, r5, 80
813009F8  6C658000  xoris       r5, r3, 0x8000
813009FC  6C038000  xoris       r3, r0, 0x8000
81300A00  7C062010  subfc       r0, r6, r4
81300A04  7C632910  subfe       r3, r3, r5
81300A08  7C652910  subfe       r3, r5, r5
81300A0C  7C6300D0  neg         r3, r3
81300A10  2C030000  cmpwi       r3, 0
81300A14  40820500  bne-        0x81300F14 
81300A18  38000002  li          r0, 2
81300A1C  900D82A8  stw         r0, -0x7D58 (r13)

        case 2:
81300A20  800D82D8  lwz         r0, -0x7D28 (r13)
81300A24  2C000000  cmpwi       r0, 0
81300A28  4082003C  bne-        0x81300A64 
81300A2C  806D82B8  lwz         r3, -0x7D48 (r13)
81300A30  38000000  li          r0, 0
81300A34  3BA00001  li          r29, 1
81300A38  90030000  stw         r0, 0 (r3)
81300A3C  38600000  li          r3, 0
81300A40  900D82BC  stw         r0, -0x7D44 (r13)
81300A44  93AD82D4  stw         r29, -0x7D2C (r13)
81300A48  48064D29  bl          0x81365770 
81300A4C  48067855  bl          DVDReset 
81300A50  93AD82D8  stw         r29, -0x7D28 (r13)
81300A54  48062DC9  bl          __OSGetSystemTime 
81300A58  908D82E4  stw         r4, -0x7D1C (r13)
81300A5C  906D82E0  stw         r3, -0x7D20 (r13)
81300A60  480004B4  b           0x81300F14 
81300A64  48062DB9  bl          __OSGetSystemTime 
81300A68  3CA08000  lis         r5, 0x8000
81300A6C  812D82E4  lwz         r9, -0x7D1C (r13)
81300A70  800500F8  lwz         r0, 248 (r5)
81300A74  3CA01062  lis         r5, 0x1062
81300A78  38A54DD3  addi        r5, r5, 0x4DD3
81300A7C  814D82E0  lwz         r10, -0x7D20 (r13)
81300A80  5400F0BE  rlwinm      r0, r0, 30, 2, 31           mask:0x3FFFFFFF
81300A84  7C050016  mulhwu      r0, r5, r0
81300A88  5408D1BE  rlwinm      r8, r0, 26, 6, 31           mask:0x03FFFFFF
81300A8C  38A0047E  li          r5, 0x047E
81300A90  38E00000  li          r7, 0
81300A94  7CC729D6  mullw       r6, r7, r5
81300A98  7C082816  mulhwu      r0, r8, r5
81300A9C  7CC60214  add         r6, r6, r0
81300AA0  7C0839D6  mullw       r0, r8, r7
81300AA4  7D292010  subfc       r9, r9, r4
81300AA8  7C6A1910  subfe       r3, r10, r3
81300AAC  7CA829D6  mullw       r5, r8, r5
81300AB0  7C060214  add         r0, r6, r0
81300AB4  6C648000  xoris       r4, r3, 0x8000
81300AB8  6C038000  xoris       r3, r0, 0x8000
81300ABC  7C054810  subfc       r0, r5, r9
81300AC0  7C632110  subfe       r3, r3, r4
81300AC4  7C642110  subfe       r3, r4, r4
81300AC8  7C6300D0  neg         r3, r3
81300ACC  2C030000  cmpwi       r3, 0
81300AD0  40820444  bne-        0x81300F14 
81300AD4  3C608130  lis         r3, 0x8130
81300AD8  90ED82D8  stw         r7, -0x7D28 (r13)
81300ADC  38630600  addi        r3, r3, 0x0600
81300AE0  48064C91  bl          0x81365770 
81300AE4  480677BD  bl          DVDReset 
81300AE8  38000003  li          r0, 3
81300AEC  900D82A8  stw         r0, -0x7D58 (r13)

        case 3:
            DVDReadDiskID ( r31+64, 0x80000000, 0x8130060C );
            DvdState = 4;
            break;

        case 4:
        case 5:
            if ( 0x813008B0 ( r1+64) )
            {
                
                if ( [0x8000001C] + 0x3DCD0000 != 0xFFFF9F3D )
                {
                    DvdState = 20;
                    break;
                }
                DvdState = 6;
            }
            else break;

        case 6:
81300B48  800D82D4  lwz         r0, -0x7D2C (r13)
81300B4C  28000000  cmplwi      r0, 0
81300B50  40820010  bne-        0x81300B60 
81300B54  38000008  li          r0, 8
81300B58  900D82A8  stw         r0, -0x7D58 (r13)
81300B5C  480003B8  b           0x81300F14 
81300B60  38000000  li          r0, 0
81300B64  900D82D4  stw         r0, -0x7D2C (r13)
81300B68  3C608000  lis         r3, 0x8000
81300B6C  88030008  lbz         r0, 8 (r3)
81300B70  28000000  cmplwi      r0, 0
81300B74  41820030  beq-        0x81300BA4 
81300B78  88A30009  lbz         r5, 9 (r3)
81300B7C  28050000  cmplwi      r5, 0
81300B80  41820008  beq-        0x81300B88 
81300B84  48000008  b           0x81300B8C 
81300B88  38A0000A  li          r5, 10
81300B8C  3C608130  lis         r3, 0x8130
81300B90  38C3060C  addi        r6, r3, 0x060C
81300B94  387F0040  addi        r3, r31, 64
81300B98  38800001  li          r4, 1
81300B9C  4806758D  bl          0x81368128 
81300BA0  4800001C  b           0x81300BBC 
81300BA4  3C608130  lis         r3, 0x8130
81300BA8  38C3060C  addi        r6, r3, 0x060C
81300BAC  387F0040  addi        r3, r31, 64
81300BB0  38800000  li          r4, 0
81300BB4  38A00000  li          r5, 0
81300BB8  48067571  bl          0x81368128 
81300BBC  38000007  li          r0, 7
81300BC0  900D82A8  stw         r0, -0x7D58 (r13)
81300BC4  48000350  b           0x81300F14 

        case 7:
            if ( 0x813008B0 (r31+64) == 0 ) break;
            DvdState = 8;

        case 8:
            DVDReadAbsAsyncForBS ( r31+64, r31+32, 32, 0x2440, 0x8130060C );
            DvdState = 9;
            break;

        case 9:
            if ( 0x813008B0 (r31+64) )
            {
                dprintf ( "  appLoaderLength ...... 0x%x\n", [r31+52] );
                dprintf ( "  appLoaderFunc1  ...... 0x%x\n", [r31+48] );
                DvdState = 10;
            }
            else break;

        case 10:
            DVDReadAbsAsyncForBS ( r31+64, 0x81200000, ([r31+52] + 31) & ~0x1f, 0x2460, 0x8130060C );
            DvdState = 11;
            break;

        case 11:
            if ( 0x813008B0 (r31+64) )
            {
                [r31+48] ( &var_7D54, &var_7D50, &var_7D4C );
                [var_7D54] ( OSReport );
                dprintf ( "\nApploader Initialized\n" );
                DvdState = 12;
            }
            else break;

        case 12:
81300CC0  818D82B0  lwz         r12, -0x7D50 (r13)
81300CC4  3861004C  addi        r3, r1, 76
81300CC8  38810048  addi        r4, r1, 72
81300CCC  38A10044  addi        r5, r1, 68
81300CD0  7D8803A6  mtlr        r12
81300CD4  4E800021  blrl         
81300CD8  2C030000  cmpwi       r3, 0
81300CDC  41820074  beq-        0x81300D50 
81300CE0  8081004C  lwz         r4, 76 (r1)
81300CE4  387D008C  addi        r3, r29, 140
81300CE8  80A10048  lwz         r5, 72 (r1)
81300CEC  4CC63182  crclr       6
81300CF0  80C10044  lwz         r6, 68 (r1)
81300CF4  4BFFF8A5  bl          0x81300598 
81300CF8  4805E559  bl          OSDisableInterrupts 
81300CFC  3CC08130  lis         r6, 0x8130
81300D00  8081004C  lwz         r4, 76 (r1)
81300D04  38E6060C  addi        r7, r6, 0x060C
81300D08  80A10048  lwz         r5, 72 (r1)
81300D0C  7C7D1B78  or          r29, r3, r3
81300D10  80C10044  lwz         r6, 68 (r1)
81300D14  387F0040  addi        r3, r31, 64
81300D18  480670E1  bl          DVDReadAbsAsyncForBS 
81300D1C  806D82B8  lwz         r3, -0x7D48 (r13)
81300D20  80030000  lwz         r0, 0 (r3)
81300D24  28000000  cmplwi      r0, 0
81300D28  41820014  beq-        0x81300D3C 
81300D2C  38600001  li          r3, 1
81300D30  80010048  lwz         r0, 72 (r1)
81300D34  906D82C4  stw         r3, -0x7D3C (r13)
81300D38  900D82C0  stw         r0, -0x7D40 (r13)
81300D3C  7FA3EB78  or          r3, r29, r29
81300D40  4805E539  bl          OSRestoreInterrupts 
81300D44  3800000D  li          r0, 13
81300D48  900D82A8  stw         r0, -0x7D58 (r13)
81300D4C  480001C8  b           0x81300F14 
81300D50  4BFFF999  bl          0x813006E8 
81300D54  2C030000  cmpwi       r3, 0
81300D58  40820010  bne-        0x81300D68 
81300D5C  38000014  li          r0, 20
81300D60  900D82A8  stw         r0, -0x7D58 (r13)
81300D64  480001B0  b           0x81300F14 
81300D68  3800000E  li          r0, 14
81300D6C  900D82A8  stw         r0, -0x7D58 (r13)
81300D70  480001A4  b           0x81300F14 

        case 13:
            if ( 0x813008B0 (r31+64) ) DvdState = 12;
            break;

        case 14:
81300D90  48064B29  bl          __DVDFSInit 
81300D94  387D00B8  addi        r3, r29, 184
81300D98  48064B59  bl          DVDConvertPathToEntrynum 
81300D9C  2C030000  cmpwi       r3, 0
81300DA0  4180008C  blt-        0x81300E2C 
81300DA4  38810008  addi        r4, r1, 8
81300DA8  48064E3D  bl          0x81365BE4 
81300DAC  800D82C8  lwz         r0, -0x7D38 (r13)
81300DB0  28000000  cmplwi      r0, 0
81300DB4  40820018  bne-        0x81300DCC 
81300DB8  387D00C8  addi        r3, r29, 200
81300DBC  4CC63182  crclr       6
81300DC0  38BD00D4  addi        r5, r29, 212
81300DC4  3880040E  li          r4, 0x040E
81300DC8  4805CBDD  bl          OSPanic 
81300DCC  806D82CC  lwz         r3, -0x7D34 (r13)
81300DD0  8001003C  lwz         r0, 60 (r1)
81300DD4  7C030040  cmplw       r3, r0
81300DD8  4080001C  bge-        0x81300DF4 
81300DDC  80CD82CC  lwz         r6, -0x7D34 (r13)
81300DE0  387D00C8  addi        r3, r29, 200
81300DE4  38BD0104  addi        r5, r29, 0x0104
81300DE8  4CC63182  crclr       6
81300DEC  38800411  li          r4, 0x0411
81300DF0  4805CBB5  bl          OSPanic 
81300DF4  80A1003C  lwz         r5, 60 (r1)
81300DF8  28050000  cmplwi      r5, 0
81300DFC  41820030  beq-        0x81300E2C 
81300E00  3C608130  lis         r3, 0x8130
81300E04  808D82C8  lwz         r4, -0x7D38 (r13)
81300E08  3805001F  addi        r0, r5, 31
81300E0C  80C10038  lwz         r6, 56 (r1)
81300E10  38E3060C  addi        r7, r3, 0x060C
81300E14  387F0040  addi        r3, r31, 64
81300E18  54050034  rlwinm      r5, r0, 0, 0, 26            mask:0xFFFFFFE0
81300E1C  48066FDD  bl          DVDReadAbsAsyncForBS 
81300E20  3800000F  li          r0, 15
81300E24  900D82A8  stw         r0, -0x7D58 (r13)
81300E28  480000EC  b           0x81300F14 
81300E2C  38600000  li          r3, 0
81300E30  38000010  li          r0, 16
81300E34  906D82D0  stw         r3, -0x7D30 (r13)
81300E38  3C608130  lis         r3, 0x8130
81300E3C  900D82A8  stw         r0, -0x7D58 (r13)
81300E40  386305E8  addi        r3, r3, 0x05E8
81300E44  4806442D  bl          DVDLowWaitCoverClose 
81300E48  480000CC  b           0x81300F14 

        case 15:
            if ( 0x813008B0(r31+64) )
            {
                var_7D30 = 1;
                DvdState = 16;
                DVDLowWaitCoverClose (0x813005E8);
            }
            break;

        case 16:
            break;

        case 17:
            var_7D30 = 0;
            DvdState = 2;
            break;

        case 18:
        case 19:
        case 24:
            0x81365770 (0);
            var_7D30 = 0;
            0x813008B0 (r31+64);
            break;

        case 20:
            var_7D30 = 0;
            0x813681E4 ( r31+64, 0x8130060C );
            DvdState = 21;

        case 21:
        case 22:
            0x813008B0 (r31+64);
            break;

        case 23:
            var_7D30 = 0;
            break;

        case 25:
            if ( 0x813008B0 (r31+64) ) DvdState = 3;
            break;

        default: OSHalt ( "BS2 ERROR >>> UNKNOWN STATE" );
    }

0F14:
    OSRestoreInterrupts (level);
    if ( 0x813657E0 () == 1 ) return 19;
    else return DvdState; 
    
*/

    return 0;
}