#include <stdio.h>
#include <string.h>
#include <stdlib.h> //Sir I used it Just to clear the terminal and to give pause after process//

void CustomerInfo(char *name, char *cnic);
void InventoryDisp(char (*codes)[10], int *quantities, float *prices, int n);
void addToCart(char (*codes)[10], int *quantities, float *prices, char (*cartCodes)[10], int *cartQty, float *cartSub, int *cartCount, int n);
float displayTotalBill(char (*cartCodes)[10], int *cartQty, float *cartSub, int cartCount);
void Invoice(char *name, char *cnic, char (*cartCodes)[10], int *cartQty, float *cartSub, int cartCount, float total, float discountedTotal);

int main()
{
    system("cls");
    char productCodes[4][10] = {"001", "002", "003", "004"};
    int stockQty[4] = {50, 10, 20, 8};
    float prices[4] = {100, 200, 300, 150};

    char cartCodes[10][10];
    int cartQty[10];
    float cartSub[10];
    int cartCount = 0;

    char name[50], cnic[20];
    int customerEntered = 0;

    float total = 0, discountedTotal = 0;
    int choice;

    printf("\n============================================\n");
    printf("        WELCOME TO SUPER MART SYSTEM\n");
    printf("============================================\n");

    do
    {
        printf("\n********** MAIN MENU ************\n");
        printf("Press 1 to Enter Customer Information\n");
        printf("Press 2 to Display Inventory\n");
        printf("Press 3 to Add Item to Cart\n");
        printf("Press 4 to Display Total Bill\n");
        printf("Press 5 to Show Invoice\n");
        printf("Press 6 to Exit System\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            CustomerInfo(name, cnic);
            customerEntered = 1;
            break;

        case 2:
            InventoryDisp(productCodes, stockQty, prices, 4);
            break;

        case 3:
            if (!customerEntered)
                printf("\nPlease enter customer info first.\n");
            else
                addToCart(productCodes, stockQty, prices, cartCodes, cartQty, cartSub, &cartCount, 4);
            break;

        case 4:
            if (cartCount == 0)
                printf("\nCart is empty! Add items first.\n");
            else
            {
                total = displayTotalBill(cartCodes, cartQty, cartSub, cartCount);
                discountedTotal = total;

                char promoAns[10], promoCode[20];
                printf("\nDo you have a promo code? (yes/no): ");
                scanf("%s", promoAns);
                if (strcmp(promoAns, "yes") == 0)
                {
                    printf("Enter promo code: ");
                    scanf("%s", promoCode);
                    if (strcmp(promoCode, "Eid2025") == 0)
                    {
                        discountedTotal = total * 0.75;
                        printf("Promo applied! You got 25%% off!\n");
                        system("pause");
                    }
                    else
                    {
                        printf("Invalid promo code.\n");
                        system("pause");
                    }
                }
            }
            break;

        case 5:
            if (!customerEntered)
                printf("\nPlease enter customer info first.\n");
            else if (cartCount == 0)
                printf("\nAdd items to cart first.\n");
            else
                Invoice(name, cnic, cartCodes, cartQty, cartSub, cartCount, total, discountedTotal);
            break;

        case 6:
            printf("\nExiting system... Thank you for shopping :)\n");
            break;

        default:
            printf("\nInvalid choice! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void CustomerInfo(char *name, char *cnic)
{
    getchar();
    printf("\nEnter Customer Name: ");
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = '\0';
    printf("Enter CNIC: ");
    scanf("%s", cnic);
    printf("\nCustomer information saved!\n");
    system("pause");
}

void InventoryDisp(char (*codes)[10], int *quantities, float *prices, int n)
{
    int i;
    printf("\n========== INVENTORY ==========\n");
    printf("%-10s %-15s %-10s\n", "Code", "Stock Qty", "Price");
    printf("-----------------------------------\n");
    for (i = 0; i < n; i++)
        printf("%-10s %-15d %-10.2f\n", *(codes + i), *(quantities + i), *(prices + i));
}

void addToCart(char (*codes)[10], int *quantities, float *prices, char (*cartCodes)[10], int *cartQty, float *cartSub, int *cartCount, int n)
{
    char code[10];
    int qty, i, found = 0;

    printf("\nEnter Product Code: ");
    scanf("%s", code);
    printf("Enter Quantity: ");
    scanf("%d", &qty);

    for (i = 0; i < n; i++)
    {
        if (strcmp(*(codes + i), code) == 0)
        {
            found = 1;
            if (qty > *(quantities + i))
            {
                printf("\nOnly %d left in stock.\n", *(quantities + i));
                return;
            }
            strcpy(*(cartCodes + *cartCount), code);
            *(cartQty + *cartCount) = qty;
            *(cartSub + *cartCount) = qty * (*(prices + i));
            (*cartCount)++;
            *(quantities + i) -= qty;
            printf("\nItem added to cart successfully!\n");
            system("pause");
            return;
        }
    }
    if (!found)
        printf("\nProduct not found!\n");
}

float displayTotalBill(char (*cartCodes)[10], int *cartQty, float *cartSub, int cartCount)
{
    int i;
    float total = 0;
    printf("\n========== CART DETAILS ==========\n");
    printf("%-10s %-10s %-10s\n", "Code", "Qty", "Subtotal");
    printf("-----------------------------------\n");
    for (i = 0; i < cartCount; i++)
    {
        printf("%-10s %-10d %-10.2f\n", *(cartCodes + i), *(cartQty + i), *(cartSub + i));
        total += *(cartSub + i);
    }
    printf("-----------------------------------\n");
    printf("\nTotal Bill: %.2f PKR\n", total);
    return total;
    system("pause");
}

void Invoice(char *name, char *cnic, char (*cartCodes)[10], int *cartQty, float *cartSub, int cartCount, float total, float discountedTotal)
{
    int i;
    printf("\n========== FINAL ==========\n");
    printf("============ INVOICE =========\n");
    printf("Customer Name: %s\n", name);
    printf("CNIC: %s\n", cnic);
    printf("-----------------------------------\n");
    printf("%-10s %-10s %-10s\n", "Code", "Qty", "Subtotal");

    for (i = 0; i < cartCount; i++)
        printf("%-10s %-10d %-10.2f\n", *(cartCodes + i), *(cartQty + i), *(cartSub + i));
    printf("Total (No Discount): %.2f PKR\n", total);
    printf("Total (With Discount): %.2f PKR\n", discountedTotal);
    printf("-----------------------------------\n");
    printf(" Thank you for shopping at Super Mart :)\n");
    system("pause");
}
