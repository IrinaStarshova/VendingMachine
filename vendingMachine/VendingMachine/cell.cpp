#include "cell.h"
#include <iostream>
#include <algorithm>
#include <iomanip>


using namespace std;

Cell::Cell(string name_, string nameOfProduct_, int price_)
	: name(name_), nameOfProduct(nameOfProduct_), price(price_)
{
	initNumberOfProducts();
	cellProducts.reserve(numberOfProducts);
	fillCell();
}

void Cell::initNumberOfProducts()
{
	numberOfProducts = 5 + rand() % 6;
}

int Cell::getnumberOfProducts() const
{
	return numberOfProducts;
}

const string& Cell::getName() const
{
	return name;
}

const string& Cell::getNameOfProduct() const
{
	return nameOfProduct;
}

int Cell::getPriceOfProduct() const
{
	return price;
}

void Cell::fillCell()
{
	for (int i = 0; i < numberOfProducts; ++i)
	{
		cellProducts.push_back(Product(nameOfProduct));
	}
	sort(cellProducts.rbegin(), cellProducts.rend(), Product::SortByDate());
}

void Cell::display() const
{
	if (cellProducts.empty()) 
		cout << '\n' << name << " - " << "CELL IS EMPTY" << endl;
	else
	{
		cout << '\n' << name << " - " << left << setw(9) << nameOfProduct << right << " - " 
			<< setw(3) << price << " - "<< setw(2) << cellProducts.size() << endl;
	}
}

void Cell::deleteElement()
{
	cellProducts.pop_back();
}

bool Cell::isCellProductsEmpty() const
{
	return  cellProducts.empty();
}

const vector<Product>& Cell::getCellProducts() const
{
	return cellProducts;
}

int Cell::getTotalPrice() const
{
	return (numberOfProducts - static_cast<int>(cellProducts.size()))*price;
}
