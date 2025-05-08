#include <graphics.h>
#include <cmath>

void drawCirclePolynomial(int xc, int yc, int r) {
    int x = 0;
    int y = r;

    // Draw the initial points
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);

    while (x <= y) {
        x++;
        y = round(sqrt(r * r - x * x));

        // Draw the symmetric points
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc = 200, yc = 200, r = 100;

    drawCirclePolynomial(xc, yc, r);

    getch();
    closegraph();
    return 0;
}
