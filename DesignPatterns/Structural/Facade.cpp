
// Facade Pattern:
// The word “facade” means a deceptive front or appearance. 
// Following this definition, a Facade pattern provides a simpler interface that hides the complex functionalities of a system. 
// The Facade pattern allows us to hide all the messy logic from the client and only display the clear and easy-to-use interface to them. 
// This allows the client to interact with an API easily in a less error-prone way and without accessing the inner workings directly.
// It provides a simplified interface to a library, a framework, or any other complex set of classes.



/*Facade is one of the easiest patterns I think... And this is very simple example.

Imagine you set up a smart house where everything is on remote. So to turn the lights on you push lights on button - And same for TV,
AC, Alarm, Music, etc...

When you leave a house you would need to push a 100 buttons to make sure everything is off and are good to go which could be little
annoying if you are lazy like me
so I defined a Facade for leaving and coming back. (Facade functions represent buttons...) So when I come and leave I just make one
call and it takes care of everything...
*/

#include <string>
#include <iostream>
using namespace std;

// Subsystem class
class Alarm
{
public:
	void alarmOn()
	{
		cout << "Alarm is on and house is secured" << endl;
	}

	void alarmOff()
	{
		cout << "Alarm is off and you can go into the house" << endl;
	}
};

// Subsystem class
class AC
{
public:
	void acOn()
	{
		cout << "Ac is on" << endl;
	}

	void acOff()
	{
		cout << "AC is off" << endl;
	}
};

// Subsystem class
class TV
{
public:
	void tvOn()
	{
		cout << "Tv is on" << endl;
	}

	void tvOff()
	{
		cout << "TV is off" << endl;
	}
};

// Facade
class HouseFacade
{
	Alarm alarm;
	AC ac;
	TV tv;

public:
	HouseFacade() {}

	void goToWork()
	{
		ac.acOff();
		tv.tvOff();
		alarm.alarmOn();
	}

	void comeHome()
	{
		alarm.alarmOff();
		ac.acOn();
		tv.tvOn();
	}
};

int main()
{
	HouseFacade hf;

	//Rather than calling 100 different on and off functions thanks to facade I only have 2 functions...
	hf.goToWork();
	hf.comeHome();
}