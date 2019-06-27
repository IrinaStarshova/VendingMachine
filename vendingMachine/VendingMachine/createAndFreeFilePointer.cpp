#include "createAndFreeFilePointer.h"
#include "availableProductsFile.h"
#include "historyFile.h"
#include "priceStatisticsFile.h"

FileStatistics* createStatisticsFile(int enteredNumber_)
{
	switch (enteredNumber_)
	{
	case 3:return new HistoryFile; break;
	case 4:return new PriceStatisticsFile; break;
	case 5:return new AvailableProductsFile; break;
	default:return nullptr;
	}
}

void freeStatisticsFile(FileStatistics* file_)
{
	delete file_;
}