#include<iostream>

int linear_search(int arr[],int size,int target);

int main(){
    int array[]={23,43,45,65,78};
    int size=sizeof(array)/sizeof(array[0]);
    int target;
    std::cout<<"Enter the target to find :";
    std::cin>>target;
    if(linear_search(array,size,target)!=-1){
    std::cout<<"Target element "<<array[linear_search(array,size,target)]<< " found at index "<<linear_search(array,size,target);
}
else{
    std::cout<<"target element not found !";
}}
int linear_search(int arr[],int size,int target){
    for(int i=0;i<size;i++){
        if(arr[i]==target){
            return i;
        }
    }
     return -1;
}
