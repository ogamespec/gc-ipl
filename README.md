<h3>Open source Gamecube bootrom</h3>

<b>!!! For educational purposes only !!!</b>

<b>Project Goals:</b>
  * Reverse engineering of retail `GameCube` bootrom
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

<b>Bootrom details:</b>

Bootrom is located in special chip, designed by Macronix Ltd., and placed near Flipper IC : <br>
<img src='http://gcdev.narod.ru/bootrom.jpg'>

Bootrom size is 2 MB.<br>
<br>
First logical part of bootrom (reset vector) called Bootstrap 1 (BS1). This small procedure is written on assembly. It prepares Gamecube hardware, checks memory and load second logical part, known as Bootstrap 2 (BS2) or IPL (Intial Program Loader).<br>
<br>
IPL is written on C. It's compiled as DOL executable, by using early version Dolphin SDK as system API.<br>
Code entrypoint for start routine is made to 0x81300000 location, by link script.<br>

Almost 50% of IPL binary payload is occupied by Dolphin SDK library calls.

Important Note: Bootrom is encrypted itself. Decryption is done by MX chip, during block reading of bootrom data. Encryption algorithm was reversed by segher : <a href='../wiki/Descrambler.md'>Descrambler</a>

Also Bootrom contains two sets of raster fonts. One for ANSI charset and another for SJIS:<br>
<img src='http://gcdev.narod.ru/font_00.jpg'> <img src='http://gcdev.narod.ru/font_03.jpg'><br>
These fonts are rarely used by some games. Font data is <b>not</b> encrypted.<br>
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
