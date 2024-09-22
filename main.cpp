#include "Mylib.h"
#include "Studentas.h"




int main() {
    vector<Studentas> studentai;
    int pasirinkimas;
    string name;
    while (true) {
        cout << "Norite ivesti studentus(spauskyte 1) ar nuskaityti is failo(spauskyte 2)?\n";
        cin >> pasirinkimas;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Klaidingas ivedimas, bandykite dar karta (Iveskite tik skaiciu): \n";
        }
        else if (pasirinkimas != 1 && pasirinkimas != 2) {
                            cout << "Klaida! Iveskite 1 arba 2: \n";
        }

        else {
            break;
        }
    }


    if (pasirinkimas == 1)
    {
        duomenys(studentai);
        sort_students(studentai);
        print_results(studentai);
    }

    else
    {
        cout<<"Iveskyte failo kelia\n";
        cin >> name;
        skaityti(studentai, name);
        sort_students(studentai);
        print_results(studentai);
       //patikrinimas(studentai);

    }





    return 0;
}

