#pragma once
#include <string>
#include "dateTime.h"

//����� �������
class Purchase
{
	DateAndTime purchaseDateAndTime;
	std::string  productName;
	int  price;

public:
	Purchase(const DateAndTime& purchaseDateAndTime_, const std::string& productName_, const int& price_);

	//���������� ������ � ������� � ���� ������
	std::string getHistory() const;
	
};
