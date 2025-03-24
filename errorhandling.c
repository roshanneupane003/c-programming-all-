#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <setjmp.h>
#include <signal.h>
#include <float.h>
#include <math.h>
#include <assert.h>

// Function prototypes
void basicErrorHandling();
void errnoHandling();
void perrorHandling();
void stringErrorHandling();
void fileErrorHandling();
void memoryErrorHandling();
void signalHandling();
void floatingPointErrorHandling();
void mathErrorHandling();
void setjmpLongjmpHandling();
void customErrorHandlerDemo();
void assertExample();
void resourceCleanup();

// Global jump buffer for setjmp/longjmp
jmp_buf jumpBuffer;

// Custom error handler function
void customErrorHandler(const char *message)
{
    fprintf(stderr, "Custom Error: %s\n", message);
    longjmp(jumpBuffer, 1); // Jump back to setjmp
}

// Signal handler function
void signalHandler(int signum)
{
    fprintf(stderr, "Signal %d caught: %s\n", signum, strsignal(signum));
    longjmp(jumpBuffer, 2); // Jump back to setjmp
}

int main()
{
    printf("--- Basic Error Handling ---\n");
    basicErrorHandling();

    printf("\n--- Errno Handling ---\n");
    errnoHandling();

    printf("\n--- Perror Handling ---\n");
    perrorHandling();

    printf("\n--- String Error Handling ---\n");
    stringErrorHandling();

    printf("\n--- File Error Handling ---\n");
    fileErrorHandling();

    printf("\n--- Memory Error Handling ---\n");
    memoryErrorHandling();

    printf("\n--- Signal Handling ---\n");
    signalHandling();

    printf("\n--- Floating Point Error Handling ---\n");
    floatingPointErrorHandling();

    printf("\n--- Math Error Handling ---\n");
    mathErrorHandling();

    printf("\n--- Setjmp/Longjmp Handling ---\n");
    setjmpLongjmpHandling();

    printf("\n--- Custom Error Handler Demo ---\n");
    customErrorHandlerDemo();

    printf("\n--- Assert Example ---\n");
    assertExample();

    printf("\n--- Resource Cleanup ---\n");
    resourceCleanup();

    return 0;
}

void basicErrorHandling()
{
    FILE *file = fopen("nonexistent.txt", "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: File not found\n");
    }
    else
    {
        fclose(file);
    }
}

void errnoHandling()
{
    FILE *file = fopen("nonexistent.txt", "r");
    if (file == NULL)
    {
        printf("Errno: %d, Error: %s\n", errno, strerror(errno));
    }
    else
    {
        fclose(file);
    }
}

void perrorHandling()
{
    FILE *file = fopen("nonexistent.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file");
    }
    else
    {
        fclose(file);
    }
}

void stringErrorHandling()
{
    char *str = (char *)malloc(20); // Allocate enough memory
    if (str == NULL)
    {
        fprintf(stderr, "Error: Memory allocation failed\n");
    }
    else
    {
        strcpy(str, "Short string"); // Avoid buffer overflow
        printf("String: %s\n", str);
        free(str);
    }
}

void fileErrorHandling()
{
    FILE *file = fopen("test.txt", "w");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Cannot create file\n");
        return;
    }
    fprintf(file, "File content");
    if (ferror(file))
    {
        fprintf(stderr, "Error writing to file\n");
    }
    fclose(file);
}

void memoryErrorHandling()
{
    int *ptr = (int *)malloc(1000000000); // Use a large, reasonable value
    if (ptr == NULL)
    {
        fprintf(stderr, "Error: Memory allocation failed (Out of memory)\n");
    }
    else
    {
        free(ptr);
    }
}

void signalHandling()
{
    if (setjmp(jumpBuffer) == 2)
    {
        printf("Signal handler returned\n");
        return;
    }
    signal(SIGINT, signalHandler); // Register signal handler for Ctrl+C
    raise(SIGINT);                 // Simulate raising SIGINT (Ctrl+C)
}

void floatingPointErrorHandling()
{
    double result = 1.0 / 0.0;
    if (isinf(result))
    {
        fprintf(stderr, "Error: Floating point division by zero\n");
    }
}

void mathErrorHandling()
{
    double result = sqrt(-1.0);
    if (isnan(result))
    {
        fprintf(stderr, "Error: Square root of a negative number\n");
    }
}

void setjmpLongjmpHandling()
{
    if (setjmp(jumpBuffer) == 1)
    {
        printf("Longjmp returned\n");
        return;
    }
    customErrorHandler("Testing setjmp/longjmp"); // This will trigger longjmp
}

void customErrorHandlerDemo()
{
    printf("Custom error handler executed separately.\n");
    customErrorHandler("Custom error message demonstration");
}

void assertExample()
{
    int x = 10;
    // assert(x > 20); // Uncommenting this will terminate the program if the condition is false
    printf("Assert example passed\n");
}

void resourceCleanup()
{
    FILE *file = fopen("cleanup.txt", "w");
    if (file == NULL)
    {
        fprintf(stderr, "Error: cleanup.txt file could not be created\n");
        return;
    }
    fprintf(file, "Resource Cleanup Example");
    // Simulate an error that requires cleanup
    if (1)
    {
        fprintf(stderr, "Simulated error occurred, cleaning up\n");
        fclose(file);
        remove("cleanup.txt");
        return;
    }
    fclose(file);
    printf("Resource cleanup successful\n");
}