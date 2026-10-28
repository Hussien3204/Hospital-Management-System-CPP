#include "Validation.h"
#include <iostream>
using namespace std;

/**
 * @brief Prompts the user and reads a strictly positive integer.
 * Handles non-numeric inputs safely by clearing the input buffer.
 */
int readValidInt(string prompt) {
    int number = 0;

    while (true) {
        cout << prompt;
        cin >> number;

        // Check for stream failure (e.g., letters entered) or non-positive values
        if (cin.fail() || number <= 0) {
            cout << "Invalid input! Please enter a positive number." << endl;
            cin.clear();               // Reset stream error flags
            cin.ignore(10000, '\n');   // Discard invalid characters from buffer
        } 
        else {
            cin.ignore(10000, '\n');   // Clean leftover newline for subsequent getline() calls
            return number;
        }
    }
}

/**
 * @brief Reads an integer and ensures it falls within a specified inclusive range.
 */
int readIntInRange(string prompt, int minVal, int maxVal) {
    while (true) {
        int number = readValidInt(prompt);

        if (number >= minVal && number <= maxVal) {
            return number;
        } 
        else {
            cout << "Error: Number must be between " << minVal << " and " << maxVal << "." << endl;
        }
    }
}

/**
 * @brief Reads a full line of text, ensuring it is neither empty nor contains the file delimiter.
 */
string readValidString(string prompt) {
    string text = "";

    while (true) {
        cout << prompt;
        getline(cin, text);

        if (text.empty()) {
            cout << "Error: The field cannot be empty! Please enter valid text." << endl;
        } 
        else if (text.find("&&&&") != string::npos) {
            cout << "Security Error: Input cannot contain the reserved sequence '&&&&'!" << endl;
        } 
        else {
            return text;
        }
    }
}

