#include <graphics.h>
#include <cmath>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc = 300, yc = 200; // Center of the sector
    int start_angle = 0;    // Starting angle in degrees
    int end_angle = 90;     // Ending angle in degrees
    int radius = 100;       // Radius of the sector

    // Draw the arc
    arc(xc, yc, start_angle, end_angle, radius);

    // Draw the two radii
    int x1 = xc + radius * cos(start_angle * M_PI / 180.0);
    int y1 = yc - radius * sin(start_angle * M_PI / 180.0);
    int x2 = xc + radius * cos(end_angle * M_PI / 180.0);
    int y2 = yc - radius * sin(end_angle * M_PI / 180.0);

    line(xc, yc, x1, y1);
    line(xc, yc, x2, y2);

    getch();
    closegraph();
    return 0;
}