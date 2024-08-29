#include <iostream>

class Rectangle {
public:
    int width, height;

    int area() {
        return width * height;
    }
};

int main() {
    Rectangle rect;
    rect.width = 10;
    rect.height = 5;
    
    std::cout << "Area of rectangle: " << rect.area() << std::endl;

    return 0;
}
