#pragma once
#include <string>
#include "dateTime.h"
#include "machine.h"
#include <fstream>

class FileStatistics
{
	DateAndTime currentDateAndTime;
protected:
	std::string fileName;
	std::ofstream outfile;

public:
	FileStatistics(std::string beginFName);
	virtual ~FileStatistics();
	virtual void writeFileStatistics(Machine* machine_)=0;
};


