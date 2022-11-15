#include "disp.h"
#include "keyboard.h"

std::array<uint8_t, 3> Disp::byteToRGB(uint8_t color) {
    std::array<uint8_t, 3> rgb{color, color, color};
    // rgb[0] = (color & 0b11100000) >> 5;
    // rgb[1] = (color & 0b00011100) >> 2;
    // rgb[2] = (color & 0b00000011);
    return rgb;
}

bool Disp::OnUserCreate() {
    return true;
}

void Disp::DispDraw(uint8_t r, uint8_t g, uint8_t b, uint8_t x, uint8_t y) {
    Draw(x, y, olc::Pixel(r,g,b));
}

bool Disp::OnUserUpdate(float fElapsedTime) {
    int idx = 0;
    std::array<uint8_t, 3> rgb;

    for (int y = 0; y < 144; y++) {
        for (int x = 0; x < 255; x++) {
            std::array<uint8_t, 3> rgb = byteToRGB(_cpu->ram[idx]);
            DispDraw(rgb[0], rgb[1], rgb[2], x, y);
            idx++;
        }
    }

    for (auto& m : valueInputKeys)
    {
        if (GetKey(m.key).bPressed)
        {
            _cpu->interrupt(0x16, 0);
            _cpu->interrupt(0x16, (byte) m.key);
        }

        if (GetKey(m.key).bReleased)
        {
            _cpu->interrupt(0x16, 1);
            _cpu->interrupt(0x16, (byte) m.key);
        }
    }
        

    return true;
}

// void Disp::RenderFontChar(uint8_t chr[8], uint8_t x, uint8_t y) {
//     for (int i = 0; i < 8; i++) {
//         for (int j = 0; j < 8; j++) {
//             if (chr[i] & (1 << j)) {
//                 DispDraw(255, 255, 255, x + j, y + i);
//             }
//         }
//     }
// }

// void Disp::RenderFontStr(std::string str, uint8_t x, uint8_t y) {
//     int j = 0;
//     for (int i = 0; i < str.length(); i++) {
//         if (x + (j * 8) > 0xFF) {
//             x = 0;
//             j = 0;
//             y += 8;
//         }
//         RenderFontChar(font8x8_basic[str[i]], x + (j * 8), y);
//         j++;
//     }
// }
