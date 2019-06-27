#pragma once
#include "fileStatistics.h"

//Создает объект нужного файла в зависимости от введенного значения и возвращает указатель на него
FileStatistics* createStatisticsFile(int enteredNumber_);

//Освобождает выделенную под объекты файлов память
void freeStatisticsFile(FileStatistics* file_);