#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <string.h>

#define MAX_ARRAY_SIZE 1000

// Function prototypes
void populate_random(int arr[], int size, int min, int max);
void print_array(int arr[], int size);
int find_max(int arr[], int size);
int find_min(int arr[], int size);
double calculate_average(int arr[], int size);
void reverse_array(int arr[], int size);
void sort_array_ascending(int arr[], int size);
void sort_array_descending(int arr[], int size);
int find_element(int arr[], int size, int target);
void copy_array(int source[], int dest[], int size);
void insert_element(int arr[], int *size, int element, int position);
void delete_element(int arr[], int *size, int position);
void concatenate_arrays(int arr1[], int size1, int arr2[], int size2, int result[], int *result_size);
void find_duplicates(int arr[], int size);
void count_occurrences(int arr[], int size, int target);
void rotate_left(int arr[], int size, int rotations);
void rotate_right(int arr[], int size, int rotations);
void swap_elements(int arr[], int index1, int index2);
void shuffle_array(int arr[], int size);
void find_second_largest(int arr[], int size);
void find_second_smallest(int arr[], int size);
void check_sorted_ascending(int arr[], int size);
void check_sorted_descending(int arr[], int size);
void find_missing_number(int arr[], int size);
void find_pairs_with_sum(int arr[], int size, int sum);
void find_triplets_with_sum(int arr[], int size, int sum);
void remove_duplicates(int arr[], int *size);
void find_mode(int arr[], int size);
void find_median(int arr[], int size);
void string_array_operations();

int main()
{
    int arr[MAX_ARRAY_SIZE];
    int size = 0;
    int choice, element, position, target, min, max, rotations, sum;
    int arr2[MAX_ARRAY_SIZE];
    int size2 = 0;
    int result[2 * MAX_ARRAY_SIZE];
    int result_size = 0;

    srand(time(NULL)); // Seed the random number generator

    while (1)
    {
        printf("\nArray Operations Menu:\n");
        printf("1. Populate Array with Random Numbers\n");
        printf("2. Print Array\n");
        printf("3. Find Maximum Element\n");
        printf("4. Find Minimum Element\n");
        printf("5. Calculate Average\n");
        printf("6. Reverse Array\n");
        printf("7. Sort Array (Ascending)\n");
        printf("8. Sort Array (Descending)\n");
        printf("9. Find Element\n");
        printf("10. Copy Array\n");
        printf("11. Insert Element\n");
        printf("12. Delete Element\n");
        printf("13. Concatenate Arrays\n");
        printf("14. Find Duplicates\n");
        printf("15. Count Occurrences\n");
        printf("16. Rotate Left\n");
        printf("17. Rotate Right\n");
        printf("18. Shuffle Array\n");
        printf("19. Find Second Largest\n");
        printf("20. Find Second Smallest\n");
        printf("21. Check if Array is Sorted Ascending\n");
        printf("22. Check if Array is Sorted Descending\n");
        printf("23. Find Missing Number (Consecutive)\n");
        printf("24. Find Pairs with Sum\n");
        printf("25. Find Triplets with Sum\n");
        printf("26. Remove Duplicates\n");
        printf("27. Find Mode\n");
        printf("28. Find Median\n");
        printf("29. String Array Operations\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter array size: ");
            scanf("%d", &size);
            if (size > 0 && size <= MAX_ARRAY_SIZE)
            {
                printf("Enter minimum value: ");
                scanf("%d", &min);
                printf("Enter maximum value: ");
                scanf("%d", &max);
                populate_random(arr, size, min, max);
            }
            else
            {
                printf("Invalid size.\n");
            }
            break;
        case 2:
            print_array(arr, size);
            break;
        case 3:
            printf("Max: %d\n", find_max(arr, size));
            break;
        case 4:
            printf("Min: %d\n", find_min(arr, size));
            break;
        case 5:
            printf("Average: %.2lf\n", calculate_average(arr, size));
            break;
        case 6:
            reverse_array(arr, size);
            break;
        case 7:
            sort_array_ascending(arr, size);
            break;
        case 8:
            sort_array_descending(arr, size);
            break;
        case 9:
            printf("Enter element to find: ");
            scanf("%d", &target);
            printf("Index: %d\n", find_element(arr, size, target));
            break;
        case 10:
            copy_array(arr, arr2, size);
            size2 = size;
            printf("Array copied.\n");
            break;
        case 11:
            printf("Enter element to insert: ");
            scanf("%d", &element);
            printf("Enter position: ");
            scanf("%d", &position);
            insert_element(arr, &size, element, position);
            break;
        case 12:
            printf("Enter position to delete: ");
            scanf("%d", &position);
            delete_element(arr, &size, position);
            break;
        case 13:
            printf("Enter second array size: ");
            scanf("%d", &size2);
            if (size2 > 0 && size2 <= MAX_ARRAY_SIZE)
            {
                printf("Enter second array elements:\n");
                for (int i = 0; i < size2; i++)
                {
                    scanf("%d", &arr2[i]);
                }
                concatenate_arrays(arr, size, arr2, size2, result, &result_size);
                print_array(result, result_size);
            }
            else
            {
                printf("Invalid size.\n");
            }
            break;
        case 14:
            find_duplicates(arr, size);
            break;
        case 15:
            printf("Enter element to count: ");
            scanf("%d", &target);
            count_occurrences(arr, size, target);
            break;
        case 16:
            printf("Enter rotations: ");
            scanf("%d", &rotations);
            rotate_left(arr, size, rotations);
            break;
        case 17:
            printf("Enter rotations: ");
            scanf("%d", &rotations);
            rotate_right(arr, size, rotations);
            break;
        case 18:
            shuffle_array(arr, size);
            break;
        case 19:
            find_second_largest(arr, size);
            break;
        case 20:
            find_second_smallest(arr, size);
            break;
        case 21:
            check_sorted_ascending(arr, size);
            break;
        case 22:
            check_sorted_descending(arr, size);
            break;
        case 23:
            find_missing_number(arr, size);
            break;
        case 24:
            printf("Enter sum: ");
            scanf("%d", &sum);
            find_pairs_with_sum(arr, size, sum);
            break;
        case 25:
            printf("Enter sum: ");
            scanf("%d", &sum);
            find_triplets_with_sum(arr, size, sum);
            break;
        case 26:
            remove_duplicates(arr, &size);
            break;
        case 27:
            find_mode(arr, size);
            break;
        case 28:
            find_median(arr, size);
            break;
        case 29:
            string_array_operations();
            break;
        case 0:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}

// Function definitions
void populate_random(int arr[], int size, int min, int max)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % (max - min + 1) + min;
    }
}

