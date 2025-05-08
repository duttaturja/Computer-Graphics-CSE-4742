#include <graphics.h>
#include <cmath>

void drawEllipsePolynomial(int xc, int yc, int a, int b) {
    float x, y;

    // Region 1: x varies from 0 to a
    for (x = 0; x <= a; x++) {
        y = b * sqrt(1 - (x * x) / (a * a));
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
    }

    // Region 2: y varies from 0 to b
    for (y = 0; y <= b; y++) {
        x = a * sqrt(1 - (y * y) / (b * b));
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc = 300, yc = 200, a = 150, b = 100;

    drawEllipsePolynomial(xc, yc, a, b);

    getch();
    closegraph();
    return 0;
}