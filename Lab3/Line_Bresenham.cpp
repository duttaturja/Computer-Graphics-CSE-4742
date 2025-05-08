#include <graphics.h>
#include <iostream>
#include <cmath>

void drawLineBresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x2 > x1) ? 1 : -1; // Step for x
    int sy = (y2 > y1) ? 1 : -1; // Step for y

    bool isSteep = dy > dx;
    if (isSteep) {
        std::swap(dx, dy);
    }

    int p = 2 * dy - dx; // Decision parameter
    int x = x1, y = y1;

    for (int i = 0; i <= dx; i++) {
        if (isSteep) {
            putpixel(y, x, WHITE); // Swap x and y for steep lines
        } else {
            putpixel(x, y, WHITE);
        }

        if (p >= 0) {
            y += sy;
            p -= 2 * dx;
        }
        x += sx;
        p += 2 * dy;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 100, y1 = 100, x2 = 400, y2 = 300;

    drawLineBresenham(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}