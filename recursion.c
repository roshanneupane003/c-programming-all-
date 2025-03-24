#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
int factorial(int n);
int fibonacci(int n);
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod);
int binarySearchRecursive(int arr[], int low, int high, int key);
void reverseStringRecursive(char *str, int start, int end);
int greatestCommonDivisor(int a, int b);
int power(int base, int exp);
void printArrayReverse(int arr[], int size);
int sumOfArray(int arr[], int size);
int isPalindromeRecursive(char *str, int start, int end);
void recursiveQuickSort(int arr[], int low, int high);
void recursiveMergeSort(int arr[], int l, int r);
void recursiveTreeTraversal(int level); // Simulated tree traversal
int recursiveAckermann(int m, int n);
void recursiveDirectoryTraversal(const char *dirPath); // Simulated directory traversal
int recursiveCombinations(int n, int k);
void recursivePermutations(char *str, int l, int r);
void recursiveFloodFill(int screen[][8], int x, int y, int prevC, int newC); // Simulated flood fill

int main()
{
    printf("--- Recursive Factorial ---\n");
    printf("Factorial of 5: %d\n", factorial(5));

    printf("\n--- Recursive Fibonacci ---\n");
    printf("Fibonacci(10): %d\n", fibonacci(10));

    printf("\n--- Tower of Hanoi ---\n");
    towerOfHanoi(3, 'A', 'C', 'B');

    printf("\n--- Recursive Binary Search ---\n");
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 23;
    int index = binarySearchRecursive(arr, 0, n - 1, key);
    if (index != -1)
    {
        printf("Element %d found at index %d\n", key, index);
    }
    else
    {
        printf("Element %d not found\n", key);
    }

    printf("\n--- Recursive String Reversal ---\n");
    char str[] = "hello";
    reverseStringRecursive(str, 0, strlen(str) - 1);
    printf("Reversed string: %s\n", str);

    printf("\n--- Recursive GCD ---\n");
    printf("GCD of 48 and 18: %d\n", greatestCommonDivisor(48, 18));

    printf("\n--- Recursive Power ---\n");
    printf("2^5: %d\n", power(2, 5));

    printf("\n--- Recursive Array Reverse Print ---\n");
    int arr2[] = {1, 2, 3, 4, 5};
    printArrayReverse(arr2, sizeof(arr2) / sizeof(arr2[0]));

    printf("\n--- Recursive Array Sum ---\n");
    printf("Sum of array: %d\n", sumOfArray(arr2, sizeof(arr2) / sizeof(arr2[0])));

    printf("\n--- Recursive Palindrome Check ---\n");
    char palindrome[] = "madam";
    if (isPalindromeRecursive(palindrome, 0, strlen(palindrome) - 1))
    {
        printf("'%s' is a palindrome\n", palindrome);
    }
    else
    {
        printf("'%s' is not a palindrome\n", palindrome);
    }

    printf("\n--- Recursive Quick Sort ---\n");
    int arr3[] = {10, 7, 8, 9, 1, 5};
    recursiveQuickSort(arr3, 0, sizeof(arr3) / sizeof(arr3[0]) - 1);
    printf("Sorted array: ");
    for (int i = 0; i < sizeof(arr3) / sizeof(arr3[0]); i++)
    {
        printf("%d ", arr3[i]);
    }
    printf("\n");

    printf("\n--- Recursive Merge Sort ---\n");
    int arr4[] = {12, 11, 13, 5, 6, 7};
    recursiveMergeSort(arr4, 0, sizeof(arr4) / sizeof(arr4[0]) - 1);
    printf("Sorted array: ");
    for (int i = 0; i < sizeof(arr4) / sizeof(arr4[0]); i++)
    {
        printf("%d ", arr4[i]);
    }
    printf("\n");

    printf("\n--- Recursive Tree Traversal (Simulated) ---\n");
    recursiveTreeTraversal(0);

    printf("\n--- Recursive Ackermann Function ---\n");
    printf("Ackermann(3, 4): %d\n", recursiveAckermann(3, 4));

    printf("\n--- Recursive Directory Traversal (Simulated) ---\n");
    recursiveDirectoryTraversal(".");

    printf("\n--- Recursive Combinations ---\n");
    printf("Combinations(5, 3): %d\n", recursiveCombinations(5, 3));

    printf("\n--- Recursive Permutations ---\n");
    char perm[] = "ABC";
    recursivePermutations(perm, 0, strlen(perm) - 1);

    printf("\n--- Recursive Flood Fill (Simulated) ---\n");
    int screen[8][8] = {
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 0, 0},
        {1, 0, 0, 1, 1, 0, 1, 1},
        {1, 2, 2, 2, 2, 0, 1, 0},
        {1, 1, 1, 2, 2, 0, 1, 0},
        {1, 1, 1, 2, 2, 2, 2, 0},
        {1, 1, 1, 1, 1, 2, 1, 1},
        {1, 1, 1, 1, 1, 2, 2, 1},
    };
    recursiveFloodFill(screen, 4, 4, 2, 3);
    printf("Flood filled screen:\n");
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("%d ", screen[i][j]);
        }
        printf("\n");
    }

    return 0;
}

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
    {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int binarySearchRecursive(int arr[], int low, int high, int key)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        if (arr[mid] > key)
        {
            return binarySearchRecursive(arr, low, mid - 1, key);
        }
        return binarySearchRecursive(arr, mid + 1, high, key);
    }
    return -1;
}