void print_array(int arr[], int size)
{
    if (size == 0)
    {
        printf("Array is empty.\n");
        return;
    }
    printf("Array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int find_max(int arr[], int size)
{
    if (size == 0)
        return INT_MIN;
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int find_min(int arr[], int size)
{
    if (size == 0)
        return INT_MAX;
    int min = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

double calculate_average(int arr[], int size)
{
    if (size == 0)
        return 0.0;
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum / size;
}

void reverse_array(int arr[], int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

void sort_array_ascending(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void sort_array_descending(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int find_element(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1; // Not found
}

void copy_array(int source[], int dest[], int size)
{
    for (int i = 0; i < size; i++)
    {
        dest[i] = source[i];
    }
}

void insert_element(int arr[], int *size, int element, int position)
{
    if (*size >= MAX_ARRAY_SIZE || position < 0 || position > *size)
    {
        printf("Invalid insertion.\n");
        return;
    }
    for (int i = *size; i > position; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    (*size)++;
}

void delete_element(int arr[], int *size, int position)
{
    if (*size == 0 || position < 0 || position >= *size)
    {
        printf("Invalid deletion.\n");
        return;
    }
    for (int i = position; i < *size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

void concatenate_arrays(int arr1[], int size1, int arr2[], int size2, int result[], int *result_size)
{
    for (int i = 0; i < size1; i++)
    {
        result[i] = arr1[i];
    }
    for (int i = 0; i < size2; i++)
    {
        result[size1 + i] = arr2[i];
    }
    *result_size = size1 + size2;
}

void find_duplicates(int arr[], int size)
{
    printf("Duplicates: ");
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                printf("%d ", arr[i]);
                break;
            }
        }
    }
    printf("\n");
}

void count_occurrences(int arr[], int size, int target)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            count++;
        }
    }
    printf("Occurrences of %d: %d\n", target, count);
}

void rotate_left(int arr[], int size, int rotations)
{
    rotations %= size;
    for (int i = 0; i < rotations; i++)
    {
        int temp = arr[0];
        for (int j = 0; j < size - 1; j++)
        {
            arr[j] = arr[j + 1];
        }
        arr[size - 1] = temp;
    }
}

void rotate_right(int arr[], int size, int rotations)
{
    rotations %= size;
    for (int i = 0; i < rotations; i++)
    {
        int temp = arr[size - 1];
        for (int j = size - 1; j > 0; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[0] = temp;
    }
}

void swap_elements(int arr[], int index1, int index2)
{
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

void shuffle_array(int arr[], int size)
{
    for (int i = size - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        swap_elements(arr, i, j);
    }
}

void find_second_largest(int arr[], int size)
{
    if (size < 2)
    {
        printf("Array size too small.\n");
        return;
    }
    int max1 = INT_MIN, max2 = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max1)
        {
            max2 = max1;
            max1 = arr[i];
        }
        else if (arr[i] > max2 && arr[i] != max1)
        {
            max2 = arr[i];
        }
    }
    if (max2 == INT_MIN)
    {
        printf("No second largest element.\n");
    }
    else
    {
        printf("Second largest: %d\n", max2);
    }
}

void find_second_smallest(int arr[], int size)
{
    if (size < 2)
    {
        printf("Array size too small.\n");
        return;
    }
    int min1 = INT_MAX, min2 = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min1)
        {
            min2 = min1;
            min1 = arr[i];
        }
        else if (arr[i] < min2 && arr[i] != min1)
        {
            min2 = arr[i];
        }
    }
    if (min2 == INT_MAX)
    {
        printf("No second smallest element.\n");
    }
    else
    {
        printf("Second smallest: %d\n", min2);
    }
}

void check_sorted_ascending(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            printf("Array is not sorted in ascending order.\n");
            return;
        }
    }
    printf("Array is sorted in ascending order.\n");
}

