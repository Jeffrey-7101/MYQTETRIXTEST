#ifndef MATRIX_H
#define MATRIX_H


#include <vector>
#include <thread>
#include <numeric>

template <typename Type=int, unsigned rowsT=0, unsigned colsT=0>
class Matrix
{

public:

    using RowType = std::vector<Type>;
    using MatrixType =  std::vector< RowType >;

    MatrixType Data{ MatrixType(rowsT, RowType(colsT, Type{} ))};

    unsigned Rows{rowsT};
    unsigned Cols{colsT};

public:
    Matrix() = default;
    Matrix(unsigned rows, unsigned cols):
        Data{ MatrixType(rows,  RowType(rowsT, Type{}))},
        Rows{rows},
        Cols{cols}{}
    //overload

    Type InnerSum()
    {
        Type sum{};

        for(const auto&  row: Data)
        {
            for(const auto& element: row)
            {
                sum += element;
            }
        }

        return sum;
    }


    Type  InnerSumThread();



};

template <typename Type, unsigned rowsT, unsigned colsT>
Type  Matrix<Type, rowsT, colsT>::InnerSumThread()
{
    Type sum{};

    std::vector< std::thread > threads;
    std::vector<Type> rowSums(Rows, Type{});


    auto sumRow = [](const RowType& row, Type& sum) //func, FO, method (callable)
    {
        sum = std::accumulate(row.begin(), row.end(), Type{});
    };


    for( unsigned i{}; i < Rows; ++i )
    {
       threads.emplace_back(std::thread(sumRow, std::ref(Data[i]), std::ref(rowSums[i]) )) ;
    }


    return sum;
}







#endif // MATRIX_H