void reverseStringRecursive(char *str, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    reverseStringRecursive(str, start + 1, end - 1);
}

int greatestCommonDivisor(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return greatestCommonDivisor(b, a % b);
}

int power(int base, int exp)
{
    if (exp == 0)
    {
        return 1;
    }
    return base * power(base, exp - 1);
}

void printArrayReverse(int arr[], int size)
{
    if (size == 0)
    {
        return;
    }
    printf("%d ", arr[size - 1]);
    printArrayReverse(arr, size - 1);
}

int sumOfArray(int arr[], int size)
{
    if (size == 0)
    {
        return 0;
    }
    return arr[size - 1] + sumOfArray(arr, size - 1);
}

int isPalindromeRecursive(char *str, int start, int end)
{
    if (start >= end)
    {
        return 1;
    }
    if (str[start] != str[end])
    {
        return 0;
    }
    return isPalindromeRecursive(str, start + 1, end - 1);
}

void recursiveQuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j <= high - 1; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        int pi = i + 1;
        recursiveQuickSort(arr, low, pi - 1);
        recursiveQuickSort(arr, pi + 1, high);
    }
}

void recursiveMergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        recursiveMergeSort(arr, l, m);
        recursiveMergeSort(arr, m + 1, r);
        int i, j, k;
        int n1 = m - l + 1;
        int n2 = r - m;
        int L[n1], R[n2];
        for (i = 0; i < n1; i++)
            L[i] = arr[l + i];
        for (j = 0; j < n2; j++)
            R[j] = arr[m + 1 + j];
        i = 0;
        j = 0;
        k = l;
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }
        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
}

void recursiveTreeTraversal(int level)
{
    if (level > 3)
    {
        return;
    }
    printf("Level: %d\n", level);
    recursiveTreeTraversal(level + 1);
    recursiveTreeTraversal(level + 1);
}

int recursiveAckermann(int m, int n)
{
    if (m == 0)
    {
        return n + 1;
    }
    if (n == 0)
    {
        return recursiveAckermann(m - 1, 1);
    }
    return recursiveAckermann(m - 1, recursiveAckermann(m, n - 1));
}

void recursiveDirectoryTraversal(const char *dirPath)
{
    printf("Visiting directory: %s\n", dirPath);
    // In a real implementation, you would use system calls to list files
    // and directories within dirPath and recursively call this function.
}

int recursiveCombinations(int n, int k)
{
    if (k == 0 || k == n)
    {
        return 1;
    }
    return recursiveCombinations(n - 1, k - 1) + recursiveCombinations(n - 1, k);
}

void recursivePermutations(char *str, int l, int r)
{
    if (l == r)
    {
        printf("%s\n", str);
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            char temp = str[l];
            str[l] = str[i];
            str[i] = temp;
            recursivePermutations(str, l + 1, r);
            temp = str[l];
            str[l] = str[i];
            str[i] = temp;
        }
    }
}

void recursiveFloodFill(int screen[][8], int x, int y, int prevC, int newC)
{
    if (x < 0 || x >= 8 || y < 0 || y >= 8)
    {
        return;
    }
    if (screen[x][y] != prevC)
    {
        return;
    }
    screen[x][y] = newC;
    recursiveFloodFill(screen, x + 1, y, prevC, newC);
    recursiveFloodFill(screen, x - 1, y, prevC, newC);
    recursiveFloodFill(screen, x, y + 1, prevC, newC);
    recursiveFloodFill(screen, x, y - 1, prevC, newC);
}