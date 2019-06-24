#pragma once
#include "product.h"
#include <vector>
#include <string>
 
//����� ������ ��������
class Cell
{
	std::string name;
	std::vector<Product> cellProducts;
	int numberOfProducts;
	std::string nameOfProduct;
	int price;
public:
	Cell(std::string name_, std::string nameOfProduct_, int price_);

	//������ �������� ���-�� ��������� � ������ (�������� �� 5 �� 10)
	void initNumberOfProducts();
	
	//���������� �������� ���-�� ��������� � ������
	int getnumberOfProducts() const;
	
	//���������� �������� ����� ������
	const std::string& getName() const;
	
	//���������� �������� ����� ��������
	const std::string& getNameOfProduct() const;
	
	//���������� �������� ���� ��������
	int getPriceOfProduct() const;
	
	//��������� ������ ����������
	void fillCell();
	
	//������� �� ����������� ���������� ������
	void display() const;
	
	//������� ��������� ������� �� ������
	void deleteElement();
	
	//������������� ���������� ����� �� ������
	bool isCellProductsEmpty() const;
	
	//���������� ������ ��������� ������
	const std::vector<Product>& getCellProducts() const;
	
	//���������� ����� ��������� ���������� ����������� ���� ������
	int getTotalPrice() const;
};
