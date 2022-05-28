#include "Header.h"
#include "DataEmp.h"

DataEmp dataEmp;

class Employee
{
public:
    string empID;
    string name;
    int age;
    double KPI;
    int salary = 50;
    
    void addEmployee();
    void removeEmployeeByID(string empID);
    void searchEmployeeByID(string empID);
    void showAllEmployee();
    void viewSalary();
};


void Employee::addEmployee()
{
    cout << "Enter empID: ";
    cin.ignore();
    getline(cin, this->empID);
    cout << "Enter name: ";
    getline(cin, this->name);
    cout << "Enter age: ";
    cin >> this->age;
    cout << "Enter KPI: ";
    cin >> this->KPI;
    dataEmp.exportData(empID, name, age, KPI);
}

void Employee::removeEmployeeByID(string inputEmpID)
{
    dataEmp.getID();
    for (int i = 0; i < 50; i++)
    {
        if (inputEmpID == dataEmp.getEmpID[i]) {
            dataEmp.deleteLine("dataEmp.txt", i+1);
        }
    }
}

void Employee::searchEmployeeByID(string inputEmpID)
{
    dataEmp.getID();
    bool isFound = false;
    for (int i = 0; i < 50; i++) {
        if (inputEmpID == dataEmp.getEmpID[i]) {
            isFound = true;
            dataEmp.searchingLine(i + 1);
        }
    }
    if (!isFound) {
        cout << "\tNot found!" << endl;
    }
}

void Employee::showAllEmployee()
{
    dataEmp.showData();
}

void Employee::viewSalary()
{
    dataEmp.getKPI();
    for (int i = 0; i < 50 ; i++)
    {
        if (dataEmp.getEmpKPI[i] != 0) {
            cout << "Employee[" << i+1 << "] : Salary = $" << this->salary*dataEmp.getEmpKPI[i] << endl;
        } else {
            if (i == 15) {
                break;
            }
        }
    }
}


