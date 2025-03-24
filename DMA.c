#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void basicAllocationAndDeallocation();
void arrayAllocation();
void resizingMemory();
void memoryForStructures();
void memoryForStrings();
void multidimensionalArrays();
void memoryForFunctionPointers();
void memoryAlignment();
void memoryErrors();
void customAllocators();
void memoryDebugging();

int add(int a, int b);

int main()
{
    printf("--- Basic Allocation and Deallocation ---\n");
    basicAllocationAndDeallocation();

    printf("\n--- Array Allocation ---\n");
    arrayAllocation();

    printf("\n--- Resizing Memory ---\n");
    resizingMemory();

    printf("\n--- Memory for Structures ---\n");
    memoryForStructures();

    printf("\n--- Memory for Strings ---\n");
    memoryForStrings();

    printf("\n--- Multidimensional Arrays ---\n");
    multidimensionalArrays();

    printf("\n--- Memory for Function Pointers ---\n");
    memoryForFunctionPointers();

    printf("\n--- Memory Alignment ---\n");
    memoryAlignment();

    printf("\n--- Memory Errors ---\n");
    memoryErrors();

    printf("\n--- Custom Allocators (Simulated) ---\n");
    customAllocators();

    printf("\n--- Memory Debugging (Simulated) ---\n");
    memoryDebugging();

    return 0;
}

void basicAllocationAndDeallocation()
{
    int *ptr = (int *)malloc(sizeof(int));
    if (ptr == NULL)
    {
        perror("malloc failed");
        return;
    }
    *ptr = 100;
    printf("Allocated int: %d\n", *ptr);
    free(ptr);
}

void arrayAllocation()
{
    int *arr = (int *)malloc(5 * sizeof(int));
    if (arr == NULL)
    {
        perror("malloc failed");
        return;
    }
    for (int i = 0; i < 5; i++)
    {
        arr[i] = i * 10;
    }
    for (int i = 0; i < 5; i++)
    {
        printf("arr[%d]: %d\n", i, arr[i]);
    }
    free(arr);
}

void resizingMemory()
{
    int *ptr = (int *)malloc(2 * sizeof(int));
    if (ptr == NULL)
    {
        perror("malloc failed");
        return;
    }
    ptr[0] = 10;
    ptr[1] = 20;

    int *newPtr = (int *)realloc(ptr, 5 * sizeof(int));
    if (newPtr == NULL)
    {
        perror("realloc failed");
        free(ptr);
        return;
    }
    newPtr[2] = 30;
    newPtr[3] = 40;
    newPtr[4] = 50;

    for (int i = 0; i < 5; i++)
    {
        printf("newPtr[%d]: %d\n", i, newPtr[i]);
    }
    free(newPtr);
}

struct Student
{
    int id;
    char name[50];
};

void memoryForStructures()
{
    struct Student *student = (struct Student *)malloc(sizeof(struct Student));
    if (student == NULL)
    {
        perror("malloc failed");
        return;
    }
    student->id = 101;
    strcpy(student->name, "Alice");
    printf("Student ID: %d, Name: %s\n", student->id, student->name);
    free(student);
}

void memoryForStrings()
{
    char *str = (char *)malloc(100 * sizeof(char));
    if (str == NULL)
    {
        perror("malloc failed");
        return;
    }
    strcpy(str, "Dynamic string");
    printf("String: %s\n", str);
    free(str);
}

void multidimensionalArrays()
{
    int(*matrix)[3] = (int(*)[3])malloc(2 * 3 * sizeof(int));
    if (matrix == NULL)
    {
        perror("malloc failed");
        return;
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix[i][j] = i * 3 + j;
        }
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("matrix[%d][%d]: %d\n", i, j, matrix[i][j]);
        }
    }
    free(matrix);
}

int add(int a, int b)
{
    return a + b;
}

void memoryForFunctionPointers()
{
    int (*funcPtr)(int, int) = add;        // No malloc needed for function pointers
    printf("Result: %d\n", funcPtr(5, 3)); // Direct call using the function pointer
}

void memoryAlignment()
{
    printf("Simulating memory alignment.\n");
}

void memoryErrors()
{
    int *ptr = (int *)malloc(sizeof(int));
    if (ptr == NULL)
    {
        perror("malloc failed");
        return;
    }
    *ptr = 10;
    free(ptr);
    // double free or use after free are undefined behavior.
    // Uncommenting the following lines would cause errors:
    // free(ptr); // Double free
    // printf("%d", *ptr); // Use after free
    printf("Simulating memory errors.\n");
}

void customAllocators()
{
    printf("Simulating custom allocators.\n");
}

void memoryDebugging()
{
    printf("Simulating memory debugging.\n");
}