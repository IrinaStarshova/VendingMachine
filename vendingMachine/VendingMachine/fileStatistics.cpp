#include "fileStatistics.h"
#include "purchasedProduct.h"
#include <iostream>
#include <vector>


using namespace std;

FileStatistics::FileStatistics(string beginFName)
{
	fileName = beginFName+"_" + currentDateAndTime.getDateString() + "_" + currentDateAndTime.getTimeStringForFileName() + ".log";
	outfile.open(fileName);
}
FileStatistics::~FileStatistics()
{
	outfile.close();
}


