#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

void print(auto &v){
    for(auto it=v.begin();it!=v.end();++it){
        std::cout<<*it<<" ";
    }
    std::cout<<"\n";
}

int main(){

    std::vector<int> v(5,0);
    print(v);

    std::fill(v.begin(),v.end(),23);
    print(v);

    std::transform(v.begin(),v.end(),v.begin(),[](int x){
        return x*2;
    });
     print(v);  

    auto sum=std::reduce(v.begin(),v.end(),0);
     std::cout<<(sum);

}