#ifndef GRAPHICS_H
#define GRAPHICS_H

#define ROWS 30
#define COLS 60

extern char canvas[ROWS][COLS];

void initCanvas();
void displayCanvas();
void drawRectangle(int row, int col, int height, int width);
void drawLine(int row1, int col1, int row2, int col2);

#endif