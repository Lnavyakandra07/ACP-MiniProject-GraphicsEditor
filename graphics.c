#include <stdio.h>
#include "graphics.h"

char canvas[ROWS][COLS];

void initCanvas()
{
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            canvas[i][j] = '_';
        }
    }
}

void displayCanvas()
{
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}
void drawRectangle(int row, int col, int height, int width)
{
    for(int i=row;i<row+height;i++)
    {
        for(int j=col;j<col+width;j++)
        {
            if(i==row || i==row+height-1 ||
               j==col || j==col+width-1)
            {
                canvas[i][j]='*';
            }
        }
    }
}
void drawLine(int row1, int col1, int row2, int col2)
{
    if(row1 == row2)
    {
        for(int j=col1;j<=col2;j++)
        {
            canvas[row1][j]='*';
        }
    }
    else if(col1 == col2)
    {
        for(int i=row1;i<=row2;i++)
        {
            canvas[i][col1]='*';
        }
    }
}
void drawTriangle(int row, int col, int height)
{
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(i==height-1 || j==0 || j==i)
            {
                canvas[row+i][col+j]='*';
            }
        }
    }
}
void drawCircle(int centerRow, int centerCol, int radius)
{
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            int dx = i - centerRow;
            int dy = j - centerCol;

            int distanceSquared = dx*dx + dy*dy;
            int radiusSquared = radius*radius;

            if(distanceSquared >= radiusSquared-radius &&
               distanceSquared <= radiusSquared+radius)
            {
                canvas[i][j] = '*';
            }
        }
    }
}