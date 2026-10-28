#pragma once
#include <string>
using namespace std;

// Data model representing a single patient record
struct Patient {
   int ID; // 1. Declare patient ID (integer)

   string FullName;   // 2. Declare patient full name (string)

    int Age;               // 3. Declare patient age (integer)
    
   int Severity; // 4. Declare condition severity from 1 to 5 (integer)
    
    string medical;// 5. Declare medical diagnosis (string)
    
};



