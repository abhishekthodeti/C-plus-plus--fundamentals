#include<iostream>

double get_avg(int arr[],int size);

int main(){

int score[]={76,86,45,67,87,8,90};
int size=sizeof(score)/sizeof(score[0]);

std::cout<<"AVERAGE SCORE OF CLASS IS : "<<get_avg(score,size);

}
double get_avg(int arr[] ,int size){

    int temp=0;

    for(int i=0;i<size;i++){
        temp+=arr[i];
    }

    double temp2=temp/double(size);
    return temp2;
}