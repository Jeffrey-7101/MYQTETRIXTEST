#include <iostream>
#include <cmath>
#include "MyVector.h"
#include <functional>
#include "Functor.h"
#include "Templates.h"
#include "Shape.h"
#include "Matrix.h"


template <typename Type, auto Value> //compilacion
Type sum(const Type& a,  const Type& b)
{
    return a + b + Value;
}


float sum(const float& a,  const float& b)
{
    return a + b + 10;
}



/*
int sum(int a, int b)
{
    std::cout<<"int\n";
    return a+b;
}

float sum(float a, float b)
{
    return a+b;
}

double sum(double a, double b)
{
    return a+b;
}

*/


int main()
{


    Matrix<float, 10, 15> matrix{};
    matrix.Data[1][1] = 10;
    matrix.Data[3][1] = 25;

    //auto sum = matrix.InnerSum();
    auto sum = matrix.InnerSumThread();

    std::cout<<sum<<"\n";


    /*
    Rectangle rec{2 , 5}; //derivada
    Shape<Rectangle> *shapeR = &rec;

    Circle cir{5};
    Shape<Circle> *shapeC = &cir;

    std::cout<<shapeR->GetArea()<<"\n";
    std::cout<<shapeC->GetArea()<<"\n";

*/

   // constexpr int x{6}; //compi

    //auto f = factorial(6);
    //std::cout<<f<<"\n";


    //int y = Factorial<6>::Result;

    //int f = Fibonacci<10>::Result;

    //std::cout<<f<<"\n";





/*    MyVector<int, 100> a{10}, b{10};

    a[95] = 8; //Set

    b[1] = 2;

    //MyVector c = a + 10;

    std::cout<< a[95]  <<"\n"; //Get
*/

    return 0;
}
