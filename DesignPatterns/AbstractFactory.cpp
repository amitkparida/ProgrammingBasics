// Factory design pattern was creating concrete classes or objects. 
// Abstract Factory design pattern is going to create factories that are going to create objects.
// Basically, abstract Factory design pattern is going to create a family of objects

#include <iostream>
using namespace std;

class ICar {
public:
	virtual void driveCar() = 0;
};

class TataCar :public ICar {
public:
	void driveCar() {
		cout << "Driving Tata Car" << endl;
	}
};

class HondaCar :public ICar {
public:
	void driveCar() {
		cout << "Driving Honda Car" << endl;
	}
};

class IBike {
public:
	virtual void rideBike() = 0;
};

class TataBike :public IBike {
public:
	void rideBike() {
		cout << "Riding Tata Bike" << endl;
	}
};

class HondaBike :public IBike {
public:
	void rideBike() {
		cout << "Riding Honda Bike" << endl;
	}
};

class IVehicleFactory {
public:
	virtual ICar* createCar() = 0;
	virtual IBike* createBike() = 0;

};

class TataFactory :public IVehicleFactory {
public:
	virtual ICar* createCar() {
		return new TataCar;
	}

	virtual IBike* createBike() {
		return new TataBike;
	}
};

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
	string vehicleBrand;
	cin >> vehicleBrand;

	IVehicleFactory* factory = VehicleAbstractFactory::CreateFactory(vehicleBrand);

	ICar* car = factory->createCar();
	car->driveCar();

	IBike* bike = factory->createBike();
	bike->rideBike();
}

