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
        string g_s = "";
        cout <<"Norite generuoti naujus failus (spauskite 'g') ar nauduotis sukurtais (spauskite 's')"<<endl;
        cin >> g_s;
        while (g_s != "g"  && g_s !=  "s" )
        {
        cout << "Klaidingas ivedimas, bandykite dar karta (Iveskite 'g' arba 's'): \n";
        cin >> g_s;
        g_s = tolowers(g_s);
        }

        if (g_s =="g")
        {
            cout << "Sugeneruoti failai: \n";
            generuoti_sarasus(n1, studentai);
            kurti_faila(studentai, "1000");
            cout << "studentai_1000.txt \n";
            generuoti_sarasus(n2, studentai);
            kurti_faila(studentai, "10000");
            cout << "studentai_10000.txt \n";
            generuoti_sarasus(n3, studentai);
            kurti_faila(studentai, "100000");
            cout << "studentai_100000.txt \n";
            generuoti_sarasus(n4, studentai);
            kurti_faila(studentai, "1000000");
            cout << "studentai_1000000.txt \n";
            generuoti_sarasus(n5, studentai);
            kurti_faila(studentai, "10000000");
            cout << "studentai_10000000.txt \n";
        }

        cout << "\nAtliekama failu analize: \n";
        darbas_su_failais( "studentai_1000.txt", n1);
        darbas_su_failais("studentai_10000.txt", n2);
        darbas_su_failais("studentai_100000.txt", n3);
        darbas_su_failais( "studentai_1000000.txt", n4);
        darbas_su_failais( "studentai_10000000.txt", n5);


    }





    return 0;
}

