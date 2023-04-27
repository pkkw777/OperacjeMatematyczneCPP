#include "Liczba.h"
#include "LiczbaR.h"
#include "LiczbaZ.h"
#include "Wyniki.h"
#include <memory>

int main()
{
    // Inicjalizacja liczby rzeczywistej
    LiczbaR re;
    re.initialize();

    // Tworzenie liczby zespolonej na podstawie wektora z liczbami rzeczywistymi i błędem
    LiczbaZ im(re.getTab(), re.getErr());

    // Wykorzystanie wskaźników do wywoływania funkcji wirtualnych dla różnych typów obiektów Liczba
    Liczba* licz = &re;
    licz->WyswietlRownanie();
    licz->ObliczPierwiastekRownania();
    licz->DodajLiczbyZespolone();
    licz->OdejmijLiczbyZespolone();

    licz = &im;
    licz->ObliczPierwiastekRownania();
    licz->DodajLiczbyZespolone();
    licz->OdejmijLiczbyZespolone();

    // Przechowywanie wyników w obiekcie wynik
    float delta = re.getDelta();
    float pdelta = re.getPdelta();
    float x1r = re.getX1r();
    float x2r = re.getX2r();
    float x3r = re.getX3r();
    float x4r = re.getX4r();
    float x1u = im.getX1u();
    float x2u = im.getX2u();
    float x3u = im.getX3u();
    float x4u = im.getX4u();
    float sr = re.getSr();
    float rr = re.getRr();
    float su = im.getSu();
    float ru = im.getRu();

    std::unique_ptr<Wyniki> wynik = std::make_unique<Wyniki>(re.getTab(), re.getErr(), delta, pdelta, x1r, x2r, x3r, x4r, x1u, x2u, x3u, x4u, sr, rr, ru, su);
    wynik->wyswietl_wynik();

    system("PAUSE");
    return 0;
}
