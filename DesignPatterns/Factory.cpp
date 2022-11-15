
//Library should be responsible to decide which object type to create based on the input.
//Client should just call library's factory and pass type without worrying about actual implementation of creation of object.

// Factory Design Pattern:
// 1. It creates object for you, rather you initiating object directly
// 2. It is also known as "Virtual Constructor". (Note: C++ does not support Virtual Constructor)

// How to implement FDP
// Ans: Define an interface or an abstract class for creating an object, but let the subclass decide which class to initiate.

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
//    another concrete factoryand force it to have the creation of at least those object
//    which is mentioned in the abstract factory class.


#include <iostream>
using namespace std;

class Vehicle {
public:
	virtual void printVehicle() = 0;
};

class Car : public Vehicle {
public:
	void printVehicle() {
		cout << "I am a Car" << endl;
	}
};

class Bike :public Vehicle {
public:
	void printVehicle() {
		cout << "I am a Bike" << endl;
	}
};

//Factory class to create objects of different types.
//Change is required only in this function to create a new object type
class VehicleFactory {
public:
	static Vehicle* getVehicle(string vehicleType) {
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

	Vehicle* pVehicle = VehicleFactory::getVehicle(vehicleType);
	pVehicle->printVehicle();
}


