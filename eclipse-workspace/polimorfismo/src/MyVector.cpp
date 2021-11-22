//#include "MyVector.h"

//MyVector::MyVector(const std::size_t& size):
//    Data{std::vector<int>(size, 0)},
//    Size{size}
//{

//}

//MyVector operator+(const MyVector& a, const MyVector& b)
//{

//    MyVector result{a.Size};

//    for(std::size_t i=0; i< a.Size; ++i)
//    {

//        result[i] = a.Data[i] + b.Data[i];

//    }

//    return result;

//}


//MyVector operator+(const MyVector& a, const int& s)
//{

//    MyVector result{a.Size};

//    for(std::size_t i=0; i< a.Size; ++i)
//    {

//        result[i] = a.Data[i] + s;

//    }

//    return result;

//}

//MyVector operator+(const int& s, const MyVector& a)
//{
//    return a+s;
//}

//bool operator==(const MyVector& a, const MyVector& b)
//{
//    for (std::size_t i = 0; i < a.Size; ++i)
//    {
//        if (a.Data[i] != b.Data[i])
//        {
//            return false;
//        }

//    }
//    return  true;

//}

//bool operator!=(const MyVector& a, const MyVector& b)
//{
//    return !(a==b);
//}

//bool operator < (const MyVector& a, const MyVector& b)
//{

//    return std::accumulate(a.Data.begin(), a.Data.end(), 0) <
//    std::accumulate(b.Data.begin(), b.Data.end(), 0);

//}


//std::ostream& operator<<(std::ostream& output, const MyVector& v)
//{
//    for(auto it = v.Data.begin();  it != v.Data.end() ; ++it)
//    {
//        output <<*it<<", ";
//    }

//    return output;
//}








