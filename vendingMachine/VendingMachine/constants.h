#pragma once

const int firstLetter = static_cast<int>('A');	//Значение начальной буквы для формирования имен ячеек автомата
const int maxNumber = 3;	//Значение максимальной цифры в имени ячейки автомата (значением минимальной цифры является 1). Например, A1, A2, A3 , B1, B2, B3 и пр.
const int lettersCount = 3;	//Количество букв, используемых в именах автомата
const int cellsCount= maxNumber*lettersCount;	//Количество ячеек в автомате (При необходимости изменить кол-во ячеек в автомате, 
//												требуется изменить кол-во имен продуктов, заданных в std::vector<std::string> productsNames