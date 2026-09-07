#include<iostream>
#include<vector>

int main(){
    std::vector<int> v={10,20,30,49};
    std::vector<int>::iterator it =v.begin();
    std::cout<<*it<<'\n';
    it++;
    std::cout<<*it<<'\n';
    for(std::vector<int>::iterator it=v.begin();it!=v.end();++it){
        std::cout<<*it<<" ";
        std::cout<<"\n";
    }
}