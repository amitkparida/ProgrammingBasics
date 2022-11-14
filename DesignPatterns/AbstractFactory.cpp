// Factory design pattern was creating concrete classes or objects. 
// Abstract Factory design pattern is going to create factories that are going to create objects.
// Basically, abstract Factory design pattern is going to create a family of objects

#include <iostream>
using namespace std;

class IButton {
public:
	virtual void click() = 0;
};

class MacButton :public IButton {
public:
	void click() {
		cout << "Clicking Mac Button" << endl;
	}
};

class WinButton :public IButton {
public:
	void click() {
		cout << "Clicking Windows Button" << endl;
	}
};

class ITextBox {
public:
	virtual void showText() = 0;
};

class MacTextBox :public ITextBox {
public:
	void showText() {
		cout << "Showing Mac TextBox" << endl;
	}
};

class WinTextBox :public ITextBox {
public:
	void showText() {
		cout << "Showing Windows TextBox" << endl;
	}
};

class IFactory {
public:
	virtual IButton* CreateButton() = 0;
	virtual ITextBox* CreateTextBox() = 0;

};

class MacFactory :public IFactory {
public:
	virtual IButton* CreateButton() {
		return new MacButton;
	}

	virtual ITextBox* CreateTextBox() {
		return new MacTextBox;
	}
};

class WinFactory :public IFactory {
public:
	virtual IButton* CreateButton() {
		return new WinButton;
	}

	virtual ITextBox* CreateTextBox() {
		return new WinTextBox;
	}
};

class GUIAbstractFactory {
public:
	static IFactory* CreateFactory(string osType) {
		if (osType == "windows") {
			return new WinFactory;
		}
		else if (osType == "mac") {
			return new MacFactory;
		}
		else {
			return new MacFactory; //Default if also Mac, for example
		}
	}
};

int main() {
	cout << "Enter you machine OS " << endl;
	string osType;
	cin >> osType;

	IFactory* fact = GUIAbstractFactory::CreateFactory(osType);

	IButton* button = fact->CreateButton();
	button->click();

	ITextBox* textBox = fact->CreateTextBox();
	textBox->showText();
}

