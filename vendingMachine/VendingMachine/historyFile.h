#pragma once
#include "fileStatistics.h"
#include "machine.h"

class HistoryFile :public FileStatistics
{
public:
	HistoryFile();

	//Записывает в текстовый файл историю покупок
	void writeFileStatistics(Machine* machine_) override;
};