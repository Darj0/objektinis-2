#include "Mylib.h"
#include "Studentas.h"




int main() {
    vector<Studentas> studentai;
    int pasirinkimas;
    string name;
    while (true) {
        cout << "Norite ivesti studentus(spauskite 1), nuskaityti is failo(spauskite 2) ar generuoti studentu sarasus (spauskite 3)?\n";
        cin >> pasirinkimas;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Klaidingas ivedimas, bandykite dar karta (Iveskite tik skaiciu): \n";
        }
        else if (pasirinkimas != 1 && pasirinkimas != 2 && pasirinkimas != 3) {
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

    else if (pasirinkimas == 2)
    {
        cout<<"Iveskyte failo kelia\n";
        cin >> name;
        skaityti(studentai, name);
        sort_students(studentai);
        print_results(studentai);
       //patikrinimas(studentai);

    }

    else
    {
        int n = 5;
        generuoti_sarasus(n, studentai);
        cout << "Sugeneruoti 5 failai: \n";
        cout << "studentai_1000.txt \n";
        cout << "studentai_10000.txt \n";
        cout << "studentai_100000.txt \n";
        cout << "studentai_1000000.txt \n";
        cout << "studentai_10000000.txt \n";

    }





    return 0;
}

