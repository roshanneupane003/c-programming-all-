#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure definitions
struct Student
{
    int id;
    char name[50];
    float gpa;
};

struct Address
{
    char street[100];
    char city[50];
    char state[30];
    int zip;
};

struct Employee
{
    int empId;
    char empName[50];
    struct Address empAddress; // Nested structure
    double salary;
};

union Data
{
    int i;
    float f;
    char str[20];
};

// Function Prototypes
void basicStructureExample();
void structureArraysExample();
void nestedStructuresExample();
void structuresAndPointersExample();
void structuresAsFunctionArguments();
void printStudent(struct Student s); // Moved here for proper scoping
void structuresAndDynamicMemory();
void bitFieldsExample();
void unionsExample();
void structuresWithFunctionPointers();
void selfReferentialStructures();
void structurePaddingAndPacking();
void anonymousStructuresUnions();
void flexibleArrayMembers();

int main()
{
    printf("--- Basic Structure Example ---\n");
    basicStructureExample();

    printf("\n--- Structure Arrays Example ---\n");
    structureArraysExample();

    printf("\n--- Nested Structures Example ---\n");
    nestedStructuresExample();

    printf("\n--- Structures and Pointers Example ---\n");
    structuresAndPointersExample();

    printf("\n--- Structures as Function Arguments ---\n");
    structuresAsFunctionArguments();

    printf("\n--- Structures and Dynamic Memory ---\n");
    structuresAndDynamicMemory();

    printf("\n--- Bit Fields Example ---\n");
    bitFieldsExample();

    printf("\n--- Unions Example ---\n");
    unionsExample();

    printf("\n--- Structures with Function Pointers ---\n");
    structuresWithFunctionPointers();

    printf("\n--- Self-Referential Structures ---\n");
    selfReferentialStructures();

    printf("\n--- Structure Padding and Packing ---\n");
    structurePaddingAndPacking();

    printf("\n--- Anonymous Structures and Unions ---\n");
    anonymousStructuresUnions();

    printf("\n--- Flexible Array Members ---\n");
    flexibleArrayMembers();

    return 0;
}

// Function Definitions

void basicStructureExample()
{
    struct Student student1 = {101, "Alice", 3.8};
    printf("Student ID: %d, Name: %s, GPA: %.2f\n", student1.id, student1.name, student1.gpa);
}

void structureArraysExample()
{
    struct Student students[3] = {
        {102, "Bob", 3.5},
        {103, "Charlie", 3.9},
        {104, "David", 3.2}};

    for (int i = 0; i < 3; i++)
    {
        printf("Student %d - ID: %d, Name: %s, GPA: %.2f\n", i + 1, students[i].id, students[i].name, students[i].gpa);
    }
}

void nestedStructuresExample()
{
    struct Employee employee1 = {
        201, "Eve", {"123 Main St", "Anytown", "CA", 91234}, 60000.0};

    printf("Employee ID: %d, Name: %s, City: %s, Salary: %.2lf\n",
           employee1.empId, employee1.empName, employee1.empAddress.city, employee1.salary);
}

void structuresAndPointersExample()
{
    struct Student student2 = {105, "Frank", 3.7};
    struct Student *ptr = &student2;

    printf("Student ID: %d, Name: %s, GPA: %.2f\n", ptr->id, ptr->name, ptr->gpa);
    ptr->gpa = 4.0;
    printf("Modified GPA: %.2f\n", student2.gpa);
}

void printStudent(struct Student s)
{
    printf("Student ID: %d, Name: %s, GPA: %.2f\n", s.id, s.name, s.gpa);
}

void structuresAsFunctionArguments()
{
    struct Student student3 = {106, "Grace", 3.6};
    printStudent(student3);
}

void structuresAndDynamicMemory()
{
    struct Student *student4 = (struct Student *)malloc(sizeof(struct Student));
    if (student4 == NULL)
    {
        perror("malloc failed");
        return;
    }
    student4->id = 107;
    strcpy(student4->name, "Hannah");
    student4->gpa = 3.9;

    printf("Dynamically allocated student: ID: %d, Name: %s, GPA: %.2f\n",
           student4->id, student4->name, student4->gpa);

    free(student4);
}

struct BitField
{
    unsigned int isReady : 1;
    unsigned int color : 3;
    unsigned int fontSize : 4;
};

void bitFieldsExample()
{
    struct BitField bf = {1, 5, 10};
    printf("Is Ready: %u, Color: %u, Font Size: %u\n", bf.isReady, bf.color, bf.fontSize);
}

void unionsExample()
{
    union Data data;
    data.i = 10;
    printf("Integer: %d\n", data.i);

    data.f = 3.14;
    printf("Float: %.2f\n", data.f);

    strcpy(data.str, "Hello");
    printf("String: %s\n", data.str);
}

struct Operation
{
    int (*func)(int, int);
};

int add(int a, int b) { return a + b; }

void structuresWithFunctionPointers()
{
    struct Operation op = {add};
    printf("Result: %d\n", op.func(5, 3));
}

struct Node
{
    int data;
    struct Node *next;
};

void selfReferentialStructures()
{
    struct Node node1 = {10, NULL};
    struct Node node2 = {20, NULL};
    node1.next = &node2;
    printf("Node 1 data: %d, Node 2 data: %d\n", node1.data, node1.next->data);
}

struct PackedStruct
{
    char a;
    int b;
    char c;
} __attribute__((packed));

void structurePaddingAndPacking()
{
    printf("Size of normal struct: %zu\n", sizeof(struct Employee));
    printf("Size of packed struct: %zu\n", sizeof(struct PackedStruct));
}

void anonymousStructuresUnions()
{
    struct
    {
        int x;
        float y;
    } point = {5, 2.5};

    union
    {
        int a;
        char b;
    } myUnion;

    myUnion.a = 10;
    printf("Anonymous struct: x=%d, y=%.2f\n", point.x, point.y);
    printf("Anonymous union: a=%d, b=%c\n", myUnion.a, myUnion.a);
}

struct FlexibleArray
{
    int count;
    int data[]; // Flexible array member
};

void flexibleArrayMembers()
{
    int numElements = 5;
    struct FlexibleArray *flexArray = (struct FlexibleArray *)malloc(sizeof(struct FlexibleArray) + numElements * sizeof(int));
    if (flexArray == NULL)
    {
        perror("malloc failed");
        return;
    }

    flexArray->count = numElements;
    for (int i = 0; i < numElements; i++)
    {
        flexArray->data[i] = i * 10;
    }

    for (int i = 0; i < numElements; i++)
    {
        printf("FlexArray data[%d] = %d\n", i, flexArray->data[i]);
    }
    free(flexArray);
}