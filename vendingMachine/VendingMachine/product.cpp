#include "product.h"

using namespace std;

Product::Product(const string& name_) : name(name_)
{
	expirationDate.initExpirationDate();
}

const string& Product::getName() const
{
	return name;
}
string Product::getExpirationDateString() const
{
	return expirationDate.getDateString();
}