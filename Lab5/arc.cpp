#include <graphics.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc = 300, yc = 200; // Center of the arc
    int start_angle = 0;    // Starting angle in degrees
    int end_angle = 180;    // Ending angle in degrees
    int radius = 100;       // Radius of the arc

    // Draw the arc
    arc(xc, yc, start_angle, end_angle, radius);

    getch();
    closegraph();
    return 0;
}