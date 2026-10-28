#pragma once
#include "Patient.h"
#include <vector>
#include <string>
using namespace std;

/**
 * @file HospitalLogic.h
 * @brief Business Logic Layer containing core algorithms (Search, Sort, CRUD).
 */

// 1. Linear Search Algorithm: returns patient index in vector, or -1 if not found
int findPatientIndexById(const vector<Patient>& list, int targetId);

// 2. Adds a new patient if ID is unique; returns true on success, false if ID exists
bool addPatient(vector<Patient>& list, Patient newPatient);

// 3. Bubble Sort Algorithm: sorts patients descending by Severity (5 down to 1)
void sortPatientsBySeverity(vector<Patient>& list);

// 4. Updates patient severity and medical diagnosis by ID; returns true if found
bool updatePatient(vector<Patient>& list, int targetId, int newSeverity, string newMedical);

// 5. Deletes a patient record by ID; returns true if found and deleted
bool deletePatient(vector<Patient>& list, int targetId);

