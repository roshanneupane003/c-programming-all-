#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include <time.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
// Function prototypes
void basicFunctionExample();
int add(int a, int b);
void passByValue(int x);
void passByReference(int *x);
int factorial(int n);
int recursiveFibonacci(int n);
void functionPointersExample();
int multiply(int a, int b);
void variableArgumentsExample(int count, ...);
int calculateArea(int width, int height); // Normal function
int calculateCircleArea(int radius);      // Overloaded-like function (different name)
int calculatePower(int base, int exponent);
void staticVariablesExample();
void externalVariablesExample();
void inlineFunctionExample(); // C doesn't have true inline, but shows the concept
int getRandomNumber();
void timeFunctionExample();

// Global variable
int globalVariable = 100;

int main()
{
    printf("--- Basic Function Example ---\n");
    basicFunctionExample();

    printf("\n--- Pass By Value ---\n");
    int val = 5;
    passByValue(val);
    printf("Value after passByValue: %d\n", val);

    printf("\n--- Pass By Reference ---\n");
    val = 5;
    passByReference(&val);
    printf("Value after passByReference: %d\n", val);

    printf("\n--- Recursive Factorial ---\n");
    printf("Factorial of 5: %d\n", factorial(5));

    printf("\n--- Recursive Fibonacci ---\n");
    printf("Fibonacci(10): %d\n", recursiveFibonacci(10));

    printf("\n--- Function Pointers ---\n");
    functionPointersExample();

    printf("\n--- Variable Arguments ---\n");
    variableArgumentsExample(4, 1, 2, 3, 4);

    printf("\n--- Function Overloading (Simulated) ---\n");
    printf("Area of rectangle: %d\n", calculateArea(5, 10));
    printf("Area of circle: %d\n", calculateCircleArea(7));

    printf("\n--- Function with default parameters (Simulated) ---\n");
    printf("2^3 : %d\n", calculatePower(2, 3));
    printf("5^2 : %d\n", calculatePower(5, 2));

    printf("\n--- Static Variables ---\n");
    for (int i = 0; i < 3; i++)
    {
        staticVariablesExample();
    }

    printf("\n--- External Variables ---\n");
    externalVariablesExample();

    printf("\n--- Inline Function (Simulated) ---\n");
    inlineFunctionExample();

    printf("\n--- Random number generation ---\n");
    printf("Random number: %d\n", getRandomNumber());

    printf("\n--- Time function example ---\n");
    timeFunctionExample();

    return 0;
}

void basicFunctionExample()
{
    int result = add(3, 7);
    printf("3 + 7 = %d\n", result);
}

int add(int a, int b)
{
    return a + b;
}

void passByValue(int x)
{
    x = 20;
    printf("Inside passByValue: x = %d\n", x);
}

void passByReference(int *x)
{
    *x = 20;
    printf("Inside passByReference: *x = %d\n", *x);
}

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

int recursiveFibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);
    }
}

int multiply(int a, int b)
{
    return a * b;
}

void functionPointersExample()
{
    int (*funcPtr)(int, int);
    funcPtr = multiply;
    printf("5 * 6 = %d\n", funcPtr(5, 6));
}

void variableArgumentsExample(int count, ...)
{
    va_list args;
    va_start(args, count);
    int sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += va_arg(args, int);
    }
    va_end(args);
    printf("Sum of variable arguments: %d\n", sum);
}

int calculateArea(int width, int height)
{
    return width * height;
}

int calculateCircleArea(int radius)
{
    return (int)(M_PI * radius * radius);
}

int calculatePower(int base, int exponent)
{
    int result = 1;
    for (int i = 0; i < exponent; i++)
    {
        result *= base;
    }
    return result;
}

void staticVariablesExample()
{
    static int counter = 0;
    counter++;
    printf("Static counter: %d\n", counter);
}

void externalVariablesExample()
{
    printf("Global variable: %d\n", globalVariable);
}

void inlineFunctionExample()
{
    // C doesn't have true inline, but compilers might optimize
    // simple functions.
    printf("Simulated inline: %d\n", add(10, 20));
}

int getRandomNumber()
{
    srand(time(NULL));   // seed the random number generator
    return rand() % 100; // returns a number between 0 and 99
}

void timeFunctionExample()
{
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    printf("Current local time and date: %s", asctime(timeinfo));
}