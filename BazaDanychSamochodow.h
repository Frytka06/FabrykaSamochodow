//
// Created by Fryderyk Forys on 17.06.2025.
//

#ifndef FABRYKASAMOCHODOW_H
#define FABRYKASAMOCHODOW_H

#include <iostream>
#include <vector>

#include "Samochod.h"

class BazaDanychSamochodow {
    private:
        std::vector<Samochod> samochody;
        int nextId = 1;
        const std::string PLIK_BAZY_DANYCH = "Samochody_baza_danych.txt";

    public:
        // Made wyczyscStrumienWejsciowyDanych public and static
        static void wyczyscStrumienWejsciowyDanych();

    private:
        void zapiszBazeDanychDoPliku();
        void wczytajPlikDoBazyDanych();

    public:
        // Konstruktor
        BazaDanychSamochodow();

        // Destruktor
        ~BazaDanychSamochodow();

        // Metody operujace na bazie danych
        void dodajSamochod(const std::string& vin, FazaProdukcji fazaProdukcji);
        void modyfikujSamochod(int id);
        void usunSamochod(int id);
        void wyswietlSamochody() const;
};

#endif //FABRYKASAMOCHODOW_H
