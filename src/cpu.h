#pragma once

#include <array>
#include <queue>
#include <functional>
#include <stdint.h>

using byte = uint8_t;

struct Interrupt
{
    byte data;
    byte handler;
};

class cpu 
{
private:
    // Holds all of the interrupt vectors for the inttable
    // Actual ports are listed in the docs, and hardcoded in because there arn't that many
    std::array<std::function<void(byte data)>, 0xff> inttable; 

    bool imask = true; // Mask interrupts, so that before there is a proper inttable interrupts wont call nullptr
public:
    int pc;
    std::array<byte, 0xffff> ram;
    void init();
    void tick();

    void interrupt(byte handler, byte data);
};