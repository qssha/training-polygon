#include <iostream>

struct NetworkDevice {
    void send() {
        std::cout << "start log" << std::endl;
        send_impl();
        std::cout << "end log" << std::endl;
    }

    virtual ~NetworkDevice() {
    }

private:
    virtual void send_impl() {
        std::cout << "NetworkDevice class" << std::endl;
    }
};

struct Router : NetworkDevice {
public:
    virtual void send_impl() {
        std::cout << "Router class" << std::endl;
    }
};

int main(int argc, char *argv[])
{
    NetworkDevice *device = new NetworkDevice();
    NetworkDevice *router = new Router();

    device->send();
    router->send();

    delete device;
    delete router;
    
    return 0;
}
