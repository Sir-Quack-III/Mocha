#define OLC_PGE_APPLICATION

#include <iostream>
#include <stdint.h>

#include "devices/disp.hpp"
#include "cpu.hpp"

// stolen: https://codereview.stackexchange.com/questions/22901/reading-all-bytes-from-a-file
static std::vector<char> ReadAllBytes(char const* filename) {
    std::ifstream ifs(filename, std::ios::binary|std::ios::ate);
    std::ifstream::pos_type pos = ifs.tellg();

    if (pos == 0) {
        return std::vector<char>{};
    }

    std::vector<char>  result(pos);

    ifs.seekg(0, std::ios::beg);
    ifs.read(&result[0], pos);

    return result;
}


int main() {
    Disp disp;
    std::vector<char> f = ReadAllBytes("mocha.bin");

    for (int i = 0; i < f.size(); i++) {
        disp.vram[i] = f[i];
    }

    if (disp.Construct(255,144,4,4)) disp.Start();
    return 0;
}
