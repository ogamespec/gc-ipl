# Open Source GAMECUBE IPL

:warning: GigaLeak Note. Yes, we know that one of the GigaLeak archives (`bb2.zip`) leaked almost all source code (most missing headers can be found in other archives) that can be built into a working BootROM image. So what of it? :-) The project has nothing to do with GigaLeak. Of course it's tempting to take at least the names of the IPL main code functions from there, but it's not interesting. Most of the information about IPL was already known before the leak.

**!!! For educational purposes only !!!**

Project Goals:
- Reverse engineering of retail GameCube bootrom (USA / NTSC version was used as reference)
- Write own bootrom, based on IPL reversing
- Use bootrom in GameCube emulators to have fun :-)

Toolchain (mostly official):
- CodeWarrior IDE for Nintendo GameCube
- Dolphin SDK
- Dolwin debugger

Overall Progress:
- Bootstrap 1 stage disassembly **DONE**
- Way to compile it back in binary file **DONE**
- Bootrom fonts investigated **DONE**
- IPL listing **DONE**
- Identify all library calls
- IPL intro
- IPL menus
- Utility to merge all pieces in single binary ROM file

GameCube Bootrom details:

Bootrom is located in special chip, designed by Macronix Ltd., and placed near Flipper IC:

![bootrom](/images/bootrom.jpg)

Same chip shares non-volatile memory (SRAM) and real-time clock (RTC).

Bootrom size is 2 MB.

First logical part of bootrom (reset vector) called Bootstrap 1 (BS1). This small procedure is written on assembly and started from 0xfff00100 physical address. It prepares GameCube hardware, checks memory, initialize virtual addressing and load second logical part, known as Bootstrap 2 (BS2) or IPL (Intial Program Loader).

IPL is written on C. It's compiled as DOL executable, by using early version Dolphin SDK as system API.
Code entrypoint for start routine is made to 0x81300000 location (virtual address), by link script.

Almost 50% of IPL binary payload is occupied by Dolphin SDK library calls.

Important Note: Bootrom is encrypted itself. Decryption is done by MX chip, during block reading of bootrom data. On early stages (BS1) decryption is done on-the-fly as Gekko load 32-Byte bursts in instruction cache. Later its decrypted by EXI DMA, during BS2 copy. Its very important to watch scrambler not to go out-of-sync, otherwise trash appear as output. Symmetric encryption algorithm (XOR-based) was reversed by segher: [Descrambler](/wiki/Descrambler.md)

Also Bootrom contains two sets of raster fonts. One for ANSI charset and another for SJIS:

|![font_00](/images/font_00.jpg)|![font_01](/images/font_01.jpg)|![font_02](/images/font_02.jpg)|
|---|---|---|

|![font_03](/images/font_03.jpg)|![font_04](/images/font_04.jpg)|![font_05](/images/font_05.jpg)|
|---|---|---|

|![font_06](/images/font_06.jpg)|![font_07](/images/font_07.jpg)|![font_08](/images/font_08.jpg)|
|---|---|---|

|![font_09](/images/font_09.jpg)|
|---|

These fonts are rarely used by some games. Font data is **not** encrypted (BS1 disables bootrom scrambler after BS2 was copied in RAM, so subsequent Font reading is actually done over 0x00000000 XOR stream. Same thing applies to first 0x100 bytes of bootrom with Copyright strings).

When IPL starts, following sequence appear:

First is rotating cube intro:

![tumblr_lrxomiSQsX1qkyzcdo1_500](/images/tumblr_lrxomiSQsX1qkyzcdo1_500.gif)

Next IPL menu appear, looking like rotating glass cube:

![iplmenu](/images/iplmenu.jpg)

Each side of cube representing different menus (memory card manager, calendar settings etc.)

Deep inside cube are floating small cubes, appearing as different patterns.

YouTube video:

<a href='http://www.youtube.com/watch?feature=player_embedded&v=In0beAki4mM' target='_blank'><img src='http://img.youtube.com/vi/In0beAki4mM/0.jpg' width='425' height=344 /></a><br>

Credits:
- Credits go to GameCube scene members and my good friends : groepaz and tmbinc :=)
- Thanks to Nintendo and ArtX team for such sexy console ^^
