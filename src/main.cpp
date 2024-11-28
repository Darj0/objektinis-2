#include "Mylib.h"
#include "Studentas.h"
#include "Failai.h"

void menu() {
    cout << "============================\n";
    cout << "Pasirinkite veiksma:\n";
    cout << "1. Ivesti studentus rankiniu budu\n";
    cout << "2. Nuskaityti studentus is failo\n";
    cout << "3. Stebeti failu nuskaitymo ir kurimo spartuma\n";
    cout << "4. Pamatyti 'Rule of Three' demonstracija\n";
    cout << "5. Bazines ir isvestines klasiu objektu kurimas\n";
    cout << "0. Iseiti\n";
    cout << "============================\n";
    cout << "Jusu pasirinkimas: ";
}

int main() {
    vector<Studentas> studentai;
    list<Studentas> studentai_list;
    int pasirinkimas;
    string name;
    string reikalavimas;

    while (true) {
        menu();

        cin >> pasirinkimas;


        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nKlaidingas įvedimas, bandykite dar kartą (Įveskite tik skaičių):\n\n";
        }
        else if (pasirinkimas != 1 && pasirinkimas != 2 && pasirinkimas != 3 && pasirinkimas != 4 && pasirinkimas != 5 && pasirinkimas != 0) {
            cout << "\nKlaida! Įveskite 1, 2, 3, 4, 5 arba 0:\n\n";
        }
        else {
            break;
        }
    }

    switch (pasirinkimas) {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;

        case 5:

            break;
        case 0:
            cout << "Programa baigta." << endl;
            break;
    }

    if (pasirinkimas == 1) {
        string lv;
        cout << "Norite ivesti studentus naudodami list (spauskite l) arba vector (spauskite v)?\n";
        cin >> lv;
           while (lv != "l" && lv != "v") {
            cout << "Klaidingas ivedimas, bandykite dar karta (Iveskite l arba v): ";
            cin >> lv;
            lv = tolowers(lv);
           }

        if (lv == "v")
        {
            duomenys(studentai);
            sort_students(studentai);
            print_results(studentai);
        }

        else
        {
            duomenys_list(studentai_list);
            sort_students_by_name_list(studentai_list);
            print_results_list(studentai_list);
        }


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
        //patikrinimas(studentai);
        sort_students(studentai);
        print_results(studentai);
    }
    else if (pasirinkimas == 3){
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
        cout << "Norite naudoti mediana ar vidurki? (mediana - 'med', vidurkis - 'vid')" << endl;
        cin >> krit;
        krit = tolowers(krit);

        while (krit != "med" && krit != "vid") {
            cout << "Klaidingas ivedimas, bandykite dar karta (Iveskite med arba vid): ";
            cin >> krit;
            krit = tolowers(krit);
        }
        string vec_list = "";
        cout << "Norite naudoti vector ar list? (vector - 'v', list - 'l')" << endl;
        cin >> vec_list;
        vec_list = tolowers(vec_list);

        while (vec_list != "v" && vec_list != "l") {
            cout << "Klaidingas ivedimas, bandykite dar karta (Iveskite v arba l): ";
            cin >> vec_list;
            vec_list = tolowers(vec_list);
        }

        int strategija;
        cout << "Kokia strategija norite nauduoti? (1, 2, 3)" << endl;
        cin >> strategija;

        while (strategija != 1 && strategija != 2 && strategija != 3) {
            cout << "Klaidingas ivedimas, bandykite dar karta (Iveskite 1, 2 arba 3): ";
            cin >> strategija;

        }

        if (vec_list == "v")
        {
              cout << "\nAtliekama failu analize su vector<Studentas> studentai: \n";
        darbas_su_failais("studentai_1000.txt", n1, rus, krit, strategija);
        darbas_su_failais("studentai_10000.txt", n2, rus, krit, strategija);
        darbas_su_failais("studentai_100000.txt", n3, rus, krit, strategija);
        darbas_su_failais("studentai_1000000.txt", n4, rus, krit, strategija);
        darbas_su_failais("studentai_10000000.txt", n5, rus, krit, strategija);

        }
        else
        {
            cout << "\nAtliekama failu analize su list<Studentas> studentai_list: \n";
        darbas_su_failais_list("studentai_1000.txt", n1, rus, krit, strategija);
        darbas_su_failais_list("studentai_10000.txt", n2, rus, krit, strategija);
        darbas_su_failais_list("studentai_100000.txt", n3, rus, krit, strategija);
        darbas_su_failais_list("studentai_1000000.txt", n4, rus, krit, strategija);
        darbas_su_failais_list("studentai_10000000.txt", n5, rus, krit, strategija);
        }

    }

    else if (pasirinkimas == 4)
{
    cout <<"Norite ivesti studenta rankiniu budu (1), generuoti duomenis (2)?"<<endl;
    int a;
    Studentas studentas1;
    cin >> a ;
    if (a == 1)
    {

        cout << "Iveskite pirmo studento duomenis:\n";
        cin >> studentas1;

    }
    else if (a == 2)
    {
        studentas1 = Studentas::generuotiStudenta();
        cout << "Studentas sugeneruotas\n";
    }





    cout << "\n=== Demonstracija: Pirmo studento duomenys ===\n";
    cout << "Pradiniai pirmo studento duomenys:\n";
    cout << studentas1;

    cout << "\n=== Demonstracija: Kopijavimo konstruktorius (Sukuriame nauja objekta kaip kopija) ===\n";
    Studentas studentas2 = studentas1;
    cout << "Antro studento duomenys (kopijuoti is pirmo studento):\n";
    cout << "studentas2 = studentas1\n";
    cout << "Antras studentas turetu buti lygus pirmajam studentui:\n";
    cout << studentas2;

    cout << "\n=== Modifikuojame antro studento varda (kopija) ===\n";
    studentas2.setVardas("NaujasVardas");
    cout << "Antro studento duomenys po vardo pakeitimo:\n";
    cout << studentas2;

    cout << "\n=== Demonstracija: Kopijavimo priskyrimo operatorius (Priskiriame pirmojo studento duomenis treciam studentui) ===\n";
    Studentas studentas3;
    studentas3 = studentas1;
    cout << "Trecio studento duomenys (priskirti is pirmo studento):\n";
    cout << "studentas3 = studentas1\n";
    cout << studentas3;

    cout << "\n=== Demonstracija: Modifikuojame trecio studento varda ===\n";
    studentas3.setVardas("TreciasVardas");
    cout << "Trecio studento duomenys po vardo pakeitimo:\n";
    cout << studentas3;

    cout << "\n=== Tikriname skirtumus tarp studento duomenu ===\n";
    cout << "Pirmo studento duomenys (nepakeisti):\n";
    cout << studentas1;
    cout << "Antro studento duomenys (kopijuoti is pirmo studento, bet pakeistas vardas):\n";
    cout << studentas2;
    cout << "Trecio studento duomenys (priskirti is pirmo studento, bet pakeistas vardas):\n";
    cout << studentas3;

    cout << "\n=== Demonstracija: Studentas irasomas i faila \"studentas3.txt\" ===\n";
    Studentas::rasytiIFaila(studentas3, "studentas3.txt");

    cout << "\nVisos demonstracijos baigtos.\n";

}

 else if (pasirinkimas == 5) {
    Studentas studentas1("Jonas", "Jonaitis", {8, 9, 10}, 9, "Studentas");

    cout << "Sukurtas Studentas objektas ir jo duomenys:\n";
    cout << studentas1;

    //Zmogus zmogus;
    }


system("pause");

    return 0;
}
