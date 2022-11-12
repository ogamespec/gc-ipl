
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Commondefs.h"

u16 FASTCALL Swap16(u16 data)
{ 
    return ((data & 0x00ff) << 8) |
           ((data & 0xff00) >> 8) ;
}
u32 FASTCALL Swap32(u32 data)
{
    return ((data >> 24)             ) |
           ((data >>  8) & 0x0000ff00) |
           ((data <<  8) & 0x00ff0000) |
           ((data << 24)             );
}

/*
 ***************************************************************************
 * Compress API. Credits to hotquik for his Compress/Decompress implementation!!
 * (SZP is actually LZSS modification).
 ***************************************************************************
*/

#define SZP_ALLOC   malloc
#define SZP_FREE    free
#define SZP_MAGIC   (('0'<<24)+('y'<<16)+('a'<<8)+'Y')  // Yay0

typedef struct SZP_S        // Szp Header.
{
    u32 check;
    u32 decodedSize;
    u32 linkOffset;
    u32 chunkOffset;
    #pragma warning (disable: 4200)
    u32 flagTable[];
} SZP_S;

// Encodes a data range in a SZP block.
// In: Memory mapped source buffer and its length in bytes.
// Out: Pre-allocated destination buffer (recommended length is twice as source),
// compressed buffer length in bytes.
void SZP_Compress(void *dest, int *encodedSize, void *src, int srcLen)
{
    #define OFSBITS     12

    u8 * decodedBuffer = (u8 *)src, *encodedBuffer = (u8 *)dest;
    u32 decodedSize = srcLen;
    u8 * decPtr, * decEndPtr;
    SZP_S * header;

    // masks buffer
    u32 maskMaxSize = (decodedSize + 32) >> 3; // 1 bit per byte
    u32 maskSize = 0;
    u32 maskBitCount = 0, mask = 0;
    u32 * maskBuffer, * maskPtr,  * maskEndPtr;

    // links buffer
    u32 linkMaxSize = decodedSize;
    u32 linkSize = 0;
    u16 link = 0;
    u16 linkOffset;
    u16 * linkBuffer, * linkPtr,  * linkEndPtr;
    u16 maxOffset = 1 << OFSBITS;
    u16 minCount = 3, maxCount = 273;

    // chunks buffer
    u32 chunkMaxSize = decodedSize;
    u32 chunkSize = 0;
    u8 chunk = 0;
    u8 * chunkBuffer, * chunkPtr,  * chunkEndPtr;

    u8 *windowPtr;
    int windowLen = 0, length, maxlen;

    // Re-allocate memory needed

    maskBuffer = (u32 *) SZP_ALLOC(maskMaxSize);
    linkBuffer = (u16 *) SZP_ALLOC(linkMaxSize);
    chunkBuffer = (u8 *) SZP_ALLOC(chunkMaxSize);

    if (maskBuffer == NULL || linkBuffer == NULL || chunkBuffer == NULL) {
        SZP_FREE(maskBuffer);
        SZP_FREE(linkBuffer);
        SZP_FREE(chunkBuffer);
        return;
    }

    memset(maskBuffer, 0, maskMaxSize);
    //memset(linkBuffer, 0, linkMaxSize);       // Unnecessary.
    //memset(chunkBuffer, 0, chunkMaxSize);

    //set pointers
    decPtr = decodedBuffer;
    decEndPtr = decPtr + decodedSize;

    maskPtr = maskBuffer;
    maskEndPtr = (u32 *)((u8 *)maskPtr + maskMaxSize);

    linkPtr = linkBuffer;
    linkEndPtr = (u16 *)((u8 *)linkPtr + linkMaxSize);

    chunkPtr = chunkBuffer;
    chunkEndPtr = chunkPtr + chunkMaxSize;
    windowPtr = decPtr;

    // start enconding
    while (decPtr < decEndPtr) {
        // check buffers pointers
#if 0
        ASSERTMSG (!(maskPtr >= maskEndPtr), "SZP Encode: Not enough memory for mask buffer");
        ASSERTMSG (!(linkPtr >= linkEndPtr), "SZP Encode: Not enough memory for links buffer");
        ASSERTMSG (!(chunkPtr >= chunkEndPtr), "SZP Encode: Not enough memory for chunks buffer");
#endif

        if(windowLen >= (1 << OFSBITS))
        {
            windowLen = windowLen - (1 << OFSBITS);
            windowPtr = decPtr - windowLen;
        }

        if((decEndPtr - decPtr) < maxCount) maxCount = (decEndPtr - decPtr);

        // Scan through the window.
        maxlen = 0;
        for(int i=0; i<windowLen; i++)
        {
            for(length=0; length<(windowLen-i) && length<maxCount; length++)
            {
                if(decPtr[length] != windowPtr[length+i]) break;
            }
            if(length > maxlen)
            {
                maxlen = length;
                linkOffset = windowLen - i;
            }
        }
        length = maxlen;

        mask <<= 1;
        if(length >= minCount)      // Add Link
        {
            link = (linkOffset - 1) & 0x0FFF;

            if (length < 18) {
                link |= ((length - 2) << 12) ;
            }
            else{
                // store current count as a chunk.
                *chunkPtr++ = (u8)(length - 18);
            }

            *linkPtr++ = Swap16(link);
            decPtr += length;
            windowLen += length;
        }
        else                        // Add single byte, increase Window.
        {
            *chunkPtr++ = *decPtr++;
            windowLen++;
            mask |= 1;
        }

        maskBitCount++;
        if (maskBitCount == 32) {
            // store current mask
            *maskPtr = Swap32(mask);
            maskPtr++;
            maskBitCount = 0;
        }
    }

    //flush mask 
    if (maskBitCount > 0) {
        mask <<= (32 - maskBitCount);
        // store current mask
        *maskPtr = Swap32(mask);
        maskPtr++;
        maskBitCount = 0;
    }

    // now join all pieces
    maskSize = (u32)((u8 *)maskPtr - (u8 *)maskBuffer);
    linkSize = (u32)((u8 *)linkPtr - (u8 *)linkBuffer);
    chunkSize = (u32)((u8 *)chunkPtr - (u8 *)chunkBuffer);

    *encodedSize = sizeof(SZP_S) + maskSize + linkSize + chunkSize;
    header = (SZP_S *)encodedBuffer;

    // swap arch. dependent data
    header->check = SZP_MAGIC;
    header->decodedSize = Swap32(decodedSize);
    header->linkOffset = Swap32(sizeof(SZP_S) + maskSize);
    header->chunkOffset = Swap32(sizeof(SZP_S) + maskSize + linkSize);

    // copy all buffer to final buffer
    memcpy((u8 *)header + sizeof(SZP_S), maskBuffer, maskSize);
    memcpy((u8 *)header + sizeof(SZP_S) + maskSize, linkBuffer, linkSize);
    memcpy((u8 *)header + sizeof(SZP_S) + maskSize + linkSize, chunkBuffer, chunkSize);

    SZP_FREE(maskBuffer);
    SZP_FREE(linkBuffer);
    SZP_FREE(chunkBuffer);
}

