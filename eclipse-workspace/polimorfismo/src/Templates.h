#ifndef TEMPLATES_H
#define TEMPLATES_H


template<typename Type=long>
Type factorial(const Type & value)
{
    if(value==0)
    {
        return 1;
    }
    return value * factorial(value-1);
}



template <auto Value>
struct Factorial
{
    enum{Result = Value * Factorial<Value-1>::Result};
};

template <>
struct Factorial<0>
{
    enum{Result = 1};
};

/////////////////////////////////////////////////////


template <typename Type>
Type fibonacci(const Type& value)
{

    if(value == 1)
    {
        return 1;
    }

    if(value == 0)
    {
       return 0;
    }

    return fibonacci(value-1) +  fibonacci(value-2);

}

template <auto Value>
struct Fibonacci
{
    enum { Result =
           Fibonacci<Value-1>::Result +
           Fibonacci<Value-2>::Result
         };
};

template <>
struct Fibonacci<1>
{
    enum{Result = 1};
};

template <>
struct Fibonacci<0>
{
    enum{Result = 0};
};















#endif // TEMPLATES_H
