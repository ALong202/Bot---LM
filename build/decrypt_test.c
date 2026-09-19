#include <stdio.h>
#include <stdint.h>
#include "../include/des.h"

static void dump(const char *name, uint8_t *buf)
{
    printf("%s:", name);
    for (int i = 0; i < 8; i++)
        printf(" %02X", buf[i]);
    printf("\n");
}

int main(void)
{
    uint8_t real[8] = {
        0x86, 0x14, 0xAA, 0x34,
        0x8C, 0xDD, 0x19, 0x7D
    };

    uint8_t bot1[8] = {
        0x1B, 0x1A, 0x4A, 0x2B,
        0x29, 0xFC, 0xEC, 0x6A
    };

    uint8_t bot2[8] = {
        0x23, 0x38, 0x87, 0x12,
        0x8A, 0x24, 0xCF, 0xE3
    };

    uint8_t out[8];

    DecryptData(real, 8, out, ENCRYPTION_KEY);
    dump("REAL", out);

    DecryptData(bot1, 8, out, ENCRYPTION_KEY);
    dump("BOT1", out);

    DecryptData(bot2, 8, out, ENCRYPTION_KEY);
    dump("BOT2", out);

    return 0;
}
