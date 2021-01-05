#include <iostream>
#include "System.h"

int main()
{
    try {
        System main;
        main.start();
    }
    catch (const char* e) {
        std::cout << "Error! " << e << std::endl;
        std::cout << "The program will now stop" << std::endl;
    }
    
}
