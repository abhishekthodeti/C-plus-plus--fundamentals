#include<iostream>
#include<thread>
void task(int freq,std::string str){
     int count=0;
    for(int i=0;i<freq;i++){
        std::cout<<str<<"\n";
        count++;
}
    std::cout<<count;
}

int main(){
    int count=0;
    std::thread t1(task,10000,"thread 1");
    std::thread t2(task,10000,"thread 2");
    t1.join();
    t2.join();
    return 0;
}