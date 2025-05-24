#include <graphics.h>
#include <conio.h>

// 5x7 bitmap font for A, B, C (expand as needed)
const int FONT_WIDTH = 5;
const int FONT_HEIGHT = 7;
const unsigned char font[][FONT_HEIGHT] = {
    // A
    {0x1E, 0x05, 0x05, 0x1E, 0x00, 0x00, 0x00},
    // B
    {0x1F, 0x15, 0x15, 0x0A, 0x00, 0x00, 0x00},
    // C
    {0x0E, 0x11, 0x11, 0x0A, 0x00, 0x00, 0x00}
    // Add more letters as needed
};

// Draw a filled rectangle for scaling
void drawBlock(int x, int y, int scale, int color) {
    for (int i = 0; i < scale; i++) {
        for (int j = 0; j < scale; j++) {
            putpixel(x + i, y + j, color);
        }
    }
}

// Draw a single character at (x, y) with scaling
void drawChar(int x, int y, char ch, int color, int scale) {
    if (ch < 'A' || ch > 'C') return; // Only A-C defined
    int index = ch - 'A';
    for (int row = 0; row < FONT_HEIGHT; row++) {
        unsigned char bits = font[index][row];
        for (int col = 0; col < FONT_WIDTH; col++) {
            if (bits & (1 << (FONT_WIDTH - 1 - col))) {
                drawBlock(x + col * scale, y + row * scale, scale, color);
            }
        }
    }
}

// Draw a string at (x, y) with scaling
void drawString(int x, int y, const char* str, int color, int scale) {
    int offset = 0;
    while (*str) {
        drawChar(x + offset, y, *str, color, scale);
        offset += (FONT_WIDTH + 1) * scale; // 1 pixel space between chars, scaled
        str++;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int scale = 5; // Change this value to make the font bigger or smaller

    // Draw "ABC" at position (100, 100) with scaling
    drawString(100, 100, "ABC", WHITE, scale);

    getch();
    closegraph();
    return 0;
}