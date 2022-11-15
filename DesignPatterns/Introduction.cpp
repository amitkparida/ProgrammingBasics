
// What is Design Pattern?
// - In software Industries, a design pattern is a general repeatable solution to a commonly occurring problem in software design.
// - They give the developer a selection of triedand tested solutions to work with.
// - They are language neutraland so can be applied to any language that supports object - orientation.
// - They have a proven track record as they are already widely used and thus reduce the technical risk to the project.
// - They are highly flexible and can be used in practically any type of application or domain.

// TYPES:
// There are 3 types of design patterns.
// 1. Creational Design Pattern[Further 6 types]
// 2. Structural Design Pattern[Further 8 types]
// 3. Behavioral Design Pattern[Further 12 types]

//1.Creational Design Patterns :
//The first thing that we do while designing any system is, to create classesand instantiate them.How do we do that ?
//Creational Design Patterns solve this problem.
//- Factory
//- Abstract Factory
//- Singleton
//- Builder

//2. Structural Design Patterns :
//After creating the classes and objects, you have to organize these different classes to form a single structureand support a functionality)
//Organizing these to form a structure comes under Structural Design patterns
//- Bridge
//- Adapter
//- Composite

//3. Behavioral Design Patterns
//After creating the classes and after putting them in a structure, we have to see the interaction between the classes,
//how will they communicate with each other.This comes under the Behavioral design Patterns
//- Interpreter
//- Stratergy
//- Observer




// ASSOCIATION, AGGREGATION and COMPOSITION 
// ========================================

//ASSOCIATION - I have a relationship with an object. Foo uses Bar.
class Bar1 {};
class Foo1 {
	void Fun(Bar1 bar) {
	}
};

//AGGREGATION - I have an object which I have borrowed from someone else. When Foo dies, Bar may live on.
class Bar2 {};
class Foo2 {
	Bar2 _bar;
	Foo2(const Bar2& bar) {
		_bar = bar;
	}
};

//COMPOSITION - I own an object and I am responsible for its lifetime. When Foo dies, so does Bar.
class Bar3 {};
class Foo3 {
	Bar3* bar = new Bar3;
};

int main() { }


// How to remember?
// ASSOCIATION - By value
// AGGREGATION - By reference
// COMPOSITION - Foo contains Bar

