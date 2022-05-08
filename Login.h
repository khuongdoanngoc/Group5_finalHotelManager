#include "Header.h"

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
};

void Login::registerAcount()
{
    cout << "Enter userName: ";
    cin >> this->userName;
    cout << "Enter password: ";
    cin >> this->password;
    cout << "\n\tRegister Suceed\n" << endl;
}

