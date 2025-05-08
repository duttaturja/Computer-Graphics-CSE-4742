#include <graphics.h>
#include <cmath>
#include <iostream>

void drawLineDDA(int x1, int y1, int x2, int y2) {
    float dx = x2 - x1;
    float dy = y2 - y1;

    int steps = std::max(abs(dx), abs(dy));

    float xIncrement = dx / steps;
    float yIncrement = dy / steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);
        x += xIncrement;
        y += yIncrement;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 100, y1 = 100, x2 = 400, y2 = 300;

    drawLineDDA(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}