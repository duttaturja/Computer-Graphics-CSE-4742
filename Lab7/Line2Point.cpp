#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <iostream>
using namespace std;

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    float x1, y1, x2, y2, xp, yp, angle;
    cout << "Enter x1, y1 of line: ";
    cin >> x1 >> y1;
    cout << "Enter x2, y2 of line: ";
    cin >> x2 >> y2;
    cout << "Enter x, y of pivot point: ";
    cin >> xp >> yp;
    cout << "Enter angle of rotation (in degrees): ";
    cin >> angle;

    // Draw axes for reference
    line(0, 240, 640, 240); // X-axis
    line(320, 0, 320, 480); // Y-axis

    // Draw original line and pivot
    line((int)x1 + 320, 240 - (int)y1, (int)x2 + 320, 240 - (int)y2);
    putpixel((int)xp + 320, 240 - (int)yp, YELLOW);

    // Convert angle to radians
    float rad = angle * M_PI / 180.0;

    // Translate both points to origin (relative to pivot)
    float xt1 = x1 - xp;
    float yt1 = y1 - yp;
    float xt2 = x2 - xp;
    float yt2 = y2 - yp;

    // Rotate both points
    float xr1 = xt1 * cos(rad) - yt1 * sin(rad);
    float yr1 = xt1 * sin(rad) + yt1 * cos(rad);
    float xr2 = xt2 * cos(rad) - yt2 * sin(rad);
    float yr2 = xt2 * sin(rad) + yt2 * cos(rad);

    // Translate back
    float x1_final = xr1 + xp;
    float y1_final = yr1 + yp;
    float x2_final = xr2 + xp;
    float y2_final = yr2 + yp;

    // Draw rotated line
    setcolor(RED);
    line((int)x1_final + 320, 240 - (int)y1_final, (int)x2_final + 320, 240 - (int)y2_final);

    getch();
    closegraph();
    return 0;