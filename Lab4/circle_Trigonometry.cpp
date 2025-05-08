#include <graphics.h>
#include <cmath>

void drawCircleTrigonometry(int xc, int yc, int r) {
    for (float angle = 0; angle <= 360; angle += 0.1) {
        int x = xc + r * cos(angle * M_PI / 180.0);
        int y = yc + r * sin(angle * M_PI / 180.0);
        putpixel(x, y, WHITE);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc = 200, yc = 200, r = 100;

    drawCircleTrigonometry(xc, yc, r);

    getch();
    closegraph();
    return 0;
}