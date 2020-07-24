#include <iostream>

struct Animal {
    virtual void say() {
        std::cout << "Animalll" << std::endl;
    }

    void altersay() {
    }
};

struct Dog : Animal {
    Dog() : age(0)
    {}

    Dog(int init_age, std::string init_name)
        : age(init_age), name(init_name) 
    {
    }

    Dog & operator=(Dog const & a) {
        std::cout << "= " << this->name << std::endl;
        this->name = a.name;
        this->age = a.age;
        return *this;
    }

    Dog (Dog const & a)
        : age(a.age), name(a.name)
    {
        std::cout << "copy " + this->name << std::endl;
    }

    void say() {
        std::cout << "doggg" << std::endl;
    }

    int age;
    std::string name;
};


int main(int argc, char *argv[])
{
    Dog dog1 = Dog(3, "FirstDog");
    Animal &a = dog1;

    a.say();

    
    return 0;
}
