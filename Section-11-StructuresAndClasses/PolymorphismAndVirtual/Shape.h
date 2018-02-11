#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

class Shape
{
    public:
        Shape() { };
        virtual ~Shape() { std::cout << "Shape Destructor\n"; };
        virtual void intro() = 0;
        virtual double calArea() = 0;
        virtual double calCircumference() = 0;
};

#endif // SHAPE_H
