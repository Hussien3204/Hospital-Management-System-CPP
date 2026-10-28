# Hospital Management System (C++ & MVC Architecture)

A structured, console-based Hospital Management System built in **C++** using **Procedural Programming** and **3-Tier / MVC Architecture**. This project focuses on clean code separation, custom algorithm implementation, and persistent file storage.

## System Architecture (MVC Pattern)
The project is strictly divided into 4 isolated layers to ensure **Separation of Concerns (SoC)**:
* **1_Models/**: Data structures (Patient.h) and Data Access Layer (FileManager) handling serialization and fstream I/O using custom delimiters (&&&&).
* **2_Controllers/**: Business Logic Layer (HospitalLogic) containing pure algorithms and CRUD operations completely decoupled from console I/O.
* **3_Views/**: Presentation Layer (HospitalUI) managing user interaction and menus.
* **4_Utils/**: Input validation shield (Validation) preventing stream crashes.
* **main.cpp**: Clean, single-line entry point.

## Core Algorithms Implemented from Scratch
1. **Bubble Sort Algorithm**: Prioritizes the Emergency Queue by sorting patients descendingly based on condition severity (5 down to 1).
2. **Linear Search Algorithm**: Locates patient records in memory by ID for fast retrieval, updates, and deletions, and prevents duplicate IDs.
3. **Custom String Tokenizer**: Parses delimited text records from patients.txt back into memory structs (vector<Patient>).
<img width="1301" height="905" alt="image" src="https://github.com/user-attachments/assets/0a83d49a-bc4d-46c5-97d4-3a587f2a6dc7" />
