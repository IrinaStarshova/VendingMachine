#include "priceStatisticsFile.h"
#include "purchasedProduct.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

PriceStatisticsFile::PriceStatisticsFile() : FileStatistics("stat_price")
{
}

void PriceStatisticsFile::writeFileStatistics(Machine* machine_)
{
	cout << "\nPurchase statistics saved to file\n" << fileName << endl;
	vector<PurchasedProduct> purchasedProducts;
	for (const auto& i : machine_->getCells())
	{
		if (i.getTotalPrice())
		{
			purchasedProducts.push_back(PurchasedProduct(i.getNameOfProduct(), i.getTotalPrice()));
		}
	}
	if (!purchasedProducts.empty())
	{
		sort(purchasedProducts.rbegin(), purchasedProducts.rend());
		for (const auto& i : purchasedProducts)
			outfile << i.getStatistic() << '\n';
	}
	else
		outfile << "No one product purchased";

}
