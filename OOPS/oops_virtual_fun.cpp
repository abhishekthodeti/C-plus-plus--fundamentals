#include<iostream>
#include<string>
class Animal{
    bool is_alive=true;
public:
    Animal(bool is_alive):is_alive(is_alive){};
    virtual void speak()const{
    std::cout<<"ANIMALS CAN MAKE SOUNDS !";
}
};
class Dog:public Animal{
    public:
    Dog():Animal(true){};

    void speak()const override{
        std::cout<<"DOG'S BARK !";
    }
};
void makesound(const Animal &animal){
    animal.speak();
}
int main(){
    Dog dog=Dog();
    //BY POINTERS
 /*Animal* animal_ptr=&dog;
 animal_ptr->speak(); */
 //BY REFERENCES
 Animal &animal=dog;
 animal.speak();
 makesound(dog);
}