#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Function to generate new label
string newLabel() {
    static int labelCounter = 0;
    stringstream ss;
    ss << "L" << labelCounter++;
    return ss.str();
}

// Function to generate intermediate code for if construct
string generateIf(string E, string S1_CODE, string S_NEXT) {
    string TRUE = newLabel();
    string FALSE = S_NEXT;
    string code = E + " TRUE: " + TRUE + "\n" +
                 " FALSE: " + FALSE + "\n" +
                 S1_CODE + "\n" +
                 TRUE + ": \n";
    return code;
}

// Function to generate intermediate code for if-else construct
string generateIfElse(string E, string S1_CODE, string S2_CODE, string S_NEXT) {
    string TRUE = newLabel();
    string FALSE = newLabel();
    string code = E + " TRUE: " + TRUE + "\n" +
                 " FALSE: " + FALSE + "\n" +
                 S1_CODE + "\n" +
                 "goto " + S_NEXT + "\n" +
                 FALSE + ": \n" +
                 S2_CODE + "\n";
    return code;
}

// Function to generate intermediate code for while construct
string generateWhile(string E, string S1_CODE) {
    string BEGIN = newLabel();
    string TRUE = newLabel();
    string NEXT = newLabel();
    string code = BEGIN + ": \n" +
                 E + " TRUE: " + TRUE + "\n" +
                 " FALSE: " + NEXT + "\n" +
                 S1_CODE + "\n" +
                 "goto " + BEGIN + "\n" +
                 NEXT + ": \n";
    return code;
}

int main() {
    // Example usage:
    string E = "if (condition)";
    string S1_CODE = "cout << \"Condition is true\";";
    string S2_CODE = "cout << \"Condition is false\";";
    string S_NEXT = "end;";
    
    // Generate intermediate code for if-else construct
    string ifElseCode = generateIfElse(E, S1_CODE, S2_CODE, S_NEXT);
    cout << "Intermediate code for if-else:\n" << ifElseCode << endl;
    
    // Generate intermediate code for if construct
    string ifCode = generateIf(E, S1_CODE, S_NEXT);
    cout << "Intermediate code for if:\n" << ifCode << endl;
    
    // Generate intermediate code for while construct
    string whileCode = generateWhile(E, S1_CODE);
    cout << "Intermediate code for while:\n" << whileCode << endl;
    
    return 0;
}

