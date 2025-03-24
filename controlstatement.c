#include <stdio.h>

int main()
{
    int choice, number, result, i;

    printf("Welcome to Control Statements Program!\n");
    printf("Menu:\n");
    printf("1. Check if a number is even or odd\n");
    printf("2. Find factorial of a number\n");
    printf("3. Print multiplication table of a number\n");
    printf("4. Exit\n");

    while (1)
    { // Infinite loop to keep the program running until the user exits
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter a number: ");
            scanf("%d", &number);

            // If-else statement
            if (number % 2 == 0)
            {
                printf("%d is an even number.\n", number);
            }
            else
            {
                printf("%d is an odd number.\n", number);
            }
            break;

        case 2:
            printf("Enter a number: ");
            scanf("%d", &number);

            result = 1; // Initialize result for factorial calculation

            // For loop to calculate factorial
            for (i = 1; i <= number; i++)
            {
                result *= i;
            }

            printf("Factorial of %d is %d.\n", number, result);
            break;

        case 3:
            printf("Enter a number: ");
            scanf("%d", &number);

            // Printing multiplication table using a loop
            printf("Multiplication table of %d:\n", number);
            for (i = 1; i <= 10; i++)
            {
                printf("%d x %d = %d\n", number, i, number * i);
            }
            break;

        case 4:
            printf("Exiting the program. Goodbye!\n");
            return 0; // Exit the program

        default:
            // If an invalid choice is entered
            printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    }

    return 0;
}