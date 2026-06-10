#ifndef GRAPHICS_H
#define GRAPHICS_H

#define ROWS 30
#define COLS 60

extern char canvas[ROWS][COLS];

#define MAX_SHAPES 50

typedef struct
{
    int type;

    int row;
    int col;

    int height;
    int width;

    int row2;
    int col2;

    int radius;

} Shape;

void initCanvas();
void displayCanvas();
void drawRectangle(int row, int col, int height, int width);
void drawLine(int row1, int col1, int row2, int col2);
void drawTriangle(int row, int col, int height);
void drawCircle(int centerRow, int centerCol, int radius);
void redrawCanvas(Shape shapes[], int shapeCount);

#endif