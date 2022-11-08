
//Library should be responsible to decide which object type to create based on the input.
//Client should just call library's factory and pass type without worrying about actual implementation of creation of object.

#include <iostream>
using namespace std;

class Vehicle {
public:
	virtual void createVehicle() = 0;
};

class Car : public Vehicle {
public:
	void createVehicle() {
		cout << "Creating Car" << endl;
	}
};

class Bike :public Vehicle {
public:
	void createVehicle() {
		cout << "Creating Bike" << endl;
	}
};

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
	pVehicle->createVehicle();
}


