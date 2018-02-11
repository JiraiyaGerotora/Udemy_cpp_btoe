#include <iostream>
#include "Rectangle.h"
#include "Circle.h"

void introShape(Shape*);
double calShapeArea(Shape*);
double calShapeCircumference(Shape*);

int main (int argc, char* argv[])
{
    //Rectangle rect(2, 5);
    Shape * rect = new Rectangle(2, 5);
    //Circle circle(3);
    Shape * circle = new Circle(3);

    introShape(rect);
    std::cout << "My area is: " << calShapeArea(rect) << ", ";
    std::cout << "My circumference is: " << calShapeCircumference(rect) << "\n\n";
    introShape(circle);
    std::cout << "My area is: " << calShapeArea(circle) << ", ";
    std::cout << "My circumference is: " << calShapeCircumference(circle) << "\n\n";

    delete rect;
    delete circle;
}

void introShape (Shape * shape)
{
    shape->intro();
}

double calShapeArea (Shape * shape)
{
    return shape->calArea();
}

double calShapeCircumference (Shape * shape)
{
    return shape->calCircumference();
}