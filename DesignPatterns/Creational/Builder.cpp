
// Question: WHY Builder Design Pattern
// Answer  : Because I want to build an object (Car) and it is compossed of complex 
//           objects(body, engine) step by step.
//			 And I want to create these complex objects step by step (Director will handle that)

//In Builder class, product is a member
//In Director class, Builder is a member
//Director will use the Builder to build the product.
//To summerize, Builder has product. Director has builder which is going to use the builder to create the product

#include <iostream>
using namespace std;

//Your end product
class Car {
	string m_body;
	string m_engine;
public:
	void setBody(string body) {
		m_body = body;
	}
	void setEngine(string engine) {
		m_engine = engine;
	}
	void showCar() {
		cout << "Body   : " << m_body << endl
			 << "Engine : " << m_engine << endl << endl;
	}
};

//CarBuilder abstract class 
class CarBuilder {
protected:
	Car* m_pCar;

public:
	CarBuilder() {
		m_pCar = new Car();
	}

	virtual void buildBody() = 0;
	virtual void buildEngine() = 0;

	virtual Car* getCar() {
		return m_pCar;
	}

	virtual ~CarBuilder() {
		delete m_pCar;
	}
};

//TataCarBuilder concrete class, knows only how to build Tata Car
class TataCarBuilder : public CarBuilder
{
public:
	void buildBody() {
		m_pCar->setBody("Tata Car Body");
	}
	void buildEngine() {
		m_pCar->setEngine("Tata Car Engine");
	}
};

//HondaCarBuilder concrete class, knows only how to build Honda Car
class HondaCarBuilder : public CarBuilder
{
public:
	void buildBody() {
		m_pCar->setBody("Honda Car Body");
	}
	void buildEngine() {
		m_pCar->setEngine("Honda Car Engine");
	}
};

//Director: It defines the steps and tells the builder to follow those steps to build the product.
class Director
{
private:
	CarBuilder* m_pCarBuilder;

public:
	Director(CarBuilder* pCarBuilder) {
		m_pCarBuilder = pCarBuilder;
	}

	Car* buildCar() {
		m_pCarBuilder->buildBody();
		m_pCarBuilder->buildEngine();

		return m_pCarBuilder->getCar();
	}
};

int main() {
	TataCarBuilder tataCarBuilder;
	Director dir(&tataCarBuilder);
	Car* pTataCar = dir.buildCar();
	pTataCar->showCar();

	HondaCarBuilder hondaCarBuilder;
	Director dir2(&hondaCarBuilder);
	Car* pHondaCar = dir2.buildCar();
	pHondaCar->showCar();
}


