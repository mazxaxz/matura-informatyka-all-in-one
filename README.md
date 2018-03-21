# Matura informatyka all in one

## Spis treści
<ol>
  <li><a href="#ogolna-informatyka">Ogólna informatyka</a></li>
  <li><a href="#algorytmy-warte-uwagi">Algorytmy warte uwagi</a></li>
  <li><a href="#c-cheatsheet">C++ cheatsheet</a></li>
  <li><a href="#java-cheatsheet">Java cheatsheet</a></li>
  <li><a href="#excel">Excel</a></li>
  <li><a href="#access-sql">Access / SQL</a></li>
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
  *Obraz*
  
  ---
  
  * **1.2**  
  Dowod na to, ze zadna ze strategii nie jest optymalna  
  Podajemy 4 filmy, z ktorych wedlug algorytmu widz obejrzy 2, natomiast moze obejrzec 3
  `Strategia A`

  *Obraz*

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

  *Obraz*

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

  *Obraz*

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

    **//Obraz//**

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

## 2016

## 2017
