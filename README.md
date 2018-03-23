# Matura informatyka all in one

## Spis treści
<ol>
  <li><a href="#ogolna-informatyka">Ogólna informatyka</a></li>
  <li><a href="#algorytmy-warte-uwagi">Algorytmy warte uwagi</a></li>
  <li><a href="#c">C++ cheatsheet</a></li>
  <li><a href="#java-cheatsheet">Java cheatsheet</a></li>
  <li><a href="#excel">Excel</a></li>
  <li><a href="#access">Access / SQL</a></li>
  <li><a href="#rozwiazania-arkuszy">Rozwiązania arkuszy</a>
    <ul>
      <li><a href="#2015">2015</a></li>
      <li><a href="#2016">2016</a></li>
      <li><a href="#2017">2017</a></li>
    </ul>
  </li>
</ol>

## Ogolna informatyka
TBA

## Algorytmy warte uwagi
**Podstawowe**
- Wyszukiwanie najmniejszej wartości w tablicy  
```
Max <- Tablica[0]

for i := 1, 2, 3..., nie więcej niż długość tablicy
  if Tablica[i] jest większe od Max
    Max <- Tablica[i]

Wyjście: Max
```  
C++:  
```cpp
int getMaxNumber(int *Tablica, const int wielkosc) {
  int Max = arr[0];

  for (int i = 1; i < wielkosc; i++) {
    if (Tablica[i] > Max)
      Max = Tablica[i];
  }

  return Max;
}
```

- Wyszukiwanie najwiekszej wartości w tablicy  
```
Min <- Tablica[0]

for i := 1, 2, 3..., nie więcej niż długość tablicy
  if Tablica[i] jest mniejsze od Min
    Min <- Tablica[i]

Wyjście: Min
```
C++:
```cpp
int getMinNumber(int *Tablica, const int wielkosc) {
  int Min = arr[0];

  for (int i = 1; i < wielkosc; i++) {
    if (Tablica[i] < Min)
      Min = Tablica[i];
  }

  return Min;
}
```

- Ciąg Fibonacciego rekurencyjnie  
C++:
```
unsigned long fib(unsigned int n) {
  if (n == 0 || n == 1)
    return n;

  return fib(n - 1) + fib(n - 2);
}
```

- Obliczanie silni rekurencyjnie  
C++:
```
unsigned long factorial(const unsigned int n) {
  if (n == 1 || n == 2)
    return n;

  return n * factorial(n-1);
}
```

- Odwrocenie tablicy
C++:
```
int* reverseArray(int *arr, int si) {
  int* newArr = 0;
  newArr = new int[si];

  for (int i = 0; i < si; i++) {
    newArr[i] = arr[si - i - 1];
  }

  return newArr;
}
```

- Odwrocenie stringa rekurencyjnie
```
Jeżeli string jest pusty albo zawiera jeden znak
  zwroć string
W przeciwnym wypadku
  Usuń pierwszy znak
  Odwroć string
  Dodaj pierwszy znak do odwroconego stringa
  Zwroć nowy string
```

C++:
```cpp
string reverseString(string s) {
  if (s.size() == 0 || s.size() == 1)
    return s;

  string last(1, s[s.length() - 1]);
  string reversed = reverseString(s.substr(0, s.length() - 1));

  return last + reversed;
}
```

---

- NWD -> Największy wspolny dzielnik (Euklides)
```
podprogram NWD(a, b)
  dopóki b ≠ 0
    c := reszta z dzielenia a przez b
    a := b
    b := c
  zwróć a
```

C++:
```cpp
int euclidean(int a, int b) {
  int c;

  while(b != 0) {
    c = a % b;
    a = b;
    b = c;
  }

  return a;
}
```

- NWD rozszerzony
```
podprogram NWD(a, b)
  x := 1
  y := 0
  r := 0
  s := 1

  dopóki b ≠ 0
    c := reszta z dzielenia a przez b
    q := część całkowita z dzielenia a przez b
    a := b
    b := c

    r' = r
    s' = s
    r = x - q · r
    s = y - q · s
    x = r'
    y = s'

  zwróć a, x, y
```

- Sito Eratostenesa (do szukania liczb pierwszych)
```
Wejście: liczba całkowita n > 1
 
Niech A będzie tablicą typów logicznych indeksowaną liczbami całkowitymi od 2 do n
początkowo wypełniona wartościami true
 
  for i := 2, 3, 4, ..., nie więcej niż pierwiastek z n
    if A[i] = true:
      for j :=  i^2, i^2 + i, i^2 + 2i, ..., nie więcej niż n :
        A[j] := false
 
Wyjście: wartości i takie, że A[i] zawiera wartość true.
```

C++:
```cpp
void sieve(bool *arr, unsigned int n) {
  for (int i = 2; i*i <= n; i++) {
    if (arr[i]) {
      for (int j = i*i; j <= n; j+=i)
        arr[j] = false;
    }
  }
}
```

- Wyszukiwanie binarne (Divide and Conquer)
```
A := [...]      { n-elementowa tablica uporządkowana }
lewo := 1       { indeks początku przedziału }
prawo := n    { indeks końca przedziału - początkowo cała tablica A }

y := poszukiwana wartość
indeks := pusty

while lewo < prawo do
  begin
    środek := (lewo + prawo) div 2; { dzielenie całkowitoliczbowe }
    
    if A[środek] < y then
      lewo := środek + 1
    else
      prawo := środek;
  end;

if A[lewo] = y then
  indeks := lewo
else
  indeks := brak;
```

