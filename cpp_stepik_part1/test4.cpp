#include <iostream>

struct Animal {
    virtual void say() {
        std::cout << "Animal" << std::endl;
    }
};

struct Pet : Animal {
    void say() {
        std::cout << "Pet" << std::endl;
    }
};

struct Dog : Pet {
    void say() {
        std::cout << "Dog" << std::endl;
    }
};

int main(int argc, char *argv[])
{
    Dog dog;
    Animal &ani = dog;

    ani.say();

    return 0;
}
