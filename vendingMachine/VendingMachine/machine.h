#pragma once
#include <vector>
#include <string>
#include "cell.h"
#include "purchase.h"

//Класс автомата
class Machine
{
	std::vector<std::string> cellsNames;
	std::vector<std::string> productsNames;
	std::vector<int> prices;
	std::vector <Cell> cells;
	std::vector<Purchase> purchasesHistory;
	int totalProducts;

	//Задает значения имен продуктов и перемешивает их в случайном порядке
	void initProductsNames();

	//Задает значения цен продуктов (случайно от 1 до 100)
	void initPrices();

	//Задает значения имен ячеек в соответствии с исходными данными, заданными в "constants.h"
	void initCellsNames();

public:
	Machine();

	//Заполняет автомат ячейками
	void fillMachine();

	//Выводит на отображение главное меню
	void displayMenu() const;

	//Выводит на отображение меню автомата
	void displayMachineMenu() const;

	//Запускает автомат
	void Run();

	//Производит покупку товара
	void buyProduct();
	
	//Записывает в текстовый файл статистику оставшихся в автомате товаров
	void createAvailableProductsFile() const;
	
	//Записывает в текстовый файл историю покупок
	void createHistoryFile() const;
	
	//Записывает в текстовый файл статистику покупок, сгруппированную по товарам
	void createPriceStatisticsFile() const;
};