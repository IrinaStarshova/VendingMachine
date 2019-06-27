#pragma once
#include <vector>
#include <string>
#include "cell.h"
#include "purchase.h"

//����� ��������
class Machine
{
	std::vector<std::string> cellsNames;
	std::vector<std::string> productsNames;
	std::vector<int> prices;
	std::vector <Cell> cells;
	std::vector<Purchase> purchasesHistory;
	int totalProducts;

	//������ �������� ���� ��������� � ������������ �� � ��������� �������
	void initProductsNames();

	//������ �������� ��� ��������� (�������� �� 1 �� 100)
	void initPrices();

	//������ �������� ���� ����� � ������������ � ��������� �������, ��������� � "constants.h"
	void initCellsNames();

public:
	Machine();

	//��������� ������� ��������
	void fillMachine();

	//������� �� ����������� ������� ����
	void displayMenu() const;

	//������� �� ����������� ���� ��������
	void displayMachineMenu() const;

	//��������� �������
	void Run();

	//���������� ������� ������
	void buyProduct();

	//���������� ����� ���������� ��������� � ��������
	int getTotalProducts() const;

	//���������� ������ �����
	const std::vector<Cell>& getCells() const;

	//���������� ������ ������ � �������
	const std::vector<Purchase>& getPurchasesHistory() const;
};