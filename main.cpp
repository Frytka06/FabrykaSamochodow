//
// Created by Fryderyk Forys on 17.06.2025.
//

#include "BazaDanychSamochodow.h"

#include <iostream>

int main() {
    std::cout << "\n\t\tFabryka Samochodow\n";

    BazaDanychSamochodow fabrykaSamochodow;
    char wyborOpcji;

    do {
        std::cout << "\nSystem Zarzadzania Fabryki Samochodow\n";
        std::cout << "1. Dodaj samochod\n";
        std::cout << "2. Modyfikuj samochod\n";
        std::cout << "3. Usun samochod\n";
        std::cout << "4. Wyswietl wszystkie samochody\n";
        std::cout << "5. Koniec pracy\n";
        std::cout << "Wprowadz swoj wybor (1-5): ";

        std::cin >> wyborOpcji;
        BazaDanychSamochodow::wyczyscStrumienWejsciowyDanych();

        switch (wyborOpcji) {
            case '1': {
                std::cout << "Wprowadz VIN: ";
                std::string vin;
                std::getline(std::cin, vin);

                std::cout << "Wybierz faze produkcji:\n"
                          << "1. Montaz\n"
                          << "2. Malowanie\n"
                          << "3. Kontrola jakosci\n"
                          << "4. Skonczone\n"
                          << "Wybierz (1-4): ";

                int fazaProdukcji;
                std::cin >> fazaProdukcji;
                BazaDanychSamochodow::wyczyscStrumienWejsciowyDanych();

                if (fazaProdukcji >= 1 && fazaProdukcji <= 4) {
                    fabrykaSamochodow.dodajSamochod(vin, static_cast<FazaProdukcji>(fazaProdukcji - 1));
                } else {
                    std::cout << "Wybrano niewlasciwa faze produkcji!" << std::endl;
                }
                break;
            }
            case '2': {
                std::cout << "Wprowadz ID samochodu do modyfikacji danych: ";
                int id;
                std::cin >> id;
                BazaDanychSamochodow::wyczyscStrumienWejsciowyDanych();
                fabrykaSamochodow.modyfikujSamochod(id);
                break;
            }
            case '3': {
                std::cout << "Wprowadz ID samochodu do usuniecia: ";
                int id;
                std::cin >> id;
                BazaDanychSamochodow::wyczyscStrumienWejsciowyDanych();
                fabrykaSamochodow.usunSamochod(id);
                break;
            }
            case '4':
                fabrykaSamochodow.wyswietlSamochody();
                break;
            case '5':
                std::cout << "Koniec programu ...\n";
                break;
            default:
                std::cout << "Niewlasciwa opcja wybrana! Prosze sprobuj ponownie.\n";
        }
    } while (wyborOpcji != '5');

    return 0;
}
