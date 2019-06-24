#pragma once
#include <string>

//Класс даты и времени
class DateAndTime
{
	tm  dateAndTime;

public:
	DateAndTime();
	
	bool operator <(const DateAndTime& rhs) const;
	
	bool operator ==(const DateAndTime& rhs) const;
	
	//Задает значение даты истечения срока годности (случайно от 1 дня до 7 от текущей даты)
	void initExpirationDate();
	
	//Возвращает время в виде строки в отформатированном виде
	//Данный метод используется для формирования имени файла 
	//(т.к. знак ":" нельзя использовать в имени файла)
	std::string getTimeStringForFileName() const;
	
	//Возвращает время в виде строки в отформатированном виде
	std::string getTimeString() const;

	//Возвращает дату в виде строки в отформатированном виде
	std::string getDateString() const;
};