#include<iostream>
double main(){
    std::string name="Onticheyi Subbadu";   
    std::string name1="NTR";
    //methods:
  // std::cout<< name.append(" NTR");
    std::cout<<  name.assign(name1);
    //std::cout<<  name.at(2);
     //std::cout<< name.length();
     std::cout<< name.compare(name1);
      std::cout<< name;
    name.swap(name1);
  std::cout<< name;
 
}
