
// 1. Factory Method pattern uses factory methods to deal with the problem of creating objects 
// without having to specify the exact class of the object that will be created.
// 
// 2. This is done by creating objects by calling a factory method - either specified in an abstract class
// and implemented by child classes, or implemented in a base class and optionally overriden by derived classes
// rather than by calling a constructor.

/*
#include <iostream>
using namespace std;

//Product
class IVehicle {
public:
	virtual void drive() = 0;
};

//Concrete Product
class TataCar : public IVehicle {
public:
	void drive() {
		cout << "Driving Tata Car" << endl;
	}
};

class TataBike :public IVehicle {
public:
	void drive() {
		cout << "Riding Tata Bike" << endl;
	}
};

class HondaCar : public IVehicle {
public:
	void drive() {
		cout << "Driving Honda Car" << endl;
	}
};

class HondaBike :public IVehicle {
public:
	void drive() {
		cout << "Riding Honda Bike" << endl;
	}
};

//Creator
class IVehicleFactory {
public:
	virtual IVehicle* createVehicle(string vehicleType) = 0;
};

//Concrete creator
class TataFactory :public IVehicleFactory {
public:
	//This is the factory method
	virtual IVehicle* createVehicle(string vehicleType) {
		if (vehicleType == "car") {
			return new TataCar;
		}
		else {
			return new TataBike;
		}
	}
};

//Concrete creator
class HondaFactory :public IVehicleFactory {
public:

	//This is the factory method
	virtual IVehicle* createVehicle(string vehicleType) {
		if (vehicleType == "car") {
			return new HondaCar;
		}
		else {
			return new HondaBike;
		}
	}
};

int main() {
	IVehicleFactory* tatafactory = new TataFactory;
	
	IVehicle* tatacar = tatafactory->createVehicle("car");
	tatacar->drive();
	
	IVehicle* tatabike = tatafactory->createVehicle("bike");
	tatabike->drive();

	
	IVehicleFactory* hondafactory = new HondaFactory;
	
	IVehicle* hondacar = hondafactory->createVehicle("car");
	hondacar->drive();

	IVehicle* hondabike = hondafactory->createVehicle("bike");
	hondabike->drive();
}
*/





// From ChatGPT

#include <iostream>
#include <string>
using namespace std;

// Product
class IVehicle
{
public:
	virtual void drive() = 0;
};

// Concrete product 1
class Car : public IVehicle
{
private:
	string make;
	string model;

public:
	Car(string make, string model) : make(make), model(model) {}

	void drive()
	{
		std::cout << "Driving " << make << " " << model << std::endl;
	}
};

// Concrete product 2
class Bike : public IVehicle
{
private:
	string make;
	string model;

public:
	Bike(string make, string model) : make(make), model(model) {}

	void drive()
	{
		std::cout << "Riding " << make << " " << model << std::endl;
	}
};

// Factory/Creator
class IVehicleFactory
{
public:
	virtual IVehicle* createVehicle(string make, string model) = 0;
};

// Concrete factory/creator 1
class CarFactory : public IVehicleFactory
{
public:
	IVehicle* createVehicle(string make, string model)
	{
		return new Car(make, model);
	}
};

// Concrete factory/creator 2
class BikeFactory : public IVehicleFactory
{
public:
	IVehicle* createVehicle(string make, string model)
	{
		return new Bike(make, model);
	}
};

int main()
{
	IVehicleFactory* car_factory = new CarFactory;
	IVehicle* car = car_factory->createVehicle("Honda", "City");
	car->drive();

	IVehicleFactory* bike_factory = new BikeFactory;
	IVehicle* bike = bike_factory->createVehicle("Yamaha", "R15");
	bike->drive();
}


/*
This program defines a Vehicle class that represents a vehicle and has a single Drive() method. 
It also defines two concrete classes that derive from Vehicle: Car and Bike.

Next, the program defines an IVehicleFactory interface that is the "creator" class in the factory method pattern. 
It has a single pure virtual method, CreateVehicle(), that is responsible for creating instances of Vehicle.

The program also defines two concrete classes that derive from IVehicleFactory: CarFactory and BikeFactory. 
These classes override the CreateVehicle() method to return an instance of Car or Bike, respectively.

In the main() function, we create an instance of CarFactory and use it to create a car, which we then drive. 
We do the same thing with BikeFactory to create a bike and drive it.

The factory method pattern allows us to create different types of vehicles without specifying their concrete classes, 
making it easy to add new types of vehicles to the program without modifying existing code.
*/




/*
// From ChatGPT, using Smart Pointers

#include <iostream>
#include <memory>

// The "Abstract Product" interface
class IVehicle {
public:
	virtual void Drive() = 0;
	virtual ~IVehicle() = default;
};

// Concrete Product classes
class Car : public IVehicle {
public:
	void Drive() override {
		std::cout << "Driving a car." << std::endl;
	}
};

class Motorcycle : public IVehicle {
public:
	void Drive() override {
		std::cout << "Driving a motorcycle." << std::endl;
	}
};

// The "Abstract Factory" interface
class IVehicleFactory {
public:
	virtual std::unique_ptr<IVehicle> CreateVehicle() = 0;
	virtual ~IVehicleFactory() = default;
};

// Concrete Factory classes
class CarFactory : public IVehicleFactory {
public:
	std::unique_ptr<IVehicle> CreateVehicle() override {
		return std::make_unique<Car>();
	}
};

class MotorcycleFactory : public IVehicleFactory {
public:
	std::unique_ptr<IVehicle> CreateVehicle() override {
		return std::make_unique<Motorcycle>();
	}
};

int main() {
	std::unique_ptr<IVehicleFactory> car_factory = std::make_unique<CarFactory>();
	std::unique_ptr<IVehicle> car = car_factory->CreateVehicle();
	car->Drive();

	std::unique_ptr<IVehicleFactory> motorcycle_factory = std::make_unique<MotorcycleFactory>();
	std::unique_ptr<IVehicle> motorcycle = motorcycle_factory->CreateVehicle();
	motorcycle->Drive();

	return 0;
}
*/