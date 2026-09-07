#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<queue>

void consumer();
void producer(int times);

std::mutex mtx;
std::condition_variable cv;
std::queue<int> q;
bool done;

void producer(int times){

    for(int i=0;i<times;i++){
        std::lock_guard<std::mutex> lock(mtx);
        q.push(i);
        std::cout<<"Produced "<<i<<"\n";
    }
    cv.notify_one();//wake up single waiting thread
    {
    std::lock_guard<std::mutex> lock(mtx);
    done=true;
    }
    cv.notify_all();//wakesup all the waiting threads
}

void consumer(){

    while(true){
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock,[]{
            return !q.empty() || done;
        });
        while(!q.empty()){
        std::cout<<"CONSUMED:"<<q.front()<<"\n";
        q.pop();
        }
        if(done){break;}
}}

int main(){
    std::thread thread1(producer,10);
    std::thread thread2(consumer);
    thread1.join();
    thread2.join();
    std::cout<<"all tasks in que are finished";
    return 0;
}
