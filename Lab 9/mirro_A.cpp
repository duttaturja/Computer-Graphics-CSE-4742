#include <graphics.h>
#include <conio.h>
#include <iostream>
using namespace std;

// Function to draw character 'A' using lines
void drawA(int x, int y, int size, int color) {
    setcolor(color);
    // Left leg
    line(x, y, x - size / 2, y + size);
    // Right leg
    line(x, y, x + size / 2, y + size);
    // Crossbar
    line(x - size / 4, y + size / 2, x + size / 4, y + size / 2);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x = 200, y = 100, size = 100;

    // Draw X-axis for reference
    setcolor(WHITE);
    line(0, y + size + 20, getmaxx(), y + size + 20);
    outtextxy(10, y + size + 25, "X-axis (Mirror)");

    // Draw original 'A'
    drawA(x, y, size, YELLOW);
    outtextxy(x - 10, y + size + 10, "Original");

    // Mirror about X-axis (y = y + size + 20)
    // For each point (xp, yp), mirrored y' = 2*axis - yp
    int axis = y + size + 20;
    int y_mirror = 2 * axis - y - size; // Adjust for top point

    drawA(x, y_mirror, size, CYAN);
    outtextxy(x - 10, y_mirror + size + 10, "Mirrored");

    getch();
    closegraph();
    return 0;
}