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
TBA

## C++ cheatsheet
TBA

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

## 2017
