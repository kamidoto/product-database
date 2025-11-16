#include "produit.h"
#include <iostream>
#include <stdlib.h>

int main()
{
	produit Produit;
	
	Produit.init();

	char lettre;

	while (true == true)
	{
		std::cin >> lettre;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (lettre == '?')
		{
			std::cout << "? : help \na : add a product \nl : list of all product \ns : search \nd : delete \n";
		}

		else if (lettre == 'a')
		{
			
			 double price;
			 std::string pN;//product name

			 std::cout << "product name : ";
			 std::getline(std::cin, pN);

			 std::cout << "price : ";
			 std::cin >> price;

			 Produit.write(pN, price);
		}

		else if (lettre == 'l')
		{
			int i = -1;
			while ( Produit.getNBP() > i)
			{
				i++;
				std::cout << Produit.getProductName(i) << " " << Produit.getprice(i) <<" euros" << std::endl;
			}
		}

		else if (lettre == 's')
		{
			std::cout << "exact name :";

		}

		else if (lettre == 'd')
		{
			std::string pN;

			std::cout << "product to delete : ";
			std::getline(std::cin, pN);

			std::string nbt; //nb de fois

			std::cout << "how much time ? if you whant to delte all the products with this name tap all : ";
			std::cin >> nbt;

			if (nbt == "all")
				Produit.del(pN);

			else
				Produit.del(pN, std::stoi(nbt));
		}
	}
}