#include <iostream>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

// Node for syntax tree
struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char data) : data(data), left(NULL), right(NULL) {}
};

// Function to check if a character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Function to construct syntax tree from postfix expression
Node* constructSyntaxTree(const string& postfix) {
    stack<Node*> stack;

    for (size_t i = 0; i < postfix.size(); ++i) {
        char c = postfix[i];
        if (isalnum(c)) {
            stack.push(new Node(c));
        } else if (isOperator(c)) {
            Node* rightOperand = stack.top();
            stack.pop();
            Node* leftOperand = stack.top();
            stack.pop();

            Node* newNode = new Node(c);
            newNode->left = leftOperand;
            newNode->right = rightOperand;
            stack.push(newNode);
        }
    }

    return stack.top();
}

// Function to perform arithmetic operation based on operator
int performOperation(char operation, int operand1, int operand2) {
    switch (operation) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
        default:
            cerr << "Invalid operator!" << endl;
            return 0;
    }
}

// Function to evaluate syntax tree recursively
int evaluateSyntaxTree(Node* root) {
    if (!root)
        return 0;

    if (isalnum(root->data)) {
        return root->data - '0'; // Convert char to int
    }

    int leftValue = evaluateSyntaxTree(root->left);
    int rightValue = evaluateSyntaxTree(root->right);

    return performOperation(root->data, leftValue, rightValue);
}

int main() {
    string postfixExpression;
    cout << "Enter a postfix expression: ";
    cin >> postfixExpression;

    Node* syntaxTreeRoot = constructSyntaxTree(postfixExpression);

    int result = evaluateSyntaxTree(syntaxTreeRoot);
    cout << "Result: " << result << endl;

    return 0;
}

