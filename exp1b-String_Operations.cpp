#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

// Function prototypes
void displayMenu();
void reverseString(char[]);
void concatenateStrings(char[], char[]);
void findStringLength(char[]);
void compareStrings(char[], char[]);
void findFirstOccurrence(char[], char[]);
void countSubstringOccurrences(char[], char[]);
void findWordCount(char[]);
void separateCounts(char[]);

int main() {
    char str1[100], str2[100];
    int choice;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter a string: ";
                cin.ignore();
                cin.getline(str1, sizeof(str1));
                reverseString(str1);
                break;
            case 2:
                cout << "Enter the first string: ";
                cin.ignore();
                cin.getline(str1, sizeof(str1));
                cout << "Enter the second string: ";
                cin.getline(str2, sizeof(str2));
                concatenateStrings(str1, str2);
                break;
            case 3:
                cout << "Enter a string: ";
                cin.ignore();
                cin.getline(str1, sizeof(str1));
                findStringLength(str1);
                break;
            case 4:
                cout << "Enter the first string: ";
                cin.ignore();
                cin.getline(str1, sizeof(str1));
                cout << "Enter the second string: ";
                cin.getline(str2, sizeof(str2));
                compareStrings(str1, str2);
                break;
            case 5:
                cout << "Enter the main string: ";
                cin.ignore();
                cin.getline(str1, sizeof(str1));
                cout << "Enter the substring to find: ";
                cin.getline(str2, sizeof(str2));
                findFirstOccurrence(str1, str2);
                break;
            case 6:
                cout << "Enter the main string: ";
                cin.ignore();
                cin.getline(str1, sizeof(str1));
                cout << "Enter the substring to count: ";
                cin.getline(str2, sizeof(str2));
                countSubstringOccurrences(str1, str2);
                break;
            case 7:
                cout << "Enter a string: ";
                cin.ignore();
                cin.getline(str1, sizeof(str1));
                findWordCount(str1);
                break;
            case 8:
                cout << "Enter a string: ";
                cin.ignore();
                cin.getline(str1, sizeof(str1));
                separateCounts(str1);
                break;
            case 9:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while(choice != 9);

    return 0;
}

void displayMenu() {
    cout << "Menu:\n";
    cout << "1. Reverse String\n";
    cout << "2. Concatenate Strings\n";
    cout << "3. Find String Length\n";
    cout << "4. Compare Strings\n";
    cout << "5. Find First Occurrence Position\n";
    cout << "6. Count Substring Occurrences\n";
    cout << "7. Find Word Count\n";
    cout << "8. Separate Numbers, Special Characters, and Alphabets\n";
    cout << "9. Exit\n";
}

void reverseString(char str[]) {
    cout << "Reversed String: ";
    for (int i = strlen(str) - 1; i >= 0; --i) {
        cout << str[i];
    }
    cout << endl;
}

void concatenateStrings(char str1[], char str2[]) {
    strcat(str1, str2);
    cout << "Concatenated String: " << str1 << endl;
}

void findStringLength(char str[]) {
    cout << "String Length: " << strlen(str) << endl;
}

void compareStrings(char str1[], char str2[]) {
    int result = strcmp(str1, str2);
    if (result == 0) {
        cout << "Strings are equal.\n";
    } else if (result < 0) {
        cout << "String 1 is less than String 2.\n";
    } else {
        cout << "String 1 is greater than String 2.\n";
    }
}

void findFirstOccurrence(char mainStr[], char subStr[]) {
    char* position = strstr(mainStr, subStr);
    if (position != NULL) {
        int index = position - mainStr;
        cout << "First Occurrence Position: " << index << endl;
    } else {
        cout << "Substring not found in the main string.\n";
    }
}

void countSubstringOccurrences(char mainStr[], char subStr[]) {
    int count = 0;
    char* position = mainStr;
    while ((position = strstr(position, subStr)) != NULL) {
        ++count;
        ++position;
    }
    cout << "Substring Occurrences: " << count << endl;
}

void findWordCount(char str[]) {
    int wordCount = 0;
    bool inWord = false;

    for (int i = 0; i < strlen(str); ++i) {
        if (isalpha(str[i])) {
            if (!inWord) {
                ++wordCount;
                inWord = true;
            }
        } else {
            inWord = false;
        }
    }

    cout << "Word Count: " << wordCount << endl;
}

void separateCounts(char str[]) {
    int numCount = 0, specialCount = 0, alphaCount = 0;

    for (int i = 0; i < strlen(str); ++i) {
        if (isdigit(str[i])) {
            ++numCount;
        } else if (isalpha(str[i])) {
            ++alphaCount;
        } else {
            ++specialCount;
        }
    }

    cout << "Number Count: " << numCount << endl;
    cout << "Alphabet Count: " << alphaCount << endl;
    cout << "Special Character Count: " << specialCount << endl;
}

