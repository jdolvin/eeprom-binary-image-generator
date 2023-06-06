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

        int twos_comp_index = index - 128;
        // twos complement
        // ones place
        mem[(uint8_t) twos_comp_index + 1024] =
                digits[abs(twos_comp_index) % 10];
        // tens place
        mem[(uint8_t) twos_comp_index + 1280] =
                digits[(abs(twos_comp_index) / 10) % 10];
        // hundreds place
        mem[(uint8_t) twos_comp_index + 1536] =
                digits[(abs(twos_comp_index) / 100) % 10];
        // sign
        if (twos_comp_index < 0) {
            mem[(uint8_t) twos_comp_index + 1792] = 0x01;
        } else {
            mem[(uint8_t) twos_comp_index + 1792] = 0x00;
        }

        // 1s in the rest of the image
        for (int i = 2048; i <= 4096; i += 256) {
            mem[index + i] = 0xFF;
        }
    }

    FILE *output;
    output = fopen("./multiplex_7seg_cc.bin", "wb");
    fwrite(mem, sizeof(mem), 1, output);
    fclose(output);

    return 0;
}