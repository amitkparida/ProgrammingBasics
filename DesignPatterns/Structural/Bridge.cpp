
// Bridge Design Pattern:
// https://www.educative.io/courses/software-design-patterns-best-practices/gx8GZWB7pO6

// Bridge is a structural design pattern that lets you split a large class or a set of closely related classes into 
// two separate hierarchies—abstraction and implementation—which can be developed independently of each other.


// Suppose you are writing software for Toyota Motors and need to represent Toyota Corolla. We'll use an abstract 
// class Corolla to represent the car. The concrete classes would represent each of the different models (L, XLE) of the car. 

// However, the same model could be built to different standards for different countries. 
// For instance, the North American model may have different safety requirements than an Asian model. 
// The same model could be left or right handed depending on which country it is being shipped to. 
// Corolla has several models and the models have different names in different countries. 
// In the US, the different models include L, LE, XLE etc. For our purposes we'll consider only one model L.

// We can divide the above class structure into two hierarchies. One (AbstractCorolla) that just represents the models 
// of the car and another (AbstractCorollaImpl) that represents the location - specific variations for each model of the car. 

// The class AbstractCorolla (the abstraction) would hold a reference to an object of the class AbstractCorollaImpl (the implementation) and 
// invoke method calls on the implementation object. We are using object composition to add location dependent behavior to each model of the car.

#include <iostream>
using namespace std;

//Implementor
class AbstractCorollaImpl {
public:
    virtual void listSafetyEquipment() = 0;
    virtual bool isCarRightHanded() = 0;
};

class Corolla_L_Impl_AsiaPacific : public AbstractCorollaImpl {
public:
    void listSafetyEquipment() {
        cout << "Not so safe." << endl;
    }

    bool isCarRightHanded() {
        return false;
    }
};

//Concrete Implementor
class Corolla_L_Impl_NorthAmerica : public AbstractCorollaImpl {
public:
    void listSafetyEquipment() {
        cout << "High safety standards." << endl;
    }

    bool isCarRightHanded() {
        return true;
    }
};


//Abstraction
class  AbstractCorolla {
protected:
    AbstractCorollaImpl* corollaImpl;

public:
    AbstractCorolla(AbstractCorollaImpl* corollaImpl) {
        this->corollaImpl = corollaImpl;
    }

    virtual void listSafetyEquipment() = 0;
    virtual bool isCarRightHanded() = 0;

    void setCorollaImpl(AbstractCorollaImpl* corollaImpl){
        this->corollaImpl = corollaImpl;
    }
};

//Refined abstraction
class Corolla_L : public AbstractCorolla {
public:
    Corolla_L(AbstractCorollaImpl* corollaImpl) : AbstractCorolla(corollaImpl) {
    }

    void listSafetyEquipment() {
        corollaImpl->listSafetyEquipment();

    }

    bool isCarRightHanded() {
        return corollaImpl->isCarRightHanded();
    }
};



 int main() {
    AbstractCorolla* myCorolla = new Corolla_L(new Corolla_L_Impl_AsiaPacific());
    cout << myCorolla->isCarRightHanded() << endl;
    myCorolla->listSafetyEquipment();

    myCorolla->setCorollaImpl(new Corolla_L_Impl_NorthAmerica());
    cout << myCorolla->isCarRightHanded() << endl;
    myCorolla->listSafetyEquipment();
 }




/*
// From ChatGPT

#include <iostream>

// Implementor
class IDrawAPI
{
public:
    virtual void drawCircle(int x, int y, int radius) = 0;
};

// Concrete Implementor
class RedCircle : public IDrawAPI
{
public:
    void drawCircle(int x, int y, int radius)
    {
        std::cout << "Drawing Circle[ color: red, x: " << x << ", y: " << y << ", radius: " << radius << " ]" << std::endl;
    }
};

// Concrete Implementor
class GreenCircle : public IDrawAPI
{
public:
    void drawCircle(int x, int y, int radius)
    {
        std::cout << "Drawing Circle[ color: green, x: " << x << ", y: " << y << ", radius: " << radius << " ]" << std::endl;
    }
};


 // Abstraction
 class Shape
 {
 protected:
     // Composition - the bridge design pattern allows the
     // abstraction to be composed with different implementations
     IDrawAPI* drawAPI;

 public:
     Shape(IDrawAPI* drawAPI)
     {
         this->drawAPI = drawAPI;
     }

     virtual void draw() = 0;
 };

 // Refined Abstraction
 class Circle : public Shape
 {
 private:
     int x, y, radius;

 public:
     Circle(int x, int y, int radius, IDrawAPI* drawAPI) : Shape(drawAPI)
     {
         this->x = x;
         this->y = y;
         this->radius = radius;
     }

     void draw()
     {
         // Delegate to the drawAPI
         drawAPI->drawCircle(x, y, radius);
     }
 };


 int main()
 {
     // The client code should be able to work with any pre-configured
     // bridge and implementation
     Shape* circle = new Circle(1, 2, 3, new RedCircle());
     circle->draw();

     circle = new Circle(5, 7, 11, new GreenCircle());
     circle->draw();

     return 0;
 }
 */