C++:
```cpp
int divideAndConquer(int *arr, int si, int elem) {
  int left = 0;
  int right = si - 1;
  int mid;

  while (left < right) {
    mid = (left + right) / 2;

    if (arr[mid] == elem)
      return mid;

    if (arr[mid] < elem)
      left = mid + 1;
    else
      right = mid - 1;
  }

  return -1;
}
```

- Potęgowanie sposobem naiwnym
```
result = 1;
a = a mod n;
for i=1 to b do
  begin
    result = result * a;
    result = result mod n;
  end;
```

C++:
```cpp
long naivePowerMod(int a, int b, int n) {
  int result = 1;
  a = a % n;

  for (int i = 1; i <= b; i++) {
    result *= a;
    result = result % n;
  }
  return result;
}
```


## C++ cheatsheet
### Biblioteki
* `Include <string>` -> do operacji na stringach
* `Include <iostream>` -> cin, cout
* `Include <fstream>` -> Odczyt i zapis plikow
* `Inlcude <cstdlib>` -> funkcje: exit(), atof(), atoi(), itoa(), rand()...
* `Include <time.h>` -> do operacji na czasie oraz generowania liczb pseudolosowych
* `Include <math.h>` -> funkcje matematyczne typu sqrt() czy pow()

### Syntax
**Pętla for**
```cpp
for (int i = 0; i < 10; i++)
  cout << i << endl;

for (int i = 0; i < 20; i++) {
  if (i % 2 == 0)
    break;                    // Przerwanie pętli
}
```


**Pętla While**
```cpp
int i = 10;
while (i > 10) {
  cout << i << endl;
  i++;
}
```

**Switch**
```cpp
switch(x) {
  case 1:
    cout << "1" << endl;
    break;
  case 2:
    cout << "2" << endl;
    break;
  case 3:
    cout << "3" << endl;
    break;
  default:
    cout << "default" << endl;
    break;
}
```

**Funkcje**  
`<typ_zwracanych_danych> nazwaFunkcji(<typ_argumentu> nazwaArgumentu)`

```cpp
int function(int a, int b) {
  return (a + b);
}

// ------------------------------------------------------------------------

/*
Funkcja zwracająca nową tablice, dostająca w argumentach
wskaźnik na pierwszy element tablicy oraz jej wielkość
*/
int* funkcja(int *tablica, int wielkosci) {
  int* nowaTablica = new int[wielkosc];

  for (int i = 0; i < wielkosc; i++)
    nowaTablica[i] = tablica[i];

  return nowaTablica
}

// ------------------------------------------------------------------------

//Funkcja zwracająca tablice dwuwymiarową, dostająca w argumencie wielkość
int** funkcja(unsigned int wielkosc) {
  int** tablica = 0;
  tablica = new int*[wielkosc];

  for (int i = 0; i < wielkosc; i++)
    tablica[i] = new int[wielkosc];

  return tablica;
}
/* Wynik dla wielkości 4
    int int int int
    int int int int
    int int int int
    int int int int
*/

// ------------------------------------------------------------------------

// Funkcja jako argument funkcji
int funkcja(int (*func)(int, int), int a, int b) {
  result = func(a, b);

  return result;
}
int przykladowaFunkcja(int c, int d) {
  return (c + d);
}
// Wywołanie
funkcja(przykladowaFunkcja, 10, 20);

```

**Warunek IF**
```cpp
if (a > b) {
  // Operacje
} else if (bool) {
  // Jeżeli bool == true
} else if (!bool) {
  // Jeżeli bool == false
} else if (a < b + 1 || a > c) {
  // Podwojny warunek "Lub"
} else if (a < b + 1 && a > c) {
  // Podwojny warunek "I"
} else {
  // Coś innego
}
```

**Zatrzymanie działania konsoli**  
`system("pause")` -> wymaga `<cstdlib>`

**Czyszczenie konsoli**  
`system("cls")` -> wymaga `<cstdlib>`

**Wskaźniki**
```cpp
int       * p;        // Wskaźnik
int const * p         // Wskaźnik do stałej wartości
int       * const p;  // Stały wskaźnik
int const * const p;  // Stały wskaźnik do stałej wartości

// Referencja
int foo = 5;
int * bar;
bar = &foo;
// *bar = 5
foo = 6;
// *bar = 6
```

**Tablice**
```cpp
int array[5];     // Tablica z zawartością typu całkowitego
int array[10][10] // Tablica dwuwymiarowa
char a[] = "foo"  // Tablica znakow

int * array[10]   // Wskaźnik na tablice
```

**Tablica ASCII**

