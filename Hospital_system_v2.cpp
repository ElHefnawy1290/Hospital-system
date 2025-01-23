#include <iostream>
using namespace std;

const int MAX_SPECIALIZATION = 20; // Maximum number of specializations supported
const int MAX_PATIENTS = 5;        // Maximum number of patients per specialization queue

// Represents a queue for a specific specialization in the hospital
struct hospital_queue
{
    string names[MAX_PATIENTS]; // Array to store patient names
    bool status[MAX_PATIENTS];  // Array to store patient status: true for urgent, false for regular
    int len;                    // Current number of patients in the queue
    int spec;                   // Specialization identifier

    // Default constructor initializes an empty queue with invalid specialization
    hospital_queue()
    {
        len = 0;
        spec = -1;
    }

    // Constructor initializes an empty queue for a specific specialization
    hospital_queue(int spec_)
    {
        len = 0;
        spec = spec_;
    }

    // Adds a patient to the end of the queue. Returns false if the queue is full
    bool addEnd(string name, int st)
    {
        if (len == MAX_PATIENTS)
            return false;
        names[len] = name, status[len] = st, len++;
        return true;
    }

    // Adds a patient to the front of the queue, shifting other patients back. Returns false if the queue is full
    bool addFront(string name, int st)
    {
        if (len == MAX_PATIENTS)
            return false;
        for (int i = len - 1; i >= 0; i--)
        {
            names[i + 1] = names[i];
            status[i + 1] = status[i];
        }
        names[0] = name, status[0] = st, len++;
        return true;
    }

    // Removes the patient at the front of the queue
    void removeFront()
    {
        if (len == 0)
        {
            cout << "There is no patients in the queue rest, DR.\n\n";
            return;
        }
        cout << names[0] << " Please go with the doctor\n\n";
        leftShift(); // Shift all remaining patients forward
        len--;
    }

    // Helper function to shift all patients one position to the left
    void leftShift()
    {
        for (int i = 1; i < len; i++)
        {
            names[i - 1] = names[i];
            status[i - 1] = status[i];
        }
    }

    // Helper function to shift all patients one position to the right (not used)
    void rightShift()
    {
        for (int i = len - 1; i > 0; i--)
        {
            names[i] = names[i - 1];
            status[i] = status[i - 1];
        }
    }

    // Prints details of all patients in the queue
    void print()
    {
        if (len == 0)
        {
            cout << "This specialization has no patients\n\n";
            return;
        }

        for (int i = 0; i < len; i++)
        {
            cout << "patient " << i + 1 << "\n";
            cout << "\tname: " << names[i];
            cout << "\tstatus: ";
            if (status[i])
                cout << "Urgent";
            else
                cout << "Regular";
            cout << "\n\n";
        }
    }
};

// Represents the entire hospital system with multiple specialization queues
struct hospitalSystem
{
    hospital_queue queues[MAX_SPECIALIZATION + 1]; // Array of queues, one for each specialization

    // Constructor initializes queues for all specializations
    hospitalSystem()
    {
        for (int i = 0; i < MAX_SPECIALIZATION; ++i)
            queues[i] = hospital_queue(i);
    }

    // Main loop to handle user input and execute corresponding actions
    void run()
    {
        while (true)
        {
            int choice = menu();
            if (choice == 1)
                add_patient();
            if (choice == 2)
                print_patients();
            if (choice == 3)
                get_patients();
            if (choice == 4)
                break; // Exit the system
        }
    }

    // Displays the main menu and returns the user's choice
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
            if (!(n >= 1 && n <= 4))
            {
                cout << "Invalid choice. Try again!!\n\n";
                continue;
            }
            return n;
        }
    }

    // Adds a new patient to the appropriate specialization queue
    void add_patient()
    {
        int spec;
        string nam;
        bool stat;
        cout << "Please enter the number of specialization you want\n";
        cin >> spec;
        if (spec > MAX_SPECIALIZATION)
        {
            cout << "Inavlid input. please try again\n\n";
            return;
        }
        cout << "then enter the name of the patient\n";
        cin >> nam;
        cout << "then enter the status: ";
        cout << "[0] for regular\t[1] for urgent\n";
        cin >> stat;
        if (!(stat == 0 || stat == 1))
        {
            cout << "Invalid input. please try again\n\n";
            return;
        }
        if (queues[spec].len == 5)
        {
            cout << "The queue of the patients is full, sorry we can't accept your request now. Please try again later\n\n";
            return;
        }
        else
        {
            if (stat == 0)
            {
                queues[spec].addEnd(nam, stat);
                cout << "Congratulations, Your request have been made successfully\n\n";
            }
            else
            {
                queues[spec].addFront(nam, stat);
                cout << "Congratulations, Your request have been made successfully\n\n";
            }
        }
    }

    // Prints a summary of patients in all specializations and detailed information for one
    void print_patients()
    {
        bool exist = false;
        for (int spec = 0; spec < MAX_SPECIALIZATION; ++spec)
        {
            if (queues[spec].len > 0)
            {
                exist = true;
                cout << "There are " << queues[spec].len << " patients in specialization " << spec << "\n";
            }
        }
        if (!exist)
        {
            cout << "There is no patients at the hospital now\n\n";
            return;
        }
        int specialization;
        cout << "Select the number of the specialization to print patients\n";
        cin >> specialization;
        queues[specialization].print();
    }

    // Gets the next patient from the specified specialization queue
    void get_patients()
    {
        int spec;
        cout << "Enter specialization: ";
        cin >> spec;
        if (!(spec >= 1 && spec <= 20))
        {
            cout << "Invalid input. please enter valid number [ There are only 20 specializations from [ 1:20 ] ]\n\n";
            return;
        }
        queues[spec].removeFront();
    }
};

int main()
{
    hospitalSystem myhospital; // Initialize the hospital system
    myhospital.run();          // Start the main loop
    return 0;
}