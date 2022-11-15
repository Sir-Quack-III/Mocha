#pragma once

#include <array>
#include <stdint.h>

using byte = uint8_t;

struct port {
    bool rw; // 0 = read, 1 = write
    byte data;
};

class cpu {
public:
    int pc;
    std::array<byte, 0xffff> ram;
    std::array<port, 16> io;
    void init();
    void tick();
};