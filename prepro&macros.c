#include <stdio.h>
#include <stdlib.h>

// Basic Macro Definitions
#define PI 3.14159
#define SQUARE(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

// Stringification and Concatenation
#define STRINGIFY(x) #x
#define CONCAT(a, b) a##b

// Variadic Macros
#define DEBUG(...) printf(__VA_ARGS__)
#define LOG(format, ...) printf(format, __VA_ARGS__)

// Conditional Compilation
#define DEBUG_MODE 1

// Include Guards
#ifndef MY_HEADER_H
#define MY_HEADER_H

// Header content...
#define MY_CONSTANT 123

#endif // MY_HEADER_H

// Macro Functions
#define IS_EVEN(n) ((n) % 2 == 0)
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

// Undefining Macros
#undef MAX

// Predefined Macros
void predefinedMacrosExample();

// Conditional Inclusion
#define OS_WINDOWS 1
#define OS_LINUX 2
#define CURRENT_OS OS_LINUX

// Error Handling
#define CHECK_ALLOCATION(ptr)                                                       \
    if (ptr == NULL)                                                                \
    {                                                                               \
        fprintf(stderr, "Memory allocation failed at %s:%d\n", __FILE__, __LINE__); \
        exit(1);                                                                    \
    }

// Macro Expansion Control
#define EXPAND(x) x

// Macro with side effects
#define INCREMENT(x) (x++)

// Macro for loop
#define FOR_LOOP(i, start, end) for (int i = start; i < end; i++)

// Macro to create a struct
#define CREATE_STRUCT(type, name, ...) \
    type name = {__VA_ARGS__};

// Macro to create a dynamic array
#define CREATE_DYNAMIC_ARRAY(type, name, size)        \
    type *name = (type *)malloc(sizeof(type) * size); \
    CHECK_ALLOCATION(name)

// Macro to free dynamic array
#define FREE_DYNAMIC_ARRAY(name) \
    free(name);                  \
    name = NULL;

// Macro to create a string
#define CREATE_STRING(name, str)                  \
    char *name = (char *)malloc(strlen(str) + 1); \
    CHECK_ALLOCATION(name);                       \
    strcpy(name, str);

// Macro to print array elements
#define PRINT_ARRAY(arr, size)                               \
    printf("[");                                             \
    for (int i = 0; i < size; i++)                           \
    {                                                        \
        printf("%d%s", arr[i], (i == size - 1) ? "" : ", "); \
    }                                                        \
    printf("]\n");

// Macro to print a message with file and line number
#define PRINT_MESSAGE(msg) \
    printf("%s (File: %s, Line: %d)\n", msg, __FILE__, __LINE__);

int main()
{
    printf("PI: %f\n", PI);
    printf("Square of 5: %d\n", SQUARE(5));
    printf("Max of 10 and 20: %d\n", MAX(10, 20));

    printf("Stringified: %s\n", STRINGIFY(PI));
    printf("Concatenated: %d\n", CONCAT(10, 20));

    DEBUG("Debug message: %d, %s\n", 42, "hello");
    LOG("Log message: %f\n", PI);

#if DEBUG_MODE
    printf("Debug mode is enabled.\n");
#endif

    printf("My constant: %d\n", MY_CONSTANT);

    int numbers[] = {1, 2, 3, 4, 5};
    printf("Array size: %zu\n", ARRAY_SIZE(numbers));

#ifdef MAX
    printf("MAX is defined.\n");
#else
    printf("MAX is not defined.\n");
#endif

    predefinedMacrosExample();

#if CURRENT_OS == OS_WINDOWS
    printf("Running on Windows.\n");
#elif CURRENT_OS == OS_LINUX
    printf("Running on Linux.\n");
#else
    printf("Unknown OS.\n");
#endif

    int *dynamicArray = NULL;
    CREATE_DYNAMIC_ARRAY(int, dynamicArray, 10);
    for (int i = 0; i < 10; i++)
    {
        dynamicArray[i] = i * 2;
    }
    PRINT_ARRAY(dynamicArray, 10);
    FREE_DYNAMIC_ARRAY(dynamicArray);

    CREATE_STRING(myString, "Dynamic String");
    printf("Dynamic String: %s\n", myString);
    free(myString);

    CREATE_STRUCT(struct { int x; char c; }, myStruct, 10, 'A');
    printf("Struct x: %d, c: %c\n", myStruct.x, myStruct.c);

    int val = 5;
    INCREMENT(val);
    printf("Incremented val: %d\n", val);

    FOR_LOOP(i, 0, 5)
    {
        printf("Loop index: %d\n", i);
    }

    PRINT_MESSAGE("This is a message.");

    return 0;
}

void predefinedMacrosExample()
{
    printf("File: %s\n", __FILE__);
    printf("Line: %d\n", __LINE__);
    printf("Date: %s\n", __DATE__);
    printf("Time: %s\n", __TIME__);
    printf("C Standard: %ld\n", __STDC_VERSION__);
}