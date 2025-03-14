#include <graphics.h>

void drawShahidMinar() {
    int midX = getmaxx() / 2;
    int baseY = getmaxy() - 100;

    setbkcolor(DARKGRAY);
    cleardevice();
    setcolor(WHITE);

    int stepY = baseY;
    int stepWidth = 700;
    int shahidMinarWidth = 60;
    for (int i = 0; i < 6; i++) {
        int x = midX - stepWidth / 2;
        rectangle(x, stepY, x + stepWidth, stepY + 10);
        stepY -= 10;
        stepWidth -= (stepWidth - shahidMinarWidth) / 6; }
    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    fillellipse(midX, stepY - 70, 50, 50);

    setcolor(WHITE);
    rectangle(midX - 30, stepY - 200, midX + 30, stepY);
    line(midX - 15, stepY - 200, midX - 15, stepY);
    line(midX + 15, stepY - 200, midX + 15, stepY);

    rectangle(midX - 80, stepY - 150, midX - 50, stepY);
    rectangle(midX + 50, stepY - 150, midX + 80, stepY);
    rectangle(midX - 120, stepY - 100, midX - 100, stepY);
    rectangle(midX + 100, stepY - 100, midX + 120, stepY);

    char text[] = "Shahid Minar";
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(midX - 60, baseY + 20, text);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, nullptr);
    drawShahidMinar();
    getch();
    closegraph();
    return 0;
}
