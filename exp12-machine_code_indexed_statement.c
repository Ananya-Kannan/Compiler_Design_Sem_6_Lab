#include <stdio.h>
 #include <stdint.h>
 // Function to generate machine code for indexed assignment statement
 void generateMachineCode() {
 // Define array and index variables
 uint32_t array[10] = {0}; // Array of 10 integers initialized to 0
 uint32_t index = 3; // Index variable with value 3
 // Assign a value to an array element at the given index
 array[index] = 42;
 // Output the machine code for the indexed assignment statement
 printf("Machine code for indexed assignment statement:\n");
 printf("lw $t0, %u($zero)\n", index * sizeof(uint32_t)); // Load index into $t0
 printf("li $t1, 42\n"); // Load value 42 into $t1
 printf("la $t2, array\n"); // Load base address of array into $t2
 printf("sw $t1, 0($t2, $t0)\n"); // Store value at indexed location in the array
 }
 int main() {
 generateMachineCode(); // Generate machine code for indexed assignment statement
 return 0;
 }
