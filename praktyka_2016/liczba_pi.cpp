#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <math.h>

using namespace std;

bool inCircle(int x, int y, int a, int b) {
  int left = (x - a) * (x - a);
  int right = (y - b) * (y - b);

  int l = left + right;

  int r = b * b;

  if (l == r)
    return true;
  return false;
}
bool insideCircle(int x, int y, int a, int b) {
  int left = (x - a) * (x - a);
  int right = (y - b) * (y - b);

  int l = left + right;

  int r = b * b;

  if (l < r)
    return true;
  return false;
}

int main()
{
  int* points[10000];
  int nr_linii = 0;
  float bok = 400;
  fstream punkty;
  string temp, tempA, tempB;
  int x, y;

  punkty.open("punkty.txt", ios::in);

  if (!punkty.good()) exit(0);

  while(!punkty.eof()) {
    getline(punkty, temp);
    points[nr_linii] = new int[2];

    for (int i = 0; i < temp.size(); i++) {
      if (temp[i] == ' ') {
        int howMany = temp.size() - i;
        tempA = temp.substr(0, i);
        tempB = temp.substr(i + 1, howMany);
      }
    }

    x = atoi(tempA.c_str());
    y = atoi(tempB.c_str());

    points[nr_linii][0] = x;
    points[nr_linii][1] = y;

    nr_linii++;
  }

  punkty.close();

  float a = bok / 2;
  int b = bok / 2;

  float iloscNaKole1000 = 0;
  float iloscNaKole5000 = 0;
  float iloscNaKole10000 = 0;

  float iloscWKole1000 = 0;
  float iloscWKole5000 = 0;
  float iloscWKole10000 = 0;

  for (int i = 0; i < 10000; i++) {
    int xTemp = points[i][0];
    int yTemp = points[i][1];

    if (inCircle(xTemp, yTemp, a, b)) {
      cout << "(" << points[i][0] << ", " << points[i][1] << ") \n";
      iloscNaKole10000++;
    }
    if (insideCircle(xTemp, yTemp, a, b))
      iloscWKole10000++;
  }

  for (int i = 0; i < 1000; i++) {
    int xTemp = points[i][0];
    int yTemp = points[i][1];

    if (inCircle(xTemp, yTemp, a, b))
      iloscNaKole1000++;

    if (insideCircle(xTemp, yTemp, a, b))
      iloscWKole1000++;
  }
  for (int i = 0; i < 5000; i++) {
    int xTemp = points[i][0];
    int yTemp = points[i][1];

    if (inCircle(xTemp, yTemp, a, b))
      iloscNaKole5000++;

    if (insideCircle(xTemp, yTemp, a, b))
      iloscWKole5000++;
  }

  float piDla1000 = ((iloscWKole1000 + iloscNaKole1000) * (bok * bok)) / (1000.0 * (a * a));
  float piDla5000 = ((iloscWKole5000 + iloscNaKole5000) * (bok * bok)) / (5000.0 * (a * a));
  float piDla10000 = ((iloscWKole10000 + iloscNaKole10000) * (bok * bok)) / (10000.0 * (a * a));

  cout << iloscNaKole10000 << endl;
  cout << iloscWKole10000 << endl << endl;
  cout << piDla1000 << endl;
  cout << piDla5000 << endl;
  cout << piDla10000 << endl;

  return 0;
}
