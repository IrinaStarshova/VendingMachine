#include "machine.h"
#include "constants.h"
#include "dateTime.h"
#include "fileStatistics.h"
#include "createAndFreeFilePointer.h"
#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;

Machine::Machine() : totalProducts(0)
{

	cellsNames.reserve(cellsCount);
	productsNames.reserve(cellsCount);
	prices.reserve(cellsCount);
	cells.reserve(cellsCount);
	initCellsNames();
	initProductsNames();
	initPrices();
	fillMachine();
}

void Machine::initProductsNames()
{

	productsNames = { "Chocolate" , "Juice", "Cookies", "Water", "IceTea", "Croissant", "Soda", "Chips", "Candies" };
	default_random_engine rand(static_cast<unsigned>(chrono::system_clock::now().time_since_epoch().count()));
	shuffle(begin(productsNames), end(productsNames), rand);
}

void Machine::initPrices()
{
	for (int i = 0; i < cellsCount; ++i)
	{
		prices.push_back(1 + rand() % 100);
	}
}

void Machine::initCellsNames()
{
	for (int i = 0; i < lettersCount; ++i)
	{

		for (int j = 1; j <= maxNumber; ++j)
		{
			string name;
			name.push_back(firstLetter + i);
			name.push_back(j + '0');
			cellsNames.push_back(name);
		}
	}
}

void Machine::fillMachine()
{
	for (int i = 0; i < cellsCount; ++i)
	{
		Cell C(cellsNames[i], productsNames[i], prices[i]);
		cells.push_back(C);
		totalProducts += cells.back().getnumberOfProducts();
	}
}

void Machine::displayMenu() const
{
	cout << "\n1 - DEVICE MENU" << endl;
	cout << "2 - BUY A PRODUCT" << endl;
	cout << "3 - SAVE PURCHASES HISTORY" << endl;
	cout << "4 - SAVE PURCHASES STATISTICS" << endl;
	cout << "5 - SAVE AVAILABLE PRODUCTS STATISTICS" << endl;
	cout << "6 - EXIT\n" << endl;
}

void Machine::displayMachineMenu() const
{
	for (const auto& i:cells)
	{
		i.display();
	}
}

void Machine::Run()
{
	int enteredNumber;
	do
	{
		displayMenu();
		cout << "Enter menu item number: ";
		cin >> enteredNumber;
		if (cin.fail())
		{
			cout << "\nInvalid value of menu item number entered\nEnter the menu item number from the list below\n" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		switch (enteredNumber)
		{
		case 1: displayMachineMenu(); break;
		case 2: buyProduct(); break;
		case 3:
		case 4:
		case 5: 
		{
			FileStatistics* file = createStatisticsFile(enteredNumber); 
			if (file)
				file->writeFileStatistics(this);
			freeStatisticsFile(file);
			break; 
		}
		case 6: break;
		default:cout << "\nInvalid value of menu item number entered\nEnter the menu item number from the list below\n" << endl; break;
		}
	} while (enteredNumber != 6);
}

void Machine::buyProduct()
{
	string cellNameEntered;
	cout << "Enter cell name:";
	cin >> cellNameEntered;
	int cellNameLetter = toupper(cellNameEntered.front());	//на случай, если пользователь введет строчную букву вместо заглавной
	int cellNameNumber = cellNameEntered.back() - '0';
	if ((cellNameEntered.length() == 2) && (cellNameLetter >= firstLetter && (cellNameLetter < firstLetter + lettersCount)
		&& (cellNameNumber > 0 && cellNameNumber <= maxNumber)))

	{
		int index = (maxNumber * (cellNameLetter - firstLetter) + cellNameNumber - 1);	//подсчет индекса ячейки, из которой производится покупка
		if (cells[index].isCellProductsEmpty())
			cout << "\nCell " << cells[index].getName() << " is empty\n" << endl;
		else 
		{
			int amountOfMoney;
			cout << "Enter amount of money:";
			cin >> amountOfMoney;
			if (amountOfMoney < cells[index].getPriceOfProduct())
				cout << "\nNot enough money for purchase\n" << endl;
			else 
			{
				DateAndTime D;
				Purchase purchase(D, cells[index].getNameOfProduct(), cells[index].getPriceOfProduct());
				purchasesHistory.push_back(purchase);
				cout << "\nPurchased product " << cells[index].getNameOfProduct() << " from the cell " 
					<< cells[index].getName() << " " << D.getDateString() << " " << D.getTimeString() << endl;
				cells[index].deleteElement();
				--totalProducts;
			}
		}
	}

	else cout << "\nInvalid value of cell name entered\nEnter the cell name from the list\n" << endl;
}

int Machine::getTotalProducts() const
{
	return totalProducts;
}

const vector<Cell>& Machine::getCells() const
{
	return cells;
}

const std::vector<Purchase>& Machine::getPurchasesHistory() const
{
	return purchasesHistory;
}
