#include <iostream>

#include "RGB.h"

// constructors
RGB::RGB(): r(0), g(0), b(0) {}

RGB::RGB(int red, int green, int blue) {
    if ((0 <= red && red <= 255) && (0 <= green && green <= 255) && (0 <= blue && blue <= 255)) {
        r = red;
        g = green;
        b = blue;
    }
    else {
        std::cout << "Error: Invalid Input(s)" << std::endl;
    }
}

// getter functions
int RGB::getR() const { return r; }
int RGB::getG() const { return g; }
int RGB::getB() const { return b; }

// print rgb info
void RGB::print() {
    std::cout << "R:\t\t" << getR() << "\nG:\t" << getG() << "\nB:\t\t" << getB() << std:: endl;
}

// static colour functions
RGB RGB::WHITE() {
    return RGB(255, 255, 255);
}

RGB RGB::BLACK() {
    return RGB(0, 0, 0);
}

RGB RGB::RED() {
    return RGB(255, 0, 0);
}

RGB RGB::GREEN() {
    return RGB(0, 255, 0);
}

RGB RGB::BLUE() {
    return RGB(0, 0, 255);
}