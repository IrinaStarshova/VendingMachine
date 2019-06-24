#pragma once
#include <string>
#include "dateTime.h"

//Класс покупки
class Purchase
{
	DateAndTime purchaseDateAndTime;
	std::string  productName;
	int  price;

public:
	Purchase(const DateAndTime& purchaseDateAndTime_, const std::string& productName_, const int& price_);

	//Возвращает данные о покупке в виде строки
	std::string getHistory() const;
	
};
