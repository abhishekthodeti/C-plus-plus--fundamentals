#include<iostream>
#include<vector>

int main(){
//Types of declarations
    std::vector<int> vector1;
    std::vector<int> vector2(5,20);
    std::vector<int> vector3={199,743,42,5675,32};

    //ADDING ELEMENTS
    vector3.push_back(543);
    //vector2.pushback(20);
    vector1.push_back(523);

    //ASSIGNING & ACCESSING ELEMENTS
    vector3[4]=334;  //LIKE ARRAYS nobounds checked
   std::cout<<vector3.at(3);//bounds checks
   vector3.pop_back();
   vector2.clear();
   std::cout<<vector2.empty();

    //printing
    for(int i=0;i<vector3.size();i++){
        std::cout<<vector3.at(i)<<'\n';
    } 
       for(int i=0;i<vector1.size();i++){
        std::cout<<vector1.at(i)<<'\n';
    } 
        for(int i=0;i<vector2.size();i++){
        std::cout<<vector2.at(i)<<'\n';
    } 
    
}