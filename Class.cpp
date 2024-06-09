// Including necessary header files for input-output operations and string manipulations
#include <iostream>
#include <string>
using namespace std;

// Defining a class named Car
class Car {
    public:
        // Public member variables to store details about the car
        int yearOfManufacture;
        string company;
        string modelName;
        string color;

        // Member function to simulate car acceleration, defined inside the class
        void accelerate() {
            cout << "Accelerating the car\n";
        }

        // Declaration of a member function to simulate car braking, to be defined outside the class
        void brake();
};

// Definition of the brake function, which was declared inside the Car class
void Car::brake() {
    cout << "Brakes applied\n";
}

int main() {
    // Creating an instance of Car named myCar1 and setting its attributes
    Car myCar1;
    myCar1.color = "red";
    myCar1.company = "Toyota";
    myCar1.modelName = "Corolla";
    myCar1.yearOfManufacture = 2015;

    // Creating another instance of Car named myCar2 and setting its attributes
    Car myCar2;
    myCar2.color = "blue";
    myCar2.company = "Honda";
    myCar2.modelName = "Civic";
    myCar2.yearOfManufacture = 2018;

    // Outputting the details of myCar1
    cout << myCar1.company << " " << myCar1.modelName << " of " << myCar1.yearOfManufacture << " is of " << myCar1.color << " color\n";
    myCar1.accelerate(); // Calling the accelerate function for myCar1

    cout << "\n"; // Printing a newline for better readability

    // Outputting the details of myCar2
    cout << myCar2.company << " " << myCar2.modelName << " of " << myCar2.yearOfManufacture << " is of " << myCar2.color << " color\n";
    myCar2.brake(); // Calling the brake function for myCar2

    return 0;
}
