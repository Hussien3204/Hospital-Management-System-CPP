#pragma once
#include "Patient.h"
#include <vector>
using namespace std;

/**
 * @file HospitalUI.h
 * @brief Presentation Layer handling console UI, menus, and user interactions.
 */

// Helper display functions
void showMainMenu();
void printPatientCard(Patient p);
void printAllPatients(const vector<Patient>& list);

// Menu action handlers
void handleAddPatient(vector<Patient>& list);
void handleEmergencyQueue(vector<Patient>& list);
void handleSearchPatient(const vector<Patient>& list);
void handleUpdatePatient(vector<Patient>& list);
void handleDeletePatient(vector<Patient>& list);

// Main system controller loop
void startHospitalSystem();

