#include "Failai.h"
#include "Studentas.h"


void print_memory_usage(const vector<Studentas>& v, const string& name) {
    size_t memory_in_bytes = v.capacity() * sizeof(Studentas);
    cout << "Memory used by " << name << ": " << memory_in_bytes << " bytes" << endl;
    }

//----------------------------------------------------------------------------
void print_memory_usage_list(const std::list<Studentas>& lst, const string& name) {
    size_t node_size = sizeof(Studentas) + 2 * sizeof(void*);
    size_t memory_in_bytes = lst.size() * node_size;
    std::cout << "Memory used by " << name << ": " << memory_in_bytes << " bytes" << std::endl;
}
//--------------------------------------------------------------------------------------------
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
        naujasStudentas.vardas = generuoti_varda(i);
        naujasStudentas.pavarde = generuoti_pavarde(i);

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
void rusiavimas_2_grupes( vector<Studentas>& studentai, vector<Studentas>& vargsiukai, vector<Studentas>& kietiakiai, int strategija)
{
if (strategija == 1)
{
     for (const auto& studentas : studentai) {
        if (studentas.galutinis < 5.0) {
            vargsiukai.push_back(studentas);
        } else {
            kietiakiai.push_back(studentas);
        }
    }
}

else if (strategija == 2)
{
    auto it = remove_if(studentai.begin(), studentai.end(),
                              [&vargsiukai](Studentas& studentas) {
                                  if (studentas.galutinis < 5.0) {
                                      vargsiukai.push_back(move(studentas));
                                      return true;
                                  }
                                  return false;
                              });

    studentai.erase(it, studentai.end());
    kietiakiai = move(studentai);
}


else
{
     auto it = partition(studentai.begin(), studentai.end(),
                                [](const Studentas& studentas) { return studentas.galutinis < 5.0; });


            vargsiukai.assign(make_move_iterator(studentai.begin()), make_move_iterator(it));
            kietiakiai.assign(make_move_iterator(it), make_move_iterator(studentai.end()));


            studentai.clear();
            studentai.shrink_to_fit();
}



}
//-------------------------------------------
void rusiavimas_2_grupes_list( list<Studentas>& studentai_list, list<Studentas>& vargsiukai_list, list<Studentas>& kietiakiai_list, int strategija)
{
 if (strategija == 1)
 {
     for (const auto& studentas : studentai_list) {
        if (studentas.galutinis < 5.0) {
            vargsiukai_list.push_back(studentas);
        } else {
            kietiakiai_list.push_back(studentas);
        }
    }
 }

else if (strategija == 2)
{
    for (auto it = studentai_list.begin(); it != studentai_list.end(); ) {
        if (it->galutinis < 5.0) {

            vargsiukai_list.push_back(move(*it));
            it = studentai_list.erase(it);
        } else {
            it++;
        }

    }



    kietiakiai_list = move(studentai_list);

}

else if (strategija == 3) {

        auto it = partition(studentai_list.begin(), studentai_list.end(), [](const Studentas& s) {
            return s.galutinis < 5.0;
        });


        vargsiukai_list.splice(vargsiukai_list.end(), studentai_list, studentai_list.begin(), it);


        kietiakiai_list.splice(kietiakiai_list.end(), studentai_list);
    }


}


//-----------------------------------------------
void darbas_su_failais(string failas, int duom_sk, string reikalavimas, string kriterijus, int strategija)
{
    vector<Studentas> studentai;

    auto start_read = chrono::high_resolution_clock::now();
    skaityti(studentai, failas, kriterijus);
    auto end_read = chrono::high_resolution_clock::now();
    chrono::duration<double> duration_read = end_read - start_read;
    cout << "Failo is " << duom_sk << " duomenu nuskaitimo laikas: " << duration_read.count() << " sek" << endl;


    chrono::duration<double> duration_sort;

    if (reikalavimas == "v")
    {
        auto start_sort = chrono::high_resolution_clock::now();
        sort_students_by_name(studentai);
        auto end_sort = chrono::high_resolution_clock::now();
        duration_sort = end_sort - start_sort;
    }
    else if (reikalavimas == "p")
    {
        auto start_sort = chrono::high_resolution_clock::now();
        sort_students_by_surname(studentai);
        auto end_sort = chrono::high_resolution_clock::now();
        duration_sort = end_sort - start_sort;
    }

    else
    {
        auto start_sort = chrono::high_resolution_clock::now();
        sort_students_by_grade(studentai);
        auto end_sort = chrono::high_resolution_clock::now();
        duration_sort = end_sort - start_sort;
    }


    cout << duom_sk << " studentu rusiavimo laikas: " << duration_sort.count() << " sek" << endl;

    vector<Studentas> vargsiukai;
    vector<Studentas> kietiakiai;
    auto start_split = chrono::high_resolution_clock::now();
    rusiavimas_2_grupes(studentai, vargsiukai, kietiakiai, strategija);
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

    print_memory_usage(studentai, "studentai");
    print_memory_usage(vargsiukai, "vargsiukai");
    print_memory_usage(kietiakiai, "kietiakiai");


    vargsiukai.clear();
    kietiakiai.clear();
    studentai.clear();
}
//--------------------------------------------------------------

