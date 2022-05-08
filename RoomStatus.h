#include "Header.h"

class RoomStatus
{
public:
    int price;
    int time;
    
    void input();
    int bill();
};

class RoomA:public RoomStatus
{
public:
    int price = 40;
};

class RoomB:public RoomStatus
{
public:
    int price = 60;
};

class RoomC:public RoomStatus
{
public:
    int price = 80;
};


void RoomStatus::input()
{
    char chooseRoom;
    do {
        cout << "Choose room ( A or B or C ): ";
        cin >> chooseRoom;
        switch (chooseRoom) {
            case 'A':
            {
                this->price = RoomA().price;
                break;
            }
            case 'B':
            {
                this->price = RoomB().price;
                break;
            }
            case 'C':
            {
                this->price = RoomC().price;
                break;
            }
            default:
                cout << "Invalid" << endl;
                break;
        }
    } while (chooseRoom != 'A' && chooseRoom != 'B' && chooseRoom != 'C');
    cout << "Time (hour) : ";
    cin >> this->time;
}

int RoomStatus::bill()
{
    return this->price * this->time;
}

