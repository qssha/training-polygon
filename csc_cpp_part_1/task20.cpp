#include <iostream>
       
struct Foo {
    void say() const { std::cout << "Foo says: " << msg << "\n"; }
protected:
    Foo(const char *msg) : msg(msg) { }
private:
    const char *msg;
};



void foo_says(const Foo &foo) { foo.say(); }

Foo get_foo(const char *msg) {
    struct Bar : Foo {
        Bar(const char* msg_to_foo) : Foo(msg_to_foo)
        {}
    };

    Bar bar(msg);
    return bar;
}


int main(int argc, char *argv[])
{
    foo_says(get_foo("Hello!"));
    return 0;
}



