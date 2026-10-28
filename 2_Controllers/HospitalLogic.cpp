#include "HospitalLogic.h"
#include "FileManager.h"
#include <algorithm> // For swap()
using namespace std;

/**
 * @brief Linear Search Algorithm to find a patient's index in the vector by ID.
 */
int findPatientIndexById(const vector<Patient>& list, int targetId) {
    for (size_t i = 0; i < list.size(); i++) {
        if (list[i].ID == targetId) {
            return i;
        }
    }
    return -1;
}

/**
 * @brief Adds a new patient if the ID is unique, and appends to storage file.
 */
bool addPatient(vector<Patient>& list, Patient newPatient) {
    int index = findPatientIndexById(list, newPatient.ID);

    if (index != -1) {
        return false; // Duplicate ID found
    }

    list.push_back(newPatient);
    appendToFile(newPatient);
    return true;
}

/**
 * @brief Bubble Sort Algorithm to order patients descending by Severity (5 down to 1).
 */
void sortPatientsBySeverity(vector<Patient>& list) {
    size_t n = list.size();
    if (n <= 1) return;

    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = 0; j < n - i - 1; j++) {
            if (list[j].Severity < list[j + 1].Severity) {
                swap(list[j], list[j + 1]);
            }
        }
    }
}

/**
 * @brief Updates an existing patient's severity and diagnosis, then syncs with file.
 */
bool updatePatient(vector<Patient>& list, int targetId, int newSeverity, string newMedical) {
    int index = findPatientIndexById(list, targetId);

    if (index == -1) {
        return false;
    }

    list[index].Severity = newSeverity;
    list[index].medical  = newMedical;
    saveToFile(list);
    return true;
}

/**
 * @brief Removes a patient record from memory and updates the storage file.
 */
bool deletePatient(vector<Patient>& list, int targetId) {
    int index = findPatientIndexById(list, targetId);

    if (index == -1) {
        return false;
    }

    list.erase(list.begin() + index);
    saveToFile(list);
    return true;
}

