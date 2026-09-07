#include<iostream>

int main(){
    int array[5];
     int size=sizeof(array)/sizeof(array[0]);
    //int arr[]={23,43,12,43,4};

    for(int i=0;i<size;i++){
        std::cin>>array[i];
    }
    for(int element:array){
        std::cout<<element<<" ";
    }
}