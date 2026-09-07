#include<iostream>
#include<atomic>
#include<thread>

std::atomic <int> counter=0; //simple lock-free atomic thread access.
//access ,modify and increment into one atomic( into a single) operation 
//so that no other thread takes already accessed resource.

void loop(std::atomic <int>&res){

    for(int i=0;i<10000;i++){
        res.fetch_add(1,std::memory_order_relaxed);//fastest but dont follow order 
        //any thread can take the action ,use for something independent of order (like increment)        
        //res.fetch_add(1,std::memory_order_seq_cst);//slow but ordered,this is default
        //just as res++;
    } //we cannot retun value to the thread so using pass-by-reference(modifying original value)
}

int main(){

    std::atomic<int> res=0;

std::thread t1(loop,std::ref(res)); 
std::thread t2(loop,std::ref(res));

t1.join();
t2.join();
std::cout<<res<<"\n";
}
