#include <graphics.h>
#include <conio.h>
#include <iostream>
using namespace std;

// Clipping window boundaries (hardcoded)
const int xmin = 100, ymin = 100, xmax = 300, ymax = 250;

// Liang-Barsky clipping function
void liangBarskyClip(int x1, int y1, int x2, int y2) {
    float p[4], q[4];
    float u1 = 0.0, u2 = 1.0;
    int dx = x2 - x1, dy = y2 - y1;

    p[0] = -dx; q[0] = x1 - xmin;
    p[1] =  dx; q[1] = xmax - x1;
    p[2] = -dy; q[2] = y1 - ymin;
    p[3] =  dy; q[3] = ymax - y1;

    for (int i = 0; i < 4; i++) {
        if (p[i] == 0) {
            if (q[i] < 0) return; // Line is parallel and outside
        } else {
            float r = q[i] / p[i];
            if (p[i] < 0) {
                if (r > u2) return;
                else if (r > u1) u1 = r;
            } else {
                if (r < u1) return;
                else if (r < u2) u2 = r;
            }
        }
    }

    int nx1 = x1 + u1 * dx;
    int ny1 = y1 + u1 * dy;
    int nx2 = x1 + u2 * dx;
    int ny2 = y1 + u2 * dy;

    setcolor(GREEN);
    line(nx1, ny1, nx2, ny2);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Draw clipping window
    setcolor(WHITE);
    rectangle(xmin, ymin, xmax, ymax);

    // Hardcoded line endpoints
    int x1 = 50, y1 = 120, x2 = 350, y2 = 200;

    // Draw original line
    setcolor(RED);
    line(x1, y1, x2, y2);

    // Clip and draw the line
    liangBarskyClip(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}