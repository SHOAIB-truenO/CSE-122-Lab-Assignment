//QUESTION NUMBER 1: C++ program to implement inheritance with following requirements,
//Classes :- Animal.//cpp, bird.cpp, canine.cpp, main.cpp (to test it) :-
//-You may need getters and setters also.
//1. Declare and define an animal base class:
// animal stores an age (int), a unique long ID (a boolean that is
//true if it is alive, and a location (a pair of double).
// animal requires a default constructor and a 3 parameter
//constructor. Both constructors should set the unique ID
//automatically. They should also set the alive boolean to true.
//The three parameter constructor should accept an int for the
//ge and two doubles for the set of coordinates. The default
//should set these three values to 0.
// animal requires a virtual move method which accepts two
//doubles that represent two coordinates, and ‘moves’ the
//animal to the set of coordinates.
// animal requires a copy constructor and a virtual destructor.
//The destructor should be virtual.
// animal requires a virtual sleep method and a virtual eat
//method. Both methods return void. Both methods should print
//an appropriate message to cout.
// animal requires a setAlive function which accepts a boolean.
//This is a void function that changes the alive data member to
//the value of the boolean that is passed in.
//Overload the insertion operator for the animal.



#include <iostream>
using namespace std;

class Animal {
public:
    Animal() : age(0), alive(true), id(++count), location(make_pair(0,0)) {}

    Animal(int age, double x, double y) : age(age), alive(true), id(++count), location(make_pair(x, y)) {}

    Animal(const Animal& other) : age(other.age), alive(other.alive), id(++count), location(other.location) {}

    virtual ~Animal() {}

    virtual void move(double x, double y) {
        location = make_pair(x, y);
    }

    virtual void sleep() {
        cout << "The animal is asleep." << endl;
    }

    virtual void eat() {
        cout << "The animal is eating." << endl;
    }

    void setAlive(bool value) {
        alive = value;
    }

    friend ostream& operator<<(ostream& os, Animal& animal) {
        os << "ID: " << animal.id << ", Age: " << animal.age << ", Location: (" << animal.location.first << ", " << animal.location.second << "), Alive: " << animal.alive;
        return os;
    }

protected:
    int age;
    long id;
    bool alive;
    pair<double, double> location;

private:
    static long count;
};

long Animal::count = 0;

class Bird : public Animal {
public:
    Bird() : Animal() {}
    
    Bird(int age, double x, double y) : Animal(age, x, y) {}

    virtual ~Bird() {}

    void move(double x, double y) {
        cout << "The bird is flying to (" << x << ", " << y << ")." << endl;
        Animal::move(x, y);
    }
    
    void sleep() {
        cout << "The bird is asleep." << endl;
    }
    
    void eat() {
        cout << "The bird is eating." << endl;
    }
};

class Canine : public Animal {
public:
    Canine() : Animal() {}

    Canine(int age, double x, double y) : Animal(age, x, y) {}

    virtual ~Canine() {}

    void move(double x, double y) {
        cout << "The canine is running to (" << x << ", " << y << ")." << endl;
        Animal::move(x, y);
    }

    void sleep() {
        cout << "The canine is asleep." << endl;
    }

    void eat() {
        cout << "The canine is eating." << endl;
    }
};

int main() {
    Canine obj(5, 10.0, 20.0);
    obj.sleep();
    obj.eat();
    obj.move(30.0, 40.0);
    cout << obj << endl;
 return 0;
}
