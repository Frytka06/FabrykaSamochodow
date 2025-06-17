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
std::string Samochod::fazaProdukcjiToString(FazaProdukcji phase) {
    switch (phase) {
        case FazaProdukcji::MONTAZ: return "MONTAZ";
        case FazaProdukcji::MALOWANIE: return "MALOWANIE";
        case FazaProdukcji::KONTROLA_JAKOSCI: return "KONTROLA_JAKOSCI";
        case FazaProdukcji::SKONCZONE: return "SKONCZONE";
        default: return "UNKNOWN";
    }
}

// Zamienia string na enum FazaProdukcji
FazaProdukcji Samochod::stringToFazaProdukcji(const std::string& phaseStr) {
    if (phaseStr == "MONTAZ") return FazaProdukcji::MONTAZ;
    if (phaseStr == "MALOWANIE") return FazaProdukcji::MALOWANIE;
    if (phaseStr == "KONTROLA_JAKOSCI") return FazaProdukcji::KONTROLA_JAKOSCI;
    if (phaseStr == "SKONCZONE") return FazaProdukcji::SKONCZONE;
    return FazaProdukcji::MONTAZ; // Default value
}

