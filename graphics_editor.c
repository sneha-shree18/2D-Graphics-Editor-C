#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 40

char canvas[ROWS][COLS];

void initializeCanvas()
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            canvas[i][j] = '_';
        }
    }
}

void displayCanvas()
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}

void drawLine(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
        if (x1 >= 0 && x1 < COLS && y1 >= 0 && y1 < ROWS)
        {
            canvas[y1][x1] = '*';
        }

        if (x1 == x2 && y1 == y2)
        {
            break;
        }

        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

int main()
{
    initializeCanvas();

    int choice;
    do
    {
        printf("\nMenu:\n");
        printf("1 Display Canvas\n");
        printf("2 Draw Line\n");
        printf("3 Exit\n");
        printf("Enter choice: ");
        
        if (scanf("%d", &choice) != 1)
        {
            // Clear input buffer in case of non-integer input
            while (getchar() != '\n');
            printf("Invalid input. Please enter a number.\n");
            choice = 0;
            continue;
        }

        switch (choice)
        {
            case 1:
                displayCanvas();
                break;
            case 2:
                {
                    int x1, y1, x2, y2;
                    printf("Enter start coordinates (x1 y1): ");
                    if (scanf("%d %d", &x1, &y1) != 2)
                    {
                        while (getchar() != '\n');
                        printf("Invalid coordinates.\n");
                        break;
                    }
                    printf("Enter end coordinates (x2 y2): ");
                    if (scanf("%d %d", &x2, &y2) != 2)
                    {
                        while (getchar() != '\n');
                        printf("Invalid coordinates.\n");
                        break;
                    }
                    drawLine(x1, y1, x2, y2);
                    printf("Line drawn.\n");
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}