#include <stdio.h>
#include <stdlib.h>

// Global variables (external storage class)
int globalVar = 10;

// Function prototypes
void autoStorageClass();
void registerStorageClass();
void staticStorageClass();
void externStorageClass();
void threadLocalStorageClass(); // Simulated thread_local
void storageClassWithStructures();
void storageClassWithArrays();
void storageClassWithPointers();
void storageClassAndScope();
void storageClassAndInitialization();
void storageClassAndLinkage();
void storageClassAndRecursion();
void storageClassAndPerformance();
void storageClassAndConcurrency(); // Simulated concurrency

int main()
{
    printf("--- Auto Storage Class ---\n");
    autoStorageClass();

    printf("\n--- Register Storage Class ---\n");
    registerStorageClass();

    printf("\n--- Static Storage Class ---\n");
    staticStorageClass();

    printf("\n--- Extern Storage Class ---\n");
    externStorageClass();

    printf("\n--- Thread-Local Storage Class (Simulated) ---\n");
    threadLocalStorageClass();

    printf("\n--- Storage Class with Structures ---\n");
    storageClassWithStructures();

    printf("\n--- Storage Class with Arrays ---\n");
    storageClassWithArrays();

    printf("\n--- Storage Class with Pointers ---\n");
    storageClassWithPointers();

    printf("\n--- Storage Class and Scope ---\n");
    storageClassAndScope();

    printf("\n--- Storage Class and Initialization ---\n");
    storageClassAndInitialization();

    printf("\n--- Storage Class and Linkage ---\n");
    storageClassAndLinkage();

    printf("\n--- Storage Class and Recursion ---\n");
    storageClassAndRecursion();

    printf("\n--- Storage Class and Performance ---\n");
    storageClassAndPerformance();

    printf("\n--- Storage Class and Concurrency (Simulated) ---\n");
    storageClassAndConcurrency();

    return 0;
}

void autoStorageClass()
{
    auto int localVar = 5;
    printf("Auto variable: %d\n", localVar);
}

void registerStorageClass()
{
    register int regVar = 20;
    printf("Register variable: %d\n", regVar);
}

void staticStorageClass()
{
    static int staticVar = 0; // Retains value between function calls
    staticVar++;
    printf("Static variable: %d\n", staticVar);
}

void externStorageClass()
{
    extern int globalVar; // Access global variable
    printf("External variable: %d\n", globalVar);
}

void threadLocalStorageClass()
{
    // thread_local is not standard C, this is a simulated example.
    printf("Simulating thread-local storage.\n");
}

struct Data
{
    int value;
};

void storageClassWithStructures()
{
    static struct Data data = {30};
    printf("Static struct value: %d\n", data.value);
}

void storageClassWithArrays()
{
    static int arr[] = {1, 2, 3}; // Static array retains values between calls
    for (int i = 0; i < 3; i++)
    {
        printf("Static array element %d: %d\n", i, arr[i]);
    }
}

void storageClassWithPointers()
{
    static int staticVar = 40;
    static int *ptr = &staticVar; // Static pointer to static variable
    printf("Static pointer value: %d\n", *ptr);
}

void storageClassAndScope()
{
    int localVar = 50; // Outer scope
    {
        int localVar = 60; // Inner scope shadows outer scope
        printf("Inner scope local variable: %d\n", localVar);
    }
    printf("Outer scope local variable: %d\n", localVar);
}

void storageClassAndInitialization()
{
    static int staticVar; // Implicitly initialized to 0
    printf("Uninitialized static variable: %d\n", staticVar);
}

void storageClassAndLinkage()
{
    extern int globalVar;
    printf("External variable with linkage: %d\n", globalVar);
}

void recursiveFunc(int count)
{
    static int staticVar = 0; // Static variable retains value between calls
    staticVar++;
    printf("Recursion count: %d, Static variable: %d\n", count, staticVar);
    if (count > 0)
    {
        recursiveFunc(count - 1);
    }
}

void storageClassAndRecursion()
{
    recursiveFunc(3);
}

void storageClassAndPerformance()
{
    // Register variables can improve performance, but modern compilers optimize automatically.
    printf("Simulating storage class and performance.\n");
}

void storageClassAndConcurrency()
{
    // thread_local is used for concurrency, but this is a simulated example.
    printf("Simulating storage class and concurrency.\n");
}