#pragma once
#include "fileStatistics.h"
#include "machine.h"

class PriceStatisticsFile :public FileStatistics
{
public:
	PriceStatisticsFile();

	//���������� � ��������� ���� ���������� �������, ��������������� �� �������
	void writeFileStatistics(Machine* machine_) override;
};
