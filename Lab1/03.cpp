#include <graphics.h>
#include <iostream>

using namespace std;

void displayText()
{

    setbkcolor(WHITE);
    cleardevice();

    setcolor(RED);
    settextstyle(BOLD_FONT, HORIZ_DIR, 5);

    outtextxy(100, 200, "Hello World!");
    delay(5000);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    displayText();

    getch();
    closegraph();
    return 0;
}
