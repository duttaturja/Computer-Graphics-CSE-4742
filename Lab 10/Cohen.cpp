#include <graphics.h>
#include <conio.h>

#define LEFT   1    // 0001
#define RIGHT  2    // 0010
#define BOTTOM 4    // 0100
#define TOP    8    // 1000

// Clipping window boundaries (hardcoded)
const int xmin = 100, ymin = 100, xmax = 300, ymax = 250;

// Function to compute region code for a point (x, y)
int computeCode(int x, int y) {
    int code = 0;
    if (x < xmin) code |= LEFT;
    else if (x > xmax) code |= RIGHT;
    if (y < ymin) code |= BOTTOM;
    else if (y > ymax) code |= TOP;
    return code;
}

// Cohen-Sutherland clipping algorithm
void cohenSutherlandClip(int x1, int y1, int x2, int y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    bool accept = false;

    while (true) {
        if ((code1 == 0) && (code2 == 0)) {
            // Both endpoints inside
            accept = true;
            break;
        } else if (code1 & code2) {
            // Both endpoints share an outside zone
            break;
        } else {
            // At least one endpoint is outside
            int code_out;
            int x, y;

            // Choose endpoint outside
            code_out = code1 ? code1 : code2;

            // Find intersection
            if (code_out & TOP) {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            } else if (code_out & BOTTOM) {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            } else if (code_out & RIGHT) {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            } else if (code_out & LEFT) {
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            // Replace outside point with intersection
            if (code_out == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    // Draw the clipped line
    if (accept) {
        setcolor(GREEN);
        line(x1, y1, x2, y2);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Draw clipping window
    setcolor(WHITE);
    rectangle(xmin, ymin, xmax, ymax);

    // Hardcoded line endpoints
    int x1 = 50, y1 = 120, x2 = 350, y2 = 200;

    // Draw original line
    setcolor(RED);
    line(x1, y1, x2, y2);

    // Clip and draw the line
    cohenSutherlandClip(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}