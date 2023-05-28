# 2023_Analysis_Uno

U ovom projektu je izneta analiza igre uno: [https://github.com/matf-pp/2020_Uno](https://github.com/matf-pp/2020_Uno). Igra je implementirana u C++u.

Projekat simulira igru UNO. Za detaljnija pravila pogledati originalan projekat. Ukratko:
- igraci na pocetku dobijaju po 6 karata
- jedna karta se stavlja na talon
- igraci igraju redom: na talon stavljaju kartu iz ruke koja je ili istog znaka/boje ili istog broja kao karta na talonu; ili neku od specijalnih karata
- ukoliko u ruci nema odgovarajuću kartu vuče kartu iz spila
- pobedio je igrač koji prvi izgubi sve karte.

Pokretanje igre:
- `g++ test.cpp -std=c++11 -o UNO`
- `./UNO`
- nakon unosa imena igrača se klikom enter se prate koraci igre.

## Korišćeni alati:
- cach.hpp biblioteka sa gcovr
- Valgrind - leak-check
- Valgrind - callgrind
- Valgrind - massif
- cppcheck

Pokretanje alata: U svakom folderu za alat se nalazi skript _exec.sh_, pokretanjem skripta sa ```sh exec.sh``` se izvršava odgovarajući alat.

