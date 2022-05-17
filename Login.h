#include "Header.h"
#include "DataUser.h"

class User
{
public:
    string userName;
    string password;
    
};

class Login:public User
{
public:
    void registerAcount();
    bool loginAcount();
};

void Login::registerAcount()
{
    cout << "Enter userName: ";
    cin >> this->userName;
    cout << "Enter password: ";
    cin >> this->password;
    cout << "\n\tRegister Suceed\n" << endl;
    DataUser dataUser;
    dataUser.exportData(this->userName, this->password);
}

bool mainLogin(string inputUser, string inputPassword)
{
    DataUser dataUser;
    dataUser.importData();
    for (int i = 0; i <= 20; i++) {
        if (inputUser == dataUser.getUser[i] && inputPassword == dataUser.getPassword[i]) {
            return true;
        }
    }
    return false;
}

bool Login::loginAcount()
{
    string inputUser;
    string inputPassword;
    bool isStop = false;
    cout << "Enter user: ";
    cin >> inputUser;
    cout << "Enter password: ";
    cin >> inputPassword;
    while (mainLogin(inputUser, inputPassword) == false) {
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
    
    if (isStop) {
        return false;
    } else {
        return true;
    }
}
