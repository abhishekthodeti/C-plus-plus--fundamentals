#include<iostream>
double square(double length,double choice);
double ask(std::string shape);

double main()
{
int choice;
double result;
double length;

std::cout<<"ENTER THE SHAPE(1,2,3) :\n1.square\n2.rectangle\3.triangle:";
std::cin>>choice;

switch(choice)
{
case 1:
std::cout<<"enter the side of square :\n";
std::cin>>length;
choice=ask("square");
result=square(length,choice);
if(choice==1){
    std::cout<<"THE AREA OF SQUARE IS:"<<result;
}
else{
    std::cout<<"PERIMETER OF SQUARE IS:"<<result;
}
}
return 0;
}


double ask(std::string shape){
    double choice;
std::cout<<"WHICH ONE DO YOU WANT TO FIND FOR"<<shape<<"\n1.AREA\n2.PERIMETER :\n";
std::cin>>choice;
return choice;
}

double square(double length,double choice){
return choice==1 ? length*length:4*length;
}