// Decodes an SZP block. Decoding is incredibly fast!
// In: Memory mapped compressed buffer and its length in bytes.
// Out: Pre-allocated destination buffer (length can be obtained from buffer's
// header), decompressed buffer length in bytes.
void SZP_Decompress(void *dest, int *destLen, void *src, int srcLen)
{
    u8 * encodedBuffer = (u8 *)src;
    SZP_S * header;
    u8 * decodedBuffer;

    u32 decodedBytes, decodedSize, linkOffset, chunkOffset;
    u32 mask, maskBitsLeft, maskOffset;

    u32 aux;
    header =  (SZP_S *)encodedBuffer;
    decodedSize = Swap32(header->decodedSize);      // size of decoded data
    linkOffset = Swap32(header->linkOffset);      // link table
    chunkOffset = Swap32(header->chunkOffset);     // byte chunks and count modifiers
    decodedBytes = 0;                     // current offset in dest buffer
    maskBitsLeft = 0;                   // mask bit counter
    maskOffset = 16;                    // current offset in mask table

    decodedBuffer = (u8 *)dest;

    //memset(decodedBuffer, 0, decodedSize);
    *destLen = decodedSize;

    do
    {

        // if all bits are done, get next mask
        if(maskBitsLeft == 0)
        {
            // read word from mask data block
            mask = Swap32(*(u32 *)(encodedBuffer + maskOffset));
            maskOffset += 4;
            maskBitsLeft = 32;   // bit counter
        }

        // if next bit is set, chunk is non-linked
        if(mask & 0x80000000)
        {
            // get next byte
            *(u8 *)(decodedBuffer + decodedBytes) = *(u8 *)(encodedBuffer + chunkOffset);
            chunkOffset++, decodedBytes++;
        }
        // do copy, otherwise
        else
        {
            u16 link;
            u32 count;
            u8 * pointer;

            // read 16-bit from link table
            link = Swap16(*(u16 *)(encodedBuffer + linkOffset));

            linkOffset += 2;
             // 'offset'
            pointer = decodedBuffer + decodedBytes - ( (link & 0xfff) + 1);
             // 'count'
            count = link >> 12;

            if(count == 0)
            {
                // get 'count' from chunks table
                count = *(u8 *)(encodedBuffer + chunkOffset) + 18;
                chunkOffset++;
            }
            else count += 2;

            // do block copy
            for(aux=0; aux<count; aux++)
            {
                *(u8 *)(decodedBuffer + decodedBytes) = *pointer;
                decodedBytes++, pointer++;
            }
    
        }

        // next bit in mask
        mask <<= 1;
        maskBitsLeft--;
    } while(decodedBytes < decodedSize);
}


