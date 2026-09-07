#include<iostream>
#include<memory>
#pragma once
template<typename T>

class Cpu_Buffer{

size_t size;
T *data;
public:
    Cpu_Buffer(size_t size):size(size),data(new T[size]()){}//Constructor

    ~Cpu_Buffer(){
        delete [] data;
        std::cout<<"BUFFER DELETED\n";}//destructor
    
    Cpu_Buffer(const Cpu_Buffer & others):size(others.size),data(new T[others.size]){        
        memcpy(data,others.data,size*sizeof(T));
    }//CPY CONSTRUCTOR (DEEP COPY)
    Cpu_Buffer(Cpu_Buffer && others): size(others.size),data(others.data){
        others.data=nullptr;
        others.size=0;
    }//MOVE CONSTRUCTOR (STEAL-POINTER)
    Cpu_Buffer & operator=(Cpu_Buffer && others){
        if(this == &others){
            return *this;
        }
        delete []data;
        size=others.size;
        others.size=0;
        data=others.data;
        others.data=nullptr;
        return *this;
    }//move operator (lets an obj move data,even it already holds old data)
    Cpu_Buffer &operator=(const Cpu_Buffer &others){
        if(this==&others){
            return *this;
        }
        delete []data;
        size=others.size;
        data=new T[size];
        memcpy(data,others.data,size*sizeof(T));
        return *this;
    }
    T &operator[](size_t index){
        return data[index];
    }
    const T &operator[](size_t index)const{
        return data[index];
    }
};