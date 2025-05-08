#include <graphics.h>
#include <iostream>
#include <cmath>

void drawLineEquation(int x1, int y1, int x2, int y2) {
    float m = (float)(y2 - y1) / (x2 - x1); // Slope of the line
    float c = y1 - m * x1;                 // Intercept of the line

    if (abs(x2 - x1) >= abs(y2 - y1)) {
        // Iterate over x-coordinates
        for (int x = x1; x <= x2; x++) {
            int y = round(m * x + c);
            putpixel(x, y, WHITE);
        }
    } else {
        // Iterate over y-coordinates
        for (int y = y1; y <= y2; y++) {
            int x = round((y - c) / m);
            putpixel(x, y, WHITE);
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 100, y1 = 100, x2 = 400, y2 = 300;

    drawLineEquation(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}