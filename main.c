#include <stdio.h>
#include "graphics.h"

int main()
{
    int deleteIndex;
    Shape shapes[MAX_SHAPES];
    int shapeCount = 0;

    int choice;
    int row,col,height,width;
    int r1,c1,r2,c2;
    int radius;

    initCanvas();

    while(1)
    {
        printf("\n");
        printf("1. Draw Rectangle\n");
        printf("2. Draw Line\n");
        printf("3. Draw Triangle\n");
        printf("4. Draw Circle\n");
        printf("5. Display Canvas\n");
        printf("6. Show Shape List\n");
        printf("7. Delete Shape\n");
        printf("8. Exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);

        if(choice==1)
        {
            printf("Enter row col height width: ");
            scanf("%d%d%d%d",&row,&col,&height,&width);

            drawRectangle(row,col,height,width);

            shapes[shapeCount].type = 1;
            shapes[shapeCount].row = row;
            shapes[shapeCount].col = col;
            shapes[shapeCount].height = height;
            shapes[shapeCount].width = width;

            shapeCount++;
        }

        else if(choice==2)
        {
            printf("Enter row1 col1 row2 col2: ");
            scanf("%d%d%d%d",&r1,&c1,&r2,&c2);

            drawLine(r1,c1,r2,c2);

            shapes[shapeCount].type = 2;
            shapes[shapeCount].row = r1;
            shapes[shapeCount].col = c1;
            shapes[shapeCount].row2 = r2;
            shapes[shapeCount].col2 = c2;

            shapeCount++;
        }

        else if(choice==3)
        {
            printf("Enter row col height: ");
            scanf("%d%d%d",&row,&col,&height);

            drawTriangle(row,col,height);

            shapes[shapeCount].type = 3;
            shapes[shapeCount].row = row;
            shapes[shapeCount].col = col;
            shapes[shapeCount].height = height;

            shapeCount++;
        }

        else if(choice==4)
        {
            printf("Enter centerRow centerCol radius: ");
            scanf("%d%d%d",&row,&col,&radius);

            drawCircle(row,col,radius);

            shapes[shapeCount].type = 4;
            shapes[shapeCount].row = row;
            shapes[shapeCount].col = col;
            shapes[shapeCount].radius = radius;

            shapeCount++;
        }

        else if(choice==5)
        {
            displayCanvas();
        }

        else if(choice==6)
        {
            printf("\nStored Shapes:\n");

            for(int i=0;i<shapeCount;i++)
            {
                printf("Shape %d : ", i+1);

                if(shapes[i].type == 1)
                    printf("Rectangle");

                else if(shapes[i].type == 2)
                    printf("Line");

                else if(shapes[i].type == 3)
                    printf("Triangle");

                else if(shapes[i].type == 4)
                    printf("Circle");

                printf("\n");
            }
        }

        else if(choice==7)
        { 
            printf("Enter shape number to delete: ");
            scanf("%d",&deleteIndex);

            deleteIndex--;

            if(deleteIndex >= 0 && deleteIndex < shapeCount)
            {
                for(int i=deleteIndex;i<shapeCount-1;i++)
                {
                    shapes[i] = shapes[i+1];
                }

            shapeCount--;

            printf("Shape deleted successfully!\n");
            }
            else
            {
                printf("Invalid shape number!\n");
            }
        }

        else if(choice==8)
        {
            break;
        }

        else
        {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}