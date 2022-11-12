## BootROM Fonts Data format

First 16 bytes are 'Yay0' header:

|offset |size|     description|
|:------|:---|:---------------|
|  +0    |4       |'Yay0' signature|
|+4    |4       |size of decoded data, in bytes|
|+8    |4       |link table offset|
|+12   |4       |non-linked chunks and count modifiers table offset|
|+16           |  |chunk description mask (words). each word describes incoming 32 chunks. if bit is set, then next chunk is non-linked (1 byte), otherwise next chunk is copied from previous data<br>Example mask : 0b 1101 0010 0000 0010 0000 0000 1101 1001,<br>bit 0 = 1, chunk 0 is non-linked, grab next byte from [+12] buffer<br>bit 1 = 1, chunk 1 is non-linked, grab next byte from [+12] buffer<br>bit 2 = 0, chunk 2 is linked, do block copy, using [+8] table<br>and so on...<br>
<tr><td>[+8]</td><td>           </td><td>chunks link table (offsets)</td></tr>
<tr><td>[+12]</td><td>         </td><td>non-linked chunks and count modifiers buffer</td></tr></tbody></table>

Total size of decoded data buffer calculated as header size (16 bytes) and size of decoded data ([+4] in header). Typical values are :<br>
<br>
ANSI font = 65824 bytes, SJIS font = 593636 bytes<br>
<br>
Average packing ratio is 20-50% (depends on data size)<br>
<br>
<h2>Description of 'decoding'</h2>

I dont know much about other data compression algorithms, so I will not be surprised, if Yay0 is just LZ modification :)<br>
<br>
Recipe : general idea to repeat previously unpacked block of data.<br>
<br>
<ol><li>if next bit in mask is '1', copy one byte to destination buffer from [+12] table, otherwise do following steps.<br>
</li><li>read 16-bit halfword from 'chunks link table' area :<br>
<pre><code>        [cccc] [oooo oooo oooo]<br>
</code></pre>
<blockquote>first 4-bits are 'count' modifier. it counts bytes to copy.<br>
next 12-bits are 'offset' modifier.<br>
</blockquote></li><li>adjust modifiers :<br>
<pre><code>        id('count' == 0)<br>
        {<br>
            'cmod' = grab next byte from 'count modifiers buffer'<br>
            'count' = 'cmod' + 18;<br>
        }<br>
        else 'count' = 'count' + 2;<br>
<br>
        'offset' = 'offset' - 1;<br>
</code></pre>
<blockquote>(assuming, that current offset is in destination buffer)<br>
</blockquote></li><li>copy 'count' bytes from 'current offset' - 'offset'.</li></ol>

<h2>Reversing of decoding routine</h2>

<pre><code>void Decode(void *s, void *d)<br>
{<br>
    i, j, k<br>
    p, q<br>
    cnt<br>
<br>
    i = r21 = *(u32 *)(s + 4);      // size of decoded data<br>
    j = r29 = *(u32 *)(s + 8);      // link table<br>
    k = r23 = *(u32 *)(s + 12);     // byte chunks and count modifiers<br>
<br>
    q = r31 = 0                     // current offset in dest buffer<br>
    cnt = r28 = 0                   // mask bit counter<br>
    p = r24 = 16                    // current offset in mask table<br>
<br>
    do<br>
    {<br>
        // if all bits are done, get next mask<br>
        if(cnt == 0)<br>
        {<br>
            // read word from mask data block<br>
            r22 = *(u32 *)(s + p);<br>
            p += 4;<br>
            cnt = 32;   // bit counter<br>
        }<br>
<br>
        // if next bit is set, chunk is non-linked<br>
        if(r22 &amp; 0x80000000)<br>
        {<br>
            // get next byte<br>
            *(u8 *)(d + q) = *(u8 *)(s + k);<br>
            k++, q++;<br>
        }<br>
        // do copy, otherwise<br>
        else<br>
        {<br>
            // read 16-bit from link table<br>
            r26 = *(u16 *)(s + j);<br>
            j += 2;<br>
<br>
            // 'offset'<br>
            r25 = q - (r26 &amp; 0xfff);<br>
<br>
            // 'count'<br>
            r30 = r26 &gt;&gt; 12;<br>
<br>
            if(r30 == 0)<br>
            {<br>
                // get 'count' modifier<br>
                r5 = *(u8 *)(s + k);<br>
                k++;<br>
                r30 = r5 + 18<br>
            }<br>
            else r30 += 2;<br>
<br>
            // do block copy<br>
            r5 = d + r25<br>
            for(i=0; i&lt;r30; i++)<br>
            {<br>
                *(u8 *)(d + q) = *(u8 *)(r5 - 1);<br>
                q++, r5++;<br>
            }<br>
        }<br>
<br>
        // next bit in mask<br>
        r22 &lt;&lt;= 1;<br>
        cnt--;<br>
    } while(q &lt; i);<br>
}<br>
</code></pre>

Notes : I found that some files on gamecube DVDs which have "SZP" extension are also compressed as "Yay0", so probably Nintendo's term for this compression algo is 'SZP'-compression.<br>
<br>
Dolphin SDK contain OSFont API to load font and convert it to texture for graphics output.
