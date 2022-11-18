#pragma once

#include <array>
#include <queue>
#include <functional>
#include <stdint.h>

using byte = uint8_t;

struct Interrupt {
    byte data;
    byte handler;
};

class cpu {
public:
    int pc;
    std::array<byte, 0xffff> ram;
    void init();
    void tick();

    void interrupt(byte handler, byte data);
};