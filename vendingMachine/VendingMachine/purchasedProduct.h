#pragma once
#include <string>

//�����  ������� ��� ����������� ������ � ����� ����������
class PurchasedProduct
{
	std::string name;
	int totalPrice;

public:
	PurchasedProduct(const std::string& name_, int tPrice_);

	bool operator <(const PurchasedProduct& p) const;

	//���������� ������ ���������� ������� ��� ����������� ������ � ����� ����������
	std::string getStatistic() const;
	
};