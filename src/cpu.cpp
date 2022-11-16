#include "cpu.h"

void cpu::interrupt(byte handler, byte data)
{
    if (!imask) inttable[handler](data);
}