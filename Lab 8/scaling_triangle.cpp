#include <graphics.h>
#include <conio.h>
#include <iostream>
using namespace std;

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1, y1, x2, y2, x3, y3;
    float sx, sy;

    cout << "Enter coordinates of the triangle (x1 y1 x2 y2 x3 y3): ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    cout << "Enter scaling factors (sx sy): ";
    cin >> sx >> sy;

    // Draw original triangle
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    outtextxy(x1 + 10, y1, "Original");

    // Scale the triangle about origin
    int x1s = x1 * sx;
    int y1s = y1 * sy;
    int x2s = x2 * sx;
    int y2s = y2 * sy;
    int x3s = x3 * sx;
    int y3s = y3 * sy;

    // Draw scaled triangle
    setcolor(RED);
    line(x1s, y1s, x2s, y2s);
    line(x2s, y2s, x3s, y3s);
    line(x3s, y3s, x1s, y1s);
    outtextxy(x1s + 10, y1s, "Scaled");

    getch();
    closegraph();
    return 0;
}