#include <iostream>
#include <string>
#include <vector>
#include "dDE.h"

std::string fonction;

int main()
{
    while (true == true)
    {

        std::getline(std::cin, fonction);

        if (fonction == "help")
        {

        }

        dE(fonction);

     //   std::cout << "double " << nb[0] << std::endl << nb[1] << std::endl;

     //   std::cout << "string " << operateur[0] << std::endl;
    }
}