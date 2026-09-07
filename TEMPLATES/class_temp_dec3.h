#include<iostream>
#include<string>
template<typename T=std::string,typename U=int>

class Storage{
    private:
        T first;
        U second;
    public:
        Storage(T val1,U val2);
        void print();
};
template<typename T,typename U>
Storage<T,U>::Storage(T val1,U val2):first(val1),second(val2){};

template<typename T,typename U>
void Storage<T,U>::print(){
    std::cout<<first<<"\n"<<second<<"\n";
}