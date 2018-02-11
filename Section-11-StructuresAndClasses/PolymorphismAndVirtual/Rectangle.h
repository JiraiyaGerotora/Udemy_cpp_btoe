#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
    private:
        double height;
        double width;
    public:
       Rectangle();
       Rectangle(double, double);
       ~Rectangle();
       void intro();
       double calArea();
       double calCircumference();
};


#endif // RECTANGLE_H