void check_sorted_descending(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            printf("Array is not sorted in descending order.\n");
            return;
        }
    }
    printf("Array is sorted in descending order.\n");
}

void find_missing_number(int arr[], int size)
{
    if (size < 2)
    {
        printf("Array size too small.\n");
        return;
    }
    sort_array_ascending(arr, size); // Ensure the array is sorted
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i + 1] - arr[i] > 1)
        {
            printf("Missing number: %d\n", arr[i] + 1);
            return;
        }
    }
    printf("No missing number (consecutive).\n");
}

void find_pairs_with_sum(int arr[], int size, int sum)
{
    printf("Pairs with sum %d:\n", sum);
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] + arr[j] == sum)
            {
                printf("(%d, %d)\n", arr[i], arr[j]);
            }
        }
    }
}

void find_triplets_with_sum(int arr[], int size, int sum)
{
    printf("Triplets with sum %d:\n", sum);
    for (int i = 0; i < size - 2; i++)
    {
        for (int j = i + 1; j < size - 1; j++)
        {
            for (int k = j + 1; k < size; k++)
            {
                if (arr[i] + arr[j] + arr[k] == sum)
                {
                    printf("(%d, %d, %d)\n", arr[i], arr[j], arr[k]);
                }
            }
        }
    }
}

void remove_duplicates(int arr[], int *size)
{
    if (*size == 0)
        return;
    int j = 0;
    for (int i = 0; i < *size - 1; i++)
    {
        if (arr[i] != arr[i + 1])
        {
            arr[j++] = arr[i];
        }
    }
    arr[j++] = arr[*size - 1];
    *size = j;
}

void find_mode(int arr[], int size)
{
    if (size == 0)
        return;
    int maxCount = 0, mode = arr[0];
    for (int i = 0; i < size; i++)
    {
        int count = 0;
        for (int j = 0; j < size; j++)
        {
            if (arr[j] == arr[i])
            {
                count++;
            }
        }
        if (count > maxCount)
        {
            maxCount = count;
            mode = arr[i];
        }
    }
    printf("Mode: %d (occurs %d times)\n", mode, maxCount);
}

void find_median(int arr[], int size)
{
    if (size == 0)
        return;
    sort_array_ascending(arr, size);
    if (size % 2 == 0)
    {
        printf("Median: %.2lf\n", (double)(arr[size / 2 - 1] + arr[size / 2]) / 2);
    }
    else
    {
        printf("Median: %d\n", arr[size / 2]);
    }
}

void string_array_operations()
{
    char strings[10][50];
    int string_count = 0;
    int choice;
    char temp_string[50];
    int found_index;

    while (1)
    {
        printf("\nString Array Operations:\n");
        printf("1. Add String\n");
        printf("2. Print Strings\n");
        printf("3. Find String\n");
        printf("4. Remove String\n");
        printf("0. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (string_count < 10)
            {
                printf("Enter string to add: ");
                scanf(" %[^\n]s", strings[string_count]);
                string_count++;
            }
            else
            {
                printf("Array is full.\n");
            }
            break;
        case 2:
            printf("Strings:\n");
            for (int i = 0; i < string_count; i++)
            {
                printf("%s\n", strings[i]);
            }
            break;
        case 3:
            printf("Enter string to find: ");
            scanf(" %[^\n]s", temp_string);
            found_index = -1;
            for (int i = 0; i < string_count; i++)
            {
                if (strcmp(strings[i], temp_string) == 0)
                {
                    found_index = i;
                    break;
                }
            }
            if (found_index != -1)
            {
                printf("String found at index: %d\n", found_index);
            }
            else
            {
                printf("String not found.\n");
            }
            break;
        case 4:
            printf("Enter string to remove: ");
            scanf(" %[^\n]s", temp_string);
            found_index = -1;
            for (int i = 0; i < string_count; i++)
            {
                if (strcmp(strings[i], temp_string) == 0)
                {
                    found_index = i;
                    break;
                }
            }
            if (found_index != -1)
            {
                for (int i = found_index; i < string_count - 1; i++)
                {
                    strcpy(strings[i], strings[i + 1]);
                }
                string_count--;
                printf("String removed.\n");
            }
            else
            {
                printf("String not found.\n");
            }
            break;
        case 0:
            return;
        default:
            printf("Invalid choice.\n");
        }
    }
}