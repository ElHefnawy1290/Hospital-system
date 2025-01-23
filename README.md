# Hospital Queue Management System

## Overview
This project provides two implementations of a hospital queue management system in C++. It handles patient queues for different medical specializations, allowing urgent and regular patient registration, queue status viewing, and patient admission to doctors.

## Features
- Two distinct implementations:
  1. **Procedural Approach**: Uses global arrays and functions for queue management.
  2. **Object-Oriented Approach**: Utilizes structs and encapsulation for better code organization.
- Support for 20 medical specializations
- Maximum of 5 patients per specialization queue
- Urgent patients prioritization at front of queue
- Regular patients added to end of queue
- Patient status tracking (urgent/regular)
- Queue status visualization
- Input validation and error handling

## Installation
1. Ensure you have a C++ compiler (e.g., g++) installed
2. Clone/download the repository
3. Compile the files separately

### Menu Options
1. Add New Patient: Register a patient with specialization, name, and urgency status
2. Print Patients: View all patients in a specific specialization queue
3. Get Next Patient: Admit the next patient from a specialization queue
4. Exit: Close the program

### Example Input & Output
#### Adding Patients:
```
Choose number for your request:
1)Add new patient
2)Print patients
3)Get next patient
4)Exit
1
Please enter the number of specialization you want
3
then enter the name of the patient
John
then enter the status: [0] for regular    [1] for urgent
1
Congratulations, Your request have been made successfully
```

#### Viewing Queue:
```
Choose number for your request:
1)Add new patient
2)Print patients
3)Get next patient
4)Exit
2
Select the number of the specialization to print patients
3
patient 1
        name: John   status: Urgent
```

#### Admitting Patient:
```
Choose number for your request:
1)Add new patient
2)Print patients
3)Get next patient
4)Exit
3
Enter specialization: 3
John Please go with the doctor
```

## Notes
- Specialization numbers range from 1-20
- Maximum 5 patients per specialization queue
- Urgent patients are prioritized at front of queue
- Regular patients are added to end of queue
- The OOP version provides better code organization and encapsulation
- Input validation included for most user interactions
