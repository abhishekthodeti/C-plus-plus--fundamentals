#include "class_temp_dec2.h"

int main(){

    Box<int> b1(10);
    Box<float> b2(2.56F);
    Box<std::string> b3("KRATOS");

    b1.print();
    b2.print();
    b3.print();
    
    return 0;
}