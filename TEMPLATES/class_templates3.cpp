#include "class_temp_dec3.h"

int main(){
    Storage<> s1("AUTHOR MORGAN",50);
    Storage<std::string,double> s2("LARA CROFT",20.3F);
    Storage<double,int> s3(23.4F,332);
    s1.print();
    s2.print();
    s3.print();
}

