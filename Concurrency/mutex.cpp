#include<iostream>
#include<thread>
#include<mutex>
#include<string>
int count=0;
std::mutex mtx;
void print_thread(int freq,std::string str){
     mtx.lock();
    for(int i=0;i<freq;i++){
        std::cout<<str<<"\n";
        count++;
}
      mtx.unlock();
}

int main(){

std::thread thread1(print_thread,5,"thread1");
std::thread thread2(print_thread,5,"thread2");
thread1.join();
thread2.join();
std::cout<<count;
return 0;
}