#include "Matrix.h"
#include "Threadpool.h"
#include<random>
const int N=500;
int main(){
    Matrix<int> A(N);
    Matrix<int> B(N);
    Matrix<int> C_seq(N); 
    Matrix<int> C_par(N);
    Matrix<int> B_t(N);
    std::function<void()>task;

    srand(time(0));
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            A.at(i,j)=rand()%N+1;
            B.at(i,j)=rand()%N+1;
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            B_t.at(i,j)=B.at(j,i);
        }
    }
    auto start=std::chrono::high_resolution_clock::now();
     for(size_t i=0;i<N;++i){
            for(size_t j=0;j<N;++j){
                int sum=0;
                for(size_t k=0;k<N;++k){
                sum+=A.at(i,k)*B_t.at(j,k);            
                }
                C_seq.at(i,j)=sum;
            }    
    }
    auto end=std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,std::milli> seq_dur=end-start;

    auto start_p=std::chrono::high_resolution_clock::now();
    std::atomic<int> done=0;
     Thread_Pool pool(8);
    {
     for(size_t i=0;i<N;++i){
    pool.enque([&A,&B,&C_par,&B_t,i,&done](){
            for(size_t j=0;j<N;++j){
                int sum=0;
                for(size_t k=0;k<N;++k){
                sum+=A.at(i,k)*B_t.at(j,k);            
                }
                C_par.at(i,j)=sum;
            }
            done++;
        }
    );}
    }
    while(done<N){}
    auto end_p=std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,std::milli> par_dur=end_p-start_p;
    bool correct=true;
     for(int i=0;i<N && correct;++i){
        for(int j=0;j<N && correct;++j){
            if(C_seq.at(i,j) !=C_par.at(i,j)){correct=false;}
        }
    }

    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            std::cout<<C_seq.at(i,j)<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<"\n";
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            std::cout<<C_par.at(i,j)<<" ";
        }
        std::cout<<std::endl;
    }
    
    correct ? std::cout<<"Mission Acomplished" :std::cout<<"Correctess Failed";
    std::cout<<"Sequential(Single-Thread) Execution :"<<seq_dur.count()<<"ms\n";
    std::cout<<"Parellel(Multi-Thread) Execution :"<<par_dur.count()<<"ms\n";
}