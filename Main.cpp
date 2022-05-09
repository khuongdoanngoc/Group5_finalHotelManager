#include "Header.h"
#include "Login.h"
#include "RoomStatus.h"
#include "Employee.h"

bool mainLogin(Login user[], string inputUser, string inputPassword)
{
    for (int i = 0; i < 50; i++) {
        if (inputUser == user[i].userName && inputPassword == user[i].password) {
            return true;
        }
    }
    return false;
}

int homePage()
{
    cout << "\t\t--HOME PAGE--" << endl;
    int choose;
    do {
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "\tEnter (1 or 2): ";
        cin >> choose;
    } while (choose != 1 && choose != 2);
    return choose;
}

int MenuManagement()
{
    cout << "\n\t\t--MANAGEMENT--" << endl;
    int choose;
    do {
        cout << "1. Room Status" << endl;
        cout << "2. Employee" << endl;
        cout << "3. Exit" << endl;
        cout << "\tEnter (1 or 2 or 3): ";
        cin >> choose;
    } while (choose != 1 && choose != 2 && choose != 3);
    return choose;
}

int empMenu()
{
    int choose;
    bool isInvalid;
    do {
        cout << "\t\t--Employee Menu--" << endl;
        cout << "1. Add new employee" << endl;
        cout << "2. Search employee by ID" << endl;
        cout << "3. Remove employee by ID" << endl;
        cout << "4. View salary" << endl;
        cout << "5. Back to Home Page" << endl;
        cout << "\t Choose: ";
        cin >> choose;
        if (choose < 1 || choose > 5) isInvalid = true;
        else isInvalid = false;
    } while (isInvalid);
    return choose;
}

void searchEmp(Employee emp[])
{
    string inputEmpID;
    int index = -1;
    cout << "Enter empID to search: ";
    cin.ignore();
    getline(cin, inputEmpID);
    for (int i = 0; i < 50; i++) {
        if (inputEmpID == emp[i].empID) {
            index = i;
        }
    }
    if (index == -1) {
        cout << "\n\tNot Found!" << endl;
    } else {
        cout << "-> Employee[ name=" << emp[index].name << ", age=" << emp[index].age << ", KPI=" << emp[index].KPI << " ]" << endl;
    }
}

void removeEmp(Employee emp[])
{
    string inputEmpID;
    int index = -1;
    cout << "Enter empID to remove: ";
    cin.ignore();
    getline(cin, inputEmpID);
    for (int i = 0; i < 50; i++) {
        if (inputEmpID == emp[i].empID) {
            index = i;
        }
    }
    if (index == -1) {
        cout << "\n\tNot Found!" << endl;
    } else {
        for (int i = index; i < 49; i++) {
            emp[i] = emp[i+1];
        }
    }
}

void viewSalary(Employee emp[])
{
    for (int i = 0; i < 50; i++) {
        if (emp[i].name.empty() == false) {
            cout << "Employee[" << i+1 << "]: name=" << emp[i].name << " Salary=$" << emp[i].KPI*emp[i].salary << endl;
        }
    }
}

int main()
{
    Login user[50];
    RoomStatus room[50];
    Employee employee[50];
    int index = 0;
    int loop = 0;
    while (loop == 0) {
        switch (homePage()) {
                
            // Login
            case 1:
            {
                string inputUser;
                string inputPassword;
                bool isStop = false;
                cout << "Enter user: ";
                cin >> inputUser;
                cout << "Enter password: ";
                cin >> inputPassword;
                while (mainLogin(user, inputUser, inputPassword) == false) {
                    cout << "\n\tWrong username or password!" << endl;
                    cout << "\tExit to home page (Y or N): ";
                    char exit;
                    cin >> exit;
                    if (exit == 'Y') {
                        isStop = true;
                        break;
                    }
                    cout << "\nEnter username: ";
                    cin >> inputUser;
                    cout << "Enter password: ";
                    cin >> inputPassword;
                }
                cout << "\t\t--Login Succeed--" << endl;
                if (!isStop) {
                    loop = 1;
                }
                break;
            }
                
            // Register
            case 2:
            {
                user[index++].registerAcount();
                break;
            }
            default:
                cout << "Invalid" << endl;
                break;
        }
    }  // Login finish
    
    while (loop == 1) {
        switch (MenuManagement()) {
                
            // Room Status
            case 1:
            {
                int num;
                cout << "Enter number of room: ";
                cin >> num;
                for (int i = 0; i < num; i++) {
                    room[i].input();
                    cout << "Price room[" << i + 1 << "] = " << room[i].bill() << endl;
                }
                break;
            }
                
            // Employee
            case 2:
            {
                int loopEmp = 1;
                while (loopEmp == 1) {
                    switch (empMenu()) {
                            // add new Employee
                        case 1:
                        {
                            int num;
                            cout << "Enter number of employee: ";
                            cin >> num;
                            for (int i = 0; i < num; i++) {
                                cout << "Enter employee[" << i+1 << "] : " << endl;
                                employee[i].addEmployee();
                            }
                            break;
                        }
                            
                            // search Employee by ID
                        case 2:
                        {
                            searchEmp(employee);
                            break;
                        }
                            
                            // remove Employee by ID
                        case 3:
                        {
                            removeEmp(employee);
                            break;
                        }
                            
                            // view Salary
                        case 4:
                        {
                            viewSalary(employee);
                            break;
                        }
                        case 5:
                        {
                            loopEmp = 2;
                            break;
                        }
                        default:
                            cout << "Invalid" << endl;
                            break;
                    }
                }
                break;
            }
                
            // finish
            case 3:
            {
                loop = 2;
                break;
            }
            default:
                cout << "Invalid" << endl;
                break;
        }
    }
}

