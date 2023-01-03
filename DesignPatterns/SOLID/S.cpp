
//The "S" in SOLID stands for the Single Responsibility Principle, which states that a class should have only one reason to change. 

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


/*
In this example, the Shape class is the base class and it defines a pure virtual method area that must be implemented by derived classes. 
The Circle and Rectangle classes are derived from Shape and they each implement the area method.

The AreaCalculator class has a static method calculate that takes a Shape reference and calculates the area. 
The AreaCalculator class has a single responsibility : calculating the area of a shape. This follows the Single Responsibility Principle, 
because the AreaCalculator class has a single, well defined purpose and does not have any other responsibilities.

This design allows the AreaCalculator class to be used with any class derived from Shape, without the need for modification. 
It also allows new shapes to be added by simply deriving from the Shape class and implementing the area method.
*/