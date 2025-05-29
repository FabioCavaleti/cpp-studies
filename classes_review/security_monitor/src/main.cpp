#include "Event.h"
#include <iostream>

int main() 
{
    Event e("192.168.1.10", EventType::LOGIN_FAIL, "Invalid password for admin");

    std::cout << e.formatToString() << std::endl;
}