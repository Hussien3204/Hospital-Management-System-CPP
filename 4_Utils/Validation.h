#pragma once
#include <string>
using namespace std;

/**
 * @file Validation.h
 * @brief Input validation utility layer to ensure safe and clean user inputs.
 */

// Reads a valid positive integer (> 0) and prevents cin stream crashes
int readValidInt(string prompt);

// Reads an integer guaranteed to be within [minVal, maxVal]
int readIntInRange(string prompt, int minVal, int maxVal);

// Reads a non-empty string and blocks the reserved file delimiter ("&&&&")
string readValidString(string prompt);

