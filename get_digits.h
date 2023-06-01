//
// Created by Justin Dolvin on 5/31/23.
//

#ifndef BINARY_IMAGE_GENERATOR_GET_DIGITS_H
#define BINARY_IMAGE_GENERATOR_GET_DIGITS_H

#include <cstdint>
#include <cstring>

[[maybe_unused]]
std::array<uint8_t, 16> get_all_digits(const std::string &ca_or_cc) {
    // common cathode 7seg display
    if (ca_or_cc == "cc") {
        return {
                0x7E, 0x30, 0x6D, 0x79,
                0x33, 0x5B, 0x5F, 0x70,
                0x7F, 0x7B, 0x77, 0x1F,
                0x4E, 0x3D, 0x4F, 0x47
        };
    }

    // common anode 7seg display
    if (ca_or_cc == "ca") {
        return {
                0x81, 0xCF, 0x92, 0x86,
                0xCC, 0xA4, 0xA0, 0x8F,
                0x80, 0x84, 0x88, 0xE0,
                0xB1, 0xC2, 0xB0, 0xB8
        };
    }

    return {
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00
    };
}

std::array<uint8_t, 10> get_digits(const std::string &ca_or_cc) {
    // common cathode 7seg display
    if (ca_or_cc == "cc") {
        return {
                0x7E, 0x30, 0x6D, 0x79,
                0x33, 0x5B, 0x5F, 0x70,
                0x7F, 0x7B
        };
    }

    // common anode 7seg display
    if (ca_or_cc == "ca") {
        return {
                0x81, 0xCF, 0x92, 0x86,
                0xCC, 0xA4, 0xA0, 0x8F,
                0x80, 0x84,
        };
    }

    return {
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x00
    };
}

#endif //BINARY_IMAGE_GENERATOR_GET_DIGITS_H
