#include <iostream>
#include <string>
using namespace std;

int main(){
    struct{
        int yearOfManufacture;
        string company;
        string modelName;
        string color;
    }myCar1,myCar2;

    myCar1.color="red";
    myCar1.company="Toyota";
    myCar1.modelName="Corolla";
    myCar1.yearOfManufacture=2015;

    myCar2.color="blue";
    myCar2.company="Honda";
    myCar2.modelName="Civic";
    myCar2.yearOfManufacture=2018;

    cout <<myCar1.company<<" "<<myCar1.modelName<<" of "<<myCar1.yearOfManufacture<<" is of "<<myCar1.color<<" color\n";
    cout <<myCar2.company<<" "<<myCar2.modelName<<" of "<<myCar2.yearOfManufacture<<" is of "<<myCar2.color<<" color\n";

    return 0;
}