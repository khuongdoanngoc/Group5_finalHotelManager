#include "Header.h"
#include <fstream>
#include <string>


class DataUser
{
public:
    string userAddress = "D:\\dataUser.txt";
    string getUser[50];
    string getPassword[50];

    void exportData(string user, string password)
    {
        ofstream fo;
        fo.open(userAddress, ios::app);
        if (fo.is_open()) {
            fo << user << "," << password << endl;
            fo.close();
        }
    }
    
    void importData()
    {
        ifstream fi;
        fi.open(userAddress);
        int index = 0;
        bool isWord2 = false;
        if (fi.is_open()) {
            while (!fi.eof()) {
                string str;
                getline(fi, str);
                for (int i = 0; i < str.length(); i++) {
                    if (str[i] != ',' && isWord2 == false) {
                        this->getUser[index] += str[i];
                    } else {
                        isWord2 = true;
                    }
                    if (str[i] == ',') {
                        i++;
                    }
                    if (isWord2) {
                        this->getPassword[index] += str[i];
                    }
                }
                index++;
            }
        }
        fi.close();
    }
    
};
