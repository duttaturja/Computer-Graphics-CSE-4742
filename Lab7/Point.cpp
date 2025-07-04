#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <iostream>
using namespace std;

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    float x, y, angle;
    cout << "Enter x coordinate: ";
    cin >> x;
    cout << "Enter y coordinate: ";
    cin >> y;
    cout << "Enter angle of rotation (in degrees): ";
    cin >> angle;

    // Draw original point
    putpixel((int)x + 320, 240 - (int)y, WHITE);

    // Convert angle to radians
    float rad = angle * M_PI / 180.0;

    // Rotation transformation
    float xr = x * cos(rad) - y * sin(rad);
    float yr = x * sin(rad) + y * cos(rad);

    // Draw rotated point
    putpixel((int)xr + 320, 240 - (int)yr, RED);

    // Draw axes for reference
    line(0, 240, 640, 240); // X-axis
    line(320, 0, 320, 480); // Y-axis

    getch();
    closegraph();
    return 0;
}