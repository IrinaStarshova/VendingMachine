#pragma once
#include "fileStatistics.h"
#include "machine.h"

class AvailableProductsFile :public FileStatistics
{

public:
	AvailableProductsFile();

	//Записывает в текстовый файл статистику оставшихся в автомате товаров
	void writeFileStatistics(Machine* machine_) override;
};
