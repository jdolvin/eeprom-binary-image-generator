#include <iostream>
#include "get_digits.h"

int main() {
    uint8_t mem[4096];

    // 7Seg digits
    // ca for common anode
    // cc for common cathode
    std::array<uint8_t, 10> digits = get_digits("cc");

    for (int index = 0; index < 256; index++) {
        // ones place
        mem[index] = digits[index % 10];
        // tens place
        mem[index + 256] = digits[(index / 10) % 10];
        // hundreds place
        mem[index + 512] = digits[(index / 100) % 10];
        // sign
        mem[index + 768] = 0x00;

        // ones place (twos complement)
        mem[index + 1024] = digits[abs(index - 128) % 10];
        // tens place (twos complement)
        mem[index + 1280] = digits[(abs(index - 128) / 10) % 10];
        // hundreds place (twos complement)
        mem[index + 1536] = digits[(abs(index - 128) / 100) % 10];
        // sign (twos complement)
        if (index < 128) {
            mem[index + 1792] = 0x01;
        } else {
            mem[index + 1792] = 0x00;
        }
    }

    for (int index = 2048; index < sizeof(mem); index++) {
        mem[index] = 0xFF;
    }

    FILE *output;
    output = fopen("./multiplex_7seg_cc.bin", "wb");
    fwrite(mem, sizeof(mem), 1, output);
    fclose(output);

    return 0;
}