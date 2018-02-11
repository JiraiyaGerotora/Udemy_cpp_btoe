#include <iostream>
#include "Rectangle.h"


Rectangle::Rectangle()
{
}

Rectangle::Rectangle (double height, double width)
{
    this->height = height;
    this->width = width;
}

Rectangle::~Rectangle()
{
    std::cout << "Rectangle Destructor\n";
}

void Rectangle::intro()
{
    std::cout << "I am a Rectangle!\n";
}

double Rectangle::calArea()
{
    return this->height * this->width;
}

double Rectangle::calCircumference()
{
    return 2 * (this->height + this->width);
}
