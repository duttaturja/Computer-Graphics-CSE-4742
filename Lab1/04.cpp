#include <graphics.h>
#include <iostream>

using namespace std;

void displayImage()
 {

    setbkcolor(WHITE);
    cleardevice();

    readimagefile("IIUC.bmp", 50, 100, 300, 400);

    delay(5000);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    displayImage();

    getch();
    closegraph();
    return 0;
}
