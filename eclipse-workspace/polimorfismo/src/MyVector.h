#ifndef MYVECTOR_H
#define MYVECTOR_H


#include <vector>
#include <iostream>
#include <numeric>

template <typename Type, unsigned sizeT=100>
class MyVector
{

private:

    std::vector<Type> Data; //for simplicity //truco
    std::size_t Size;
    Type data2;

public:


    MyVector(const std::size_t& size):

    Data{std::vector<Type>(size, 0)},
        Size{sizeT}
    {

    }

    const Type& operator[](const unsigned& index) const
    {
        return Data[index];
    }; //Get

    Type& operator[](const unsigned& index) //Set
    {
        return Data[index];
    }


//    int GetValue(unsigned index) const {return Data[index]; } //Get

//    int& SetValue (unsigned index) //method
//    {
//        return Data[index];
//    }




//    friend  MyVector operator+(const MyVector& a, const MyVector& b); //function
//    friend  MyVector operator+(const MyVector& a, const int& s); //function
//    friend  MyVector operator+(const int& s, const MyVector& a); //function

//    friend  bool operator==(const MyVector& a, const MyVector& b);
//    friend  bool operator!=(const MyVector& a, const MyVector& b);
//    friend  bool operator < (const MyVector& a, const MyVector& b);


//    friend std::ostream& operator<<(std::ostream& output, const MyVector& v);











};

#endif // MYVECTOR_H
