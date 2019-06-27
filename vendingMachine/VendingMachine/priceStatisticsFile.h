#pragma once
#include "fileStatistics.h"
#include "machine.h"

class PriceStatisticsFile :public FileStatistics
{
public:
	PriceStatisticsFile();

	//Записывает в текстовый файл статистику покупок, сгруппированную по товарам
	void writeFileStatistics(Machine* machine_) override;
};
