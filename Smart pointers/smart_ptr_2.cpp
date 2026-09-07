#include<iostream>
#include<memory>

int main(){
    
auto sp2=std::make_shared<int>(67);

   { std::shared_ptr<int> sp1{new int(453)};
    *sp1=3423;
    auto sp3=sp2;
    std::cout<<sp2.use_count();//ownership count
    } 
std::cout<<sp2.use_count();
}