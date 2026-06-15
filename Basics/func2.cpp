#include<iostream>
double *movepointer(double *pointer);
int main(){
double pointer=500;
double* moved_adress=movepointer(&pointer);
std::cout<<moved_adress;
return 0;
}
double *movepointer(double *pointer){
    std::cout<<pointer<<"\n";
    return pointer+1;
}