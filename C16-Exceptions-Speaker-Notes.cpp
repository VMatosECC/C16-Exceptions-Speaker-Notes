#include <iostream>
#include <string>
#include <stdexcept> // Include this header for std::runtime_error
using namespace std;
//----------------------------------------------------------------
// Simple Lazy Class with a static member variable
// and a constructor. The constructor checks the age
// and throws an exception if the age is greater than 100
//----------------------------------------------------------------
class Person {
private:
    string  name;
    int     age;
    int     id;
    static int count; // static member variable
public:
    //Condensed constructor 
    Person(const string& n = "", int a = 0)
        : name(n), age(a), id(++count + 1000)  {

        if (age >= 100) 
            throw runtime_error("Age violation, check " + name);
    }

    void print() const {
        cout << " Person[ID: " << id << ", Name: " << name 
            << ", Age : " << age << "]" << endl;
    }


};
int Person::count = 0; // static member variable definition


//----------------------------------------------------------------
void experiment01() {
    //Naive version - Fatal Interruption may occur
    Person person1("Homer", 239);
    person1.print();
}
//----------------------------------------------------------------
void experiment02() {
    //Well framed call - uses try-catch blocks
    try {
        Person person1("Homer", 239);
        person1.print();
    }
    catch (exception& e) {
        cout << "ERROR - Call a manager " << endl;
        cout << "REASON: " << e.what() << endl;
    }

}

int main() {

    //experiment01(); // Uses an improper invocation - main may die

    //experiment02(); // Well framed call - uses try-catch blocks
                    // age errors will be caught and main will continue   

    cout << "\nmain=> I'm alive, alive, alive! ... \n" << endl;
}

