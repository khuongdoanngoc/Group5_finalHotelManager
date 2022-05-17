#include "Header.h"
#include "Login.h"
#include "RoomStatus.h"
#include "Employee.h"

int homePage()
{
    cout << "\t\t--HOME PAGE--" << endl;
    int choose;
    do {
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
        cout << "\tEnter (1 or 2): ";
        cin >> choose;
    } while (choose != 1 && choose != 2 && choose != 3);
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
        cout << "4. Show all employee" << endl;
        cout << "5. View salary" << endl;
        cout << "6. Back to Home Page" << endl;
        cout << "\t Choose: ";
        cin >> choose;
        if (choose < 1 || choose > 6) isInvalid = true;
        else isInvalid = false;
    } while (isInvalid);
    return choose;
}

int main()
{
    Login user;
    RoomStatus room[50];
    Employee employee;
    int loop = 0;
    while (loop == 0) {
        switch (homePage()) {
                
            // Login
            case 1:
            {
                if (user.loginAcount()) {
                    cout << "\t\t--Login Succeed--" << endl;
                    loop  = 1;
                } else {
                    cout << "\t\t--Login Fail--" << endl;
                }
                break;
            }
                
            // Register
            case 2:
            {
                user.registerAcount();
                break;
            }
            case 3:
                return 0;
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
                    cout << "Price room[" << i + 1 << "] = $" << room[i].bill() << endl;
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
                                employee.addEmployee();
                            }
                            break;
                        }
                            
                            // search Employee by ID
                        case 2:
                        {
                            string inputID;
                            cout << "Enter empID to search: ";
                            cin.ignore();
                            getline(cin, inputID);
                            employee.searchEmployeeByID(inputID);
                            break;
                        }
                            
                            // remove Employee by ID
                        case 3:
                        {
                            string inputID;
                            cout << "Enter empID to remove: ";
                            cin.ignore();
                            getline(cin, inputID);
                            employee.removeEmployeeByID(inputID);
                            break;
                        }
                            
                            // show emp
                        case 4:
                        {
                            employee.showAllEmployee();
                            break;
                        }
                            // view salary
                        case 5:
                        {
                            employee.viewSalary();
                            break;
                        }
                        case 6:
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

