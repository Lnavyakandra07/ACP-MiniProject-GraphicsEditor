#include <stdio.h>
#include "graphics.h"

int main()
{
    int choice;
    int row,col,height,width;
    int r1,c1,r2,c2;

    initCanvas();

    printf("1. Draw Rectangle\n");
    printf("2. Draw Line\n");
    printf("3. Display Canvas\n");

    printf("Enter choice: ");
    scanf("%d",&choice);

    if(choice==1)
    {
        printf("Enter row col height width: ");
        scanf("%d%d%d%d",&row,&col,&height,&width);

        drawRectangle(row,col,height,width);
        displayCanvas();
    }

    else if(choice==2)
    {
        printf("Enter row1 col1 row2 col2: ");
        scanf("%d%d%d%d",&r1,&c1,&r2,&c2);

        drawLine(r1,c1,r2,c2);
        displayCanvas();
    }

    else if(choice==3)
    {
        displayCanvas();
    }

    return 0;
}