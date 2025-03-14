#include <graphics.h>
#include <iostream>

void drawSmilingFace() {
    setbkcolor(WHITE);
    cleardevice();

    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    circle(200, 200, 100);
    floodfill(200, 200, YELLOW);

    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    fillellipse(170, 170, 10, 15);
    fillellipse(230, 170, 10, 15);

    arc(200, 200, 210, 330, 50);

    delay(5000);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    drawSmilingFace();
    getch();
    closegraph();
    return 0;
}
