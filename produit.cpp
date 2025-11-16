#include "produit.h"

void produit::init()
{
#pragma region variables
	std::string productName;
	std::string productPrice;
	double productPriceI;
	
	std::fstream folderProduct("Product.txt", std::ios::in);
	std::fstream folderPrix("prix.txt", std::ios::in);
#pragma endregion

	while (std::getline(folderProduct, productName,'\n'))
	{
		Produit.push_back(productName);
		//std::cout << productName << std::endl;
	}

	while (std::getline(folderPrix, productPrice,'\n'))
	{
		productPriceI = std::stoi(productPrice);
		Prix.push_back(productPriceI);
		//std::cout << productPriceI << std::endl;
	}

	folderPrix.close();
	folderProduct.close();
}

void produit::write(std::string productname, double price)
{
	Produit.push_back(productname);
	Prix.push_back(price);

	std::ofstream folderProduct("Product.txt", std::ios::app); 
	std::ofstream folderPrix("prix.txt", std::ios::app);      

			if (folderPrix.is_open())
			{
				folderPrix << price << '\n';

				folderPrix.close();
			}

			if (folderProduct.is_open()) 
			{
				folderProduct << productname << '\n';

				folderProduct.close();
			}
}

std::string produit::getProductName(int nDebug)
{
	if (Produit.size() > nDebug)
		return Produit[nDebug];

	else
		return "bug taille tableau";
}

double produit::getprice(int nDebug)
{
	if (Prix.size() > nDebug)
		return Prix[nDebug];

	else
		std::cout << "err vector size";
}

int produit::getNBP()
{
	return Produit.size()-1;
}

void produit::search(std::string productName)
{
	int i = 0;

	bool find = false;
	while (i < Produit.size())
	{
		if (Produit[i] == productName)
		{
			std::cout << Produit[i] << " " << Prix[i] << std::endl;

			i++;

			find = true;
		}

		else
			i++;
	}

	if (find == false)
	{
		std::cout << productName << " not find" << std::endl;
	}
}

void produit::del(std::string productName)
{
	int i = 0;

    while (i < Produit.size())
	{
		if (Produit[i] == productName)
		{
			Produit.erase(Produit.begin() + i);
			Prix.erase(Prix.begin() + i);

			std::remove("Product.txt");
			std::remove("prix.txt");


			std::ofstream folderProduct("Product.txt", std::ios::app);
			std::ofstream folderPrix("prix.txt", std::ios::app);

			int j = 0;

			while (j < Produit.size())
			{
				if (folderPrix.is_open())
				{
					folderPrix << Prix[j] << '\n';
				}

				if (folderProduct.is_open())
				{
					folderProduct << Produit[j] << '\n';
				}

				j++;
			}

				folderProduct.close();
				folderPrix.close();

			i = 0;
		}

		else
			i++;
	}

}

void produit::del(std::string productName, int nBOfTime)
{
	int i = 0;
	int time = 0;
	while (i < Produit.size() and time < nBOfTime)
	{
		if (Produit[i] == productName)
		{
			time++;
			Produit.erase(Produit.begin() + i);
			Prix.erase(Prix.begin() + i);

			std::remove("Product.txt");
			std::remove("prix.txt");


			std::ofstream folderProduct("Product.txt", std::ios::app);
			std::ofstream folderPrix("prix.txt", std::ios::app);

			int j = 0;

			while (j < Produit.size())
			{
				if (folderPrix.is_open())
				{
					folderPrix << Prix[j] << '\n';
				}

				if (folderProduct.is_open())
				{
					folderProduct << Produit[j] << '\n';
				}

				j++;
			}

			folderProduct.close();
			folderPrix.close();

			i=0;
		}

		else
			i++;
	}

}