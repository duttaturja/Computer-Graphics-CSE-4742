#include <graphics.h>
using namespace std;

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, nullptr);

    setbkcolor(BLACK);
    cleardevice();

    setcolor(WHITE);

    rectangle(100, 400, 540, 420);
    line(80, 420, 560, 420);

    line(320, 100, 380, 400);
    line(320, 100, 260, 400);
    line(260, 400, 380, 400);

    line(320, 160, 290, 300);
    line(320, 160, 350, 300);
    line(290, 300, 350, 300);

    line(260, 400, 230, 320);
    line(230, 320, 200, 400);
    line(200, 400, 180, 350);
    line(180, 350, 160, 400);
    line(160, 400, 140, 370);
    line(140, 370, 120, 400);

    line(380, 400, 410, 320);
    line(410, 320, 440, 400);
    line(440, 400, 460, 350);
    line(460, 350, 480, 400);
    line(480, 400, 500, 370);
    line(500, 370, 520, 400);

    setcolor(WHITE);
    line(140, 370, 180, 350);
    line(180, 350, 230, 320);
    line(230, 320, 320, 100);
    line(320, 100, 410, 320);
    line(410, 320, 460, 350);
    line(460, 350, 500, 370);

    getch();
    closegraph();
    return 0;
}
