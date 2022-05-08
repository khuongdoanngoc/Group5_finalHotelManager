#include "Header.h"

class Employee
{
public:
    string empID;
    string name;
    int age;
    double KPI;
    int salary = 50;
    
    void addEmployee();

};


void Employee::addEmployee()
{
    cout << "Enter empID: ";
    cin.ignore();
    getline(cin, this->empID);
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, this->name);
    cout << "Enter age: ";
    cin >> this->age;
    cout << "Enter KPI: ";
    cin >> this->KPI;
}



