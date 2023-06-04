
//Library should be responsible to decide which object type to create based on the input.
//Client should just call library's factory and pass type without worrying about actual implementation of creation of object.

// Factory Design Pattern:
// 1. It creates object for you, rather you initiating object directly
// 2. It is also known as "Virtual Constructor". (Note: C++ does not support Virtual Constructor)

// How to implement FDP
// Ans: Define an interface or an abstract class for creating an object, but let the subclass decide 
// which class to instantiate.

// Advantages:
// 1. Less code change if we change object creation process
// 2. We create object without exposing creation logic to the client
// 3. We get the benefits of virtual consructor


// Factory vs Factory Method vs Abstract Factory
// ===================================================
// 1. Factory itself is responsible for instantiating the object.
//
// 2. Factory Method also is responsible for instantiating the object 
//    but the instantiation logic will be delegated to subclass inheriting the factory.
//
// 3. Abstract Factory is not at all responsible for instantiating instead it will create
//    another concrete factory and force it to have the creation of at least those object
//    which is mentioned in the abstract factory class.


/*
Factory, Factory Method, and Abstract Factory are design patterns used in object - oriented programming to create 
objects in a flexible and modular way.While they all involve the concept of creating objects, they have distinct 
purposes and implementation approaches.Let's explore each pattern:

1. Factory Pattern :
The Factory pattern provides a centralized factory class that encapsulates the object creation logic.It defines 
a common interface for creating objects, but the specific type of object created is determined by the factory class.
The client code requests an object from the factory, which internally decides the concrete implementation to 
instantiate and return.

2. Factory Method Pattern :
The Factory Method pattern focuses on creating objects through subclasses.It defines an abstract base class with 
a method(the factory method) responsible for object creation.Subclasses then implement the factory method to 
instantiate specific objects, allowing for different object types to be created without modifying the client code.

3. Abstract Factory Pattern :
The Abstract Factory pattern provides an interface for creating families of related or dependent objects.
It is useful when there are multiple related objects that need to be created together to ensure their compatibility.
The abstract factory interface declares a set of methods, each responsible for creating a different type of object.
Concrete factory classes implement these methods to produce the desired objects.

To summarize, the Factory pattern provides a centralized factory for creating objects, the Factory Method pattern 
delegates object creation to subclasses, and the Abstract Factory pattern focuses on creating families of related 
objects.Each pattern addresses different needs and can be used based on the specific requirements and structure of 
the application.
*/


#include <iostream>
using namespace std;

//Product
class Vehicle {
public:
	virtual void drive() = 0;
};

//Concrete Product 1
class Car : public Vehicle {
public:
	void drive() {
		cout << "Driving a Car" << endl;
	}
};

//Concrete Product 2
class Bike :public Vehicle {
public:
	void drive() {
		cout << "Riding a Bike" << endl;
	}
};

//Factory class to create objects of different types.
//Change is required only in this function to create a new object type
class VehicleFactory {
public:
	static Vehicle* createVehicle(string vehicleType) {
		Vehicle* pVehicle = nullptr;

		if (vehicleType == "car") {
			pVehicle = new Car;
		}
		else if (vehicleType == "bike") {
			pVehicle = new Bike;
		}
		else {
			cout << "Invalid input" << endl;
		}

		return pVehicle;
	}
};

int main() {
	string vehicleType;
	cout << "Enter Vehicle Type : ";
	cin >> vehicleType;

	Vehicle* pVehicle = VehicleFactory::createVehicle(vehicleType);
	pVehicle->drive();
}


