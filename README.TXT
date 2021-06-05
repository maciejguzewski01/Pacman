Spis zawartości pliku README.txt;

1. Założenia projektu 
2. Lista klas i plików z których składa się projekt 
3. Lista bonusów 


1. ZAŁOŻENIA PROJEKTU 

W moim projekcie realizuję grę opartą na pacmanie.

Zasady/założenia 
a. Gracz porusza się pacmanem zjadając szczepionki (zbierając punkty)
b. Wirusy (odpowiednik duchów) poruszają się po planszy; jeśli spotkają pacmana plansza się resetuje, pacmanowi ubywa życie (jeśli ilość żyć==0 --> game over)
c. Na planszy generują się bonusy--> specjalne pola które jeśli pacman na nie najedzie w różny sposób zmodyfikują parametry gry (na korzyść lub niekorzyść gracza)
d. Rozpoczynając grę gracz może wybrać poziom trudności, imię oraz układ planszy (jeden z pięciu zdefiniowanych lub wygenerować losową). Przy rozpoczęciu gry gracz otrzymuje instrukcje, pod koniec gry wyświetla wyniki 10 ostatnich rund 


2. LISTA KLAS I PLIKÓW 
każda klasa składa się z pliku nagłówkowego i wykonawczego, poniżej wypisałem ogólne zadanie każdej z klas, szczegłową listę zadań danej klasy umieściłem w odpowiadającym im pliku nagłówkowym 

I. Lista klas 
a. Board--> reprezentacja planszy
b. Bonus--> zarządza generowaniem bonusów 
c. Coronavirus--> reprezentacja wirusa (ducha)
d. Events--> obsługuje zdarzenia 
e. Manager--> zarządza grą 
f. Pacman--> reprezentacja pacmana 
g. SFMLapp--> wyświetla SFMLową aplikację 
h. Start--> odpowiada za rozpoczęcie gry (wybór imienia, poziomu, planszy oraz wyświetlenie instrukcji)

II. Lista innych plików 
a. .replit
b. .gitignore 
c. CMakeLists.txt 
d. README.txt
e. wyniki.txt--> przechowuje wynik 10 ostatnich rozgrywek 
f. Calibri.ttf LibreBaskerville-Regular.ttf --> fonty
g. pliki *.png w katalogu \resources i jego podkatalogach--> tekstury, wszystkie tekstury wykonałem samemu 

3. LISTA BONUSÓW 
Nazwa w enum/ nazwa bonusu/ikonka/ co robi 
a. SCHOOL/ otwarcie szkół/ dzwonek/ zwiększa dwukrotnie ilość wirusów 
b. PLANE/ przesyłka z Chin / samolot/ przez 20 sekund pacman jest odporny na wirusy 
c. BORDER/ otwarcie granic/ otwarty szlaban/ szczepionki ponownie pojawiają się na polach 
d. BRITAIN/ brytyjska herbata/ filiżanka/ wirusy zwiększają prędkość dwukrotnie 
e. RESPIRATOR/ respirator/ czerwony krzyż / ilość żyć zwiększa się do 4
f. LOCKDOWN/ twardy lockdown/ zamknięta kłódka/ wirusy nie ruszają się przez 20 sekund
g. SUMMER/ wirus w odwrocie/ słońce/ wirusy cofają się do punktów wyjścia 
h. LITE_LOCKDOWN/ lekki lockdown/ otwarta kłódka/ wirusy zmniejszają prędkość 
i. DEATH/ zwiększona śmiertelność/ grób/ ilość wirusów zmniejsza się o połowę 
j. ANTIVAXXERS/ populacja antyszczpionkowców zwiększa się/ przekreślony mózg/ od teraz każda szczepionka liczona za dwa punkty 