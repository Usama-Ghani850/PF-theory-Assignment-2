#include <stdio.h>
void Update_Sector_Status(int row, int col, int Grid[3][3], int *flag, int *button)
{
    int temp = Grid[row][col];
    int bitMask = 1 << *flag;
    if ((*button == 1) && (temp & bitMask))
    {
        printf("The selected flag is already ON!\n");
    }
    else if ((*button == 0) && !(temp & bitMask))
    {
        printf("The selected flag is already OFF!\n");
    }
    else if (*button == 1)
    {
        Grid[row][col] |= bitMask;
        printf("Flag has been turned ON successfully!\n");
    }
    else if (*button == 0)
    {
        Grid[row][col] &= ~bitMask;
        printf("Flag has been turned OFF successfully!\n");
    }
}
void Query_Sector_Status(int Grid[3][3], int row, int col)
{
    int status = Grid[row][col];

    printf("Sector Status Report (%d,%d) ---\n", row, col);

    if (status & (1 << 0))
        printf("Power Status: ON\n");
    else
        printf("Power Status: OFF\n");

    if (status & (1 << 1))
        printf("Overload Warning: YES (Overloaded)\n");
    else
        printf("Overload Warning: NO (Normal)\n");

    if (status & (1 << 2))
        printf("Maintenance Required: YES\n");
    else
        printf("Maintenance Required: NO\n");
}

void Run_System_Diagnostic(int Grid[3][3])
{
    int overloadedCount = 0;
    int maintenanceCount = 0;

    printf("Running System Diagnostic\n");
int row;
    for ( row = 0; row < 3; row++)
    {  int col; 
        for ( col = 0; col < 3; col++)
        {
            int status = Grid[row][col];
            if (status & (1 << 1))
                overloadedCount++;
            if (status & (1 << 2))
                maintenanceCount++;
        }
    }

    printf("Total overloaded sectors: %d\n", overloadedCount);
    printf("Total sectors requiring maintenance: %d\n", maintenanceCount);
}

int main()
{
    const int r = 3;
    const int c = 3;
    int row, col, button, choice, flag, Grid[r][c];
    do
    {
        printf("Enter your choice here:\n1.Update Sector Status\n2.Query_Sector_Status\n3.Run_System_Diagnostic\n4.Exit");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        case 2:
            do
            {
                printf("Enter row num here:\n");
                scanf("%d", &row);
                if (row >= r || row < 0)
                {
                    printf("Invalid choice!!!\nPlease Re-");
                }
            } while (row >= r || row < 0);
            do
            {
                printf("Enter col num here:\n");
                scanf("%d", &col);
                if (col >= c || col < 0)
                {
                    printf("Invalid choice!!!\nPlease Re-");
                }
            } while (col >= c || col < 0);
            do
            {
                printf("Enter the flag that you want to change\n0: Power Status\n1: Overload Warning\n2: Maintenance Required");
                scanf("%d", &flag);
                if (flag > 2 || flag < 0)
                {
                    printf("Invalid choice!!!\nPlease Re-");
                }
            } while (flag > 2 || flag < 0);
            do
            {
                printf("Enter the switch\n0: OFF\n1: On");
                scanf("%d", &button);
                if (button > 1 || button < 0)
                {
                    printf("Invalid choice!!!\nPlease Re-");
                }
            } while (button > 1 || button < 0);
            if (choice == 1)
            {
                Update_Sector_Status(row, col, Grid, &flag, &button);
            }
            else if (choice == 2)
            {
                Query_Sector_Status(Grid, row, col);
            }
            break;
        case 3:
            Run_System_Diagnostic(Grid);
            break;
        case 4:
            break;
        default:
            printf("Invalid choice.\nPlease Re-");
            break;
        }
    } while (choice != 4);

    return 0;
}
