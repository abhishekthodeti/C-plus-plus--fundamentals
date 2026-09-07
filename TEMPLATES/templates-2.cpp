#include<iostream>

template<typename M>

M maxVal(M first ,M second){
    M big=first>second ?first:second;
    return big; 
}

int main(){
int  big=maxVal(3,6);
    std::cout<<big;
    return 0;
}