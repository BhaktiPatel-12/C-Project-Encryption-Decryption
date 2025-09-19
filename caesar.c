#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);

    if (key < 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    char input[100]; // Assuming a maximum input length of 100 characters

    printf("plaintext: ");
    fgets(input, sizeof(input), stdin);

    printf("ciphertext: ");

    for (int i = 0; i < strlen(input); i++)
    {
        char a = input[i];

        if (isspace(a))
        {
            printf(" ");
        }
        else if (isalpha(a) && islower(a))
        {
            int x = ((input[i] + key - 97) % 26) + 97;
            printf("%c", x);
        }
        else if (isalpha(a) && isupper(a))
        {
            int y = ((input[i] + key - 65) % 26) + 65;
            printf("%c", y);
        }
        else
        {
            printf("%c", a);
        }
    }

    printf("\n");

    return 0;
}
