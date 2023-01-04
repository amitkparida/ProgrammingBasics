

// From ChatGPT

#include <iostream>
#include <vector>

// Base component class
class Component {
public:
    virtual void Operation() = 0;
};

// Leaf class
class Leaf : public Component {
public:
    void Operation() override {
        std::cout << "Leaf operation" << std::endl;
    }
};

// Composite class
class Composite : public Component {
private:
    std::vector<Component*> children;

public:
    void Operation() override {
        std::cout << "Composite operation" << std::endl;
        for (auto& child : children) {
            child->Operation();
        }
    }

    void AddChild(Component* child) {
        children.push_back(child);
    }

    void RemoveChild(Component* child) {
        //children.erase(std::remove(children.begin(), children.end(), child), children.end());

        auto it = std::find(children.begin(), children.end(), child);
        if (it != children.end())
            children.erase(it);

    }

    Component* GetChild(int index) {
        return children[index];
    }
};

int main() {
    // Initialize leaf objects
    Leaf leaf1, leaf2;

    // Initialize composite object
    Composite composite;

    // Add the leaves to the composite
    composite.AddChild(&leaf1);
    composite.AddChild(&leaf2);

    // Perform operation on composite
    composite.Operation();

    return 0;
}


/*
This example defines a Component class that serves as the base class for both leaf and composite objects. 
The Leaf class is a leaf node in the composite structure and the Composite class is a composite node that can have child components. 
The Operation function is defined in both the Leaf and Composite classes and is used to perform some action on the object.

In the main function, we create two Leaf objects and a Composite object. We add the Leaf objects to the Composite object and 
then call the Operation function on the Composite object. This will result in the Operation function being called on both 
leaf objects as well as the composite object.
*/






/*
 
// https://medium.com/must-know-computer-science/basic-design-patterns-in-c-39bd3d477a5c 
 
#include <vector>
#include <iostream> // std::cout
#include <memory> // std::auto_ptr
#include <algorithm> // std::for_each
using namespace std;

class Graphic
{
public:
    virtual void print() const = 0;
    virtual ~Graphic() {}
};

class Ellipse : public Graphic
{
public:
    void print() const {
        cout << "Ellipse \n";
    }
};

class CompositeGraphic : public Graphic
{
public:
    void print() const {
        for (Graphic* a : graphicList_) {
            a->print();
        }
    }

    void add(Graphic* aGraphic) {
        graphicList_.push_back(aGraphic);
    }

private:
    vector<Graphic*>  graphicList_;
};

int main()
{
    // Initialize four ellipses
    const auto_ptr<Ellipse> ellipse1(new Ellipse());
    const auto_ptr<Ellipse> ellipse2(new Ellipse());
    const auto_ptr<Ellipse> ellipse3(new Ellipse());
    const auto_ptr<Ellipse> ellipse4(new Ellipse());

    // Initialize three composite graphics
    const auto_ptr<CompositeGraphic> graphic(new CompositeGraphic());
    const auto_ptr<CompositeGraphic> graphic1(new CompositeGraphic());
    const auto_ptr<CompositeGraphic> graphic2(new CompositeGraphic());

    // Composes the graphics
    graphic1->add(ellipse1.get());
    graphic1->add(ellipse2.get());
    graphic1->add(ellipse3.get());

    graphic2->add(ellipse4.get());

    graphic->add(graphic1.get());
    graphic->add(graphic2.get());

    // Prints the complete graphic (four times the string "Ellipse")
    graphic->print();
    return 0;
}
*/