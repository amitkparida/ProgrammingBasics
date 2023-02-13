
//Strategy design pattern (From ChatGPT)

//The Strategy design pattern is a behavioral design pattern that defines a family of algorithms, encapsulates each one as an object, and makes them interchangeable. 
//This allows the client to choose the best algorithm for the task at hand and change algorithms dynamically during runtime.

//#include <iostream>
//#include <vector>
//
//class SortStrategy {
//public:
//    virtual ~SortStrategy() = default;
//    virtual void Sort(std::vector<int>& data) = 0;
//};
//
//class BubbleSortStrategy : public SortStrategy {
//public:
//    void Sort(std::vector<int>& data) override {
//        std::cout << "Using bubble sort" << std::endl;
//        // Implementation of bubble sort
//    }
//};
//
//class QuickSortStrategy : public SortStrategy {
//public:
//    void Sort(std::vector<int>& data) override {
//        std::cout << "Using quick sort" << std::endl;
//        // Implementation of quick sort
//    }
//};
//
//class Sorter {
//public:
//    Sorter(SortStrategy* strategy) : strategy_(strategy) {}
//
//    void SetSortStrategy(SortStrategy* strategy) {
//        strategy_ = strategy;
//    }
//
//    void Sort(std::vector<int>& data) {
//        strategy_->Sort(data);
//    }
//
//private:
//    SortStrategy* strategy_;
//};
//
//int main() {
//    std::vector<int> data = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };
//
//    Sorter sorter(new BubbleSortStrategy());
//    sorter.Sort(data);
//
//    sorter.SetSortStrategy(new QuickSortStrategy());
//    sorter.Sort(data);
//
//    return 0;
//}

// In this example, the SortStrategy class defines the interface for sorting algorithms.The BubbleSort Strategy and QuickSort Strategy classes are concrete 
// implementations of the sorting algorithms. The Sorter class is responsible for sorting a collection of numbers. It contains a reference to a SortStrategy
// object and delegates the sorting operation to the encapsulated strategy. The client code can change the sorting strategy at runtime by calling 
// the setSortStrategy method.




// From https://www.youtube.com/watch?v=u8DttUrXtEw

using namespace std;
#include <iostream>
#include<string>
using namespace std;

class DriveStratergy {
public:
    virtual void drive() = 0;
};

class NormalDrive : public DriveStratergy {
public:
    void drive() {
        cout << "Normal drive" << endl;
    }
};

class SpecialDrive : public DriveStratergy {
public:
    void drive() {
        cout << "Fast drive" << endl;
    }
};


class Vehicle {
private:
    DriveStratergy* ds;
public:
    Vehicle(DriveStratergy* ds) {
        this->ds = ds;
    }

    void drive() {
        ds->drive();
    }
};

class SportsVehicle : public Vehicle {
public:
    SportsVehicle() :Vehicle(new SpecialDrive()) {

    }
};

class OffroadVehicle : public Vehicle {
public:
    OffroadVehicle() :Vehicle(new SpecialDrive()) {

    }
};

class PassengerVehicle : public Vehicle {
public:
    PassengerVehicle() :Vehicle(new NormalDrive()) {

    }
};

int main(void) {
    OffroadVehicle ov;
    ov.drive();

    PassengerVehicle pv;
    pv.drive();

    return 0;
}
