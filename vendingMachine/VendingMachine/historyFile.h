#pragma once
#include "fileStatistics.h"
#include "machine.h"

class HistoryFile :public FileStatistics
{
public:
	HistoryFile();

	//���������� � ��������� ���� ������� �������
	void writeFileStatistics(Machine* machine_) override;
};