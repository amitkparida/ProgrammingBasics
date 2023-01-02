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

//Abstract Product A
class ICar {
public:
	virtual void drive() = 0;
};

//Concrete Product A1
class TataCar :public ICar {
public:
	void drive() {
		cout << "Driving Tata Car" << endl;
	}
};

//Concrete Product A2
class HondaCar :public ICar {
public:
	void drive() {
		cout << "Driving Honda Car" << endl;
	}
};

//Abstract Product B
class IBike {
public:
	virtual void drive() = 0;
};

//Concrete Product B1
class TataBike :public IBike {
public:
	void drive() {
		cout << "Riding Tata Bike" << endl;
	}
};

//Concrete Product B2
class HondaBike :public IBike {
public:
	void drive() {
		cout << "Riding Honda Bike" << endl;
	}
};

//Abstract factory 
class IVehicleFactory {
public:
	virtual ICar* createCar() = 0;
	virtual IBike* createBike() = 0;
};

//Concrete Factory 1 : This is factory of Tata which will actually create the objects/products
class TataFactory :public IVehicleFactory {
public:
	virtual ICar* createCar() {
		return new TataCar;
	}

	virtual IBike* createBike() {
		return new TataBike;
	}
};

//Concrete Factory 2 : This is factory of Honda which will actually create the objects/products
class HondaFactory :public IVehicleFactory {
public:
	ICar* createCar() {
		return new HondaCar;
	}

	IBike* createBike() {
		return new HondaBike;
	}
};

class VehicleAbstractFactory {
public:
	static IVehicleFactory* CreateFactory(string vehicleBrand) {
		if (vehicleBrand == "tata") {
			return new TataFactory;
		}
		else if (vehicleBrand == "honda") {
			return new HondaFactory;
		}
		else {
			cout << "Invalid input" << endl;

		}
	}
};

int main() {
	cout << "Enter vehicle brand name (tata/honda): ";
	string vehicleCompany;
	cin >> vehicleCompany;

	IVehicleFactory* factory = VehicleAbstractFactory::CreateFactory(vehicleCompany);

	ICar* car = factory->createCar();
	car->drive();

	IBike* bike = factory->createBike();
	bike->drive();
}






