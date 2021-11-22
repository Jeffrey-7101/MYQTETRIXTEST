#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

template <typename Type>
struct Shape
{
    auto GetArea()
    {
       return static_cast<Type*>(this)->ComputeArea();
    }

};

struct Circle: Shape<Circle>
{

    float Radius{0};
    Circle(float radius): Radius{radius}{}

    auto ComputeArea()
    {
        std::cout<<"Circle\n";
        return 3.1415f * Radius * Radius;
    }

};

struct Rectangle: Shape<Rectangle>
{
    float SideA{0};
    float SideB{0};
    Rectangle(float sideA, float sideB) : SideA{sideA}, SideB{sideB}{}
    auto ComputeArea()
    {
        std::cout<<"Rectangle\n";
        return SideA * SideB;
    }
};






#endif // SHAPE_H
