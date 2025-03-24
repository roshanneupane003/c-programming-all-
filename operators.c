#include <stdio.h>

void encryptDecryptChar(char message, char key)
{
    char encrypted, decrypted;

    // Encrypt the message
    encrypted = message ^ key;
    printf("Encrypted character: %c (ASCII Code: %d)\n", encrypted, encrypted);

    // Decrypt the message
    decrypted = encrypted ^ key;
    printf("Decrypted character: %c (ASCII Code: %d)\n", decrypted, decrypted);
}

int performCompoundOperations(int a, int b)
{
    int result;

    // Using compound and relational operators together
    result = (a > b) && (a %= b); // Modifies 'a' only if 'a > b'
    printf("Result of compound operation: %d\n", result);
    printf("New value of a after operation: %d\n", a);

    return a;
}

int main()
{
    char message, key;
    int a, b, choice;

    printf("Welcome to the Combined Operator Program!\n");

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Encrypt and Decrypt a Character\n");
        printf("2. Perform Compound Operations\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter a character to encrypt: ");
            scanf(" %c", &message); // Space before %c to handle newline character
            printf("Enter a key (integer between 0 and 255): ");
            scanf(" %c", &key);

            encryptDecryptChar(message, key);
            break;

        case 2:
            printf("\nEnter two integers (a and b):\n");
            printf("a = ");
            scanf("%d", &a);
            printf("b = ");
            scanf("%d", &b);

            a = performCompoundOperations(a, b);
            break;

        case 3:
            printf("Exiting the program. Goodbye!\n");
            return 0;

        default:
            printf("Invalid choice. Please select again.\n");
        }
    }

    return 0;
}