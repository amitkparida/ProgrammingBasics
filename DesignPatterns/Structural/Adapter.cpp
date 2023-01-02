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

// This is socket which we want to use (Adaptee)
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

// Adapter class — Based on (Multiple) Inheritance
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

// This is client (Indian charger/plug). It connects to adaptee (USA/German sockets) using adapter
int main() {
    IndianSocket* socket = new SocketAdapter;
    socket->indianCharge(1); // 
    socket->indianCharge(2);
    return 0;
}




/*
#include<iostream>
using namespace std;

typedef int Coordinate;
typedef int Dimension;

// Desired interface
class Rectangle
{
public:
    virtual void draw() = 0;
};

// Legacy component
class LegacyRectangle
{
public:
    LegacyRectangle(Coordinate x1, Coordinate y1, Coordinate x2, Coordinate y2)
    {
        x1_ = x1;
        y1_ = y1;
        x2_ = x2;
        y2_ = y2;
        cout << "LegacyRectangle:  create.  (" << x1_ << "," << y1_ << ") => ("
            << x2_ << "," << y2_ << ")" << endl;
    }
    void oldDraw()
    {
        cout << "LegacyRectangle:  oldDraw.  (" << x1_ << "," << y1_ <<
            ") => (" << x2_ << "," << y2_ << ")" << endl;
    }
private:
    Coordinate x1_;
    Coordinate y1_;
    Coordinate x2_;
    Coordinate y2_;
};

// Adapter wrapper
class RectangleAdapter : public Rectangle, private LegacyRectangle
{
public:
    RectangleAdapter(Coordinate x, Coordinate y, Dimension w, Dimension h) :
        LegacyRectangle(x, y, x + w, y + h)
    {
        cout << "RectangleAdapter: create.  (" << x << "," << y <<
            "), width = " << w << ", height = " << h << endl;
    }
    virtual void draw()
    {
        cout << "RectangleAdapter: draw." << endl;
        oldDraw();
    }
};

int main()
{
    // The rectangle object can use the legacy_rectangle object to draw itself. 
    // This allows the client code to use the new rectangle class with the old legacy_rectangle class, 
    // without having to modify the legacy_rectangle class.
    Rectangle* r = new RectangleAdapter(120, 200, 60, 40);
    r->draw();
}

*/





/*

// From ChatGPT

#include <iostream>
#include <string>

// The Adaptee class
class legacy_rectangle
{
private:
    int x1, y1, x2, y2;

public:
    legacy_rectangle(int x1, int y1, int x2, int y2)
    {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }

    int get_x1() { return x1; }
    int get_y1() { return y1; }
    int get_x2() { return x2; }
    int get_y2() { return y2; }

    void draw()
    {
        std::cout << "legacy_rectangle:  [" << x1 << ", " << y1 << ", " << x2 << ", " << y2 << "]" << std::endl;
    }
};

// The Target class
class rectangle
{
private:
    legacy_rectangle* rect;

public:
    rectangle(legacy_rectangle* rect)
    {
        this->rect = rect;
    }

    void draw()
    {
        std::cout << "rectangle: [" << rect->get_x1() << ", " << rect->get_y1() << ", " << rect->get_x2() << ", " << rect->get_y2() << "]" << std::endl;
    }
};

int main()
{
    // Client code that uses the legacy_rectangle class
    legacy_rectangle* legacy_rect = new legacy_rectangle(1, 1, 10, 10);
    legacy_rect->draw();

    // The rectangle object can use the legacy_rectangle object to draw itself. 
    // This allows the client code to use the new rectangle class with the old legacy_rectangle class, 
    // without having to modify the legacy_rectangle class.
    rectangle* rect = new rectangle(legacy_rect);
    rect->draw();

    return 0;
}

*/