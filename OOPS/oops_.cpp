#include<iostream>
#include<string>
class Vechile{
    public:
        bool has_engine=true;
        std::string works_on;
        Vechile(bool has_engine, std::string works_on)
        : has_engine(has_engine), works_on(works_on) {}
};
class Car:public Vechile{
    public:
   
   /* CAR(std::string name,int model){//CONSTRUCTORS
        this->name=name;
        this->model=model;
        this->budget=0;
    }*/
   Car(std::string name,int model):Vechile(true,"LAND"),name(name),model(model),budget(0){}//MODERN WAY

     Car(std::string name,int model,int budget):Vechile(true,"LAND"){//OVERLOADING
        this->name=name;
        this->model=model;
        this->budget=budget;
    }
    void using_carkey(const bool n)const{//ENCAPSULATION getter(only-readable)
        if(n==1){
         startcar(name);
        }
         else if(n==0){
         stopcar();
        }
    }
    void change_car(std::string new_name){//ENCAPSULATION setter(overwrite)
        this->name=new_name;
    }
    ~Car(){std::cout<<"Gracefully deleted the object !\n";}
    private:
        //ATTRIBUTES OF OBJECTS
    std::string name;
    int model;
    int budget;
    void startcar(std::string name) const{     //BEHAVIOUR OF OBJECTS
        std::cout<<name<<" is starting\n";
    }
    
    void stopcar() const{
         std::cout<<name<<" is stopped\n";
    }
};
class Boat:public Vechile{
    public:
         Boat(std::string name,int model):Vechile(true,"WATER"),name(name),model(model),budget(0){}//MODERN WAY
         ~Boat(){std::cout<<"object destroyed !"<<"\n";}
     private:
        //ATTRIBUTES OF OBJECTS
    std::string name;
    int model;
    int budget;
};
int main(){
    Car car1=Car("Ferrari",2015);
    Car car2=Car("FORD GT",2006,350000);
    car1.using_carkey(true);
    car2.using_carkey(false);
    car1.using_carkey(true);
    car2.using_carkey(true);
    car1.change_car("BURRARI");
    car1.using_carkey(0);
    std::cout<<car1.has_engine<<"\n";
    std::cout<<car1.works_on<<"\n";
    Boat boat=Boat("RIVERSIDE",1991);
     std::cout<<boat.works_on<<"\n";
    return 0;
}