#include <graphics.h>
#include <conio.h>
#include <iostream>
using namespace std;

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1, y1, x2, y2, x3, y3;
    float sx, sy;
    int xf, yf;

    cout << "Enter coordinates of the triangle (x1 y1 x2 y2 x3 y3): ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    cout << "Enter scaling factors (sx sy): ";
    cin >> sx >> sy;
    cout << "Enter fixed point for scaling (xf yf): ";
    cin >> xf >> yf;

    // Draw original triangle
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    outtextxy(x1 + 10, y1, "Original");

    // Scale the triangle about (xf, yf)
    int x1s = xf + (x1 - xf) * sx;
    int y1s = yf + (y1 - yf) * sy;
    int x2s = xf + (x2 - xf) * sx;
    int y2s = yf + (y2 - yf) * sy;
    int x3s = xf + (x3 - xf) * sx;
    int y3s = yf + (y3 - yf) * sy;

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