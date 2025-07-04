#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <iostream>
using namespace std;

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    float x, y, xp, yp, angle;
    cout << "Enter x coordinate of point to rotate: ";
    cin >> x;
    cout << "Enter y coordinate of point to rotate: ";
    cin >> y;
    cout << "Enter x coordinate of pivot point: ";
    cin >> xp;
    cout << "Enter y coordinate of pivot point: ";
    cin >> yp;
    cout << "Enter angle of rotation (in degrees): ";
    cin >> angle;

    // Draw axes for reference
    line(0, 240, 640, 240); // X-axis
    line(320, 0, 320, 480); // Y-axis

    // Draw original point and pivot
    putpixel((int)x + 320, 240 - (int)y, WHITE);
    putpixel((int)xp + 320, 240 - (int)yp, YELLOW);

    // Convert angle to radians
    float rad = angle * M_PI / 180.0;

    // Translate point to origin (relative to pivot)
    float xt = x - xp;
    float yt = y - yp;

    // Rotate about origin
    float xr = xt * cos(rad) - yt * sin(rad);
    float yr = xt * sin(rad) + yt * cos(rad);

    // Translate back
    float x_final = xr + xp;
    float y_final = yr + yp;

    // Draw rotated point
    putpixel((int)x_final + 320, 240 - (int)y_final, RED);

    getch();
    closegraph();