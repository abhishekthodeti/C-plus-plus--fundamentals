#include<iostream>
#include<vector>
#include<algorithm>

int main(){
    std::vector<int> v={10,32,45,532,3453,123,4};
    std::vector<int>::iterator min_v=std::min_element(v.begin(),v.end());
    std::cout<<*min_v<<"\n";
    auto max_v=std::max_element(v.begin(),v.end());
    std::cout<<*max_v<<"\n";
    std::sort(v.begin(),v.end());
    for(auto it=v.begin();it!=v.end();++it){
        std::cout<<*it<<" ";
    }
}