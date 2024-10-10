#include "Mylib.h"
#include "Studentas.h"
#include "Failai.h"

int main() {
    vector<Studentas> studentai;
    int pasirinkimas;
    string name;
    string reikalavimas;

    while (true) {
        cout << "Norite ivesti studentus(spauskite 1), nuskaityti is failo(spauskite 2)\n ar stebeti failu nuskaitimo ir kurimo spartuma (spauskite 3)?\n";
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

    if (pasirinkimas == 1) {
        duomenys(studentai);
        sort_students(studentai);
        print_results(studentai);
    }
    else if (pasirinkimas == 2) {
        cout << "Iveskyte failo kelia\n";
        cin >> name;
        cout << "Galutinio balo skaiciavimui norite naudoti vidurki ar mediana? (Iveskite 'vid' arba 'med'  )" << endl;
        cin >> reikalavimas;
        reikalavimas = tolowers(reikalavimas);

        while (reikalavimas != "vid" && reikalavimas != "med") {
            cout << "Klaidingas ivedimas, bandykite dar karta (Iveskite vid arba med): ";
            cin >> reikalavimas;
            reikalavimas = tolowers(reikalavimas);
        }
        skaityti(studentai, name, reikalavimas);
        sort_students(studentai);
        print_results(studentai);
    }
    else {
        int n1 = 1000;
        int n2 = 10000;
        int n3 = 100000;
        int n4 = 1000000;
        int n5 = 10000000;
        string s_g = "";

        cout << "Norite naudoti jau sukurtus failus (spauskite s) ar generuoti naujus (spauskite g)?" << endl;
        cin >> s_g;
        s_g = tolowers(s_g);

        while (s_g != "s" && s_g != "g") {
            cout << "Klaidingas ivedimas, bandykite dar karta (Iveskite s arba g): ";
            cin >> s_g;
            s_g = tolowers(s_g);
        }

        if (s_g == "g") {
            cout << "Sugeneruoti failai: \n";
            generuoti_sarasus(n1, studentai);
            kurti_faila(studentai, "1000");
            studentai.clear();
            cout << "studentai_1000.txt \n";
            generuoti_sarasus(n2, studentai);
            kurti_faila(studentai, "10000");
            studentai.clear();
            cout << "studentai_10000.txt \n";
            generuoti_sarasus(n3, studentai);
            kurti_faila(studentai, "100000");
            studentai.clear();
            cout << "studentai_100000.txt \n";
            generuoti_sarasus(n4, studentai);
            kurti_faila(studentai, "1000000");
            studentai.clear();
            cout << "studentai_1000000.txt \n";
            generuoti_sarasus(n5, studentai);
            kurti_faila(studentai, "10000000");
            studentai.clear();
            cout << "studentai_10000000.txt \n";
        }

        string rus = "";
        cout << "Pagal ka norite rusioti? (Vardas - 'v', Pavarde - 'p', Galutinus pazymys - 'g')" << endl;
        cin >> rus;
        rus = tolowers(rus);

        while (rus != "v" && rus != "p" && rus != "g") {
            cout << "Klaidingas ivedimas, bandykite dar karta (Iveskite v, p arba g): ";
            cin >> rus;
            rus = tolowers(rus);
        }

        string krit = "";
        cout << "Norite naudoti mediana ar vidurki? (mediana - 'm', vidurkis - 'v')" << endl;
        cin >> krit;
        krit = tolowers(krit);

        while (krit != "m" && krit != "v") {
            cout << "Klaidingas ivedimas, bandykite dar karta (Iveskite m arba v): ";
            cin >> krit;
            krit = tolowers(krit);
        }

        cout << "\nAtliekama failu analize: \n";
        darbas_su_failais("studentai_1000.txt", n1, rus, krit);
        darbas_su_failais("studentai_10000.txt", n2, rus, krit);
        darbas_su_failais("studentai_100000.txt", n3, rus, krit);
        darbas_su_failais("studentai_1000000.txt", n4, rus, krit);
        darbas_su_failais("studentai_10000000.txt", n5, rus, krit);
    }

    return 0;
}