![main-qimg-f4c01360fc4a6a8717f6c431e0c9bcd5](https://user-images.githubusercontent.com/32012952/37831090-8f0118fe-2ea4-11e8-99e0-c4bb7abd8f90.png)

```cpp
// Konwersja znaku na liczbe jemu odpowiadającą
char c = 'a';
int ci = (int)c;
// ci = 97

// Konwersja liczby na znak jemu odpowiadający
int ci = 97;
char c = (char)ci;
// c = 'a';
```

**Typy danych w C++**

![typy](https://user-images.githubusercontent.com/32012952/37831150-c2221c06-2ea4-11e8-84ff-3bd4fd9ff2fd.PNG)

### "Gotowe rozwiązania"
**Odczyt pliku**
```cpp
fstream input;
string zmienna;

string tablica[100];
int nr_linii = 0;

input.open("input.txt", ios::in);
if (!input.good()) exit(0);

// Odczyt jednej linijki do zmiennej
getline(input, zmienna);

// Odczyt do tablicy
while (!input.eof()) {
  getline(input, tablica[nr_linii]);
  nr_linii++
}

input.close();
```

**Zapis do pliku**
```cpp
fstream output;

// Dla zapisu usuwającego poprzednie dane w pliku
output.open("output.txt", ios::out);

// Dla zapisu dopisującego dane do już istniejących
output.open("output.txt", ios::out | ios::app);

output << "Pierwsza linijka" << endl;
output << "Druga linijka" << endl;

output.close();
```

## Java cheatsheet
TBA

## Excel
TBA

## Access / SQL
TBA

## Rozwiazania arkuszy
### 2015
### Pisemny
---
**1. Problem telewidza**  
  Algorytm:
  ```
  T -> Zbior filmow, dane
  S -> Strategia
  P -> Zbior filmow, wynik

  P jest pusty
  Dopoki T zawiera filmy
    Wybierz z T film X i usuń go z T, zgodnie z S
    Dodaj X do P
    Usun z T wszystkie filmy, ktorych czasy emisji koliduja z X
  Wypisz P
  ```
  ---
  * **1.1**

  | Strategia S | Zawartosc P po zakończeniu algorytmu |
  | ----------- | ------------------------------------ |
  | B           | Film 5, Film 2                       |
  | C           | Film 1, Film 4, Film 2               |
  | D           | Film 1, Film 4, Film 2               |

  *Przykładowy przebieg algorytmu dla strategii C*

  ![strategiac](https://user-images.githubusercontent.com/32012952/37739227-c844128e-2d59-11e8-97f8-d448865f8d60.png)
  
  ---
  
  * **1.2**  
  Dowod na to, ze zadna ze strategii nie jest optymalna  
  Podajemy 4 filmy, z ktorych wedlug algorytmu widz obejrzy 2, natomiast moze obejrzec 3
  `Strategia A`

  ![1](https://user-images.githubusercontent.com/32012952/37739229-c935999c-2d59-11e8-832a-96962491ddf3.png)

  | Stacja | Film i godziny emisji      | Czas trwania |
  | ------ | -------------------------- | ------------ |
  | TV1    | Film 1 (od 9:00 do 13:00)  | 4 godziny    |
  |        | Film 2 (od 10:00 do 12:00) | 2 godziny    |
  | TV2    | Film 3 (od 12:00 do 14:00) | 2 godziny    |
  |        | Film 4 (od 14:00 do 17:00) | 3 godziny    |

  *Wynik dzialania algorytmu*  
  `P` = Film 1, Film 4  
  `Liczniejszy zbior` = Film 2, Film 3, Film 4  

  `Strategia B`

  ![2](https://user-images.githubusercontent.com/32012952/37739231-ca140d3a-2d59-11e8-8b4f-7538eb4fc3b1.png)

  | Stacja | Film i godziny emisji      | Czas trwania |
  | ------ | -------------------------- | ------------ |
  | TV1    | Film 1 (od 10:00 do 12:00) | 2 godziny    |
  |        | Film 2 (od 11:30 do 12:30) | 1 godziny    |
  | TV2    | Film 3 (od 12:00 do 14:00) | 2 godziny    |
  |        | Film 4 (od 15:00 do 16:00) | 1 godziny    |

  *Wynik dzialania algorytmu*  
  `P` = Film 2, Film 4  
  `Liczniejszy zbior` = Film 1, Film 3, Film 4  

  `Strategia C`

  ![3](https://user-images.githubusercontent.com/32012952/37739236-cb00fe56-2d59-11e8-8f40-f5b348571f69.png)

  | Stacja | Film i godziny emisji      | Czas trwania |
  | ------ | -------------------------- | ------------ |
  | TV1    | Film 1 (od 9:00 do 13:00)  | 4 godziny    |
  |        | Film 2 (od 10:00 do 12:00) | 2 godziny    |
  | TV2    | Film 3 (od 12:00 do 14:00) | 2 godziny    |
  |        | Film 4 (od 14:00 do 16:00) | 2 godziny    |

  *Wynik dzialania algorytmu*  
  `P` = Film 1, Film 4  
  `Liczniejszy zbior` = Film 2, Film 3, Film 4  

---

**2. Test**  
  * 1032<sub>4</sub> * 131<sub>4</sub> = ? --> 
    1032<sub>4</sub> = 78<sub>10</sub> ||
    131<sub>4</sub> = 29<sub>10</sub>  
      
    **1.** 78<sub>10</sub>  
    **2.** 8D6<sub>16</sub>  
    **3.** 4326<sub>8</sub>  
    **4.** 10011010110<sub>2</sub>  

    **1** -> Fałsz; **2** -> Prawda; **3** -> Prawda; **4** -> Fałsz 

  * `Kompresja stratna w grafice`  
    **1.** ma zwiazek z plikami w formacie BMP  
    **2.** ma zwiazek z plikami w formacie JPG  
    **3.** jest metoda zmniejszania rozmiary pliku graficznego bez utraty szczegołow w obrazie  
    **4.** wykorzystuje algorytm szyfrowania RSA  

    **1** -> Fałsz; **2** -> Prawda; **3** -> Fałsz; **4** -> Prawda

  * `Filtrowanie tabeli w bazie danych`  
    **1.** polega na wyborze wierszy spełniających określone kryterium  
    **2.** polega na wyborze niektorych kolumn  
    **3.** zmienia jej zawartość  
    **4.** wymaga podania warunku dla jednej lub kilku kolumn tabeli  

    **1** -> Prawda; **2** -> Fałsz; **3** -> Fałsz; **4** -> Prawda

  * `Licencja ADWARE`  
    **1.** jest rozpowszechniane za darmo, ale zawiera funkcje wyświetlające reklamy  
    **2.** ma otwarty kod źródłowy.  
    **3.** jest opłacane przez użytkownika.  
    **4.** może być używane tylko przez z góry ustalony czas.  

    **1** -> Prawda; **2** -> Fałsz; **3** -> Fałsz; **4** -> Fałsz
  
  * `Arkusz kalkulacyjny`  
    **1.** W komórce C2 umieszczona zostanie formuła =A$2∗C1.  
    **2.** W komórce B3 umieszczona zostanie formuła =A$2∗B2.  
    **3.** Wartość w komórce B10 wyniesie 1024.  
    **4.** Wartość w komórce C2 wyniesie 4.  

    **1** -> TBA; **2** -> TBA; **3** -> TBA; **4** -> TBA

---

**3. Rozszerzony algorytm Euklidesa**  
  Wyznacza NWD (Największy wspolny dzielnik) dwoch licz *a > 0* i *b >= 0*  

  Algorytm:
  ```
  Jeżeli b = 0 to NWD = a, koniec programu
    r = a modulo b
    a = b
    b = r
  
  zwroć a
  ```
  `NWD(a, b) = a * x + b * y`

  ```
  Jeżeli r = a modulo b nie rowna się 0
    NWD(b, r) = b * x' + r * y'

    więc (x, y) można zapisać
    x = y'
    y = x' - (a div b) * y'
  ```

---

  * **3.1**
    Uzupełnij tabele -> a = 188, b = 12

    ![tabela](https://user-images.githubusercontent.com/32012952/37783708-72f1a362-2df6-11e8-87ca-5a412f8a564a.png)

---

  * **3.2**  
    a > 0 oraz b >=0 ---> (x, y) dla ktorych NWD(a, b) = a * x + b * y  
    Uzupełnij **#1**, **#2**, **#3**, **#4**  

    - Jeżeli b = 0, zwroć (1, 0) i zakończ
    - r = a modulo b
    - (x, y) = NWD(**#1**, **#2**)
    - zwroć (**#3**, **#4**)

  Odpowiedz jest zawarta w podanym wyżej algorytmie:
  > NWD(b, r) = b * x' + r * y'  
  > więc (x, y) można zapisać  
  > x = y'  
  > y = x' - (a div b) * y'  
  
  Z tego wynika, że:  
    **#1** = b  
    **#2** = r  
    **#3** = y  
    **#4** = x - (a div b) * y  

---
### Praktyka
---

**4. Liczby binarne**
  * **4.1**  
  ```
  > Zapisujemy każdą linijke z pliku do tablicy[n]
  > Piszemy funkcje zwracającą ilość liczb w ktorych jest więcej zer niż jedynek
  > Zapisujemy do pliku tekstowego wynik funkcji
  ```

  Funkcje sprawdzającą w C++ można napisać w ten sposob:
  ```cpp
  int getCountWhereMoreZeros(string *nums, int si) { // Argumentami są: wskaźnik na tablice oraz jej wielkość
    int moreZerosCount = 0;                          // Inicjujemy ilość szukanych liczb z wartością startową
    int oneCounter, zeroCounter, index;              // Licznik jedynek, dwojek oraz
                                                     // obecny index sprawdzanego stringa
    for (int i = 0; i < si; i++) {
      oneCounter = 0;                                // Za każdym powtorzeniem pętli
      zeroCounter = 0;                               // Zmienne się zerują
      index = 0;

      while (nums[i][index]) {                       // Sprawdzamy każdy znak
        if (nums[i][index] == '1')                   // Dopoki nie trafimy na \0
          oneCounter++;
        else
          zeroCounter++;

        index++;
      }
                                                     // Po sprawdzeniu ciągu znakow
      if (zeroCounter > oneCounter)                  // sprawdzamy czy zer jest
        moreZerosCount++;                            // więcej od jedynek
    }

    return moreZerosCount;                           // Zwracamy ilość wyrazow
  }
  ```
---

  * **4.2**  
  ```
  > Sprawdzamy podzielność liczb podzielnych przez 2 oraz 8
  > Liczba binarna jest podzielna przez 2 jeżeli ostatni znak jest zerem
  > Liczba binarna jest podzielna przez 8 jeżeli 3 ostatnie znaki są zerami
  > Wypisujemy ilość takich liczb
  ```

  Funkcje sprawdzającą czy liczba jest podzielna przez 2 w C++ można zapisać w ten sposob:
  ```cpp
  int getEvenNumbersCount(string *nums, int si) { // Wskaźnik na tablice i wielkość
    int evenNumber = 0;                           // Ilość startowa liczb parzystych
    int lastIndex;                                // Ostatni znak ciągu

    for (int i = 0; i < si; i++) {
      lastIndex = nums[i].size() - 1;             // Inicjujemy ostatni znak ciągu
                                                  // z każdym powtorzeniem pętli
      if (nums[i][lastIndex] == '0')              // Jeżeli ostatni znak jest zerem
        evenNumber++;                             // inkrementuj ilość liczb parzystych
    }

    return evenNumber;                            // Zwracamy ilość liczb parzystych
  }
  ```

  Natomiast funkcje wypisującą liczby podzielne przez 8 w ten sposob:
  ```cpp
  int getEightCount(string *nums, int si) {             // To samo co w poprzednich
    int eightDiv = 0;                                   // przypadkach
    int lastIndex;                                      //
    bool isDivided;                                     // Zmienna logiczna podzielności

    for (int i = 0; i < si; i++) {
      lastIndex = nums[i].size() - 1;                   // Z każdą iteracją inicjujemy ostatni index
      isDivided = true;                                 // oraz zmienna logiczną

      for (int j = lastIndex; j > lastIndex - 3; j--) { // Odwrotna pętla 
        if (nums[i][j] == '1')                          // Sprawdzająca czy ktoryś z
          isDivided = false;                            // 3 ostatnich znakow
      }                                                 // rowna się 1, jeżeli tak
                                                        // to isDivided = false
      if (isDivided)                                    // Jeżeli jest podzielna
        eightDiv++;                                     // inkrementujemy ilość tych liczb
    }

    return eightDiv;                                    // Zwracamy ilość liczb
  }
  ```
---

  * **4.3**
  ```
  > Szukamy najmniejszej i największej liczby
  > Najmniejsza posiada najmniej wyrazow, i ma najwięcej zer z tych wyrazow ktore mają tą samą długość
  > Największa ma najwięcej tych wyrazow oraz najwięcej jedynek
  > Podajemy numer linii tych wyrazow
  ```

  Funkcja wyszukująca wartość najmniejszą zaimplementowana w C++:
  ```cpp
  int getMinLine(string *nums, int si) {          // Wskaźnik na tablice oraz jej wielkość
    int minIndex = 0;                             // Startowy indeks liczby najmniejszej
    string minValue = nums[0];                    // Startowa wartość liczby najmniejszej

    for (int i = 1; i < si; i++) {                // Zaczynamy od 2 wartości tablicy
      if (nums[i].size() < minValue.size()) {     // Jeżeli długość obecnego wyrazu jest mniejsza
        minValue = nums[i];                       // od długości najmniejszego znalezionego wyrazu
        minIndex = i;                             // Nadpisujemy najmniejsze wartości obecnymi
      } else {
        if (nums[i].size() == minValue.size()) {  // Jeżeli długość jest taka sama
          if (nums[i] < minValue) {               // Porownujemy leksykalnie obecna wartośc i najmniejszą
            minValue = nums[i];                   // Jeżeli obecna jest mniejsza nadpisujemy
            minIndex = i;                         // najmniejsze wartości obecnymi
          }
        }
      }
    }

    return (minIndex + 1);                        // Zwracamy indeks najmniejszego dodając jeden
  }                                               // ponieważ indeks tablicy jest liczony od zera
  ```
  
  Funkcja wyszukująca wartość największą zaimplementowana w C++:
  ```cpp
  int getMaxLine(string *nums, int si) {          // To samo co wyżej
    int maxIndex = 0;
    string maxValue = nums[0];

    for (int i = 1; i < si; i++) {                // Pętla działa na tej samej zasadzie
      if (nums[i].size() > maxValue.size()) {     // Tylko tutaj sprawdzamy czy obecna wartość
        maxValue = nums[i];                       // jest większa
        maxIndex = i;
      } else {
        if (nums[i].size() == maxValue.size()) {
          if (nums[i] > maxValue) {               // To samo co wyżej
            maxValue = nums[i];
            maxIndex = i;
          }
        }
      }
    }
    return (maxIndex + 1);
  }
  ```
---

**5. Demografia**
  * **5.1**
  ```
  > Wyznaczamy ludność wszystkich mieszkańcow każdego z regionow w roku 2013
  > Sporządzamy wykres kolumnowy porownujący ludność regionow

  Wojewodztwo || kobiety w 2013 || mężczyźni w 2013 || kobiety w 2014 || mężczyźni w 2014
  ```

  Do wyznaczania ludności można wyznaczyć przy pomocy formuły  
  `=SUMA.JEŻELI(A1:A50;"*A";B1:B50)+SUMA.JEŻELI(A1:A50;"*A";C1:C50)` dla woj. A  
  `=SUMA.JEŻELI(A1:A50;"*B";B1:B50)+SUMA.JEŻELI(A1:A50;"*B";C1:C50)` dla woj. B  
  `=SUMA.JEŻELI(A1:A50;"*C";B1:B50)+SUMA.JEŻELI(A1:A50;"*C";C1:C50)` dla woj. C  
  `=SUMA.JEŻELI(A1:A50;"*D";B1:B50)+SUMA.JEŻELI(A1:A50;"*D";C1:C50)` dla woj. D  

  Wykres:

  ![wykres](https://user-images.githubusercontent.com/32012952/37787311-f38cb3d8-2dfe-11e8-97cd-fa4d0fcbd87f.PNG)

---
  * **5.2**
  ```
  > Podajemy liczbe wojewodztw w ktorych liczba kobiet w 2014 roku była większa niż w 2013  
    i jednocześnie liczba mężczyzn w 2014 roku była większa niż w 2013
  ```

  Na początek wyznaczamy ktore wojewodztwo spełniło warunek formułą:  
  `=JEŻELI(ORAZ(C1 < E1; B1 < D1);"TAK";"NIE")`  
  następnie zliczamy dla każdego wojewodztwa ilość wystąpień `TAK` formułą:  
  `=LICZ.WARUNKI(F1:F50; "TAK"; A1:A50; "*A")` dla wojewodztwa A  
  `=LICZ.WARUNKI(F1:F50; "TAK"; A1:A50; "*B")` dla wojewodztwa B  
  `=LICZ.WARUNKI(F1:F50; "TAK"; A1:A50; "*C")` dla wojewodztwa C  
  `=LICZ.WARUNKI(F1:F50; "TAK"; A1:A50; "*D")` dla wojewodztwa D  
  i na koniec zliczamy ilość wszystkich wystąpień

---
  * **5.3**
  ```
  > Mamy podać liczbę wszystkich mieszkańcow w 2025 roku i wskazać, ktore wojewodztwo bedzie miało najwięcej  
    mieszkańcow w tym roku
  > Mamy też podać ilość wojewodztw w ktorych nastąpi efekt przeludnienia w latach 2014-2025 włącznie
  ```

  TBA

---
**6. Formuła 1**  
TBA
## 2016
## Pisemny
---
**1 Liczby skojarzone**
```
> Suma wszystkich rożnych dodatnich dzielnikow a mniejszych od a jest rowna b+1,  
  a suma wszystkich dodatnich dzielnikow b mniejszych od b jest rowna a+1

> Przykładowo dla a = 140 i b = 195
> 140 -> 1, 2, 4, 5, 7, 10, 14, 20, 28, 35, 70 ich suma = 196 = b + 1
> 195 -> 1, 3, 5, 13, 15, 38, 65 ich suma = 141 = a + 1
```

* **1.1**  

  | a  | b  | dzielniki a            | dzielniki b                  | suma dz. a | suma dz. b | skojarzone |
  |:--:|:--:|:----------------------:|:----------------------------:|:----------:|:----------:|:----------:|
  | 78 | 64 | 1, 2, 3, 6, 13, 26, 39 | 1, 2, 4, 8, 16, 32           | 90         | 63         | NIE        |
  | 20 | 21 | 1, 2, 4, 5, 10         | 1, 3, 7                      | 22         | 11         | NIE        |
  | 75 | 48 | 1, 3, 5, 15, 25        | 1, 2, 3, 4, 6, 8, 12, 16, 24 | 49         | 76         | TAK        |

---

* **1.2**  
```cpp
//Algorytm wyszukiwania liczb skojarzonych
int znajdz(int a) {
  int b, sumaA = 0; sumaB = 0;

  for (int i = 1; i < a; i++) {
    if (a % i == 0)
      sumaA += i;
  }
  b = sumaA - 1;

  for (int i = 1; i < b; i++) {
    if (b % i == 0)
      sumaB += i;
  }

  if (a == sumaB - 1)
    return b;
  else
    return -1; // "NIE"
}

if (znajdz(a) == -1)
  cout << "NIE";
else
  cout << znajdz(a);

// Sposob drugi
int sumaDzielnikow(int n) {
  int suma = 0;
  int i = 2;

  while (i * i <= n) {
    if (n % i == 0) {
      suma += i;

      if (n / i != i)
        suma += n / i;
    }

    i++;
  }

  return suma;
}

int x = sumaDzielnikow(a);
int y = sumaDzielnikow(b);

if (y - 1 = a)
  cout << x - 1;
else
  cout << "NIE";
```

---

**2. Przestawienia w Tablicy**  
Algorytm:
```
n - liczba całkowita
A[1...n] - tablica liczb całkowitych

funkcja przestaw(A)
  klucz = A[1]
  w = 1
  dla k = 2, 3, 4..., n wykonaj
    jesli A[k] < klucz
      zamień(A[w], A[k])
      w++
```

---

* **2.1**  
`n = 6, A = [4, 6, 3, 5, 2, 1]. Podaj kolejność tablicy po wykonaniu funkcji`

![zamiana](https://user-images.githubusercontent.com/32012952/37842359-36b92f74-2ec2-11e8-94fc-a4fab8360cce.png)

`Odp: A = [3, 2, 1, 5, 6, 4]`

---

* **2.2**  
```
> Mamy podać przykład siedmioelementowej tablicy A, dla ktorej funkcja przestaw(A),  
  5 razy wykona zamiane  

  n = 7; A = [6, 7, 4, 5, 3, 1, 2]

  1 - [4, 7, 6, 5, 3, 1, 2]   4 <-> 6
  2 - [4, 5, 6, 7, 3, 1, 2]   7 <-> 5
  3 - [4, 5, 3, 7, 6, 1, 2]   6 <-> 3
  4 - [4, 5, 3, 1, 6, 7, 2]   7 <-> 1
  5 - [4, 5, 3, 1, 2, 7, 6]   6 <-> 2

  Odp: A = [6, 7, 4, 5, 3, 1, 2]
```

---

* **2.3**
```
> Tablica A = [10, 20, 30, ..., 100, 9, 19, 29, ..., 99, 8, 18, 28, ..., 98, ..., 1, 11, 21, ..., 91]
> Podaj A[1], A[2], A[3] po wykonaniu funkcji przestaw(A)

w = 10
A[1] = 9    A[2] = 8    A[3] = 7
```

---

**3. Test**
* `Po wpisaniu 81.219.47.83 strona się otwiera, a po wpisaniu cke.edu.pl "Nie można znależć strony"`   
  **1.** awaria serwera SMTP cke  
  **2.** awaria serwera poczty użytkownika  
  **3.** awaria systemu DNS  
  **4.** brak prawidłowego klucza szyfrującego w przeglądarce  

  **1** -> Fałsz; **2** -> Fałsz; **3** -> Prawda; **4** -> Fałsz

* `f(1) = 4; f(n+1) = 1 / 1 - f(n) wtedy: `  
  **1.** f(8) = 1/3  
  **2.** f(9) = 3/4  
  **3.** f(10) = 4  
  **4.** f(100) = -1/3  

  **1** -> Fałsz; **2** -> Prawda; **3** -> Prawda; **4** -> Fałsz

```cpp
// Widać schemat postępowania rekurencji
f(8) = 1 / 1 - f(7) ->                                     // f(8) = -1/3
      f(7) = 1 / 1 - f(6) ->                               // f(7) = 4
            f(6) = 1 / 1 - f(5) ->                         // f(6) = 3/4
                  f(5) = 1 / 1 - f(4) ->                   // f(5) = -1/3
                        f(4) = 1 / 1 - f(3) ->             // f(4) = 4
                              f(3) = 1 / 1 - f(2) ->       // f(3) = 3/4
                                    f(2) = 1 / 1 - f(1) -> // f(2) = -1/3
                                          f(1) = 4
```

* `Dla dwoch liczb 1111 i 101 w notacji dwojkowej, ich`   
  **1.** suma jest rowna 10110  
  **2.** rożnica jest rowna 1010  
  **3.** iloczyn jest mniejszy od 110000  
  **4.** iloraz jest większy od 10  

  **1** -> Fałsz; **2** -> Prawda; **3** -> Fałsz; **4** -> Prawda

* `3.4`  
  **1.** Jednym z zadań OS jest przydział pamięci działąjącym programom  
  **2.** Na jendym dysku twardym mogą być zainstalowane dwa OS  
  **3.** OS musi być przechowywany w pamięci ROM  
  **4.** OS musi być przechowywany na dysku twardym  

  **1** -> Prawda; **2** -> Prawda; **3** -> Fałsz; **4** -> Fałsz
## Praktyka

---

**Liczba PI**  
Ogolnie zadanie jest przeznaczone do wykonania w Excelu, natomiast 2 pierwsze podpunkty można 
napisać np. w C++
```cpp
// Zczytujemy zawartość pliku punkty.txt i zapisujemy je w tablicy
int* points[10000];                             // Tablica 10000 wspołżędnych
int nr_linii = 0;
float bok = 400;                                // Bok kwadratu
int x, y;                                       // Tymczasowe wspołżędne x, y

fstream punkty;
string temp, tempA, tempB;                      // Tymczasowe zmienne użyte to rozdzielenia
                                                // stringa "123 23" na x = 123; y = 23
punkty.open("punkty.txt", ios::in);

if (!punkty.good()) exit(0);

while(!punkty.eof()) {
  getline(punkty, temp);
  points[nr_linii] = new int[2];                // Inicjujemy z każdą iteracją szufladki na zmienne
                                                // x i y ([0] = x, [1] = y)
  for (int i = 0; i < temp.size(); i++) {
    if (temp[i] == ' ') {                       // Splitowanie stringa
      int howMany = temp.size() - i;
      tempA = temp.substr(0, i);
      tempB = temp.substr(i + 1, howMany);
    }
  }

  x = atoi(tempA.c_str());                      // Parsowanie stringa na int
  y = atoi(tempB.c_str());                      // Jak wyżej

  points[nr_linii][0] = x;                      // Przypisanie punktow
  points[nr_linii][1] = y;

  nr_linii++;
}

punkty.close();
```

  * **4.1**
  ```
  > Wypisujemy ile punktow należy do wnętrza koła, nie licząc jego brzegu
  ```

  Excel:  
  TBA  
    
  C++:
  ```cpp
// Rownanie okręgu o środku w punkcie S = (a, b) i r > 0
// r^2 = (x - a)^2 + (y - b)^2
bool insideCircle(int x, int y, int a, int b) {
  int left = (x - a) * (x - a);               // Lewa strona rownania przed +
  int right = (y - b) * (y - b);              // Lewa strona rownania po +

  int l = left + right;                       // Lewa strona rownania

  int r = b * b;                              // Promień do kwadratu to połowa boku
                                              // czyli odległość od środka do miejsca zerowego
  if (l < r)                                  // Jeżeli Lewa strona jest mniejsza od Prawej
    return true;                              // Punkt znajduje się w okręgu
  return false;
}

int iloscWKole = 0;
int a = bok / 2;                              // S = (a, b)
int b = bok / 2;                              // S = (a, b)

for (int i = 0; i < 10000; i++) {
  int xTemp = points[i][0];
  int yTemp = points[i][1];

  if (insideCircle(xTemp, yTemp, a, b))       // Jeżeli zrwoci true
    iloscWKole++;                             // Inkrementuj
}

cout << iloscWKole;
  ```

---

  * **4.2**
  ```
  > Obliczamy wartość PI z podanych punktow "Metoda Monte Carlo"
  > Oblicz dla 1000, 5000 i wszystkich punktow
  ```

  Excel:  
  TBA  

  C++:
  ```cpp
// Dodajemy funkcje sprawdzającą czy punkt znajduje się na okręgu
bool inCircle(int x, int y, int a, int b) {
  int left = (x - a) * (x - a);
  int right = (y - b) * (y - b);

  int l = left + right;

  int r = b * b;

  if (l == r)                               // Od poprzedniej rożni się tylko tym
    return true;                            // że sprawdzamy czy lewa strona rowna sie prawej
  return false;
}

float iloscNaKole = 0;
float iloscWKole = 0;
float ilePunktow = 10000;                   // Do obliczenie poszczegolnej ilosci
                                            // zmieniamy tylko tą wartość
for (int i = 0; i < ilePunktow; i++) {
  int xTemp = points[i][0];
  int yTemp = points[i][1];

  if (inCircle(xTemp, yTemp, a, b))
    iloscNaKole++;

  if (insideCircle(xTemp, yTemp, a, b))
    iloscWKole++;
}

/*
Wzor z ktorego będziemy obliczać wartość PI

nk / n = pk / p
iloscwkole / wszystkie = (pi * r * r) / bok * bok
iloscwkole * bok * bok / wszystkie = pi * r * r
iloscwkole * bok * bok / wszystkie * r * r = pi
iloscWKole * 400 * 400 / ilePunktow * 200 * 200 = pi

*/

// Więc liczymy
float pi = ((iloscWKole + iloscNaKole) * (bok * bok)) / (ilePunktow * (a * a));

cout << pi;
  ```

---

  * **4.3**
  ```
  > TBA
  ```

  Excel:  
  TBA  

---

**Biblioteka Podręcznikow**  
TBA  

---

**Szyfr Cezara**
  * **6.1**
  ```
  > Zaszyfrowanie słow z kluczem rownym 107
  ```

  ```cpp
// Funkcja szyfrująca
char encrypt(char c) {
  int k = 107;                                    // klucz

  if ((int)c > 64 && (int)c < 91) {               // Znak musi znajdować się w alfabecie
    k = k % 26;                                   // Reszta z dzielenia przez ilość liter i alfabecie
    c += k;                                       // Przesuwamy w prawo

    if (c > 90)                                   // Jeżeli numer znaku przekroczyl alfabet
      c -= 26;                                    // Odejmujemy ilość liter

    return (char)c;                               // Zwracamy zparsowany znak
  }
}

// Przebieg
int nr_wiersza = 0;
string slowa[100];

fstream slowaNieszyfrowane;
fstream wynik;

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
    slowa[i][j] = encrypt(slowa[i][j]);           // Zamieniamy każdą literę na
    j++;                                          // zaszyfrowaną
  }
}

wynik.open("wyniki_6_1.txt", ios::out);

if (!wynik.good()) exit(0);

for (int i = 0; i < 100; i++)                     // Zapis do pliku
  wynik << slowa[i] << endl;

wynik.close();
  ```

---

  * **6.2**
  ```
  > Rozszyfrowywanie słow o kluczu podanym obok zaszyfrowanego słowa
  ```

  ```cpp
// Funkcja deszyfrująca
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

// Przebieg
int nr_linii = 0;
int klucz[3000];

string slowaSz[3000];
string temp, tempA, tempB;

fstream slowaSzyfrowane;

// Otwieramy w ten sam sposob natomiast pobieramy zawartość w inny
while (!slowaSzyfrowane.eof()) {
  getline(slowaSzyfrowane, temp);           // Zapisujemy całą linie do zmiennej temp

  for (int i = 0; i < temp.size(); i++) {
    if (temp[i] == ' ') {
      int howMany = temp.size() - i;        // Standardowo rozdzielamy string na klucz
      tempA = temp.substr(0, i);            // oraz zaszyfrowane slowo
      tempB = temp.substr(i + 1, howMany);
    }
  }

  slowaSz[nr_linii] = tempA;                // Zapisujemy wydobyte slowo do tablicy
  klucz[nr_linii] = atoi(tempB.c_str());    // Zapisujemy zparsowany klucz do tablicy

  nr_linii++;
}

// Deszyfrowanie
for (int i = 0; i < 3000; i++) {
  int j = 0;
  while (slowaSz[i][j]) {
    slowaSz[i][j] = decrypt(slowaSz[i][j], klucz[i]);
    j++;
  }
}
  ```

---

  * **6.3**
  ```
  > Mamy podane w linii słowo niezaszyfrowane i zaszyfrowane
  > Mamy znaleźć i wypisać linijki ktore zostały źle zaszyfrowane
  ```

  ```cpp
// Funkcja znajdująca klucz
int findKey(char a, char b) {
  a = (int)a % 26;
  b = (int)b % 26;

  int c = b - a;                                          // Odejmujemy pozycje zaszyfrowanego
                                                          // Od niezaszyfrowanego
  if (b > a) {                                            // Jeżeli pozycja zaszyf. jest większa od niezasz.
    if (c < 0)                                            // Jeżeli klucz jest ujemny
      return ((26 - c) * (-1));                           // Zwroć wartość bezwzględną
    return (26 - c);
  }

  if (c > 0)                                              // Jeżeli zaszyf. nie jest większy od niezaszyf.
    return c;                                             // oraz klucz jest dodatni, zwracamy klucz

  return (c * (-1));                                      // Jeżeli klucz jest ujemny zwracamy wartość
}                                                         // bezwzględną

// Przebieg
int linia = 0;
string slowaNieszy[3000];
string slowaSzyfr[3000];

string temp3;

fstream slowaSprawdz;
fstream wynik3;

// Otwieramy w ten sam sposob zapisujemy w podobny jak w poprzednim podpunkcie
while (!slowaSprawdz.eof()) {
  getline(slowaSprawdz, temp3);

  for (int i = 0; i < temp3.size(); i++) {
    if (temp3[i] == ' ') {
      int howMany = temp3.size() - i;                     // Standardowe rozdzielenie stringow
      slowaNieszy[linia] = temp3.substr(0, i);            // Zapisujemy niezaszyfrowane do tablicy
      slowaSzyfr[linia] = temp3.substr(i + 1, howMany);   // to samo co wyżej tylko, zaszyfrowane słowo
    }
  }

  linia++;
}

// Zapisujemy do pliku te słowa ktore są źle zaszyfrowane
bool correct;
int key;
int key2;

for (int i = 0; i < 3000; i++) {
  int j = 1;
  correct = true;                                         // za każdą iteracją pierwotny klucz jest poprawny
  key = findKey(slowaNieszy[i][0], slowaSzyfr[i][0]);     // Klucz pierwszego znaku
  key2 = 0;                                               // Zerujemy klucz z każdym powtorzeniem

  while (slowaNieszy[i][j]) {                             // Dopoki znak istnieje
    key2 = findKey(slowaNieszy[i][j], slowaSzyfr[i][j]);  // klucz obecnego znaku

    if (key != key2)                                      // Jeżeli klucz pierwszego znaku
      correct = false;                                    // nie zgadza się z ktorymkolwiek
                                                          // Zmieniamy zmienna
    j++;
  }

  if (!correct)                                           // Jeżeli słowo jest niepoprawnie
    wynik3 << slowaNieszy[i] << endl;                     // zaszyfrowane, zapisujemy je
}
  ```
## 2017
