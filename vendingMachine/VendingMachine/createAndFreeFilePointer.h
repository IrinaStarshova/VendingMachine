#pragma once
#include "fileStatistics.h"

//������� ������ ������� ����� � ����������� �� ���������� �������� � ���������� ��������� �� ����
FileStatistics* createStatisticsFile(int enteredNumber_);

//����������� ���������� ��� ������� ������ ������
void freeStatisticsFile(FileStatistics* file_);