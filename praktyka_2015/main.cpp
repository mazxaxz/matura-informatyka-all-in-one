#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

int getCountWhereMoreZeros(string *nums, int si) {
  int moreZerosCount = 0;
  int oneCounter, zeroCounter, index;

  for (int i = 0; i < si; i++) {
    oneCounter = 0;
    zeroCounter = 0;
    index = 0;

    while (nums[i][index])
    {
      if (nums[i][index] == '1')
        oneCounter++;
      else
        zeroCounter++;

      index++;
    }

    if (zeroCounter > oneCounter)
      moreZerosCount++;
  }

  return moreZerosCount;
}

int getEvenNumbersCount(string *nums, int si) {
  int evenNumber = 0;
  int lastIndex;

  for (int i = 0; i < si; i++) {
    lastIndex = nums[i].size() - 1;

    if (nums[i][lastIndex] == '0')
      evenNumber++;
  }

  return evenNumber;
}

int getEightCount(string *nums, int si) {
  int eightDiv = 0;
  int lastIndex;
  bool isDivided;

  for (int i = 0; i < si; i++) {
    lastIndex = nums[i].size() - 1;
    isDivided = true;

    for (int j = lastIndex; j > lastIndex - 3; j--) {
      if (nums[i][j] == '1')
        isDivided = false;
    }

    if (isDivided)
      eightDiv++;
  }

  return eightDiv;
}

int getMinLine(string *nums, int si) {
  int minIndex = 0;
  string minValue = nums[0];

  for (int i = 1; i < si; i++) {
    if (nums[i].size() < minValue.size()) {
      minValue = nums[i];
      minIndex = i;
    } else {
      if (nums[i].size() == minValue.size()) {
        if (nums[i] < minValue) {
          minValue = nums[i];
          minIndex = i;
        }
      }
    }
  }

  return (minIndex + 1);
}

int getMaxLine(string *nums, int si) {
  int maxIndex = 0;
  string maxValue = nums[0];

  for (int i = 1; i < si; i++) {
    if (nums[i].size() > maxValue.size()) {
      maxValue = nums[i];
      maxIndex = i;
    } else {
      if (nums[i].size() == maxValue.size()) {
        if (nums[i] > maxValue) {
          maxValue = nums[i];
          maxIndex = i;
        }
      }
    }
  }
  return (maxIndex + 1);
}

int main()
{
  int ilosc_liczb = 1000;
  string numbers[ilosc_liczb];
  fstream liczby, wynik4;
  int line_number = 0;

  liczby.open("liczby.txt", ios::in);

  if (!liczby.good()) exit(0);

  while(!liczby.eof()) {
    getline(liczby, numbers[line_number]);
    line_number++;
  }

  liczby.close();


  int zad4_1 = getCountWhereMoreZeros(numbers, ilosc_liczb);
  int zad4_2_2 = getEvenNumbersCount(numbers, ilosc_liczb);
  int zad4_2_8 = getEightCount(numbers, ilosc_liczb);
  int zad4_3_min = getMinLine(numbers, ilosc_liczb);
  int zad4_3_max = getMaxLine(numbers, ilosc_liczb);


  wynik4.open("wynik4.txt", ios::out);

  wynik4 << "4.1 -> " << zad4_1 << endl;
  wynik4 << "4.2 podzielne przez 2 -> " << zad4_2_2 << endl;
  wynik4 << "4.2 podzielne przez 8 -> " << zad4_2_8 << endl;
  wynik4 << "4.3 min index -> " << zad4_3_min << endl;
  wynik4 << "4.3 max index -> " << zad4_3_max << endl;

  wynik4.close();

  return 0;
}