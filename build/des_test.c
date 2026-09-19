#include <stdio.h>
#include <stdint.h>
#include "../include/des.h"

int main(void)
{
    uint8_t in[8] = {
        0x07, 0x00, 0x00, 0x00,
        0x9B, 0x02, 0x70, 0x40
    };

    uint8_t out[8];

    EncryptData(in, 8, out, ENCRYPTION_KEY);

    printf("OUT:");
    for (int i = 0; i < 8; i++)
        printf(" %02X", out[i]);
    printf("\n");

    return 0;
}
