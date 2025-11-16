#pragma once

#include <fstream>
#include <vector>
#include <string>
#include <iostream>

class produit
{
public:

void init(); //  initialisation produit  

void write(std::string productname, double price);

std::string getProductName(int nDebug);

double getprice(int nDebug);

int getNBP();// get number of products

void search(std::string productName);

void del(std::string productName);

void del(std::string productName, int nBOfTime);

private:

	std::vector<std::string> Produit;
	std::vector<double> Prix;
};

