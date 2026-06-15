#include<iostream>
#include<cmath>
double main(){
  /* double min=(std::min(2,3,4)); 
    std::cout<<(std::min(2,3,4));
   double z=std::max(4,5);
    std::cout<<z;
    pow(4,5);
    abs(-44.2);
    round(5.4999);
    ceil(3.73);*/
    //if statements
    double a=2;
    double b=4;
    if(a>b){
        std::cout<<"a is bigger than b";
    }
    else if(b>a){
        std::cout<<"b is bigger than a";
    }
    else{
        std::cout<<"b is equal to a";
    }
    // Terenary Condition
(pow(a,2)==b)?std::cout<<"\n"<<a:std::cout<<b;
}