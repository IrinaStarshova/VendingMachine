#include "availableProductsFile.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

AvailableProductsFile::AvailableProductsFile() :FileStatistics("stat_valid")
{
}

void AvailableProductsFile::writeFileStatistics(Machine* machine_)
{
	cout << "\nStatistics of available products  saved to file\n" << fileName << endl;
	if (!(machine_->getTotalProducts()))
		outfile << "No available products  in the machine";
	else
	{
		vector<Product> availableProducts;
		availableProducts.reserve(machine_->getTotalProducts());
		for (const auto& i : machine_->getCells())
		{
			const vector<Product>& V = i.getCellProducts();
			availableProducts.insert(availableProducts.end(), V.begin(), V.end());
		}
		sort(availableProducts.begin(), availableProducts.end(), Product::SortByNameAndDate());

		for (const auto& i : availableProducts)
			outfile << i.getName() << " - " << i.getExpirationDateString() << '\n';
	}

}