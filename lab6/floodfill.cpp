#include <graphics.h>
#include <conio.h>

// Recursive Flood Fill function
void floodFill(int x, int y, int oldColor, int newColor) {
    int currentColor = getpixel(x, y);
    if (currentColor == oldColor && currentColor != newColor) {
        putpixel(x, y, newColor);
        floodFill(x + 1, y, oldColor, newColor);
        floodFill(x - 1, y, oldColor, newColor);
        floodFill(x, y + 1, oldColor, newColor);
        floodFill(x, y - 1, oldColor, newColor);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Draw a rectangle to fill
    rectangle(100, 100, 300, 200);

    // Get the color inside the rectangle (background color)
    int oldColor = getpixel(150, 150);
    int newColor = RED;

    // Call flood fill starting from a point inside the rectangle
    floodFill(150, 150, oldColor, newColor);

    getch();
    closegraph();
    return 0;
}