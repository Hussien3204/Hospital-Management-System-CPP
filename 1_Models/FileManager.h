#pragma once
#include "Patient.h"
#include <vector>
#include <string>
using namespace std;

/**
 * @file FileManager.h
 * @brief Data Access Layer responsible for file I/O and string serialization.
 */

// 1. Converts a Patient struct into a single delimited string line
string patientToLine(Patient p, string delimiter = "&&&&");

// 2. Parses a delimited string line back into a Patient struct
Patient lineToPatient(string line, string delimiter = "&&&&");

// 3. Loads all patient records from the file into the memory vector
void loadFromFile(vector<Patient>& list, string fileName = "patients.txt");

// 4. Overwrites the file with the current vector data (used after update/delete)
void saveToFile(const vector<Patient>& list, string fileName = "patients.txt");

// 5. Appends a single new patient to the end of the file
void appendToFile(Patient p, string fileName = "patients.txt");

