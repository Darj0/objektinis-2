#include "Mylib.h"
#include "Studentas.h"
#include "Failai.h"



int main() {
    vector<Studentas> studentai;
    int pasirinkimas;
    string name;



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
    if (s_g == "g")
    {
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
        cout<< "Pagal ka norite rusioti? (Vardas - 'v', Pavarde - 'p')"<<endl;
        cin >>rus;
        rus = tolowers(rus);
        while (rus != "v" && rus != "p") {
        cout << "Klaidingas ivedimas, bandykite dar karta (Iveskite v arba p): ";
        cin >> rus;
        rus = tolowers(rus);
    }

    cout << "\nAtliekama failu analize: \n";
        darbas_su_failais( "studentai_1000.txt", n1, rus);
        darbas_su_failais("studentai_10000.txt", n2, rus);
        darbas_su_failais("studentai_100000.txt", n3,rus);
        darbas_su_failais( "studentai_1000000.txt", n4, rus);
        darbas_su_failais( "studentai_10000000.txt", n5, rus);




    }





    return 0;
}

