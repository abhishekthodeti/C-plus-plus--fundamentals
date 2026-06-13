#include<iostream>
double main(){
    double age=19;
    double Balance=123.4;
    std::string name="RAJUBHAI";
    char grade='d';
    bool is_bhai=true;
    //ARITHMETIC OPERATIONS
   double orgi_price=245.3;
   double discount=0.1;
   double sell_price=orgi_price-orgi_price*discount;
     std::cout<<"discout: "<<orgi_price*discount<<'\n';
     std::cout<<"selling price:"<<sell_price<<'\n';
     double sell_count=50;
     if(sell_count==50){
        sell_price+=100;
     }
     std::cout<<"selling price:"<<sell_price;
}      