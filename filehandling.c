#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Function prototypes
void basicFileOperations();
void formattedFileIO();
void binaryFileIO();
void filePositioning();
void errorHandling();
void fileBuffering();
void temporaryFiles();
void filePermissions();
void fileMetadata();
void fileLocking();
void memoryMappedFiles();

int main()
{
    printf("--- Basic File Operations ---\n");
    basicFileOperations();

    printf("\n--- Formatted File I/O ---\n");
    formattedFileIO();

    printf("\n--- Binary File I/O ---\n");
    binaryFileIO();

    printf("\n--- File Positioning ---\n");
    filePositioning();

    printf("\n--- Error Handling ---\n");
    errorHandling();

    printf("\n--- File Buffering ---\n");
    fileBuffering();

    printf("\n--- Temporary Files ---\n");
    temporaryFiles();

    printf("\n--- File Permissions (Simulated) ---\n");
    filePermissions();

    printf("\n--- File Metadata (Simulated) ---\n");
    fileMetadata();

    printf("\n--- File Locking (Simulated) ---\n");
    fileLocking();

    printf("\n--- Memory-Mapped Files (Simulated) ---\n");
    memoryMappedFiles();

    return 0;
}

void basicFileOperations()
{
    FILE *file = fopen("basic.txt", "w");
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }
    fprintf(file, "Hello, File Handling!\n");
    fclose(file);

    file = fopen("basic.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }
    char buffer[100];
    fgets(buffer, sizeof(buffer), file);
    printf("Read from file: %s", buffer);
    fclose(file);
}

void formattedFileIO()
{
    FILE *file = fopen("formatted.txt", "w+");
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }
    fprintf(file, "Name: %s, Age: %d, GPA: %.2f\n", "Alice", 20, 3.8);

    rewind(file);

    char name[50];
    int age;
    float gpa;
    fscanf(file, "Name: %s, Age: %d, GPA: %f", name, &age, &gpa);
    printf("Read from formatted file: Name: %s, Age: %d, GPA: %.2f\n", name, age, gpa);
    fclose(file);
}

void binaryFileIO()
{
    int data[] = {1, 2, 3, 4, 5};
    FILE *file = fopen("binary.bin", "wb");
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }
    fwrite(data, sizeof(int), 5, file);
    fclose(file);

    int readData[5];
    file = fopen("binary.bin", "rb");
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }
    fread(readData, sizeof(int), 5, file);
    fclose(file);

    printf("Read from binary file: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", readData[i]);
    }
    printf("\n");
}

void filePositioning()
{
    FILE *file = fopen("position.txt", "w+");
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }
    fprintf(file, "Positioning test");
    fseek(file, 9, SEEK_SET);
    fprintf(file, "!");
    rewind(file);
    char buffer[100];
    fgets(buffer, sizeof(buffer), file);
    printf("Positioning result: %s", buffer);
    fclose(file);
}

void errorHandling()
{
    FILE *file = fopen("nonexistent.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file: %s\n", strerror(errno));
        return;
    }
    fclose(file);
}

void fileBuffering()
{
    FILE *file = fopen("buffered.txt", "w");
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }
    setvbuf(file, NULL, _IONBF, 0); // No buffering
    fprintf(file, "Unbuffered write\n");
    fclose(file);
}

void temporaryFiles()
{
    char tempFileName[] = "tempXXXXXX";
    int fd = mkstemp(tempFileName);
    if (fd == -1)
    {
        perror("mkstemp failed");
        return;
    }
    FILE *tempFile = fdopen(fd, "w+");
    if (tempFile == NULL)
    {
        perror("fdopen failed");
        return;
    }
    fprintf(tempFile, "Temporary data");
    rewind(tempFile);
    char buffer[100];
    fgets(buffer, sizeof(buffer), tempFile);
    printf("Temp file content: %s", buffer);
    fclose(tempFile);
    remove(tempFileName);
}

void filePermissions()
{
    // Simulated file permissions. In real systems, use chmod.
    printf("Simulating file permission changes.\n");
}

void fileMetadata()
{
    // Simulated file metadata retrieval. In real systems, use stat.
    printf("Simulating file metadata retrieval.\n");
}

void fileLocking()
{
    // Simulated file locking. In real systems, use flock or fcntl.
    printf("Simulating file locking.\n");
}

void memoryMappedFiles()
{
    // Memory mapping is OS dependent, this is a simulated example.
    printf("Simulating memory-mapped file operations.\n");
}