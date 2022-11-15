// Factory design pattern was creating concrete classes or objects. 
// Abstract Factory design pattern is going to create factories that are going to create objects.
// Basically, abstract Factory design pattern is going to create a family of objects

// Abstracte Factory Design Pattern:
// It defines an abstract class for creating families of related objects but without specifying their concrete sub-class.

//Why/When to use Abstract Factory Design Pattern?
// 1. You need system to be independent of how objects are created, composed and represented.
// 2. Show interface, not implementation
// 3. System need to be configured with one of the multiple family of objects.

#include <iostream>
using namespace std;

class ICar {
public:
	virtual void printCar() = 0;
};

class TataCar :public ICar {
public:
	void printCar() {
		cout << "Tata Car" << endl;
	}
};

class HondaCar :public ICar {
public:
	void printCar() {
		cout << "Honda Car" << endl;
	}
};

class IBike {
public:
	virtual void printBike() = 0;
};

class TataBike :public IBike {
public:
	void printBike() {
		cout << "Tata Bike" << endl;
	}
};

class HondaBike :public IBike {
public:
	void printBike() {
		cout << "Honda Bike" << endl;
	}
};

//This is abstract factory which will return factory of similar objects
//Example Tata, Honda etc
class IVehicleFactory {
public:
	virtual ICar* getCar() = 0;
	virtual IBike* getBike() = 0;
};

//This is a factory of similar object which will actually create the objects
class TataFactory :public IVehicleFactory {
public:
	virtual ICar* getCar() {
		return new TataCar;
	}

	virtual IBike* getBike() {
		return new TataBike;
	}
};

class HondaFactory :public IVehicleFactory {
public:
	ICar* getCar() {
		return new HondaCar;
	}

	IBike* getBike() {
		return new HondaBike;
	}
};

class VehicleAbstractFactory {
public:
	static IVehicleFactory* CreateFactory(string vehicleBrand) {
		if (vehicleBrand == "Tata") {
			return new TataFactory;
		}
		else if (vehicleBrand == "Honda") {
			return new HondaFactory;
		}
		else {
			cout << "Invalid input" << endl;

		}
	}
};

int main() {
	cout << "Enter vehicle brand name (Tata/Honda): ";
	string vehicleCompany;
	cin >> vehicleCompany;

	IVehicleFactory* factory = VehicleAbstractFactory::CreateFactory(vehicleCompany);

	ICar* car = factory->getCar();
	car->printCar();

	IBike* bike = factory->getBike();
	bike->printBike();
}
