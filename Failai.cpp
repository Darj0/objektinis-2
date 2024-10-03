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

    for (int i = 0; i < n; ++i) {
        Studentas naujasStudentas;
        naujasStudentas.vardas = generuoti_varda(i + 1);
        naujasStudentas.pavarde = generuoti_pavarde(i + 1);

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
void darbas_su_failais(vector<Studentas>& studentai, string failas, int duom_sk)
{

    auto start_read = std::chrono::high_resolution_clock::now();
    skaityti(studentai, failas);
    auto end_read = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_read = end_read - start_read;
    std::cout << "Failo is " <<duom_sk <<" duomenu nuskaitimo laikas: " << duration_read.count() << " sek" << std::endl;

    auto start_sort = std::chrono::high_resolution_clock::now();
    sort_students(studentai);
    auto end_sort = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_sort = end_sort - start_sort;
    std::cout << duom_sk <<" studentu rusiavimo laikas: " << duration_sort.count() << " sek" << std::endl;


    vector<Studentas> vargsiukai;
    vector<Studentas> kietiakiai;
    auto start_split = std::chrono::high_resolution_clock::now();
    rusiavimas_2_grupes(studentai, vargsiukai, kietiakiai);
    auto end_split = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_split = end_split - start_split;
    std::cout << duom_sk <<" studentu skirstymo i 2 grupes laikas: " << duration_split.count() << " sek" << std::endl;


    auto start_protingi = std::chrono::high_resolution_clock::now();
    surusioti_failai(kietiakiai, "protingi_" + to_string(duom_sk) +".txt");
    auto end_protingi = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_protingi = end_protingi - start_protingi;
    std::cout << duom_sk <<" protingu studentu irasimo i faila laikas: " << duration_protingi.count() << " sek" << std::endl;


    auto start_nelaimingi = std::chrono::high_resolution_clock::now();
    surusioti_failai(vargsiukai, "nelaimingi_" + to_string(duom_sk) +".txt");
    auto end_nelaimingi = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_nelaimingi = end_nelaimingi - start_nelaimingi;
    std::cout << duom_sk <<" nelaimingu studentu irasimo i faila laikas: " << duration_nelaimingi.count() << " sek" << std::endl;
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
