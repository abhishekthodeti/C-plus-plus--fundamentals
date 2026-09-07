#include<iostream>
#include<thread>
#include<string>
#include<mutex>
#include<chrono>
std::mutex mtx;
int count=0;
void safe_lock(int times,std::string s)
{ 
    for(int i=0;i<times;i++){
        {std::lock_guard<std::mutex> lock(mtx);
        std::cout<<s<<" "<<i<<std::endl;
        count++;
    }
    }
}
int main(){
    
    std::thread t1(safe_lock,10000,"thread1");
    std::thread t2(safe_lock,10000,"thread2");
    t1.join();
    t2.join();
    std::cout<<count;
}