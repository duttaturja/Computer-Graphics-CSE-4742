#include <graphics.h>
#include <conio.h>
#include <vector>

using namespace std;

// Clipping window boundaries (hardcoded)
const int xmin = 100, ymin = 100, xmax = 300, ymax = 250;

// Structure for a point
struct Point {
    int x, y;
};

// Function to compute intersection point
Point getIntersection(Point p1, Point p2, int edge, int value) {
    Point p;
    float m;
    if (p1.x != p2.x)
        m = (float)(p2.y - p1.y) / (p2.x - p1.x);
    else
        m = 1e5; // Large value for vertical lines

    switch (edge) {
        case 0: // Left
            p.x = value;
            p.y = p1.y + m * (value - p1.x);
            break;
        case 1: // Right
            p.x = value;
            p.y = p1.y + m * (value - p1.x);
            break;
        case 2: // Bottom
            if (p1.x != p2.x)
                p.x = p1.x + (float)(value - p1.y) / m;
            else
                p.x = p1.x;
            p.y = value;
            break;
        case 3: // Top
            if (p1.x != p2.x)
                p.x = p1.x + (float)(value - p1.y) / m;
            else
                p.x = p1.x;
            p.y = value;
            break;
    }
    return p;
}

// Function to check if point is inside edge
bool inside(Point p, int edge, int value) {
    switch (edge) {
        case 0: return p.x >= value; // Left
        case 1: return p.x <= value; // Right
        case 2: return p.y >= value; // Bottom
        case 3: return p.y <= value; // Top
    }
    return false;
}

// Sutherland-Hodgman polygon clipping
vector<Point> suthHodgClip(vector<Point> poly) {
    int edges[4] = {xmin, xmax, ymin, ymax};
    for (int edge = 0; edge < 4; edge++) {
        vector<Point> input = poly;
        poly.clear();
        int n = input.size();
        for (int i = 0; i < n; i++) {
            Point curr = input[i];
            Point prev = input[(i + n - 1) % n];
            bool curr_in = inside(curr, edge, edges[edge]);
            bool prev_in = inside(prev, edge, edges[edge]);
            if (curr_in) {
                if (!prev_in)
                    poly.push_back(getIntersection(prev, curr, edge, edges[edge]));
                poly.push_back(curr);
            } else if (prev_in) {
                poly.push_back(getIntersection(prev, curr, edge, edges[edge]));
            }
        }
    }
    return poly;
}

void drawPolygon(const vector<Point>& poly, int color) {
    setcolor(color);
    int n = poly.size();
    for (int i = 0; i < n; i++)
        line(poly[i].x, poly[i].y, poly[(i+1)%n].x, poly[(i+1)%n].y);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Draw clipping window
    setcolor(WHITE);
    rectangle(xmin, ymin, xmax, ymax);

    // Hardcoded polygon (pentagon)
    vector<Point> poly = {
        {120, 80}, {340, 120}, {280, 260}, {160, 300}, {80, 180}
    };

    // Draw original polygon
    drawPolygon(poly, RED);

    // Clip and draw the polygon
    vector<Point> clipped = suthHodgClip(poly);
    drawPolygon(clipped, GREEN);

    getch();
    closegraph();
    return 0;
}