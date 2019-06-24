#pragma once
#include <string>

//����� ���� � �������
class DateAndTime
{
	tm  dateAndTime;

public:
	DateAndTime();
	
	bool operator <(const DateAndTime& rhs) const;
	
	bool operator ==(const DateAndTime& rhs) const;
	
	//������ �������� ���� ��������� ����� �������� (�������� �� 1 ��� �� 7 �� ������� ����)
	void initExpirationDate();
	
	//���������� ����� � ���� ������ � ����������������� ����
	//������ ����� ������������ ��� ������������ ����� ����� 
	//(�.�. ���� ":" ������ ������������ � ����� �����)
	std::string getTimeStringForFileName() const;
	
	//���������� ����� � ���� ������ � ����������������� ����
	std::string getTimeString() const;

	//���������� ���� � ���� ������ � ����������������� ����
	std::string getDateString() const;
};