void darbas_su_failais_list(string failas, int duom_sk, string reikalavimas, string kriterijus, int strategija)
{
    list<Studentas> studentai_list;

    auto start_read = chrono::high_resolution_clock::now();
    skaityti_list(studentai_list, failas, kriterijus);
    auto end_read = chrono::high_resolution_clock::now();
    chrono::duration<double> duration_read = end_read - start_read;

    cout << "Failo is " << duom_sk << " duomenu nuskaitimo laikas: " << duration_read.count() << " sek" << endl;

    chrono::duration<double> duration_sort;

    if (reikalavimas == "v")
    {
        auto start_sort = chrono::high_resolution_clock::now();
        sort_students_by_name_list(studentai_list);
        auto end_sort = chrono::high_resolution_clock::now();
        duration_sort = end_sort - start_sort;
    }
    else if (reikalavimas == "p")
    {
        auto start_sort = chrono::high_resolution_clock::now();
        sort_students_by_surname_list(studentai_list);
        auto end_sort = chrono::high_resolution_clock::now();
        duration_sort = end_sort - start_sort;
    }
    else
    {
        auto start_sort = chrono::high_resolution_clock::now();
        sort_students_by_grade_list(studentai_list);
        auto end_sort = chrono::high_resolution_clock::now();
        duration_sort = end_sort - start_sort;
    }

    cout << duom_sk << " studentu rusiavimo laikas: " << duration_sort.count() << " sek" << endl;

    list<Studentas> vargsiukai_list;
    list<Studentas> kietiakiai_list;

    auto start_split = chrono::high_resolution_clock::now();
    rusiavimas_2_grupes_list(studentai_list, vargsiukai_list, kietiakiai_list, strategija);
    auto end_split = chrono::high_resolution_clock::now();
    chrono::duration<double> duration_split = end_split - start_split;
    cout << duom_sk << " studentu skirstymo i 2 grupes laikas: " << duration_split.count() << " sek" << endl;


    auto start_protingi = chrono::high_resolution_clock::now();
    surusioti_failai_list(kietiakiai_list, "protingi_" + to_string(duom_sk) + ".txt");
    auto end_protingi = chrono::high_resolution_clock::now();
    chrono::duration<double> duration_protingi = end_protingi - start_protingi;
    cout << duom_sk << " protingu studentu irasimo i faila laikas: " << duration_protingi.count() << " sek" << endl;

    auto start_nelaimingi = chrono::high_resolution_clock::now();
    surusioti_failai_list(vargsiukai_list, "nelaimingi_" + to_string(duom_sk) + ".txt");
    auto end_nelaimingi = chrono::high_resolution_clock::now();
    chrono::duration<double> duration_nelaimingi = end_nelaimingi - start_nelaimingi;
    cout << duom_sk << " nelaimingu studentu irasimo i faila laikas: " << duration_nelaimingi.count() << " sek" << endl;


    cout << "Bendras laikas: " << duration_read.count() + duration_sort.count() + duration_split.count() + duration_protingi.count() + duration_nelaimingi.count() << " sek" << endl;


    print_memory_usage_list(studentai_list, "studentai_list");
    print_memory_usage_list(vargsiukai_list, "vargsiukai_list");
    print_memory_usage_list(kietiakiai_list, "kietiakiai_list");


    vargsiukai_list.clear();
    kietiakiai_list.clear();
    studentai_list.clear();
}


//--------------------------------------------------------------
void surusioti_failai(vector<Studentas>& studentai, string name)
{
   ofstream failas(name);

    failas << left
         << setw(20) << "Vardas"
         << setw(20) << "Pavarde"
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

//--------------------------------------------------------------
void surusioti_failai_list(list<Studentas>& studentai_list, const string& name)
{
    ofstream failas(name);


    failas << std::left
           << std::setw(20) << "Vardas"
           << std::setw(20) << "Pavarde"
           << std::setw(10) << "Galutinis"
           << std::endl;
    failas << std::string(60, '-') << std::endl;


    for (const auto& studentas : studentai_list) {
        failas << std::left
               << std::setw(20) << studentas.pavarde
               << std::setw(20) << studentas.vardas
               << std::setw(10) << studentas.galutinis
               << std::endl;
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
//-----------------------------------------------------------
bool compare_by_grade(const Studentas& a, const Studentas& b) {
    return a.galutinis < b.galutinis;
}
//--------------------------------------------------

void sort_students_by_grade(vector<Studentas>& studentai) {
    sort(studentai.begin(), studentai.end(), compare_by_grade);
}
//--------------------------------------------------
void sort_students_by_name_list(list<Studentas>& studentai_list) {
    studentai_list.sort(compare_by_name);
}
//--------------------------------------------------
void sort_students_by_surname_list(list<Studentas>& studentai_list) {
    studentai_list.sort(compare_by_surname);
}

//--------------------------------------------------
void sort_students_by_grade_list(list<Studentas>& studentai_list) {
    studentai_list.sort(compare_by_grade);
}
