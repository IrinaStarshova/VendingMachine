#pragma once
#include "fileStatistics.h"
#include "machine.h"

class AvailableProductsFile :public FileStatistics
{

public:
	AvailableProductsFile();

	//���������� � ��������� ���� ���������� ���������� � �������� �������
	void writeFileStatistics(Machine* machine_) override;
};
