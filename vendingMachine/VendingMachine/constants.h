#pragma once

const int firstLetter = static_cast<int>('A');	//�������� ��������� ����� ��� ������������ ���� ����� ��������
const int maxNumber = 3;	//�������� ������������ ����� � ����� ������ �������� (��������� ����������� ����� �������� 1). ��������, A1, A2, A3 , B1, B2, B3 � ��.
const int lettersCount = 3;	//���������� ����, ������������ � ������ ��������
const int cellsCount= maxNumber*lettersCount;	//���������� ����� � �������� (��� ������������� �������� ���-�� ����� � ��������, 
//												��������� �������� ���-�� ���� ���������, �������� � std::vector<std::string> productsNames