#include <graphics.h>
#include <iostream>

using namespace std;

void drawShapes() {

    setbkcolor(WHITE);
    cleardevice();

    setcolor(BLUE);

    line(100, 100, 300, 100);

    circle(200, 180, 50);

    rectangle(100, 300, 300, 400);

    delay(5000);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    drawShapes();

    getch();
    closegraph();
    return 0;
}
