// Prototype or Clone Design Pattern:

// https://www.educative.io/courses/software-design-patterns-best-practices/gxpWJ3ZKYwl

// Definition: A prototype pattern is used when the type of objects to create is determined by a prototypical instance, 
// which is cloned to produce new objects.

// Problem: This pattern is used, for example, when the inherent cost of creating a new object 
// in the standard way (e.g., using the new keyword) is prohibitively expensive for a given application.

// Solution: Declare an abstract base class that specifies a pure virtual clone() method.
// Any class that needs a "polymorphic constructor" capability derives itself from the abstract base class  
// and implements the clone() operation.

#include <iostream>
using namespace std;

class F16Engine{
public:
    virtual void start() = 0;
};

class F16AEngine : public F16Engine {
public:
    void start() {
        cout << "F16A engine started" << endl;
    }
};

class F16BEngine : public F16Engine {
public:
    void start() {
        cout << "F16B engine started" << endl;
    }
};


//Prototype
class IAircraftPrototype {
public:
    virtual IAircraftPrototype* clone() = 0;
    virtual void setEngine(F16Engine* f16Engine) = 0;
    virtual void fly() = 0;
};

//Concrete Prototype
class F16 : public IAircraftPrototype {
    // default engine
    F16Engine* f16Engine = nullptr;

public:
    IAircraftPrototype* clone() {
        // Deep copy/clone self and return the product
        return new F16();

        // Shallow copy/clone
        //return this;
    }

    void setEngine(F16Engine* f16Engine) {
        this->f16Engine = f16Engine;
    }

    void fly() {
        f16Engine->start();
        cout << "F16 flying" << endl;
    }
};


//Client
int main() {
    IAircraftPrototype* prototype = new F16();

    // Create F16-A
    IAircraftPrototype* f16A = prototype->clone();
    f16A->setEngine(new F16AEngine);
    f16A->fly();

    // Create F16-B
    IAircraftPrototype* f16B = prototype->clone();
    f16B->setEngine(new F16BEngine);
    f16B->fly();
}
