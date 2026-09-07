#include<iostream>
#include<memory>
int main(){
  std::shared_ptr<int> ptr=std::make_shared<int>(10);
   std::weak_ptr<int> b=ptr;
   auto v=b;
    std::cout<<v.use_count();
}