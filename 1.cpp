#include <graphics.h>
#include <stdio.h>
#include <math.h>

// Function to implement DDA algorithm
void drawDDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    // Calculate steps required for generating pixels
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    // Calculate increment in x & y for each steps
    float xInc = dx / (float)steps;
    float yInc = dy / (float)steps;

    // Put pixel for each step
    float x = x1;
    float y = y1;
    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);
        x += xInc;
        y += yInc;
    }
}

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;

    // Getting input from user
    printf("Enter x1, y1: ");
    scanf("%d %d", &x1, &y1);
    printf("Enter x2, y2: ");
    scanf("%d %d", &x2, &y2);

    
    initgraph(&gd, &gm, (char*)"");

    drawDDA(x1, y1, x2, y2);

    getch();
    closegraph();
    printf("Sujan Bhattarai: (32/80)");
    return 0;
}
