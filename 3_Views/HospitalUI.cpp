#include "HospitalUI.h"
#include "Validation.h"
#include "HospitalLogic.h"
#include "FileManager.h"
#include <iostream>
using namespace std;

/**
 * @brief Displays the main console menu options.
 */
void showMainMenu() {
    cout << "\n========================================\n";
    cout << "       HOSPITAL MANAGEMENT SYSTEM       \n";
    cout << "========================================\n";
    cout << "1. Add New Patient\n";
    cout << "2. Display Emergency Queue (By Severity)\n";
    cout << "3. Search Patient by ID\n";
    cout << "4. Update Patient Condition\n";
    cout << "5. Discharge (Delete) Patient\n";
    cout << "6. Exit\n";
    cout << "========================================\n";
}

/**
 * @brief Formats and prints a single patient record card.
 */
void printPatientCard(Patient p) {
    cout << "----------------------------------------\n";
    cout << "ID        : " << p.ID << "\n";
    cout << "Full Name : " << p.FullName << "\n";
    cout << "Age       : " << p.Age << "\n";
    cout << "Severity  : " << p.Severity << " / 5\n";
    cout << "Diagnosis : " << p.medical << "\n";
    cout << "----------------------------------------\n";
}

/**
 * @brief Iterates through the vector and prints all patient records.
 */
void printAllPatients(const vector<Patient>& list) {
    if (list.empty()) {
        cout << "\n[!] No patients currently registered.\n";
        return;
    }
    cout << "\n--- Patient List (" << list.size() << " records) ---\n";
    for (size_t i = 0; i < list.size(); i++) {
        printPatientCard(list[i]);
    }
}

/**
 * @brief Handles user input and logic call for adding a new patient.
 */
void handleAddPatient(vector<Patient>& list) {
    cout << "\n--- Add New Patient ---\n";
    Patient newP;

    newP.ID       = readValidInt("Enter Patient ID: ");
    newP.FullName = readValidString("Enter Full Name: ");
    newP.Age      = readIntInRange("Enter Patient Age (1-120): ", 1, 120);
    newP.Severity = readIntInRange("Enter Severity (1-5): ", 1, 5);
    newP.medical  = readValidString("Enter Medical Diagnosis: ");

    if (addPatient(list, newP)) {
        cout << "\n[+] Patient added successfully!\n";
    } else {
        cout << "\n[!] Error: A patient with ID " << newP.ID << " already exists!\n";
    }
}

/**
 * @brief Triggers the Bubble Sort algorithm and displays the emergency queue.
 */
void handleEmergencyQueue(vector<Patient>& list) {
    cout << "\n--- Emergency Queue (Sorted by Highest Severity) ---\n";
    sortPatientsBySeverity(list);
    printAllPatients(list);
}

/**
 * @brief Searches for a patient by ID using Linear Search and displays the result.
 */
void handleSearchPatient(const vector<Patient>& list) {
    cout << "\n--- Search Patient ---\n";
    int targetId = readValidInt("Enter Patient ID to search: ");
    int index = findPatientIndexById(list, targetId);

    if (index != -1) {
        cout << "\n[+] Patient Found:\n";
        printPatientCard(list[index]);
    } else {
        cout << "\n[!] Patient with ID " << targetId << " was not found.\n";
    }
}

/**
 * @brief Prompts for updated fields and modifies an existing patient record.
 */
void handleUpdatePatient(vector<Patient>& list) {
    cout << "\n--- Update Patient Condition ---\n";
    int targetId    = readValidInt("Enter Patient ID to update: ");
    int newSeverity = readIntInRange("Enter New Severity (1-5): ", 1, 5);
    string newMed   = readValidString("Enter New Diagnosis: ");

    if (updatePatient(list, targetId, newSeverity, newMed)) {
        cout << "\n[+] Patient condition updated successfully!\n";
    } else {
        cout << "\n[!] Error: Patient with ID " << targetId << " was not found.\n";
    }
}

/**
 * @brief Removes a patient record by ID from both memory and file storage.
 */
void handleDeletePatient(vector<Patient>& list) {
    cout << "\n--- Discharge (Delete) Patient ---\n";
    int targetId = readValidInt("Enter Patient ID to delete: ");

    if (deletePatient(list, targetId)) {
        cout << "\n[+] Patient discharged and removed from records successfully!\n";
    } else {
        cout << "\n[!] Error: Patient with ID " << targetId << " was not found.\n";
    }
}

/**
 * @brief Main application controller loop.
 */
void startHospitalSystem() {
    vector<Patient> hospitalPatients;
    loadFromFile(hospitalPatients);

    int choice = 0;
    while (choice != 6) {
        showMainMenu();
        choice = readIntInRange("Enter your choice (1-6): ", 1, 6);

        if (choice == 1) {
            handleAddPatient(hospitalPatients);
        } 
        else if (choice == 2) {
            handleEmergencyQueue(hospitalPatients);
        } 
        else if (choice == 3) {
            handleSearchPatient(hospitalPatients);
        } 
        else if (choice == 4) {
            handleUpdatePatient(hospitalPatients);
        } 
        else if (choice == 5) {
            handleDeletePatient(hospitalPatients);
        } 
        else if (choice == 6) {
            cout << "\nExiting Hospital System. Goodbye!\n";
        }
    }
}

