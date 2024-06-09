// Including the necessary header files for input-output operations and string manipulations
#include <iostream>
#include <string>
using namespace std;

int main() {
    // Defining a structure to represent a car with various attributes
    struct {
        int yearOfManufacture;
        string company;
        string modelName;
        string color;
    } myCar1, myCar2; // Declaring two instances of the structure: myCar1 and myCar2

    // Initializing the attributes of the first car (myCar1)
    myCar1.color = "red";
    myCar1.company = "Toyota";
    myCar1.modelName = "Corolla";
    myCar1.yearOfManufacture = 2015;

    // Initializing the attributes of the second car (myCar2)
    myCar2.color = "blue";
    myCar2.company = "Honda";
    myCar2.modelName = "Civic";
    myCar2.yearOfManufacture = 2018;

    // Outputting the details of the first car
    cout << myCar1.company << " " << myCar1.modelName << " of " << myCar1.yearOfManufacture << " is of " << myCar1.color << " color\n";

    // Outputting the details of the second car
    cout << myCar2.company << " " << myCar2.modelName << " of " << myCar2.yearOfManufacture << " is of " << myCar2.color << " color\n";

    return 0; // Indicating that the program ended successfully
}
