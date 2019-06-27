#include "historyFile.h"
#include <iostream>

using namespace std;

HistoryFile::HistoryFile() : FileStatistics("history")
{
}

void HistoryFile::writeFileStatistics(Machine* machine_)
{
	cout << "\nPurchase history saved to file\n" << fileName << endl;
	if (!machine_->getPurchasesHistory().empty())
	{
		for (int i = static_cast<int>(machine_->getPurchasesHistory().size()) - 1; i >= 0; --i)
			outfile << machine_->getPurchasesHistory()[i].getHistory() << '\n';
	}
	else outfile << "No one product purchased";

}