// Decorator Pattern
// https://www.educative.io/courses/software-design-patterns-best-practices/xV9vlmDPJAE

// A decoration is added to something to make it more attractive, in the same spirit, the decorator pattern adds
// new functionality to objects without modifying their defining classes.

// The decorator pattern can be thought of as a wrapper or more formally a way to enhance or extend the behavior of an object dynamically.
// The pattern provides an alternative to subclassing when new functionality is desired.


#include <iostream>
using namespace std;

//Component
class IAircraft {
protected:
    float baseWeight = 100;
public:
    virtual void fly() = 0;
    virtual void land() = 0;
    virtual float getWeight() = 0;
};

//Concrete component
class Boeing747 : public IAircraft {
public:
    void fly() {
        cout << "Boeing-747 flying..." << endl;
    }
    void land() {
        cout << "Boeing-747 landing..." << endl;
    }

    float getWeight() {
        return baseWeight;
    }
};

//Decorator
class BoeingDecorator : public IAircraft {

};

//Concerete Decorator 1
class LuxuryFittings : public BoeingDecorator {
    IAircraft* boeing;

public:
    LuxuryFittings(IAircraft* boeing) {
        this->boeing = boeing;
    }

    void fly() {
        boeing->fly();
    }

    void land() {
        boeing->land();
    }

    float getWeight() {
        return (30.5f + boeing->getWeight());
    }
};

//Concerete Decorator 2
class BulletProof : public BoeingDecorator {
    IAircraft* boeing;

public:
    BulletProof(IAircraft* boeing) {
        this->boeing = boeing;
    }

    void fly() {
        boeing->fly();
    }

    void land() {
        boeing->land();
    }

    float getWeight() {
        return (50.0f + boeing->getWeight());
    }
};


int main() {
    IAircraft* simpleBoeing = new Boeing747();
    IAircraft* luxuriousBoeing = new LuxuryFittings(simpleBoeing);
    IAircraft* bulletProofBoeing = new BulletProof(luxuriousBoeing);
    float netWeight = bulletProofBoeing->getWeight();
    cout << "Final weight of the plane: " << netWeight;
}





/*
// From ChatGPT

#include <iostream>
#include <string>

class Beverage {
public:
    virtual std::string GetDescription() const = 0;
    virtual double GetCost() const = 0;
};

class Espresso : public Beverage {
public:
    std::string GetDescription() const override {
        return "Espresso";
    }

    double GetCost() const override {
        return 1.99;
    }
};

class CondimentDecorator : public Beverage {
public:
    virtual std::string GetDescription() const = 0;
};

class Milk : public CondimentDecorator {
public:
    explicit Milk(Beverage* beverage) : beverage_(beverage) {}

    std::string GetDescription() const override {
        return beverage_->GetDescription() + ", Milk";
    }

    double GetCost() const override {
        return 0.10 + beverage_->GetCost();
    }

private:
    Beverage* beverage_;
};

int main() {
    Beverage* espresso = new Espresso();
    std::cout << espresso->GetDescription() << ": $" << espresso->GetCost()
        << std::endl;

    Beverage* espresso_with_milk = new Milk(espresso);
    std::cout << espresso_with_milk->GetDescription() << ": $"
        << espresso_with_milk->GetCost() << std::endl;

    return 0;
}

*/