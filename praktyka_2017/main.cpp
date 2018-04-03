#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int findLightest(int** arr) {
  int lightestPixel = arr[0][0];

  for (int y = 0; y < 200; y++) {
    for (int x = 0; x < 320; x++) {
      if (arr[y][x] > lightestPixel)
        lightestPixel = arr[y][x];
    }
  }

  return lightestPixel;
}

int findDarkest(int** arr) {
  int darkestPixel = arr[0][0];

  for (int y = 0; y < 200; y++) {
    for (int x = 0; x < 320; x++) {
      if (arr[y][x] < darkestPixel && arr[y][x] != 0) {
        darkestPixel = arr[y][x];
      }
    }
  }

  return darkestPixel;
}

int mirror(int** arr) {
  int counts = 0;

  for (int row = 0; row < 200; ++row) {
    for (int col = 0; col < 160; ++col) {
      if (arr[row][col] != arr[row][319 - col]) {
        counts++;
        break;
      }
    }
  }
  return counts;
}

int findContrast(int** arr) {
  int licznik = 0;

  for (int row = 0; row < 200; row++) {
    for (int col = 0; col < 320; col++) {

      if (col < 319 && (abs(arr[row][col] - arr[row][col + 1]) > 128)) {
        licznik++;
        continue;
      }

      if (col > 0 && (abs(arr[row][col] - arr[row][col - 1]) > 128)) {
        licznik++;
        continue;
      }

      if (row < 199 && (abs(arr[row][col] - arr[row + 1][col]) > 128)) {
        licznik++;
        continue;
      }

      if (row > 0 && (abs(arr[row][col] - arr[row - 1][col]) > 128)) {
        licznik++;
        continue;
      }
    }
  }

  return licznik;
}

int findLine(int** arr) {
  int pionowa = 1, pionowaNaj = 1;
  int pozioma = 1, poziomaNaj = 1;

  for (int row = 0; row < 200; row++) {
    for (int col = 0; col < 320; col++) {
      if (col != 319) {
        if (arr[row][col] == arr[row][col + 1]) {
          pozioma++;
        } else {
          if (arr[row][col] == arr[row][col - 1])
            pozioma++;

          if (poziomaNaj < pozioma)
            poziomaNaj = pozioma;

          pozioma = 1;
        }
      } else {
        if (arr[row][col] == arr[row][col - 1]) {
          pozioma++;
          poziomaNaj = pozioma;
        } else {
          if (poziomaNaj < pozioma)
            poziomaNaj = pozioma;

          pozioma = 1;
        }
      }
    }
  }

  for (int col = 0; col < 320; col++) {
    for (int row = 0; row < 200; row++) {
      if (row != 199) {
        if (arr[row][col] == arr[row + 1][col]) {
          pionowa++;
        } else {
          if (arr[row][col] == arr[row - 1][col])
            pionowa++;

          if (pionowaNaj < pionowa)
            pionowaNaj = pionowa;

          pionowa = 1;
        }
      } else {
        if (arr[row][col] == arr[row - 1][col]) {
          pionowa++;
          pionowaNaj = pionowa;
        } else {
          if (pionowaNaj < pionowa)
            pionowaNaj = pionowa;

          pionowa = 1;
        }
      }
    }
  }

  if (pionowaNaj > poziomaNaj) {
    return pionowaNaj;
  }
  return poziomaNaj;
}

int main()
{
  int* pixels[200];
  int nr_linii = 0;

  fstream dane;
  string temp, temp2;

  dane.open("dane.txt", ios::in);

  if (!dane.good()) exit(0);

  while (!dane.eof()) {
    getline(dane, temp);
    pixels[nr_linii] = new int[320];

    int found, i = 0;
    temp2 = "";

    while (temp != "\0" && i < 320) {
      temp2 = "";
      found = temp.find(" ");

      if (found > 0)
        for (int j = 0; j < found; j++)
          temp2 += temp[j];
      else
        temp2 = temp;

      pixels[nr_linii][i] = atoi(temp2.c_str());

      temp.erase(0, found + 1);
      i++;
    }

    nr_linii++;
  }

  dane.close();

  cout << "Najjasniejszy: " << findLightest(pixels) << endl;
  cout << "Najciemniejszy: " << findDarkest(pixels) << endl;
  cout << "Najmniejsza liczba wierszy do usuniecia: " << mirror(pixels) << endl;
  cout << "Sasiednie piksele: " << findContrast(pixels) << endl;
  cout << "Najdluzsza linia: " << findLine(pixels) << endl;

  return 0;
}
