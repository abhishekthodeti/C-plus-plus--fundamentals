#include<iostream>
int main(){
    int *dynamic_arr=new int[5];//ALLOCATES 5 BLOCKS OF MEMORY OF INT SIZE IN RAM
    int *ptr=dynamic_arr;
    *ptr=0;
    for(int i=0;i<5;i++){
        *ptr=(i+1)*10;
        ptr+=1;
    }
    ptr=dynamic_arr;
    for(int i=0;i<5;i++){
        std::cout<<*(ptr+i)<<" ";
    }
    delete[] dynamic_arr;
    }
