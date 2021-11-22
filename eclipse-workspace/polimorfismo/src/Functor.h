#ifndef FUNCTOR_H
#define FUNCTOR_H

#include <iostream>


struct Functor
{
    auto operator() (const float& radius) const
    {
        auto area  = 3.1415 * std::pow(radius, 2);
        std::cout<<"Functor\n";
        return area;
    }
};


auto areaFunc ( const float& radius )
{

    auto area  =3.1415f * std::pow(radius, 2);
    std::cout<<"Function\n";
    return area;

}
//void foo( const Functor& functor   ) //object
//thread
void foo(const std::function<void(const float&)>& func) //object
{
    func(4.f);
}

#endif // FUNCTOR_H
