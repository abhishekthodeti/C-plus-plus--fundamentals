#include<iostream>
#include<string>
template<typename T>
class Box{
    private:
       T secret;
    public:
        Box(T value);
        T get_val();
        void print();
};
template<typename T>
Box<T>::Box(T value):secret(value){};

template<typename T>
T Box<T>::get_val(){
    return secret;
}
template<typename T>
void Box<T>::print(){
std::cout<<secret<<"\n";
}

