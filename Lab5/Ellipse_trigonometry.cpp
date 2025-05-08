#include <graphics.h>
#include <cmath>

void drawEllipseTrigonometry(int xc, int yc, int a, int b) {
    float angle, x, y;

    // Loop through angles from 0 to 360 degrees
    for (angle = 0; angle <= 360; angle += 0.1) {
        x = a * cos(angle * M_PI / 180.0);
        y = b * sin(angle * M_PI / 180.0);

        // Plot the points
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

    drawEllipseTrigonometry(xc, yc, a, b);

    getch();
    closegraph();
    return 0;
}