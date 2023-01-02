
//The "S" in SOLID stands for the Single Responsibility Principle, which states that a class should have only one reason to change. 

//Here is an example of how this principle can be applied in C++ :

#include <iostream>
#include <string>
#include <vector>

// A class that represents a person
class Person
{
private:
    std::string name;
    std::string address;

public:
    Person(const std::string& name, const std::string& address) : name(name), address(address) {}

    std::string get_name() const { return name; }
    std::string get_address() const { return address; }

    void set_address(const std::string& address) { this->address = address; }
};

// A class that represents a persister responsible for saving and loading persons
class Persister
{
public:
    static void save(const Person& p)
    {
        std::cout << "Saving person: " << p.get_name() << std::endl;
        // Save the person to a database or file
    }

    static Person load(const std::string& name)
    {
        std::cout << "Loading person: " << name << std::endl;
        // Load the person from a database or file
        return Person(name, "unknown");
    }
};

int main()
{
    // Create a person and set their address
    Person p("John", "123 Main St.");
    p.set_address("456 Main St.");

    // Save the person
    Persister::save(p);

    // Load the person
    Person p2 = Persister::load("John");

    std::cout << p2.get_name() << " lives at " << p2.get_address() << std::endl;

    return 0;
}


/* 
In this example, the Person class has a single responsibility: to represent a person with a name and address. 
The Persister class has a single responsibility: to save and load persons. This separation of responsibilities makes it 
easier to maintain the code, because changes to the Person class will not affect the Persister class, and vice versa. 
*/




/*
// Here is an example of how the Single Responsibility Principle can be applied in a C++ program that uses the Shape class:

#include <iostream>
#include <string>

// The base class
class Shape
{
public:
    virtual double area() = 0;
};

// A derived class
class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double radius) : radius(radius) {}

    double area() { return 3.14 * radius * radius; }
};

// A derived class
class Rectangle : public Shape
{
private:
    double width;
    double height;

public:
    Rectangle(double width, double height) : width(width), height(height) {}

    double area() { return width * height; }
};

// A class that calculates the area of a shape
class AreaCalculator
{
public:
    static double calculate(Shape& shape)
    {
        return shape.area();
    }
};

int main()
{
    // Calculate the area of a circle
    Circle c(2.0);
    std::cout << "Area of circle: " << AreaCalculator::calculate(c) << std::endl;

    // Calculate the area of a rectangle
    Rectangle r(2.0, 4.0);
    std::cout << "Area of rectangle: " << AreaCalculator::calculate(r) << std::endl;

    return 0;
}

*/


/*
In this example, the Shape class is the base classand it defines a pure virtual method area that must be implemented by derived classes. 
The Circleand Rectangle classes are derived from Shapeand they each implement the area method.

The AreaCalculator class has a static method calculate that takes a Shape referenceand calculates the area. 
The AreaCalculator class has a single responsibility : calculating the area of a shape. This follows the Single Responsibility Principle, 
because the AreaCalculator class has a single, well - defined purpose and does not have any other responsibilities.

This design allows the AreaCalculator class to be used with any class derived from Shape, without the need for modification. 
It also allows new shapes to be added by simply deriving from the Shape classand implementing the area method.
*/