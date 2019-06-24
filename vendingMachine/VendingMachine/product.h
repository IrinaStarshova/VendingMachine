#pragma once
#include "dateTime.h"

//����� ��������
class Product
{
	DateAndTime expirationDate;
	std::string name;
public:
	Product(const std::string& name_);

	//������� ��� ���������� ��������� �� ���� ��������� ����� ��������
	struct SortByDate
	{
		bool operator()(const Product& lhs, const Product& rhs) const {
			return lhs.expirationDate < rhs.expirationDate;
		}
	};

	//������� ��� ���������� ��������� �� ���� ��������� ����� �������� � �����
	struct SortByNameAndDate
	{
		bool operator()(const Product& lhs, const Product& rhs) const {
			return (lhs.expirationDate == rhs.expirationDate) 
				? lhs.name < rhs.name : lhs.expirationDate< rhs.expirationDate;
		}
	};

	//���������� �������� ����� ��������
	const std::string& getName() const;
	
	//���������� �������� ���� ��������� ����� �������� � ���� ������
	std::string getExpirationDateString() const;
};

