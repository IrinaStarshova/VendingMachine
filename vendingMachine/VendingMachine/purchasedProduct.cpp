#include "purchasedProduct.h"
#include <sstream>

using namespace std;

PurchasedProduct::PurchasedProduct(const string& name_, int tPrice_):
	name(name_), totalPrice(tPrice_)
{
}

bool PurchasedProduct::operator <(const PurchasedProduct& p) const
{
	return (totalPrice == p.totalPrice) ? name > p.name : totalPrice < p.totalPrice;
}

string PurchasedProduct::getStatistic() const
{
	stringstream tPrice;
	tPrice << totalPrice;
	return name + " - " + tPrice.str();
}
