
// The "O" in SOLID stands for the Open-Closed Principle, which states that a class should be open for extension but closed for modification. 

// Here is an example of how this principle can be applied in C++:

#include <iostream>
#include <string>
#include <vector>

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

// A class that calculates the total area of a set of shapes
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
In this example, the Shape class is the base class and it defines a pure virtual method area that must be implemented by derived classes.
The Circle and Rectangle classes are derived from Shape and they each implement the area method.

The AreaCalculator class has a list of Shape pointers and a method total_area that calculates the total area of all the shapes. 
The AreaCalculator class is open for extension, because new shapes can be added by simply deriving from the Shape class and implementing 
the area method. The AreaCalculator class is closed for modification, because the total_area method does not need to be modified 
to support new shapes. This allows the AreaCalculator class to be used with any number of shapes, without the need for modification.
*/