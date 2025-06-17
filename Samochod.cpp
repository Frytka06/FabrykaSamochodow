//
// Created by Fryderyk on 17.06.2025.
//

#include "Samochod.h"


Samochod::Samochod(int id, std::string vin, FazaProdukcji faza)
    : id(id), vin(std::move(vin)), fazaProdukcji(faza) {}

// Getters
int Samochod::getId() const { return id; }
const std::string& Samochod::getVin() const { return vin; }
FazaProdukcji Samochod::getFazaProdukcji() const { return fazaProdukcji; }

// Setters
void Samochod::setFazaProdukcji(FazaProdukcji nowaFazaProdukcji) { fazaProdukcji = nowaFazaProdukcji; }
void Samochod::setVin(const std::string& nowyVin) { vin = nowyVin; }

// Zamienia enum FazaProdukcji na string
std::string Samochod::fazaProdukcjiToString(FazaProdukcji fazaProdukcji) {
    switch (fazaProdukcji) {
        case FazaProdukcji::MONTAZ: return "MONTAZ";
        case FazaProdukcji::MALOWANIE: return "MALOWANIE";
        case FazaProdukcji::KONTROLA_JAKOSCI: return "KONTROLA_JAKOSCI";
        case FazaProdukcji::SKONCZONE: return "SKONCZONE";
        default: return "UNKNOWN";
    }
}

// Zamienia string na enum FazaProdukcji
FazaProdukcji Samochod::stringToFazaProdukcji(const std::string& fazaProdukcjiString) {
    if (fazaProdukcjiString == "MONTAZ") return FazaProdukcji::MONTAZ;
    if (fazaProdukcjiString == "MALOWANIE") return FazaProdukcji::MALOWANIE;
    if (fazaProdukcjiString == "KONTROLA_JAKOSCI") return FazaProdukcji::KONTROLA_JAKOSCI;
    if (fazaProdukcjiString == "SKONCZONE") return FazaProdukcji::SKONCZONE;
    return FazaProdukcji::MONTAZ; // Default value
}

