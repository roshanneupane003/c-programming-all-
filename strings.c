#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void basicStringOperations();
void stringInputOutput();
void stringLengthAndCopy();
void stringComparison();
void stringConcatenation();
void stringSearch();
void stringTokenization();
void stringConversion();
void stringManipulation();
void dynamicStringAllocation();
void stringFormatting();
void characterClassification();
void advancedStringManipulation();

int main()
{
    printf("--- Basic String Operations ---\n");
    basicStringOperations();

    printf("\n--- String Input/Output ---\n");
    stringInputOutput();

    printf("\n--- String Length and Copy ---\n");
    stringLengthAndCopy();

    printf("\n--- String Comparison ---\n");
    stringComparison();

    printf("\n--- String Concatenation ---\n");
    stringConcatenation();

    printf("\n--- String Search ---\n");
    stringSearch();

    printf("\n--- String Tokenization ---\n");
    stringTokenization();

    printf("\n--- String Conversion ---\n");
    stringConversion();

    printf("\n--- String Manipulation ---\n");
    stringManipulation();

    printf("\n--- Dynamic String Allocation ---\n");
    dynamicStringAllocation();

    printf("\n--- String Formatting ---\n");
    stringFormatting();

    printf("\n--- Character Classification ---\n");
    characterClassification();

    printf("\n--- Advanced String Manipulation ---\n");
    advancedStringManipulation();

    return 0;
}

void basicStringOperations()
{
    char str1[] = "Hello";
    char str2[] = {'W', 'o', 'r', 'l', 'd', '\0'};

    printf("String 1: %s\n", str1);
    printf("String 2: %s\n", str2);
}

void stringInputOutput()
{
    char input[100];

    printf("Enter a string: ");
    scanf("%99[^\n]", input); // Read up to 99 characters, including spaces.

    printf("You entered: %s\n", input);

    char buffer[100];
    sprintf(buffer, "Formatted string: %s", input);
    printf("%s\n", buffer);
}

void stringLengthAndCopy()
{
    char source[] = "Copy this string";
    char destination[100];

    size_t length = strlen(source);
    printf("Length of source: %zu\n", length);

    strcpy(destination, source);
    printf("Copied string: %s\n", destination);

    strncpy(destination, "Short", 3);
    destination[3] = '\0'; // Ensure null termination.
    printf("Partial copy: %s\n", destination);
}

void stringComparison()
{
    char str1[] = "apple";
    char str2[] = "banana";
    char str3[] = "apple";

    int result1 = strcmp(str1, str2);
    int result2 = strcmp(str1, str3);

    printf("strcmp(str1, str2): %d\n", result1);
    printf("strcmp(str1, str3): %d\n", result2);

    int result3 = strncmp(str1, "app", 3);
    printf("strncmp(str1, 'app', 3): %d\n", result3);
}

void stringConcatenation()
{
    char dest[100] = "Hello, ";
    char src[] = "World!";

    strcat(dest, src);
    printf("Concatenated string: %s\n", dest);

    char part[100] = "Partial";
    strncat(dest, part, 3);
    printf("Partial concatenation: %s\n", dest);
}

void stringSearch()
{
    char str[] = "This is a sample string";
    char *ptr1 = strchr(str, 's');
    char *ptr2 = strstr(str, "sample");

    if (ptr1 != NULL)
    {
        printf("First occurrence of 's': %s\n", ptr1);
    }
    if (ptr2 != NULL)
    {
        printf("Substring 'sample' found: %s\n", ptr2);
    }

    char *ptr3 = strrchr(str, 's');
    if (ptr3 != NULL)
    {
        printf("Last occurrence of 's': %s\n", ptr3);
    }
}

void stringTokenization()
{
    char str[] = "apple,banana,orange";
    char *token = strtok(str, ",");

    while (token != NULL)
    {
        printf("Token: %s\n", token);
        token = strtok(NULL, ",");
    }

    char str2[] = "one two    three";
    char *token2 = strtok(str2, " ");
    while (token2 != NULL)
    {
        printf("Token2: %s\n", token2);
        token2 = strtok(NULL, " ");
    }
}

void stringConversion()
{
    char numStr[] = "12345";
    int num = atoi(numStr);
    printf("String to integer: %d\n", num);

    char floatStr[] = "3.14159";
    double floatNum = atof(floatStr);
    printf("String to float: %lf\n", floatNum);

    char longStr[] = "1234567890";
    long longNum = atoll(longStr);
    printf("String to long long: %lld\n", longNum);

    char intStr[20];
    sprintf(intStr, "%d", num * 2);
    printf("Integer to string: %s\n", intStr);
}

void stringManipulation()
{
    char str[] = "Mixed Case String";

    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = tolower(str[i]);
    }
    printf("Lowercase: %s\n", str);

    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = toupper(str[i]);
    }
    printf("Uppercase: %s\n", str);

    char rev[] = "reverse";
    size_t len = strlen(rev);
    for (size_t i = 0; i < len / 2; i++)
    {
        char temp = rev[i];
        rev[i] = rev[len - i - 1];
        rev[len - i - 1] = temp;
    }
    printf("Reversed: %s\n", rev);
}

void dynamicStringAllocation()
{
    char *dynamicStr = (char *)malloc(100 * sizeof(char));
    if (dynamicStr == NULL)
    {
        perror("malloc failed");
        return;
    }
    strcpy(dynamicStr, "Dynamic string");
    printf("Dynamic string: %s\n", dynamicStr);
    free(dynamicStr);
}

void stringFormatting()
{
    char formatted[100];
    int num = 42;
    double pi = 3.14159;

    sprintf(formatted, "Number: %d, Pi: %.2lf", num, pi);
    printf("Formatted string: %s\n", formatted);
}

void characterClassification()
{
    char input[] = "Hello123World!";
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (isalpha(input[i]))
        {
            printf("'%c' is an alphabet.\n", input[i]);
        }
        else if (isdigit(input[i]))
        {
            printf("'%c' is a digit.\n", input[i]);
        }
        else if (isspace(input[i]))
        {
            printf("'%c' is whitespace.\n", input[i]);
        }
    }
}

void advancedStringManipulation()
{
    char original[] = "This is a test string";
    char copy[100];
    memcpy(copy, original, strlen(original) + 1);
    printf("memcpy copy: %s\n", copy);

    char *memchrResult = memchr(original, 't', strlen(original));
    if (memchrResult != NULL)
    {
        printf("memchr found 't': %s\n", memchrResult);
    }

    char *substring = strdup("Test");
    if (substring != NULL)
    {
        printf("strdup result: %s\n", substring);
        free(substring);
    }

    char strToModify[] = "Modify this string";