#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape
{
    private:
        double radius;
    public:
        Circle();
        Circle(double);
        ~Circle();
        void intro();
        double calArea();
        double calCircumference();
};

#endif // CIRCLE_H
