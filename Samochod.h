//
// Created by Fryderyk on 17.06.2025.
//

#ifndef SAMOCHOD_H
#define SAMOCHOD_H

#include "FazaProdukcji.h"

#include <iostream>

class Samochod {
    private:
    int id;
    std::string vin;
    FazaProdukcji fazaProdukcji;

    public:
    // Konstruktor
    Samochod(int id, std::string vin, FazaProdukcji fazaProdukcji);

    // Gettery
    int getId() const;
    const std::string& getVin() const;
    FazaProdukcji getFazaProdukcji();

    // Settery
    void setFazaProdukcji(FazaProdukcji nowaFazaProdukcji);
    void setVin(const std::string& newVin);

    // Zamienia enum FazaProdukcji na string
    static std::string fazaProdukcjiToString(FazaProdukcji fazaProdukcji);

    // Zamienia string na enum FazaProdukcji
    static FazaProdukcji stringToFazaProdukcji(const std::string& fazaProdukcjiStr);
};

#endif //SAMOCHOD_H
