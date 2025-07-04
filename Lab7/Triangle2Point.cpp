#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <iostream>
using namespace std;

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    float x1, y1, x2, y2, x3, y3, xp, yp, angle;
    cout << "Enter x1, y1 of triangle: ";
    cin >> x1 >> y1;
    cout << "Enter x2, y2 of triangle: ";
    cin >> x2 >> y2;
    cout << "Enter x3, y3 of triangle: ";
    cin >> x3 >> y3;
    cout << "Enter x, y of pivot point: ";
    cin >> xp >> yp;
    cout << "Enter angle of rotation (in degrees): ";
    cin >> angle;

    // Draw axes for reference
    line(0, 240, 640, 240); // X-axis
    line(320, 0, 320, 480); // Y-axis

    // Draw original triangle and pivot
    line((int)x1 + 320, 240 - (int)y1, (int)x2 + 320, 240 - (int)y2);
    line((int)x2 + 320, 240 - (int)y2, (int)x3 + 320, 240 - (int)y3);
    line((int)x3 + 320, 240 - (int)y3, (int)x1 + 320, 240 - (int)y1);
    putpixel((int)xp + 320, 240 - (int)yp, YELLOW);

    // Convert angle to radians
    float rad = angle * M_PI / 180.0;

    // Translate and rotate each vertex
    float xt1 = x1 - xp, yt1 = y1 - yp;
    float xt2 = x2 - xp, yt2 = y2 - yp;
    float xt3 = x3 - xp, yt3 = y3 - yp;

    float xr1 = xt1 * cos(rad) - yt1 * sin(rad);
    float yr1 = xt1 * sin(rad) + yt1 * cos(rad);
    float xr2 = xt2 * cos(rad) - yt2 * sin(rad);
    float yr2 = xt2 * sin(rad) + yt2 * cos(rad);
    float xr3 = xt3 * cos(rad) - yt3 * sin(rad);
    float yr3 = xt3 * sin(rad) + yt3 * cos(rad);

    float x1_final = xr1 + xp, y1_final = yr1 + yp;
    float x2_final = xr2 + xp, y2_final = yr2 + yp;
    float x3_final = xr3 + xp, y3_final = yr3 + yp;

    // Draw rotated triangle
    setcolor(RED);
    line((int)x1_final + 320, 240 - (int)y1_final, (int)x2_final + 320, 240 - (int)y2_final);
    line((int)x2_final + 320, 240 - (int)y2_final, (int)x3_final + 320, 240 - (int)y3_final);
    line((int)x3_final + 320, 240 - (int)y3_final, (int)x1_final + 320, 240 - (int)y1_final);

    getch();
    closegraph();
    return 0;