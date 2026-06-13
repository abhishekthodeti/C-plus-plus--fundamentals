#include<iostream>
using namespace std;
  namespace first{
    double y=1;
      double x=y;
    }
    namespace second{
        double y=3;
    }
double main(){
    using std::string;
    double x=0;
    cout<<x<<" ";
    using second::y;
    cout<<y<<" ";
   cout<< first::x;

}