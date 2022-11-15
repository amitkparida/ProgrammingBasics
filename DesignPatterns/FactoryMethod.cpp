// I referred one YouTube video for this program. I am not confident about this program
// https://www.youtube.com/watch?v=E2VZNLNptLg&list=PLJhxHp6j1l-8_kjEL2hVJDs0_4eJbHtWH&index=9


#include <iostream>
using namespace std;

class IVehicle {
public:
	virtual void printVehicle() = 0;
};

class TataCar : public IVehicle {
public:
	void printVehicle() {
		cout << "I am a Tata Car" << endl;
	}
};

class TataBike :public IVehicle {
public:
	void printVehicle() {
		cout << "I am a Tata Bike" << endl;
	}
};

class HondaCar : public IVehicle {
public:
	void printVehicle() {
		cout << "I am a Honda Car" << endl;
	}
};

class HondaBike :public IVehicle {
public:
	void printVehicle() {
		cout << "I am a Honda Bike" << endl;
	}
};

class IVehicleFactory {
public:

	//This is the factory method
	virtual IVehicle* getVehicle(string vehicleType) = 0;
};

class TataFactory :public IVehicleFactory {
public:

	//This is the factory method
	virtual IVehicle* getVehicle(string vehicleType) {
		if (vehicleType == "car") {
			return new TataCar;
		}
		else {
			return new TataBike;
		}
	}
};

class HondaFactory :public IVehicleFactory {
public:

	//This is the factory method
	virtual IVehicle* getVehicle(string vehicleType) {
		if (vehicleType == "car") {
			return new HondaCar;
		}
		else {
			return new HondaBike;
		}
	}
};

int main() {

	IVehicleFactory* tata = new TataFactory;
	IVehicle* tatacar = tata->getVehicle("car");
	IVehicle* tatabike = tata->getVehicle("bike");
	tatacar->printVehicle();
	tatabike->printVehicle();

	IVehicleFactory* honda = new HondaFactory;
	IVehicle* hondacar = honda->getVehicle("car");
	IVehicle* hondabike = honda->getVehicle("bike");
	hondacar->printVehicle();
	hondabike->printVehicle();
}
