
// The "I" in SOLID stands for the Interface Segregation Principle, which states that clients should not be forced 
// to depend on interfaces they do not use. 

// Here is an example of how this principle can be applied in C++:

#include <iostream>
#include <string>

// An interface for shapes
class Shape
{
public:
    virtual double area() = 0;
    virtual double perimeter() = 0;
};

// A derived class that implements the Shape interface
class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double radius) : radius(radius) {}

    double area() { return 3.14 * radius * radius; }
    double perimeter() { return 2 * 3.14 * radius; }
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
    double perimeter() { return 2 * (width + height); }
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

// A class that calculates the perimeter of a shape
class PerimeterCalculator
{
public:
    static double calculate(Shape& shape)
    {
        return shape.perimeter();
    }
};

int main()
{
    // Calculate the area of a circle
    Circle c(2.0);
    std::cout << "Area of circle: " << AreaCalculator::calculate(c) << std::endl;

    // Calculate the perimeter of a rectangle
    Rectangle r(2.0, 4.0);
    std::cout << "Perimeter of rectangle: " << PerimeterCalculator::calculate(r) << std::endl;

    return 0;
}

/*
In this example, the Shape interface defines two methods: area and perimeter. 
The Circle and Rectangle classes are derived from Shape and they each implement both methods.

The AreaCalculator class has a static method calculate that takes a Shape reference and calculates the area. 
The PerimeterCalculator class has a static method calculate that takes a Shape reference and calculates the perimeter.

Each calculator class only depends on the specific methods it uses from the Shape interface, and does not depend on the other methods. 
This allows each calculator class to be used with any class derived from Shape, without the need for the derived classes to implement 
unnecessary methods. This follows the Interface Segregation Principle, because the clients (the calculator classes) are not forced 
to depend on interfaces they do not use.
*/