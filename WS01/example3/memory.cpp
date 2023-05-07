#include <iostream>

struct object
{
    int value = 0;
};

int main()
{
    object* obj = new object();
    // use the resource
    obj->value = 42;
    std::cout << "Object value: " << obj->value << std::endl;
    // free the memory
    delete obj;

    return 0;
}