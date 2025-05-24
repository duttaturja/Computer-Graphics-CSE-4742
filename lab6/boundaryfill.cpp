#include <graphics.h>
#include <conio.h>

// Function to get the color of a pixel
int getPixelColor(int x, int y) {
    return getpixel(x, y);
}

// Boundary Fill Algorithm (4-connected)
void boundaryFill(int x, int y, int fill_color, int boundary_color) {
    int current = getPixelColor(x, y);
    if (current != boundary_color && current != fill_color) {
        putpixel(x, y, fill_color);
        boundaryFill(x + 1, y, fill_color, boundary_color);
        boundaryFill(x - 1, y, fill_color, boundary_color);
        boundaryFill(x, y + 1, fill_color, boundary_color);
        boundaryFill(x, y - 1, fill_color, boundary_color);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Draw a rectangle as boundary
    rectangle(100, 100, 200, 200);

    int boundary_color = WHITE;
    int fill_color = RED;

    // Call boundary fill from inside the rectangle
    boundaryFill(150, 150, fill_color, boundary_color);

    getch();
    closegraph();
    return 0;
}