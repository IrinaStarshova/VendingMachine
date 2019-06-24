#include "purchase.h"
#include "dateTime.h"
#include <sstream>

using namespace std;

Purchase::Purchase(const DateAndTime& purchaseDateAndTime_, const string& productName_, const int& price_) 
	:purchaseDateAndTime(purchaseDateAndTime_), productName(productName_), price(price_)
{
}
string Purchase::getHistory() const
{
	stringstream priceString;
	priceString << price;
	return purchaseDateAndTime.getDateString() + " " + purchaseDateAndTime.getTimeString() + " - "
		+ productName + " - " + priceString.str();
}