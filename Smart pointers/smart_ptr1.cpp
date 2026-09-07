#include<iostream>
#include<memory>
//unique_ptr=these are smart pointers,allocate and deallocate memory on heap 
//automatically without any overhead
//unique pointer means single owner ship cannot copy/pass by value to fun().
void custom_del(int *p){

    delete p;
}
int main(){

{
    std::unique_ptr<int,decltype(&custom_del)> a{new int(521476),&custom_del};//declaration
//for arrays:
auto b=std::make_unique<int []>(1000);// recommended declaration.

//auto c=a; copying don't work will results to two pointers pointing the same memory block

std::cout<<b<<'\n';//b's address

auto c=std::move(b);//moving is valid now c points to a's memory block and b to the nullptr

std::cout<<*a<<'\n';//de-referencing
std::cout<<sizeof(*a);

std::cout<<b<<'\n'; //points to null

std::cout<<c<<'\n';//takes address of b

}//scope sensitive
//std::cout<<*c<<'\n'; not in scope of unique_ptr
}