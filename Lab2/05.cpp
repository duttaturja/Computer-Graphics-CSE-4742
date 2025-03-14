
#include <graphics.h>
#include <iostream>

void drawFlag() {
    setbkcolor(WHITE);
    cleardevice();

    setcolor(GREEN);

    setfillstyle(SOLID_FILL, GREEN);
    bar(100, 100, 400, 250);

    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    fillellipse(250, 175, 50, 50);

    setcolor(BLACK);
    line(100, 100, 100, 400);

    delay(5000);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    drawFlag();
    getch();
    closegraph();
    return 0;
}
