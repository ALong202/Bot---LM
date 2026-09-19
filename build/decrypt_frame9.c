#include <stdio.h>
#include <stdint.h>
#include "../include/des.h"

static uint16_t u16(const uint8_t *p)
{
    return (uint16_t)p[0] |
           ((uint16_t)p[1] << 8);
}

static uint32_t u32(const uint8_t *p)
{
    return (uint32_t)p[0] |
           ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) |
           ((uint32_t)p[3] << 24);
}

int main(void)
{
    uint8_t enc[27] = {
        0xEC, 0x58, 0x73, 0x9D, 0x20, 0xEA, 0x54, 0x35,
        0xF2, 0x47, 0x2A, 0x61, 0xE5, 0xB8, 0x10, 0x86,
        0xB0, 0x0D, 0xDC, 0x02, 0x32, 0x10, 0x29, 0x50,
        0x54, 0x88, 0x6C
    };

    uint8_t dec[27];

    DecryptData(enc, 27, dec, ENCRYPTION_KEY);

    printf("DECRYPTED:");
    for (int i = 0; i < 27; i++)
        printf(" %02X", dec[i]);
    printf("\n\n");

    printf("seq   = %u (0x%08X)\n",
           u32(dec + 0), u32(dec + 0));

    printf("zone  = %u (0x%04X)\n",
           u16(dec + 4), u16(dec + 4));

    printf("point = %u (0x%02X)\n",
           dec[6], dec[6]);

    printf("food  = %u\n", u32(dec + 7));
    printf("rock  = %u\n", u32(dec + 11));
    printf("wood  = %u\n", u32(dec + 15));
    printf("ore   = %u\n", u32(dec + 19));
    printf("gold  = %u\n", u32(dec + 23));

    return 0;
}
