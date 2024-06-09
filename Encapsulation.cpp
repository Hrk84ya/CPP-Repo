#include <iostream>
#include <string>  
using namespace std;

// Define a class Employee
class Employee {
    private:
        // Private member variables to store the employee's name, age, and company
        string name;
        int age;
        string company;
    public:
        // Method to set the employee's name
        void setName(string n) {
            name = n;
        }
        // Method to set the employee's age
        void setAge(int a) {
            age = a;
        }
        // Method to set the employee's company
        void setCompany(string c) {
            company = c;
        }
        // Method to get the employee's name
        string getName() {
            return name;
        }
        // Method to get the employee's age
        int getAge() {
            return age;
        }
        // Method to get the employee's company
        string getCompany() {
            return company;
        }
};

int main() {
    Employee emp1; // Create an instance of Employee

    // Set the name, age, and company of the employee
    emp1.setName("Harsh");
    emp1.setAge(19);
    emp1.setCompany("Google");

    // Output the employee's details
    cout << emp1.getName() << " is " << emp1.getAge() << " years old and works at " << emp1.getCompany() << endl;

    return 0;
}
