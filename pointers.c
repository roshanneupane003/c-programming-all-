#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void basicPointerOperations();
void pointerArithmetic();
void pointersAndArrays();
void pointersAndStrings();
void pointersToFunctions();
void dynamicMemoryAllocation();
void pointersToPointers();
void pointersAndStructures();
void constPointers();
void voidPointers();

int main()
{
    printf("--- Basic Pointer Operations ---\n");
    basicPointerOperations();

    printf("\n--- Pointer Arithmetic ---\n");
    pointerArithmetic();

    printf("\n--- Pointers and Arrays ---\n");
    pointersAndArrays();

    printf("\n--- Pointers and Strings ---\n");
    pointersAndStrings();

    printf("\n--- Pointers to Functions ---\n");
    pointersToFunctions();

    printf("\n--- Dynamic Memory Allocation ---\n");
    dynamicMemoryAllocation();

    printf("\n--- Pointers to Pointers ---\n");
    pointersToPointers();

    printf("\n--- Pointers and Structures ---\n");
    pointersAndStructures();

    printf("\n--- Const Pointers ---\n");
    constPointers();

    printf("\n--- Void Pointers ---\n");
    voidPointers();

    return 0;
}

void basicPointerOperations()
{
    int num = 10;
    int *ptr = &num;

    printf("Value of num: %d\n", num);
    printf("Address of num: %p\n", (void *)&num);
    printf("Value of ptr: %p\n", (void *)ptr);
    printf("Value pointed to by ptr: %d\n", *ptr);

    *ptr = 20;
    printf("Modified value of num: %d\n", num);
}

void pointerArithmetic()
{
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr;

    printf("First element: %d\n", *ptr);
    ptr++;
    printf("Second element: %d\n", *ptr);
    ptr += 2;
    printf("Fourth element: %d\n", *ptr);

    ptr = arr + 4;
    printf("Last element: %d\n", *ptr);

    int diff = ptr - arr;
    printf("Difference between pointers: %d\n", diff);
}

void pointersAndArrays()
{
    int arr[] = {1, 2, 3, 4, 5};
    int *ptr = arr;

    for (int i = 0; i < 5; i++)
    {
        printf("Element %d: %d\n", i, *(ptr + i));
    }

    printf("Array using pointer notation:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Element %d: %d\n", i, ptr[i]);
    }
}

void pointersAndStrings()
{
    char str[] = "Hello, World!";
    char *ptr = str;

    while (*ptr != '\0')
    {
        printf("%c", *ptr);
        ptr++;
    }
    printf("\n");

    char text[] = "C Pointers";
    char *cStr = text;

    printf("C-string: %s\n", cStr);
}

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }

void pointersToFunctions()
{
    int (*funcPtr)(int, int);

    funcPtr = add;
    printf("Addition: %d\n", funcPtr(5, 3));

    funcPtr = subtract;
    printf("Subtraction: %d\n", funcPtr(5, 3));
}

void dynamicMemoryAllocation()
{
    int *dynamicInt = (int *)malloc(sizeof(int));
    if (dynamicInt == NULL)
    {
        perror("malloc failed");
        return;
    }
    *dynamicInt = 100;
    printf("Dynamic int: %d\n", *dynamicInt);
    free(dynamicInt);

    int *dynamicArray = (int *)malloc(5 * sizeof(int));
    if (dynamicArray == NULL)
    {
        perror("malloc failed");
        return;
    }
    for (int i = 0; i < 5; i++)
    {
        dynamicArray[i] = i * 2;
    }
    for (int i = 0; i < 5; i++)
    {
        printf("Dynamic array element %d: %d\n", i, dynamicArray[i]);
    }
    free(dynamicArray);
}

void pointersToPointers()
{
    int num = 5;
    int *ptr1 = &num;
    int **ptr2 = &ptr1;

    printf("Value of num: %d\n", num);
    printf("Value pointed to by ptr1: %d\n", *ptr1);
    printf("Value pointed to by ptr2: %d\n", **ptr2);

    **ptr2 = 25;
    printf("Modified value of num: %d\n", num);
}

struct Point
{
    int x;
    int y;
};

void pointersAndStructures()
{
    struct Point p1 = {10, 20};
    struct Point *ptr = &p1;

    printf("Point x: %d\n", ptr->x);
    printf("Point y: %d\n", ptr->y);

    ptr->x = 30;
    printf("Modified Point x: %d\n", p1.x);
}

void constPointers()
{
    int num = 5;
    const int *ptr1 = &num;
    int *const ptr2 = &num;
    const int *const ptr3 = &num;

    printf("Const int pointer value: %d\n", *ptr1);
    *ptr2 = 15;
    printf("Const pointer to int value: %d\n", num);
    printf("Const const pointer value: %d\n", *ptr3);
}

void voidPointers()
{
    int num = 10;
    float f = 3.14f;

    void *ptr;

    ptr = &num;
    printf("Value pointed to by void pointer (int): %d\n", *(int *)ptr);

    ptr = &f;
    printf("Value pointed to by void pointer (float): %f\n", *(float *)ptr);
}