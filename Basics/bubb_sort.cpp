#include<iostream>
void bubble_sort(int *arr,int size);
void printing_sorted_ele(int *arr,int size);
int main(){
    int array[]={23,87,32,43,786,34,2,98};
    int size=sizeof(array)/sizeof(array[0]);
    bubble_sort(array,size);
    printing_sorted_ele(array,size);
}
void bubble_sort(int *arr,int size){
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void printing_sorted_ele(int *arr,int size){
    for(int i=0;i<size;i++){
std::cout<<arr[i]<<std::endl;
    }
}