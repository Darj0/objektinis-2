#include "Failai.h"
#include "Studentas.h"
string generuoti_varda(int indeksas) {
    return "Vardas" + to_string(indeksas);
}
//---------------------------------------------------------
string generuoti_pavarde(int indeksas) {
    return "Pavarde" + to_string(indeksas);
}
//------------------------------------------------------
void generuoti_sarasus(int n, vector<Studentas>& studentai)
{



    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 10);

    for (int i = 1; i < n; ++i) {
        Studentas naujasStudentas;
        naujasStudentas.vardas = generuoti_varda(i );
        naujasStudentas.pavarde = generuoti_pavarde(i );

        int nd_kiekis = 5;
        for (int j = 0; j < nd_kiekis; ++j) {
            naujasStudentas.nd.push_back(dist(gen));
        }

        naujasStudentas.egz = dist(gen);



        studentai.push_back(naujasStudentas);
    }




}
//--------------------------------------------------------
void kurti_faila(vector<Studentas>& studentai, string failo_priedas)
{
    ofstream studentu_failas("studentai_" + failo_priedas + ".txt");

    studentu_failas << left
         << setw(15) << "Pavarde"
         << setw(15) << "Vardas"
         << setw(6)  << "ND1"
         << setw(6)  << "ND2"
         << setw(6)  << "ND3"
         << setw(6)  << "ND4"
         << setw(6)  << "ND5"
         << setw(10) << "Egzaminas"
         << endl;
    studentu_failas << string(60, '-') << endl;

    for (const auto& studentas : studentai) {
        studentu_failas << left
             << setw(15) << studentas.pavarde
             << setw(15) << studentas.vardas;

        for (const auto& pazymys : studentas.nd) {
            studentu_failas << setw(6) << pazymys;
        }

        studentu_failas << setw(10) << studentas.egz << endl;
    }

    studentu_failas.close();
}

//-------------------------------------------
void rusiavimas_2_grupes(const vector<Studentas>& studentai, vector<Studentas>& vargsiukai, vector<Studentas>& kietiakiai)
{
    for (const auto& studentas : studentai) {
        if (studentas.galutinis < 5.0) {
            vargsiukai.push_back(studentas);
        } else {
            kietiakiai.push_back(studentas);
        }
    }
}

//-----------------------------------------------
void darbas_su_failais(string failas, int duom_sk, string reikalavimas)
{
    vector<Studentas> studentai;

    auto start_read = chrono::high_resolution_clock::now();
    skaityti(studentai, failas);
    auto end_read = chrono::high_resolution_clock::now();
    chrono::duration<double> duration_read = end_read - start_read;
    cout << "Failo is " << duom_sk << " duomenu nuskaitimo laikas: " << duration_read.count() << " sek" << endl;

    // Объявляем переменную duration_sort вне условий
    chrono::duration<double> duration_sort;

    if (reikalavimas == "v")
    {
        auto start_sort = chrono::high_resolution_clock::now();
        sort_students_by_name(studentai);
        auto end_sort = chrono::high_resolution_clock::now();
        duration_sort = end_sort - start_sort;
    }
    else
    {
        auto start_sort = chrono::high_resolution_clock::now();
        sort_students_by_surname(studentai);
        auto end_sort = chrono::high_resolution_clock::now();
        duration_sort = end_sort - start_sort;
    }

    // Теперь можем использовать duration_sort
    cout << duom_sk << " studentu rusiavimo laikas: " << duration_sort.count() << " sek" << endl;

    vector<Studentas> vargsiukai;
    vector<Studentas> kietiakiai;
    auto start_split = chrono::high_resolution_clock::now();
    rusiavimas_2_grupes(studentai, vargsiukai, kietiakiai);
    auto end_split = chrono::high_resolution_clock::now();
    chrono::duration<double> duration_split = end_split - start_split;
    cout << duom_sk << " studentu skirstymo i 2 grupes laikas: " << duration_split.count() << " sek" << endl;

    auto start_protingi = chrono::high_resolution_clock::now();
    surusioti_failai(kietiakiai, "protingi_" + to_string(duom_sk) + ".txt");
    auto end_protingi = chrono::high_resolution_clock::now();
    chrono::duration<double> duration_protingi = end_protingi - start_protingi;
    cout << duom_sk << " protingu studentu irasimo i faila laikas: " << duration_protingi.count() << " sek" << endl;

    auto start_nelaimingi = chrono::high_resolution_clock::now();
    surusioti_failai(vargsiukai, "nelaimingi_" + to_string(duom_sk) + ".txt");
    auto end_nelaimingi = chrono::high_resolution_clock::now();
    chrono::duration<double> duration_nelaimingi = end_nelaimingi - start_nelaimingi;
    cout << duom_sk << " nelaimingu studentu irasimo i faila laikas: " << duration_nelaimingi.count() << " sek" << endl;

    cout << "Bendras laikas: " << duration_read.count() + duration_sort.count() + duration_split.count() + duration_protingi.count() + duration_nelaimingi.count() << " sek" << endl;

    vargsiukai.clear();
    kietiakiai.clear();
    studentai.clear();
}


//--------------------------------------------------------------
void surusioti_failai(vector<Studentas>& studentai, string name)
{
   ofstream failas(name);

    failas << left
         << setw(20) << "Pavarde"
         << setw(20) << "Vardas"
         << setw(10) << "Galutinis"
         << endl;
    failas << string(60, '-') << endl;
   for (const auto& studentas : studentai) {
        failas << left
             << setw(20) << studentas.pavarde
             << setw(20) << studentas.vardas << setw(10) << studentas.galutinis << endl;
        }
   failas.close();
}
//-----------------------------------------------------------
bool compare_by_name(const Studentas& a, const Studentas& b) {
    return a.vardas < b.vardas;
}
//--------------------------------------------------

void sort_students_by_name(vector<Studentas>& studentai) {
    sort(studentai.begin(), studentai.end(), compare_by_name);
}

//-----------------------------------------------------
bool compare_by_surname(const Studentas& a, const Studentas& b) {
    return a.pavarde < b.pavarde;
}
//--------------------------------------------------

void sort_students_by_surname(vector<Studentas>& studentai) {
    sort(studentai.begin(), studentai.end(), compare_by_surname);
}
