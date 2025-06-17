//
// Created by Fryderyk Forys on 17.06.2025.
//

#include "BazaDanychSamochodow.h"

#include <algorithm>
#include <fstream>
#include <limits>
#include <sstream>

// Metody publiczne
BazaDanychSamochodow::BazaDanychSamochodow() {
    wczytajPlikDoBazyDanych();
}

BazaDanychSamochodow::~BazaDanychSamochodow() {
    zapiszBazeDanychDoPliku();
}

void BazaDanychSamochodow::dodajSamochod(const std::string& vin, FazaProdukcji fazaProdukcji) {
    samochody.emplace_back(nextId++, vin, fazaProdukcji);
    std::cout << "Samochod dodany poprawnie z ID: " << (nextId - 1) << std::endl;
    zapiszBazeDanychDoPliku();
}

void BazaDanychSamochodow::modyfikujSamochod(int id) {
    auto it = std::find_if(samochody.begin(), samochody.end(),
        [id](const Samochod& samochod) { return samochod.getId() == id; });

    if (it != samochody.end()) {
        std::cout << "Obecny VIN: " << it->getVin() << std::endl;
        std::cout << "Wprowadz nowy VIN (lub nacisnij Enter aby pozostawic obecny): ";
        std::string newVin;
        std::getline(std::cin, newVin);

        if (!newVin.empty()) {
            it->setVin(newVin);
        }

        std::cout << "Wybierz nowa faze produkcji:\n"
                  << "1. Montaz\n"
                  << "2. Malowanie\n"
                  << "3. Kontrola jakosci\n"
                  << "4. Skonczony\n"
                  << "Wybierz (1-4): ";

        int choice;
        std::cin >> choice;
        wyczyscStrumienWejsciowyDanych();

        if (choice >= 1 && choice <= 4) {
            it->setFazaProdukcji(static_cast<FazaProdukcji>(choice - 1));
            std::cout << "Dane samochodu zmodyfikowane poprawnie!" << std::endl;
            zapiszBazeDanychDoPliku();
        } else {
            std::cout << "Wybrana niewlasciwa faza produkcji!" << std::endl;
        }
    } else {
        std::cout << "Nie znaleziono takiego samochodu!" << std::endl;
    }
}

void BazaDanychSamochodow::usunSamochod(int id) {
    auto it = std::remove_if(samochody.begin(), samochody.end(),
        [id](const Samochod& samochod) { return samochod.getId() == id; });

    if (it != samochody.end()) {
        samochody.erase(it, samochody.end());
        std::cout << "Samochod usuniety poprawnie!" << std::endl;
        zapiszBazeDanychDoPliku();
    } else {
        std::cout << "Samochod nie zostal znaleziony!" << std::endl;
    }
}

void BazaDanychSamochodow::wyswietlSamochody() const {
    if (samochody.empty()) {
        std::cout << "Nie ma zadnego samochodu w bazie danych!" << std::endl;
        return;
    }

    std::cout << "\nSamochody w fabryce:\n";
    std::cout << "ID\tVIN\t\tFaza Produkcji\n";
    std::cout << "----------------------------------------\n";

    for (const auto& samochod : samochody) {
        std::cout << samochod.getId() << "\t"
                  << samochod.getVin() << "\t";

        switch (samochod.getFazaProdukcji()) {
            case FazaProdukcji::MONTAZ: std::cout << "Montaz"; break;
            case FazaProdukcji::MALOWANIE: std::cout << "Malowanie"; break;
            case FazaProdukcji::KONTROLA_JAKOSCI: std::cout << "Kontrola jakosci"; break;
            case FazaProdukcji::SKONCZONE: std::cout << "Skonczone"; break;
        }
        std::cout << std::endl;
    }
}

// Metoda statyczna i publiczna czyszcza strumien wejsciowy danych do konsoli
void BazaDanychSamochodow::wyczyscStrumienWejsciowyDanych() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Metody prywatne
void BazaDanychSamochodow::zapiszBazeDanychDoPliku() {
    std::ofstream file(PLIK_BAZY_DANYCH);
    if (!file) {
        std::cerr << "Error: Nie mozna otworzyc pliku bazy danych do zapisu!" << std::endl;
        return;
    }

    // Zapisz najpierw nextId
    file << nextId << std::endl;

    // Zapisz kazdy samochod do pliku bazy danych
    for (const auto& samochod : samochody) {
        file << samochod.getId() << "|"
             << samochod.getVin() << "|"
             << Samochod::fazaProdukcjiToString(samochod.getFazaProdukcji()) << std::endl;
    }
    file.close();
}

void BazaDanychSamochodow::wczytajPlikDoBazyDanych() {
    std::ifstream file(PLIK_BAZY_DANYCH);
    if (!file) {
        std::cout << "Nie znaleziono istniejacej bazy danych. Trzeba utworzyc nowa baze." << std::endl;
        return;
    }

    samochody.clear();
    std::string line;

    // Read nextId first
    if (std::getline(file, line)) {
        nextId = std::stoi(line);
    }

    // Wczytaj wszystkie samochody z pliku
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string idStr, vin, fazaProdukcjiStr;

        // Parse the line using '|' as delimiter
        std::getline(ss, idStr, '|');
        std::getline(ss, vin, '|');
        std::getline(ss, fazaProdukcjiStr, '|');

        int id = std::stoi(idStr);
        FazaProdukcji fazaProdukcji = Samochod::stringToFazaProdukcji(fazaProdukcjiStr);
        samochody.emplace_back(id, vin, fazaProdukcji);
    }
    file.close();
}
