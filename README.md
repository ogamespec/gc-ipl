<h3>Open source Gamecube bootrom</h3>

<b>!!! For educational purposes only !!!</b>

<b>Project Goals:</b>
  * Reverse engineering of retail `GameCube` bootrom (USA / NTSC version was used as reference)
  * Write own bootrom, based on IPL reversing
  * Use bootrom in gamecube emulators to have fun :-)

<b>Toolchain (mostly official):</b>
  * `CodeWarrior` IDE for Nintendo `GameCube`
  * Dolphin SDK
  * Dolwin debugger

<b>Overall Progress:</b>
  * Bootstrap 1 stage disassembly **DONE**
  * Way to compile it back in binary file **DONE**
  * Bootrom fonts investigated **DONE**
  * IPL listing **DONE**
  * Identify all library calls
  * IPL intro
  * IPL menus
  * Utility to merge all pieces in single binary ROM file

<b>Gamecube Bootrom details:</b>

Bootrom is located in special chip, designed by Macronix Ltd., and placed near Flipper IC : <br>
<img src='http://gcdev.narod.ru/bootrom.jpg'>

Same chip shares non-volatile memory (SRAM) and real-time clock (RTC).

Bootrom size is 2 MB.<br>
<br>
First logical part of bootrom (reset vector) called Bootstrap 1 (BS1). This small procedure is written on assembly and started from 0xfff00100 address. It prepares Gamecube hardware, checks memory and load second logical part, known as Bootstrap 2 (BS2) or IPL (Intial Program Loader).<br>
<br>
IPL is written on C. It's compiled as DOL executable, by using early version Dolphin SDK as system API.<br>
Code entrypoint for start routine is made to 0x81300000 location, by link script.<br>

Almost 50% of IPL binary payload is occupied by Dolphin SDK library calls.

Important Note: Bootrom is encrypted itself. Decryption is done by MX chip, during block reading of bootrom data. On early stages (BS1) decryption is done on-the-fly as Gekko load 32-Byte bursts in instruction cache. Later its decrypted by EXI DMA, during BS2 copy. Its very important to watch scrambler not to go out-of-sync, otherwise trash appear as output. Symmetric encryption algorithm (XOR-based) was reversed by segher : <a href='../wiki/Descrambler.md'>Descrambler</a>

Also Bootrom contains two sets of raster fonts. One for ANSI charset and another for SJIS:<br>
<img src='http://gcdev.narod.ru/font_00.jpg'> <img src='http://gcdev.narod.ru/font_03.jpg'><br>
These fonts are rarely used by some games. Font data is <b>not</b> encrypted (BS1 disables bootrom scrambler after BS2 was copied in RAM, so subsequent Font reading is actually done over 0x00000000 XOR stream. Same thing applies to first 0x100 bytes of bootrom with Copyright strings)<br> 
<br>
When IPL starts, following sequence appear :<br>
<br>
First is rotating cube intro:<br>
<img src='http://27.media.tumblr.com/tumblr_lrxomiSQsX1qkyzcdo1_500.gif'>

Next IPL menu appear, looking like rotating glass cube:<br>
<img src='http://gcdev.narod.ru/iplmenu.jpg'><br>
Each side of cube representing different menus (memory card manager, calendar settings etc.)<br>
Deep inside cube are floating small cubes, appearing as different patterns.<br>
<br>
YouTube video : <br>
<a href='http://www.youtube.com/watch?feature=player_embedded&v=In0beAki4mM' target='_blank'><img src='http://img.youtube.com/vi/In0beAki4mM/0.jpg' width='425' height=344 /></a><br>
<br>
<b>Credits:</b>
Credits go to Gamecube scene members and my good friends : groepaz and tmbinc :=)<br>
Thanks to Nintendo and ArtX team for such sexy console ^^
