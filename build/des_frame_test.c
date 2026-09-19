#include <stdio.h>
#include <stdint.h>
#include "../include/des.h"

int main(void)
{
    uint8_t in[8] = {
        0xEC, 0x58, 0x73, 0x9D,
        0x20, 0xEA, 0x54, 0x35
    };

    uint8_t out[8];

    DecryptData(in, 8, out, ENCRYPTION_KEY);

    printf("IN :");
    for (int i = 0; i < 8; i++)
        printf(" %02X", in[i]);

    printf("\nOUT:");
    for (int i = 0; i < 8; i++)
        printf(" %02X", out[i]);

    printf("\n");
    return 0;
}
