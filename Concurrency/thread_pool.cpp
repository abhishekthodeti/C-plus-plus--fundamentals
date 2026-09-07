#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<queue>
#include<vector>
#include<functional>
#include<chrono>

std::mutex mtx;

class Thread_Pool{
        std::mutex mtx;
        std::vector<std::thread> workers;
        std::queue<std::function<void()>> tasks;
        std::condition_variable cv;
        bool stop=false;
    public:
        Thread_Pool(size_t threads){
            for(int i=0;i<threads;i++){
                workers.emplace_back([this](){
                while(true){
                    std::function<void()> task;
                   { std::unique_lock<std::mutex> lock(this->mtx);
                    cv.wait(lock,[this]{
                     return !this->tasks.empty() || this->stop;
                    }); 
                    if(this->tasks.empty() && this->stop)
                       {return;}
                       task= std::move(tasks.front());
                       tasks.pop();
                    } 
                        task();
                } 
            });
        } };
         ~Thread_Pool(){
           { std::lock_guard<std::mutex> lock(mtx);
            stop=true;}
            cv.notify_all();
            for(std::thread &worker : workers){
             if(worker.joinable()){
                worker.join();
             }   
            }
        }
        void enque(std::function<void()> task){
           { std::lock_guard<std::mutex> lock(mtx);
            tasks.push(task);
           }
           cv.notify_one();
        }
};
int main(){
    Thread_Pool pool(8);
    for(int i=0;i<10;i++){
        pool.enque([i]{
           {std::lock_guard<std::mutex> lock(mtx);
            std::cout<<"Task "<<i<<"\n"<<"THREAD ID IS: "<<std::this_thread::get_id()<<std::endl;}
            std::this_thread::sleep_for(std::chrono::microseconds(100));
        });
}
std::this_thread::sleep_for(std::chrono::seconds(2));
    }