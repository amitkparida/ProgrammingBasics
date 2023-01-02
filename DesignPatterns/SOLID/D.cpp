
// The "D" in SOLID stands for the Dependency Inversion Principle, which states that high-level modules should 
// not depend on low-level modules, but rather both should depend on abstractions. 
// Here is an example of how this principle can be applied in C++:

#include <iostream>
#include <string>
#include <vector>

// An interface for shapes
class Shape
{
public:
    virtual double area() = 0;
};

// A derived class that implements the Shape interface
class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double radius) : radius(radius) {}

    double area() { return 3.14 * radius * radius; }
};

// A derived class that implements the Shape interface
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
private:
    std::vector<Shape*> shapes;

public:
    void add_shape(Shape* shape) { shapes.push_back(shape); }

    double total_area()
    {
        double total = 0.0;
        for (auto shape : shapes)
        {
            total += shape->area();
        }
        return total;
    }
};

int main()
{
    // Create some shapes and add them to the calculator
    Circle c(2.0);
    Rectangle r(2.0, 4.0);
    AreaCalculator calc;
    calc.add_shape(&c);
    calc.add_shape(&r);

    // Calculate the total area
    std::cout << "Total area: " << calc.total_area() << std::endl;

    return 0;
}


/*
In this example, the Shape interface defines a single method: area. 
The Circle and Rectangle classes are derived from Shape and they each implement the area method.

The AreaCalculator class has a list of Shape pointers and a method total_area that calculates the total area of all the shapes. 
The AreaCalculator class depends on the Shape interface, rather than on the concrete Circle and Rectangle classes. 
This follows the Dependency Inversion Principle, because the AreaCalculator class (a high-level module) depends on an 
abstraction (the Shape interface), rather than on a concrete implementation (the Circle and Rectangle classes).

This design allows the AreaCalculator class to be used with any class derived from Shape, without the need for modification. 
It also allows new shapes to be added by simply deriving from the Shape interface and implementing the area method.
*/