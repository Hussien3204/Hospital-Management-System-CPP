#include "FileManager.h"
#include <fstream>
using namespace std;

/**
 * @brief Serializes a Patient struct into a single delimited string line.
 */
string patientToLine(Patient p, string delimiter) {
    string line = to_string(p.ID) + delimiter 
                + p.FullName + delimiter 
                + to_string(p.Age) + delimiter 
                + to_string(p.Severity) + delimiter 
                + p.medical;
    return line;
}

/**
 * @brief Deserializes a delimited string line back into a Patient struct.
 */
Patient lineToPatient(string line, string delimiter) {
    vector<string> parts;
    size_t pos = 0;

    // Split string by delimiter
    while ((pos = line.find(delimiter)) != string::npos) {
        string word = line.substr(0, pos);
        parts.push_back(word);
        line.erase(0, pos + delimiter.length());
    }
    parts.push_back(line); // Last remaining field (medical diagnosis)

    // Map parsed tokens to Patient fields
    Patient p;
    p.ID       = stoi(parts[0]);
    p.FullName = parts[1];
    p.Age      = stoi(parts[2]);
    p.Severity = stoi(parts[3]);
    p.medical  = parts[4];

    return p;
}

/**
 * @brief Appends a single new patient record to the end of the storage file.
 */
void appendToFile(Patient p, string fileName) {
    ofstream outFile(fileName, ios::app);

    if (outFile.is_open()) {
        string line = patientToLine(p);
        outFile << line << endl;
        outFile.close();
    }
}

/**
 * @brief Overwrites the storage file with all records currently in the vector.
 */
void saveToFile(const vector<Patient>& list, string fileName) {
    ofstream outFile(fileName);

    if (outFile.is_open()) {
        for (size_t i = 0; i < list.size(); i++) {
            string line = patientToLine(list[i]);
            outFile << line << endl;
        }
        outFile.close();
    }
}

/**
 * @brief Loads all patient records from the storage file into the memory vector.
 */
void loadFromFile(vector<Patient>& list, string fileName) {
    list.clear();
    ifstream inFile(fileName);

    if (inFile.is_open()) {
        string line = "";
        while (getline(inFile, line)) {
            if (!line.empty()) {
                Patient p = lineToPatient(line);
                list.push_back(p);
            }
        }
        inFile.close();
    }
}

