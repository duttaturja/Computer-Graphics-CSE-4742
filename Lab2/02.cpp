#include <graphics.h>
#include <iostream>

void drawAB() {
    setbkcolor(WHITE);
    cleardevice();
    setcolor(RED);
    setlinestyle(SOLID_LINE, 0, 3);

    line(100, 300, 150, 100);
    line(150, 100, 200, 300);
    line(120, 220, 180, 220);

    line(250, 100, 250, 300);
    arc(250, 150, 270, 90, 50);
    arc(250, 250, 270, 90, 50);

    delay(5000);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    drawAB();
    getch();
    closegraph();
    return 0;
}
