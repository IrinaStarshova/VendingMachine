#pragma once
#include <string>

// ласс  покупки дл€ конкретного товара с общей стоимостью
class PurchasedProduct
{
	std::string name;
	int totalPrice;

public:
	PurchasedProduct(const std::string& name_, int tPrice_);

	bool operator <(const PurchasedProduct& p) const;

	//¬озвращает данные статистики покупок дл€ конкретного товара с общей стоимостью
	std::string getStatistic() const;
	
};