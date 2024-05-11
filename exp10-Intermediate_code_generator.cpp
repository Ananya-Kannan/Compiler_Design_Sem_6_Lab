#include <stdio.h>
#include <stdlib.h>


// Global variable for label index
int labelIndex = 1;

// Function to generate unique labels
char* generateLabel() {
    char* label = (char*)malloc(10 * sizeof(char)); // Dynamically allocate memory for label
    sprintf(label, "L%d", labelIndex++);
    return label;
}


int main() {
    // Example If statement
    char* ifCondition = "x < y";
    char* ifTrueLabel = generateLabel(); // Generate label for true branch
    char* ifFalseLabel = generateLabel(); // Generate label for false branch
    printf("Intermediate code for If-Else:\n");
    printf("IF %s GOTO %s ELSE GOTO %s\n", ifCondition, ifTrueLabel, ifFalseLabel);
    printf("%s: printf(\"x is less than y\\n\");\n", ifTrueLabel); // Output code for true branch
    printf("%s: printf(\"x is not less than y\\n\");\n", ifFalseLabel); // Output code for false branch

    // Example While loop
    char* whileStartLabel = generateLabel(); // Generate label for loop start
    char* whileBodyLabel = generateLabel(); // Generate label for loop body 
    char* whileEndLabel = generateLabel(); // Generate label for loop end

	printf("\n\nIntermediate code for While loop:\n");
    printf("%s:\n", whileStartLabel); // Output label for loop body 1
    printf("IF i < 5 GOTO %s ELSE GOTO %s\n", whileBodyLabel, whileEndLabel); // Check condition for loop
    printf("%s: printf(\"i: %%d\\n\", i);\n", whileBodyLabel); // Output code for loop body
    printf("i++;\n"); // Increment loop counter
    printf("GOTO %s;\n", whileStartLabel); // Jump back to loop start
    printf("%s:\n", whileEndLabel); // Output label for loop end

    // Free dynamically allocated memory for labels
    free(ifTrueLabel);
    free(ifFalseLabel);
    free(whileStartLabel);
    free(whileBodyLabel);
    free(whileEndLabel);

    return 0;
}
