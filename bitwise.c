#include <stdio.h>
#include <stdint.h> // For portable integer types

// Function prototypes
void bitwiseAND();
void bitwiseOR();
void bitwiseXOR();
void bitwiseNOT();
void leftShift();
void rightShift();
void bitMasking();
void bitSettingAndClearing();
void bitToggling();
void bitCounting();
void bitReversal();
void bitFieldManipulation();
void bitwiseOperationsOnStructures();
void bitwiseOperationsForDataCompression();
void bitwiseOperationsForCryptography();
void bitwiseOperationsForNetworkProtocols();
void bitwiseOperationsForHardwareControl();

int main()
{
    printf("--- Bitwise AND ---\n");
    bitwiseAND();

    printf("\n--- Bitwise OR ---\n");
    bitwiseOR();

    printf("\n--- Bitwise XOR ---\n");
    bitwiseXOR();

    printf("\n--- Bitwise NOT ---\n");
    bitwiseNOT();

    printf("\n--- Left Shift ---\n");
    leftShift();

    printf("\n--- Right Shift ---\n");
    rightShift();

    printf("\n--- Bit Masking ---\n");
    bitMasking();

    printf("\n--- Bit Setting and Clearing ---\n");
    bitSettingAndClearing();

    printf("\n--- Bit Toggling ---\n");
    bitToggling();

    printf("\n--- Bit Counting ---\n");
    bitCounting();

    printf("\n--- Bit Reversal ---\n");
    bitReversal();

    printf("\n--- Bit Field Manipulation ---\n");
    bitFieldManipulation();

    printf("\n--- Bitwise Operations on Structures ---\n");
    bitwiseOperationsOnStructures();

    printf("\n--- Bitwise Operations for Data Compression (Simulated) ---\n");
    bitwiseOperationsForDataCompression();

    printf("\n--- Bitwise Operations for Cryptography (Simulated) ---\n");
    bitwiseOperationsForCryptography();

    printf("\n--- Bitwise Operations for Network Protocols (Simulated) ---\n");
    bitwiseOperationsForNetworkProtocols();

    printf("\n--- Bitwise Operations for Hardware Control (Simulated) ---\n");
    bitwiseOperationsForHardwareControl();

    return 0;
}

void bitwiseAND()
{
    uint8_t a = 0b11001010;
    uint8_t b = 0b10100110;
    uint8_t result = a & b;
    printf("a & b = 0x%X\n", result);
}

void bitwiseOR()
{
    uint8_t a = 0b11001010;
    uint8_t b = 0b10100110;
    uint8_t result = a | b;
    printf("a | b = 0x%X\n", result);
}

void bitwiseXOR()
{
    uint8_t a = 0b11001010;
    uint8_t b = 0b10100110;
    uint8_t result = a ^ b;
    printf("a ^ b = 0x%X\n", result);
}

void bitwiseNOT()
{
    uint8_t a = 0b11001010;
    uint8_t result = ~a;
    printf("~a = 0x%X\n", result);
}

void leftShift()
{
    uint8_t a = 0b00000001;
    uint8_t result = a << 3;
    printf("a << 3 = 0x%X\n", result);
}

void rightShift()
{
    uint8_t a = 0b10000000;
    uint8_t result = a >> 3;
    printf("a >> 3 = 0x%X\n", result);
}

void bitMasking()
{
    uint8_t data = 0b11011011;
    uint8_t mask = 0b00001111;
    uint8_t result = data & mask;
    printf("data & mask = 0x%X\n", result);
}

void bitSettingAndClearing()
{
    uint8_t data = 0b10101010;
    uint8_t mask = 0b00000100;
    uint8_t set = data | mask;
    uint8_t clear = data & (~mask);
    printf("Set: 0x%X, Clear: 0x%X\n", set, clear);
}

void bitToggling()
{
    uint8_t data = 0b10101010;
    uint8_t mask = 0b00000100;
    uint8_t result = data ^ mask;
    printf("Toggled: 0x%X\n", result);
}

void bitCounting()
{
    uint8_t data = 0b11011011;
    uint8_t count = 0;
    for (int i = 0; i < 8; i++)
    {
        if ((data >> i) & 1)
        {
            count++;
        }
    }
    printf("Bit count: %u\n", count);
}

void bitReversal()
{
    uint8_t data = 0b11011011;
    uint8_t result = 0;
    for (int i = 0; i < 8; i++)
    {
        if ((data >> i) & 1)
        {
            result |= (1 << (7 - i));
        }
    }
    printf("Reversed: 0x%X\n", result);
}

struct BitFields
{
    uint8_t field1 : 3;
    uint8_t field2 : 5;
};

void bitFieldManipulation()
{
    struct BitFields bf;
    bf.field1 = 5;
    bf.field2 = 20;
    printf("Field1: %u, Field2: %u\n", bf.field1, bf.field2);
}

struct Data
{
    uint8_t flags;
    uint16_t value;
};

void bitwiseOperationsOnStructures()
{
    struct Data data;
    data.flags = 0b00000001;
    data.value = 0x1234;
    printf("Flags: 0x%X, Value: 0x%X\n", data.flags, data.value);
}

void bitwiseOperationsForDataCompression()
{
    // Simulated data compression using bitwise operations.
    printf("Simulating data compression.\n");
}

void bitwiseOperationsForCryptography()
{
    // Simulated cryptography using bitwise operations.
    printf("Simulating cryptography.\n");
}

void bitwiseOperationsForNetworkProtocols()
{
    // Simulated network protocol parsing using bitwise operations.
    printf("Simulating network protocol parsing.\n");
}

void bitwiseOperationsForHardwareControl()
{
    // Simulated hardware register manipulation using bitwise operations.
    printf("Simulating hardware control.\n");
}