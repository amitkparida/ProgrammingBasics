// Adapter Design Pattern:
// This is very basic form of design pattern in software design, which is 
// used to make two different incompatible component to talk to each other.

#include <iostream>
#include <memory>
using namespace std;
// This is interface class for charger
class IndianSocket {
public:
    virtual void indianCharge(int) = 0;
};
// This is some socket which we want to use (Adapter)
class USASocket {
public:
    void usaCharge() {
        cout << "USA plug is charging" << endl;
    }
};

class GermanSocket {
public:
    void germanCharge() {
        cout << "German plug is charging" << endl;
    }
};

// This is the Adapter, used to charge with USASocket
class SocketAdapter : public IndianSocket, public USASocket, public GermanSocket {
public:
    void indianCharge(int type) {
        switch (type)
        {
        case 1:
            usaCharge();
            break;
        case 2:
            germanCharge();
            break;
        default:
            break;
        }
    }
};
// This is kind of Mobile which is using Charger for charging.
int main() {
    unique_ptr<IndianSocket> socket = make_unique<SocketAdapter>();
    socket->indianCharge(1);
    socket->indianCharge(2);
    return 0;
}