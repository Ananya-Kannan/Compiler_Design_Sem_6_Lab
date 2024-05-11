 #include <stdio.h>
 #include <stdlib.h>
 // Define the node structure for the syntax tree
 typedef struct Node {
 	char data;
 	struct Node *left;
 	struct Node *right;
 } Node;
 // Function to create a new node
 Node* createNode(char data) {
 	Node* newNode = (Node*)malloc(sizeof(Node));
 	newNode->data = data;
 	newNode->left = NULL;
 	newNode->right = NULL;
 	return newNode;
 }
// Function to traverse the syntax tree and perform arithmetic operations
int evaluateExpression(Node* root) {
 	if (root == NULL) return 0;
 	// If the node is a number, return its value
 	if (root->data >= '0' && root->data <= '9') {
 		return root->data- '0';
 	}
	// Recursively evaluate left and right subtrees
 	int leftValue = evaluateExpression(root->left);
 	int rightValue = evaluateExpression(root->right);
 	// Perform arithmetic operations based on the operator
 	switch (root->data) {
 		case '+':
			return leftValue + rightValue;
 		case '-':
 			return leftValue- rightValue;
 		case '*':
 			return leftValue * rightValue;
 		case '/':
 			if (rightValue != 0) {
 				return leftValue / rightValue;
 			} else {
 				printf("Error: Division by zero\n");
 				exit(EXIT_FAILURE);
 			}
 		default:
 			printf("Error: Invalid operator\n");
 			exit(EXIT_FAILURE);
 	}
}
int main() {
	// Construct the syntax tree for the expression "((3+2)*5)"
 	Node* root = createNode('*');
 	root->left = createNode('+');
 	root->right = createNode('5');
 	root->left->left = createNode('3');
 	root->left->right = createNode('2');
 	// Evaluate the expression and print the result
 	int result = evaluateExpression(root);
 	printf("Result: %d\n", result);
 	// Free memory allocated for the syntax tree
 	free(root->left->left);
 	free(root->left->right);
 	free(root->left);
 	free(root->right);
 	free(root);
 	return 0;
}
