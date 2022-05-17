#include "Header.h"
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>

class DataEmp
{
public:
    string empAddress = "D:\\dataEmp.txt";
    string getEmpID[50];
    double getEmpKPI[50];
    int indexKPI = 0;
    
    void getKPI()
    {
        ifstream fi;
        fi.open(empAddress);
        int count = 0;
        int indexKPI = 0;
        string KPI;
        if (fi.is_open()) {
            while (!fi.eof()) {
                string str;
                getline(fi, str);
                for (int i = 0; i < 20; i++) {
                    if (str[i] == '\0') {
                        break;
                    }
                    if (count == 3) {
                        KPI += str[i];
                    }
                    if (str[i] == ' ') {
                        count ++;
                    }
                }
                int temp = atoi(KPI.c_str());
                if (temp != 0) {
                    this->getEmpKPI[indexKPI++] = temp;
                }
                KPI = "";
                count = 0;
                str = "";
            }
        }
    }
    
    void getID()
    {
        ifstream fi;
        fi.open(empAddress);
        int index = 0;
        if (fi.is_open()) {
            while (!fi.eof()) {
                string str = "";
                getline(fi, str);
                // get first word in line = empID
                for (int i = 0; str[i] != ' '; i++)
                {
                    this->getEmpID[index] += str[i];
                }
                index++;
            }
        }
    }
    
    void deleteLine(const char *file_name, int n)
    {
        // open file in read mode or in mode
        ifstream is(file_name);
      
        // open file in write mode or out mode
        ofstream ofs;
        ofs.open("temp.txt", ofstream::out);
      
        // loop getting single characters
        char c;
        int line_no = 1;
        while (is.get(c))
        {
            // if a newline character
            if (c == '\n')
            line_no++;
      
            // file content not to be deleted
            if (line_no != n)
                ofs << c;
        }
      
        // closing output file
        ofs.close();
      
        // closing input file
        is.close();
      
        // remove the original file
        remove(file_name);
      
        // rename the file
        rename("temp.txt", file_name);
    }
    
    void searchingLine(int line)
    {
        ifstream fi;
        fi.open(empAddress);
        string str;
        int index = 1;
        if (fi.is_open()) {
            char c;
            int line_no = 1;
            while (fi.get(c))
            {
                if (c == '\n')
                    line_no++;
                
                if (line_no == line)
                    // get data in line to str
                    str += c;
            }
        }
        string word;
        for (istringstream is(str); is >> word && index < 5; ) {
            switch (index) {
                case 1:
                    cout << "[ EmpID=" << word;
                    break;
                case 2:
                    cout << ", Name=" << word;
                    break;
                case 3:
                    cout << ", Age=" << word;
                    break;
                case 4:
                    cout << ", KPI=" << word << " ]" << endl;
                    break;
                default:
                    
                    break;
            }
            index++;
        }
    }
    
    void showData()
    {
        ifstream fi;
        fi.open(empAddress);
        char c;
        string str;
        int index = 1;
        if (fi.is_open()) {
            while (!fi.eof()) {
                while (fi.get(c)) {
                    if (c != '\n') {
                        str += c;
                    } else {
                        string word;
                        for (istringstream is(str); is >> word && index < 5; ) {
                            switch (index) {
                                case 1:
                                    cout << "[ EmpID=" << word;
                                    break;
                                case 2:
                                    cout << ", Name=" << word;
                                    break;
                                case 3:
                                    cout << ", Age=" << word;
                                    break;
                                case 4:
                                    cout << ", KPI=" << word << " ]" << endl;
                                    break;
                                default:
                                    
                                    break;
                            }
                            index++;
                        }
                        word = "";
                        index = 1;
                        str = "";
                    }
                }
            }
        }
    }
    
    void exportData(string empID, string name, int age, double KPI)
    {
        ofstream fo;
        fo.open(empAddress, ios::app);

        if (fo.is_open()) {
            fo << empID << " " << name << " " << age << " " << KPI << endl;
            fo.close();
        }
    }
    
};
