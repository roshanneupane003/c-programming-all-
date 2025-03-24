#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

// Function prototypes
void basicCommandLineArguments(int argc, char *argv[]);
void argumentParsing(int argc, char *argv[]);
void optionParsing(int argc, char *argv[]);
void longOptionParsing(int argc, char *argv[]);
void argumentValidation(int argc, char *argv[]);
void environmentVariables();
void errorHandlingCommandLine(int argc, char *argv[]);
void helpAndUsage(int argc, char *argv[]);
void argumentConversion(int argc, char *argv[]);
void argumentHandlingWithStructs(int argc, char *argv[]);
void advancedArgumentParsing(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    printf("--- Basic Command Line Arguments ---\n");
    basicCommandLineArguments(argc, argv);

    printf("\n--- Argument Parsing ---\n");
    argumentParsing(argc, argv);

    printf("\n--- Option Parsing ---\n");
    optionParsing(argc, argv);

    printf("\n--- Long Option Parsing ---\n");
    longOptionParsing(argc, argv);

    printf("\n--- Argument Validation ---\n");
    argumentValidation(argc, argv);

    printf("\n--- Environment Variables ---\n");
    environmentVariables();

    printf("\n--- Error Handling (Command Line) ---\n");
    errorHandlingCommandLine(argc, argv);

    printf("\n--- Help and Usage ---\n");
    helpAndUsage(argc, argv);

    printf("\n--- Argument Conversion ---\n");
    argumentConversion(argc, argv);

    printf("\n--- Argument Handling with Structs ---\n");
    argumentHandlingWithStructs(argc, argv);

    printf("\n--- Advanced Argument Parsing ---\n");
    advancedArgumentParsing(argc, argv);

    return 0;
}

void basicCommandLineArguments(int argc, char *argv[])
{
    printf("Number of arguments: %d\n", argc);
    for (int i = 0; i < argc; i++)
    {
        printf("Argument %d: %s\n", i, argv[i]);
    }
}

void argumentParsing(int argc, char *argv[])
{
    if (argc > 1)
    {
        printf("First argument (excluding program name): %s\n", argv[1]);
    }
}

void optionParsing(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        if (argv[i][0] == '-')
        {
            printf("Option: %s\n", argv[i]);
            if (i + 1 < argc && argv[i + 1][0] != '-')
            {
                printf("Value: %s\n", argv[i + 1]);
                i++;
            }
        }
    }
}

void longOptionParsing(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        if (strncmp(argv[i], "--", 2) == 0)
        {
            printf("Long option: %s\n", argv[i]);
            if (i + 1 < argc && strncmp(argv[i + 1], "--", 2) != 0)
            {
                printf("Value: %s\n", argv[i + 1]);
                i++;
            }
        }
    }
}

void argumentValidation(int argc, char *argv[])
{
    if (argc > 2)
    {
        int num = atoi(argv[2]);
        if (num > 0)
        {
            printf("Validated number: %d\n", num);
        }
        else
        {
            printf("Invalid number argument.\n");
        }
    }
}

void environmentVariables()
{
    char *home = getenv("HOME");
    if (home != NULL)
    {
        printf("HOME environment variable: %s\n", home);
    }
}

void errorHandlingCommandLine(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Error: Missing argument.\n");
    }
}

void helpAndUsage(int argc, char *argv[])
{
    if (argc == 2 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0))
    {
        printf("Usage: %s [options] <arguments>\n", argv[0]);
        printf("Options:\n");
        printf("  -a, --alpha   Alpha option\n");
        printf("  -b, --beta    Beta option\n");
    }
}

void argumentConversion(int argc, char *argv[])
{
    if (argc > 1)
    {
        long num = strtol(argv[1], NULL, 10);
        if (num != LONG_MAX && num != LONG_MIN)
        {
            printf("Converted long: %ld\n", num);
        }
        else
        {
            printf("Conversion failed.\n");
        }
    }
}

struct Config
{
    int alpha;
    char beta[100];
};

void argumentHandlingWithStructs(int argc, char *argv[])
{
    struct Config config = {0, ""};
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-a") == 0)
        {
            config.alpha = 1;
        }
        else if (strcmp(argv[i], "-b") == 0 && i + 1 < argc)
        {
            strcpy(config.beta, argv[i + 1]);
            i++;
        }
    }
    printf("Alpha: %d, Beta: %s\n", config.alpha, config.beta);
}

void advancedArgumentParsing(int argc, char *argv[])
{
    int verbose = 0;
    char *input = NULL;
    char *output = NULL;
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--verbose") == 0)
        {
            verbose = 1;
        }
        else if (strcmp(argv[i], "-i") == 0 && i + 1 < argc)
        {
            input = argv[i + 1];
            i++;
        }
        else if (strcmp(argv[i], "-o") == 0 && i + 1 < argc)
        {
            output = argv[i + 1];
            i++;
        }
    }
    if (verbose)
    {
        printf("Verbose mode enabled.\n");
    }
    if (input != NULL)
    {
        printf("Input file: %s\n", input);
    }
    if (output != NULL)
    {
        printf("Output file: %s\n", output);
    }
}