#include <graphics.h>
#include <conio.h>
#include <iostream>
using namespace std;

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x, y;
    float sx, sy;

    cout << "Enter coordinates of the point (x y): ";
    cin >> x >> y;
    cout << "Enter scaling factors (sx sy): ";
    cin >> sx >> sy;

    // Draw original point
    putpixel(x, y, WHITE);
    outtextxy(x + 10, y, "Original");

    // Scale the point about origin
    int x_scaled = x * sx;
    int y_scaled = y * sy;

    // Draw scaled point
    putpixel(x_scaled, y_scaled, RED);
    outtextxy(x_scaled + 10, y_scaled, "Scaled");

    getch();
    closegraph();
    return 0;
}