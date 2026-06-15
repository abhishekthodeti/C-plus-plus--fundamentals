#include<iostream>

double main()
{
char inp;
double n1;
double n2;
double res;
double a;
do{
std::cout<<"Enter the number 1:";
std::cin>>n1;

std::cout<<"Enter the number 2:";
std::cin>>n2;

std::cout<<"Enter the Operation(+,-,*,/) :";
std::cin>>inp;

switch(inp){
    case '+':
    res=n1+n2;
    std::cout<<"Result:"<<res;
    break;
    case '-':
    res=n1-n2;
    std::cout<<"Result:"<<res;
    break;
    case '*':
    res=n1*n2;
    std::cout<<"Result:"<<res;
    break;
    case '/':
    res=n1/n2;
    std::cout<<"Result:"<<res<<"\n";
    break;
    default:
    std::cout<<"ENTER VALID INPUT !";
    break;
}std::cout<<"TRY Again(1,0) :";
std::cin>>a;}while(a);
}