#include "Buffer_manager.h"
#pragma once
template<typename T>

class Matrix{
    size_t rows;
    size_t cols;
    Cpu_Buffer<T> buf;
public:
    Matrix(size_t N):buf(N*N),rows(N),cols(N){}
    Matrix(size_t r,size_t c): buf(r*c),rows(r),cols(c){}

    ~Matrix(){std::cout<<"matrix obj is no longer alive"<<"\n";}

    size_t get_row()const{
    return rows;
    }
    size_t get_col()const{
        return cols;
    }
    const T &at(size_t r,size_t c)const{
         return buf[(r*cols)+c];
    }
    T &at(size_t r,size_t c){
        return buf[(r*cols)+c];
    }
};