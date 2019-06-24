#pragma once
#include "product.h"
#include <vector>
#include <string>
 
//Класс ячейки автомата
class Cell
{
	std::string name;
	std::vector<Product> cellProducts;
	int numberOfProducts;
	std::string nameOfProduct;
	int price;
public:
	Cell(std::string name_, std::string nameOfProduct_, int price_);

	//Задает значение кол-ва продуктов в ячейке (случайно от 5 до 10)
	void initNumberOfProducts();
	
	//Возвращает значение кол-ва продуктов в ячейке
	int getnumberOfProducts() const;
	
	//Возвращает значение имени ячейки
	const std::string& getName() const;
	
	//Возвращает значение имени продукта
	const std::string& getNameOfProduct() const;
	
	//Возвращает значение цены продукта
	int getPriceOfProduct() const;
	
	//Заполняет ячейку продуктами
	void fillCell();
	
	//Выводит на отображение содержимое ячейки
	void display() const;
	
	//Удаляет купленный продукт из ячейки
	void deleteElement();
	
	//Предоставляет информацию пуста ли ячейка
	bool isCellProductsEmpty() const;
	
	//Возвращает массив продуктов ячейки
	const std::vector<Product>& getCellProducts() const;
	
	//Возвращает общую стоимость купленного конкретного вида товара
	int getTotalPrice() const;
};
