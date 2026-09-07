#include<iostream>
#include<thread>
#include<functional>
#include<mutex>
#include<condition_variable>
#include<vector>
#include<queue>
#include<chrono>

class Thread_Pool{
    std::mutex mtx;
    std::condition_variable cv;
    std::vector<std::thread> workers; 
    std::queue<std::function<void()>> tasks; 
    bool stop=false;
public:
    Thread_Pool(size_t size){
        for(int i=0;i<size;i++){
            workers.emplace_back([this](){
                while(true){
                    std::function<void()> task;
                   { std::unique_lock<std::mutex> lock(mtx);
                    cv.wait(lock,[this]{
                        return !this->tasks.empty() || stop; 
                    });
                    if(this->tasks.empty() &&stop){
                        return;
                    } 
                    task=std::move(tasks.front());
                    tasks.pop();
                    }
                    task();
                }
            });
        }
    }
    void enque(std::function<void()> task){
        {
            std::lock_guard<std::mutex> lock(mtx);
            tasks.push(std::move(task));
        }
        cv.notify_one();
    }
    ~Thread_Pool(){
        {
            std::lock_guard<std::mutex> lock(mtx);
            stop=true;
        }
            
            cv.notify_all();

        for(std::thread & worker : workers){    
            if(worker.joinable()){
                std::cout<<"thread destroyed"<<"\n";
                worker.join();
            }
        }
}
};
