#include<iostream>
template<class T>
class unique{
    T *data;
    size_t size;
    public:
    unique(T value):size(1){
         data=new T(value);
        std::cout<<"resoure alocated"<<'\n';
    }
      unique(const unique&) = delete;

    ~unique(){
        delete data;
        std::cout<<"resource deallocated"<<'\n';
    }
    
    unique(unique &&others)noexcept:size(others.size),data(others.data){
            others.data=nullptr;
            others.size=0;
            std::cout<<"Move Constructor\n";
        };
        unique& operator=(unique &&others)noexcept{
                if(this==&others){
                    return *this;
                }
                delete data;
                size=others.size;
                data=others.data;
                others.data=nullptr;
                others.size=0;
                std::cout<<"moving assigned objects\n";
                return *this;
            }
    };

int main(){
    unique<int> p(10);
    unique<int> num(43);
    unique<int> move_o=std::move(p);
    p=std::move(num);
}