#include <stdio.h>

void push(int stack[], int *tos, int maximum);
void pop(int stack[], int *tos);
void peek(int stack[], int tos);
void display(int stack[], int tos);

int main()
{
    int maximum;
    printf("Enter stack size here:\n");
    scanf("%d", &maximum);

    int stack[maximum];

    int tos = -1;
    int choice;

    do
    {
        printf("Enter your choice:\nMenu:\n1.push\n2.pop\n3.peek\n4.display\n5.Exit");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push(stack, &tos, maximum);
            break;
        case 2:
            pop(stack, &tos);
            break;
        case 3:
            peek(stack, tos);
            break;

        case 4:
            display(stack, tos);
            break;
        case 5:
            break;
        default:
            printf("Choice out of range!!!Please Re-");
        }
    } while (choice != 5);

    return 0;
}

void push(int stack[], int *tos, int maximum)
{
    if (*tos == maximum - 1)
    {
        printf("The Stack is already full\n");
        return;
    }
    int add;
    (*tos)++;
    printf("Enter value to push in stack[%d]:", *tos);
    scanf("%d", &stack[*tos]);

    printf("Value: %d pushed in a stack", stack[*tos]);
}

void pop(int stack[], int *tos)
{
    if (*tos == -1)
    {
        printf("The Stack is empty\n");
        return;
    }
    printf("The element %d is popped from the stack", stack[*tos]);
    (*tos)--;
}

void peek(int stack[], int tos)
{

    printf("The top of stack value is: %d", stack[tos]);
}
void display(int stack[], int tos)
{
    if (tos == -1)
    {
        printf("The stack is empty");
        return;
    }
    printf("Display\n ");
    for (int i = 0; i <= tos; i++)
    {
        printf("%d\n", stack[i]);
    }
}
