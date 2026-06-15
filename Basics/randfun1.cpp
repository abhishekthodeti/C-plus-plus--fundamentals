#include<iostream>
#include<ctime>
double main(){

    srand(time(0));
    
    double num=rand()%100+1;
    double guess;
    double tries=0;
    bool not_found=true;

     do{

    std::cout<<"Enter the guess number(1-100) :";
    std::cin>>guess;
    
    if(guess>0){
        if(guess>num){
            std::cout<<"number is less than the guess ! Try a lower number\n";
            tries++;
        }
        else if(guess<num){
            std::cout<<"number is greater than the guess ! Try a bigger number\n";
            tries++;
        }
        else{
            std::cout<<"YOU FOUND THE NUMBER "<<num<<" AFTER "<<tries<<" tries !";
            not_found=false;
        }
    }
}while(not_found);
}