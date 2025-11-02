#include <stdio.h>
#include <stdlib.h>

void AddBook(int isbns[], char titles[][50], float prices[], int quantities[], int *count);

void SaleProcess(int isbns[], int quantities[], int count);

void LowStockReport(int isbns[], char titles[][50], int quantities[], int count);

int main()
{
    system("cls");
    int isbns[100];
    char titles[100][50];
    float prices[100];
    int quantities[100];
    int count = 0, choice;
    do
    {
        system("cls");
        printf("==============================\n");
        printf("Liberty Books Inventory Menu");
        printf("\n==============================\n");
        printf("Press 1 to Add New Book\nPress 2 to Procces  A Sale\nPress 3 to Generate A Low Stock Report\nPress 4 to Exit.\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            AddBook(isbns, titles, prices, quantities, &count);
            break;
        case 2:
            SaleProcess(isbns, quantities, count);
            break;
        case 3:
            LowStockReport(isbns, titles, quantities, count);
            break;
        case 4:
            printf("\nExiting The Program........");
            break;

        default:
            printf("\n Invalid Choice :( Try Again :-)D\n");
            break;
        }
    } while (choice != 4);
    return 0;
}
void AddBook(int isbns[], char titles[][50], float prices[], int quantities[], int *count)
{
    if (*count >= 100)
    {
        printf("\n****Inventory Full****\n");
    }

    int newisbn;
    // char newtitle[50];
    float newprice;
    int newquantity;

    printf("\nEnter ISBN:");
    scanf("%d", &newisbn);

    for (int i = 0; i < *count; i++)
    {
        if (isbns[i] == newisbn)
        {
            printf("\n A book with this ISBN Already Exists..\n");
            system("pause");
            return;
        }
    }
    getchar();
    printf("Enter Book Title: ");
    fgets(titles[*count], 50, stdin);

    printf("\nEnter Price: ");
    scanf("%f", &newprice);

    printf("\nEnter Quantity: ");
    scanf("%d", &newquantity);

    isbns[*count] = newisbn;
    prices[*count] = newprice;
    quantities[*count] = newquantity;
    (*count)++;

    printf("\nBook Added Successfully :)\n");
    system("pause");
}
void SaleProcess(int isbns[], int quantities[], int count)
{
    if (count == 0)
    {
        printf("\nNo Books In Inventory.");
        system("pause");
        return;
    }
    int sell_ISBN, copies_sold;
    printf("'\nEnter ISBN To Sell: ");
    scanf("%d", &sell_ISBN);

    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (isbns[i] == sell_ISBN)
        {
            found = 1;
            printf("\nEnter Number of Copies Sold: ");
            scanf("%d", &copies_sold);
            if (copies_sold > quantities[i])
            {
                printf("\nNot Enough Stock Available...");
                system("pause");
            }
            else
            {
                quantities[i] -= copies_sold;
                printf("\nSale Done! \n Remaining Stock=%d\n", quantities[i]);
                system("pause");
            }
            break;
        }
    }
    if (!found)
    {
        printf("\nBook With ISBN %d Not Found.", sell_ISBN);
        system("pause");
    }
}
void LowStockReport(int isbns[], char titles[][50], int quantities[], int count)
{
    if (count == 0)
    {
        printf("\nNo Books In Inventory..");
        system("pause");
        return;
    }

    printf("\n====Low Stock Report=====");
    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (quantities[i] < 5)
        {
            printf("\nISBN: %d | Title: %s | Quantity: %d", isbns[i], titles[i], quantities[i]);
            system("pause");
            found = 1;
        }
    }
    if (!found)
    {
        printf("\nAll Books Have Sufficient Stock :) ");
        system("pause");
    }
}