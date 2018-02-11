#include "Circle.h"
#include <iostream>

#define PI 3.14

Circle::Circle()
{
}

Circle::Circle (double radius)
{
    this->radius = radius;
}

Circle::~Circle()
{
    std::cout << "Circle Destructor\n";
}

void Circle::intro()
{
    std::cout << "I am a Circle!\n";
}

double Circle::calArea()
{
    return PI * this->radius * this->radius;
}

double Circle::calCircumference()
{
    return 2 * PI * this->radius;
}