// --- Quick File Compress/Decompress (memory mapping used! So do not apply on huge files)

// Load data from file.
void *FileLoad(char *filename, u32 *size, char *mode)
{
    FILE*   f;
    void*   buffer;
    u32     filesize;

    if(size) *size = 0;

    fopen_s(&f, filename, mode);
    if(f == NULL) return NULL;

    fseek(f, 0, SEEK_END);
    filesize = ftell(f);
    fseek(f, 0, SEEK_SET);

    buffer = malloc (filesize + 1);
    if(buffer == NULL)
    {
        fclose(f);
        return NULL;
    }
    memset(buffer, 0, filesize + 1);

    fread(buffer, 1, filesize, f);
    fclose(f);
    if(size) *size = filesize;    
    return buffer;
}

// Save data in file.
bool FileSave(char *filename, void *data, u32 size, char *mode)
{
    FILE* f;
    fopen_s(&f, filename, mode);
    if(f == NULL) return false;

    fwrite(data, size, 1, f);
    fclose(f);
    return true;
}

bool FileCompress(char *to, char *from)
{
    void *buf, *filedata;
    u32 filesize = 0, packedSize = 0;
    filedata = FileLoad(from, &filesize, "rb");
    if(filedata == NULL) return false;
    buf = SZP_ALLOC(filesize*2);
    if(buf == NULL)
    {
        free(filedata);
        return false;
    }
    SZP_Compress(buf, (int *)&packedSize, filedata, (int)filesize);
    bool result = FileSave(to, buf, packedSize, "wb");
    free(filedata);
    SZP_FREE(buf);
    return result;
}

bool FileDecompress(char *to, char *from)
{
    u32 filesize, unpackedSize;
    void *filedata = FileLoad(from, &filesize, "rb");
    if(filedata == NULL) return false;
    SZP_S *header = (SZP_S *)filedata;
    if(header->check != SZP_MAGIC)
    {
        free(filedata);
        return false;
    }
    void *buf = SZP_ALLOC(Swap32(header->decodedSize));
    if(buf == NULL)
    {
        free(filedata);
        return false;
    }
    SZP_Decompress(buf, (int *)&unpackedSize, filedata, (int)filesize);
    bool result = FileSave(to, buf, unpackedSize, "wb");
    free(filedata);
    SZP_FREE(buf);
    return result;
}
