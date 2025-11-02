#include <stdio.h>
#include <string.h>

void reversemessage(char message[])
{
    char temp;

    int length = strlen(message);
    for (int i = 0; i < length / 2; i++)
    {
        temp = message[i];
        message[i] = message[length - i - 1];
        message[length - i - 1] = temp;
    }
}
void encodeMessage(char message[])
{
    reversemessage(message);
    int bit1 = 1, bit2 = 4;
    for (int i = 0; message[i] != '\0'; i++)
    {
        // We cannot directly toggle the value for m, so we are manually encoding it to r
        // we used r because it isnt a toggled value of any other letter
        if (message[i] == 'm')
        {
            message[i] = 'r';
        }
        else
        {
            message[i] = message[i] ^ (1 << bit1);
            message[i] = message[i] ^ (1 << bit2);
        }
    }
    printf("Encoded Message:%s\n", message);
}
void decodeMessage(char message[])
{

    int bit1 = 1, bit2 = 4;
    for (int i = 0; message[i] != '\0'; i++)
    {
        // As we knew tat we manually encoded m to r so well also reverse it manually
        if (message[i] == 'r')
        {
            message[i] = 'm';
        }
        else
        {
            message[i] = message[i] ^ (1 << bit1);
            message[i] = message[i] ^ (1 << bit2);
        }
    }
    reversemessage(message);
    printf("Decoded message:%s\n", message);
}

int main()
{

    char message[200];
    int choice;
    int length;
    printf("Welcome TCS Secure Message System \n");
    do
    {
        printf("Enter your choice:\n1.Encoding \n2.Decoding \n3.Exit\n");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:

            printf("Enter your message for encode:");
            fgets(message, sizeof(message), stdin);
            message[strcspn(message, "\n")] = '\0';
            encodeMessage(message);

            break;

        case 2:
            printf("Enter your message for decode :");
            fgets(message, sizeof(message), stdin);
            message[strcspn(message, "\n")] = '\0';
            decodeMessage(message);

            break;

        case 3:
            break;

        default:
            printf("Choice out of range!!!\nPlease Re-");
            return 0;
        }
    } while (choice != 3);

    return 0;
}
