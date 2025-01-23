#include <iostream>
using namespace std;

// Constants for maximum specializations and patients per specialization
const int MAX_SPECIALIZATION = 20;
const int MAX_PATIENTS = 5;

// Data structures to manage hospital system
// `names`: Stores patient names for each specialization and queue index
// `status`: Tracks urgency of each patient (0: regular, 1: urgent)
// `queue`: Tracks the number of patients in each specialization
string names[MAX_SPECIALIZATION + 1][MAX_PATIENTS + 1];
bool status[MAX_SPECIALIZATION + 1][MAX_PATIENTS + 1];
int queue[MAX_SPECIALIZATION + 1] = {0}; // Initialize all specializations with zero patients

// Function declarations
int menu();
void hospital_system();
void add_patient();
void print_patients();
void get_patient();
void right_shift(int specialize, int len);
void left_shift(int specialization, int len);

int main()
{
    // Entry point to the hospital system
    hospital_system();
    return 0;
}

// Displays the menu and ensures valid input
int menu()
{
    while (true)
    {
        int n;
        cout << "Choose number for your request:\n";
        cout << "1)Add new patient\n";
        cout << "2)Print patients\n";
        cout << "3)Get next patient\n";
        cout << "4)Exit\n";
        cin >> n;
        // Validate user input and prompt again if invalid
        if (!(n >= 1 && n <= 4))
        {
            cout << "Invalid choice. Try again!!\n\n";
            continue;
        }
        return n;
    }
}

// Main loop for the hospital system
void hospital_system()
{
    while (true)
    {
        int choice = menu();
        if (choice == 1)
            add_patient();
        if (choice == 2)
            print_patients();
        if (choice == 3)
            get_patient();
        if (choice == 4)
            break; // Exit the system
    }
}

// Handles adding a new patient to the system
void add_patient()
{
    int spec;
    string nam;
    bool stat;

    // Input specialization and validate range
    cout << "Please enter the number of specialization you want\n";
    cin >> spec;
    if (spec > MAX_SPECIALIZATION)
    {
        cout << "Inavlid input. please try again\n\n";
        return;
    }

    // Input patient name and status (urgent or regular)
    cout << "then enter the name of the patient\n";
    cin >> nam;
    cout << "then enter the status: ";
    cout << "[0] for regular\t[1] for urgent\n";
    cin >> stat;

    // Validate status input
    if (!(stat == 0 || stat == 1))
    {
        cout << "Invalid input. please try again\n\n";
        return;
    }

    // Check if the queue for the specialization is full
    if (queue[spec] == 5)
    {
        cout << "The queue of the patients is full, sorry we can't accept your request now. Please try again later\n\n";
        return;
    }

    // Add patient based on urgency
    if (stat == 0) // Regular patient added to the end of the queue
    {
        names[spec][queue[spec]] = nam;
        status[spec][queue[spec]] = stat;
        queue[spec]++;
        cout << "Congratulations, Your request have been made successfully\n\n";
    }
    else // Urgent patient added to the front of the queue
    {
        queue[spec]++;
        right_shift(spec, queue[spec]); // Shift existing patients to make room at the front
        names[spec][0] = nam;
        status[spec][0] = stat;
        cout << "Congratulations, Your request have been made successfully\n\n";
    }
}

// Shifts patients to the right to make room at the front of the queue
void right_shift(int specialize, int len)
{
    for (int i = len - 1; i > 0; i--)
    {
        names[specialize][i] = names[specialize][i - 1];
        status[specialize][i] = status[specialize][i - 1];
    }
}

// Prints patients for a selected specialization
void print_patients()
{
    bool exist = false;

    // Check for patients in all specializations
    for (int i = 0; i < MAX_SPECIALIZATION; i++)
    {
        if (queue[i] > 0)
        {
            exist = true;
            cout << "There are " << queue[i] << " patients in specialization " << i << "\n";
        }
    }

    // No patients in the system
    if (!exist)
    {
        cout << "There is no patients at the hospital now\n\n";
        return;
    }
    cout << "\n";
    int spec;

    // Input specialization to view its patients
    cout << "Select the number of the specialization to print patients\n";
    cin >> spec;
    int size = queue[spec];

    // Handle empty specialization
    if (queue[spec] == 0)
        cout << "This specialization has no patients\n\n";

    // Print patient details
    for (int i = 0; i < size; i++)
    {
        cout << "patient " << i + 1 << "\n";
        cout << "\tname: " << names[spec][i];
        cout << "\tstatus: ";
        if (status[spec][i])
            cout << "Urgent";
        else
            cout << "Regular";
        cout << "\n\n";
    }
}

// Processes the next patient for a given specialization
void get_patient()
{
    int spec;

    // Input specialization and validate range
    cout << "Specialization: \n";
    cin >> spec;
    if (!(spec >= 1 && spec <= 20))
    {
        cout << "Invalid input. please enter valid number [ There are only 20 specializations from [ 1:20 ] ]\n\n";
        return;
    }

    // Handle empty queue
    if (queue[spec] == 0)
    {
        cout << "There is no patients in the queue rest, DR.\n\n";
        return;
    }

    // Serve the first patient and shift the queue
    cout << names[spec][0] << " please go to the doctor\n\n";
    left_shift(spec, queue[spec]);
    queue[spec]--;
}

// Shifts patients to the left after serving the first patient
void left_shift(int specialization, int len)
{
    for (int i = 0; i <= len; i++)
    {
        names[specialization][i] = names[specialization][i + 1];
        status[specialization][i] = status[specialization][i + 1];
    }
}