#include <iostream>
#include <string>

using namespace std;

struct Employee {
    int id;
    string name;
    float salary;
};

const int ARRAY_SIZE = 10;
const float SALARY_THRESHOLD = 30000.0f;
const float SALARY_INCREASE_PERCENT = 0.10f;

void displayEmployee(const Employee& emp) {

    cout << "| " << emp.id 
         << " | " << emp.name 
         << " | Rs. " << emp.salary << " |" << endl;
    cout << "+------+----------------------+------------+" << endl;
}

void readEmployees(Employee arr[], int size) {
    cout << "\n--- Entering Employee Data (Up to " << size << ") ---\n";
    for (int i = 0; i < size; ++i) {
        cout << "\nEnter details for Employee #" << i + 1 << endl;
        
        cout << "Enter ID: ";
        cin >> arr[i].id;
        cin.ignore(100, '\n'); 

        cout << "Enter Name (can include spaces): ";
        getline(cin, arr[i].name); 

        cout << "Enter Salary (in Rs.): ";
        cin >> arr[i].salary;
    }
}


void displayAllEmployees(const Employee arr[], int size) {
    cout << "\n==============================================" << endl;
    cout << "          ALL EMPLOYEE DETAILS (" << size << ")" << endl;
    cout << "==============================================" << endl;

    cout << "| ID | Name | Salary |" << endl;
    cout << "==============================================" << endl;


    for (int i = 0; i < size; ++i) {
        displayEmployee(arr[i]);
    }
    cout << "\nDisplay complete." << endl;
}

void searchEmployeeById(const Employee arr[], int size) {
    int searchId;
    cout << "\nEnter the ID of the employee to search: ";
    cin >> searchId;
    
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (arr[i].id == searchId) {
            cout << "\n--- Employee Found ---" << endl;
            displayEmployee(arr[i]);
            found = true;
            break; 
        }
    }
    
    if (!found) {
        cout << "\nError: Employee with ID " << searchId << " not found." << endl;
    }
}


void increaseSalary(Employee arr[], int size) {
    int increasedCount = 0;
    cout << "\n--- Applying Salary Increase Rule ---" << endl;
    
    for (int i = 0; i < size; ++i) {
        if (arr[i].salary < SALARY_THRESHOLD) {
            arr[i].salary *= (1.0f + SALARY_INCREASE_PERCENT);
            increasedCount++;
        }
    }

    if (increasedCount > 0) {
        cout << "Success! Increased salary for " << increasedCount << " employee(s) by 10%." << endl;
        cout << "New threshold applied: Less than Rs. " << SALARY_THRESHOLD << "." << endl;
        cout << "Use option 1 to view updated salaries." << endl;
    } else {
        cout << "No employees found with a salary less than Rs. " 
             << SALARY_THRESHOLD << ". No changes made." << endl;
    }
}


int main() {
    
    Employee employeeArray[ARRAY_SIZE];
    
    readEmployees(employeeArray, ARRAY_SIZE);

    int choice;
    do {
        cout << "\n==============================================" << endl;
        cout << "            EMPLOYEE MENU" << endl;
        cout << "==============================================" << endl;
        cout << "1. Display all employee details" << endl;
        cout << "2. Search for an employee by ID" << endl;
        cout << "3. Increase salary (less than Rs. 30,000 by 10%)" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        
        if (!(cin >> choice)) {
            cout << "\nInvalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(100, '\n'); 
            continue;
        }

        switch (choice) {
            case 1:
                displayAllEmployees(employeeArray, ARRAY_SIZE);
                break;
            case 2:
                searchEmployeeById(employeeArray, ARRAY_SIZE);
                break;
            case 3:
                increaseSalary(employeeArray, ARRAY_SIZE);
                break;
            case 4:
                cout << "\nExiting program. Goodbye!" << endl;
                break;
            default:
                cout << "\nInvalid choice. Please enter a number between 1 and 4." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
