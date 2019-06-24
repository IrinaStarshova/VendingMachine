#pragma once
#include "dateTime.h"

//Класс продукта
class Product
{
	DateAndTime expirationDate;
	std::string name;
public:
	Product(const std::string& name_);

	//Функтор для сортировки продуктов по дате истечения срока годности
	struct SortByDate
	{
		bool operator()(const Product& lhs, const Product& rhs) const {
			return lhs.expirationDate < rhs.expirationDate;
		}
	};

	//Функтор для сортировки продуктов по дате истечения срока годности и имени
	struct SortByNameAndDate
	{
		bool operator()(const Product& lhs, const Product& rhs) const {
			return (lhs.expirationDate == rhs.expirationDate) 
				? lhs.name < rhs.name : lhs.expirationDate< rhs.expirationDate;
		}
	};

	//Возвращает значение имени продукта
	const std::string& getName() const;
	
	//Возвращает значение даты истечения срока годности в виде строки
	std::string getExpirationDateString() const;
};

