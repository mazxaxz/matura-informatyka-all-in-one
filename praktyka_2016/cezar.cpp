#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

char encrypt(char c) {
    int k = 107;

    if ((int)c > 64 && (int)c < 91) {
        k = k % 26;
        c += k;

        if (c > 90)
            c -= 26;

        return (char)c;
    }
}

char decrypt(char c, int key) {
    int k = key % 26;
    c = (int)c;

    if (c > 64 && c < 91) {
        c -= k;

        if (c < 65)
            c += 26;

        return (char)c;
    }
}

int findKey(char a, char b) {
    a = (int)a % 26;
    b = (int)b % 26;

    int c = b - a;

    if (b > a) {
        if (c < 0)
            return ((26 - c) * (-1));
        return (26 - c);
    }

    if (c > 0)
        return c;

    return (c * (-1));
}

int main()
{
  /////////////////////////////////////ZAD_6.1////////////////////////
  int nr_wiersza = 0;
  fstream slowaNieszyfrowane;
  fstream wynik;
  string slowa[100];

  slowaNieszyfrowane.open("dane_6_1.txt", ios::in);

  if (!slowaNieszyfrowane.good()) exit(0);

  while (!slowaNieszyfrowane.eof()) {
    getline(slowaNieszyfrowane, slowa[nr_wiersza]);
    nr_wiersza++;
  }

  slowaNieszyfrowane.close();

  for (int i = 0; i < 100; i++) {
    int j = 0;
    while (slowa[i][j]) {
      slowa[i][j] = encrypt(slowa[i][j]);
      j++;
    }
  }

  wynik.open("wyniki_6_1.txt", ios::out);

  if (!wynik.good()) exit(0);

  for (int i = 0; i < 100; i++) {
    wynik << slowa[i] << endl;
  }

  wynik.close();
  ////////////////////////////////////////////ZAD6.2//////////////////////////

  int nr_linii = 0;
  int klucz[3000];
  string slowaSz[3000];
  string temp, tempA, tempB;
  fstream slowaSzyfrowane;
  fstream wynik2;

  slowaSzyfrowane.open("dane_6_2.txt", ios::in);

  if (!slowaSzyfrowane.good()) exit(0);

  while (!slowaSzyfrowane.eof()) {
    getline(slowaSzyfrowane, temp);

    for (int i = 0; i < temp.size(); i++) {
      if (temp[i] == ' ') {
        int howMany = temp.size() - i;
        tempA = temp.substr(0, i);
        tempB = temp.substr(i + 1, howMany);
      }
    }

    slowaSz[nr_linii] = tempA;
    klucz[nr_linii] = atoi(tempB.c_str());

    nr_linii++;
  }

  slowaSzyfrowane.close();

  for (int i = 0; i < 3000; i++) {
    int j = 0;
    while (slowaSz[i][j]) {
      slowaSz[i][j] = decrypt(slowaSz[i][j], klucz[i]);
      j++;
    }
  }

  wynik2.open("wyniki_6_2.txt", ios::out);

  if (!wynik2.good()) exit(0);

  for (int i = 0; i < 3000; i++)
    wynik2 << slowaSz[i] << endl;

  wynik2.close();
  ///////////////////////////////////////////////////////ZAD6.3///////////////////

  int linia = 0;
  string slowaClean[3000];
  string slowaDirty[3000];

  string temp3;

  fstream slowaSprawdz;
  fstream wynik3;

  slowaSprawdz.open("dane_6_3.txt", ios::in);

  if (!slowaSprawdz.good()) exit(0);

  while (!slowaSprawdz.eof()) {
    getline(slowaSprawdz, temp3);

    for (int i = 0; i < temp3.size(); i++) {
      if (temp3[i] == ' ') {
        int howMany = temp3.size() - i;
        slowaClean[linia] = temp3.substr(0, i);
        slowaDirty[linia] = temp3.substr(i + 1, howMany);
      }
    }

    linia++;
  }

  slowaSprawdz.close();

  wynik3.open("wyniki_6_3.txt", ios::out);

  if (!wynik3.good()) exit(0);

  bool correct;
  int key;
  int key2;

  for (int i = 0; i < 3000; i++) {
    int j = 1;
    correct = true;
    key = findKey(slowaClean[i][0], slowaDirty[i][0]);
    key2 = 0;

    while (slowaClean[i][j]) {
      key2 = findKey(slowaClean[i][j], slowaDirty[i][j]);

      if (key != key2)
        correct = false;

      j++;
    }

    if (!correct)
      wynik3 << slowaClean[i] << endl;
  }

  wynik3.close();

  return 0;
}
