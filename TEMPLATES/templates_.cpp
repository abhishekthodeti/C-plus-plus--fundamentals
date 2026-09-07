/*#include<iostream>
template<typename T,typename U>
void print(T a,U b){
    std::cout<<"First: "<<a<<"\nSecond: "<<b;
}
int main(){
print(42,"hello");
}*/

#include<iostream>
#include<type_traits>
template<typename T,typename U>
constexpr auto multiply(T a,U b){
    std::string result;
    if constexpr (std::is_same_v<T,std::string> ||
                   std::is_same_v<T,const char*>){
    for(int i=0;i<b;i++){
        result+=a;
    }
     return result;
    }
    else{
        return a*b;
    }
}

int main(){
auto a=multiply(42,56);
auto b=multiply(67.03F,23.2F);
auto c=multiply(67.03F,21);
auto d=multiply("A",2);
std::cout<<a<<"\n"<<b<<"\n"<<c<<"\n"<<d;
}