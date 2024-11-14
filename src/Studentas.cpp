#include "Studentas.h"
void galutinis_balas_vid(vector<Studentas>& studentai) {
    for (auto& student : studentai) {
        double suma = accumulate(student.getNd().begin(), student.getNd().end(), 0.0);
        double vidurkis_nd = suma / student.getNd().size();
        student.setGalutinis(vidurkis_nd * 0.4 + student.getEgz() * 0.6);
    }
}
//---------------------------------------------------
void galutinis_balas_vid_list(list<Studentas>& studentai_list) {
    for (auto& student : studentai_list) {
        double suma = accumulate(student.getNd().begin(), student.getNd().end(), 0.0);
        double vidurkis_nd = suma / student.getNd().size();
        student.setGalutinis(vidurkis_nd * 0.4 + student.getEgz() * 0.6);
    }
}

//---------------------------------------------------

void galutinis_balas_med(vector<Studentas>& studentai) {
    for (auto& student : studentai) {
        auto nd_copy = student.getNd();
        sort(nd_copy.begin(), nd_copy.end());

        double mediana;
        int size = nd_copy.size();

        if (size % 2 == 0) {
            mediana = (nd_copy[size / 2 - 1] + nd_copy[size / 2]) / 2.0;
        } else {
            mediana = nd_copy[size / 2];
        }

        student.setGalutinis(mediana * 0.4 + student.getEgz() * 0.6);
    }
}

//-------------------------------------------------------
void galutinis_balas_med_list(list<Studentas>& studentai_list) {
    for (auto& student : studentai_list) {
        auto nd_copy = student.getNd();
        sort(nd_copy.begin(), nd_copy.end());

        double mediana;
        int size = nd_copy.size();

        if (size % 2 == 0) {
            mediana = (nd_copy[size / 2 - 1] + nd_copy[size / 2]) / 2.0;
        } else {
            mediana = nd_copy[size / 2];
        }

        student.setGalutinis(mediana * 0.4 + student.getEgz() * 0.6);
    }
}

//-------------------------------------------------------
void print_results(const vector<Studentas>& studentai) {
    cout << left
              << setw(15) << "Pavarde"
              << setw(15) << "Vardas"
              << setw(15) << "Vid."
              << setw(15) << "Med."
              << setw(20) << "Adresas"
              << setw(10) << "Zingsnis" << endl;

    cout << setfill('-')
              << setw(80) << "-"
              << setfill(' ') << endl;

    const Studentas* previous_student = nullptr;

    for (const auto& studentas : studentai) {
        cout << left
                  << setw(15) << studentas.getPavarde()
                  << setw(15) << studentas.getVardas();

        if (studentas.getReikalavimas() == "vid") {
            cout << setw(15) << fixed << setprecision(2) << studentas.getGalutinis()
                      << setw(15) << "-----"
                      << setw(20) << &studentas;
        } else if (studentas.getReikalavimas() == "med") {
            cout << setw(15) << "-----"
                      << setw(15) << fixed << setprecision(2) << studentas.getGalutinis()
                      << setw(20) << &studentas;
        }

        if (previous_student) {
            ptrdiff_t zingsnis = reinterpret_cast<const char*>(&studentas) - reinterpret_cast<const char*>(previous_student);
            cout << setw(10) << zingsnis;
        } else {
            cout << setw(10) << "-----";
        }

        cout << endl;
        previous_student = &studentas;
    }
}

//----------------------------------------------------------------------------
void print_results_list(const list<Studentas>& studentai_list) {
    cout << left
              << setw(10) << "Pavarde"
              << setw(10) << "Vardas"
              << setw(15) << "Vid."
              << setw(15) << "Med."
              << setw(20) << "Adresas"
              << setw(10) << "Zingsnis" << endl;

    cout << setfill('-')
              << setw(80) << "-"
              << setfill(' ') << endl;

    const Studentas* previous_student = nullptr;

    for (const auto& studentas : studentai_list) {
        cout << left
                  << setw(10) << studentas.getPavarde()
                  << setw(10) << studentas.getVardas();

        if (studentas.getReikalavimas() == "vid") {
            cout << setw(15) << fixed << setprecision(2) << studentas.getGalutinis()
                      << setw(15) << "-----"
                      << setw(20) << &studentas;
        } else if (studentas.getReikalavimas() == "med") {
            cout << setw(15) << "-----"
                      << setw(15) << fixed << setprecision(2) << studentas.getGalutinis()
                      << setw(20) << &studentas;
        }

        if (previous_student) {
            ptrdiff_t zingsnis = abs(reinterpret_cast<const char*>(&studentas) - reinterpret_cast<const char*>(previous_student));
            cout << setw(10) << zingsnis;
        } else {
            cout << setw(10) << "-----";
        }

        cout << endl;
        previous_student = &studentas;
    }
}
//----------------------------------------------------------------------------
    string capitalize(string var)
    {
    if (!var.empty()) {
        var[0] = toupper(var[0]);
        for (size_t i = 1; i < var.length(); ++i) {
            var[i] = tolower(var[i]);
        }
    }
    return var;
    }
//----------------------------------------------------------------------------
    string tolowers(string var)
    {
    if (!var.empty()) {
          for (size_t i = 0; i < var.length(); ++i) {
            var[i] = tolower(var[i]);
        }
    }
    return var;
    }

//--------------------------------------------------------------------------------
void duomenys(vector<Studentas>& studentai)
{

int studentuSkaicius;

    while (true) {
        cout << "Kiek studentu norite ivesti? \n";
        cin >> studentuSkaicius;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Klaidingas ivedimas, bandykite dar karta (Iveskite tik skaiciu): \n";
        } else {
            break;
        }
    }


    for (int i = 0; i < studentuSkaicius; i++) {
        Studentas naujasStudentas;
        cout << "Iveskite studento varda: ";
        string vardas;
        cin >> vardas;
        naujasStudentas.setVardas(capitalize(vardas));
        cout << "Iveskite studento pavarde: ";
        string pavarde;
        cin >> pavarde;
        naujasStudentas.setPavarde(capitalize(pavarde));

        string atsakymas;
        cout << "Ar jau zinote kiek pazymiu noryte ivesti? ('Taip'  'Ne'  'G' - Generuoja pazymius)\n";
        cin >> atsakymas;
        atsakymas = tolowers(atsakymas);

       while (atsakymas != "taip"  && atsakymas !=  "ne"&& atsakymas != "g" )
        {
        cout << "Klaidingas ivedimas, bandykite dar karta (Iveskite 'Taip' arba 'Ne' arba 'G'): \n";
        cin >> atsakymas;
        atsakymas = tolowers(atsakymas);
        }


       if (atsakymas == "taip") {
        int nd_count;
        while (true) {
            cout << "Kiek namu darbu ivertinimu norite ivesti? \n";
            cin >> nd_count;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Klaidingas ivedimas, bandykite dar karta (Iveskite tik skaiciu): \n";
            }
            else
            {
                cout << "Iveskite namu darbu ivertinimus (atskiriant ENTER): \n";
                for (int j = 0; j < nd_count; j++)
                {
                    int nd_verte;

                    while (true)
                    {
                        cin >> nd_verte;

                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Klaida! Iveskite skaiciu nuo 1 iki 10: \n";
                        } else if (nd_verte < 1 || nd_verte > 10) {
                            cout << "Klaida! Iveskite skaiciu nuo 1 iki 10: \n";
                        } else {
                            naujasStudentas.addNd(nd_verte);
                            break;
                        }
                    }
                }
                break;
            }
        }
    }

        else if (atsakymas == "ne" )
        {
            cout << "Iveskite namu darbu ivertinimus (baigus iveskite '0'): \n" << endl;
            int input;

            while (true)
            {
                cin >> input;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Klaidingas ivedimas, bandykite dar karta (Iveskite tik skaiciu): \n";
                }

                else if (input == 0)
                {
                break;
                }
                else if (input < 1 || input > 10)
                {
                    cout << "Klaida! Iveskite skaiciu nuo 1 iki 10: \n";
                }
                else
                {
                naujasStudentas.addNd(input);
                }
            }
        }

        else if (atsakymas == "g")
        {
            int nd_count = rand() % 5 + 3;
            cout << "Generuojami " << nd_count << " namu darbu ivertinimai: ";
            for (int j = 0; j < nd_count; j++) {
                int nd_verte = rand() % 10 + 1;
                naujasStudentas.addNd(nd_verte);
                cout << nd_verte << " ";
            }
            cout << endl;

            naujasStudentas.setEgz(rand() % 10 + 1);
            cout << "Generuojamas egzamino ivertinimas: " << naujasStudentas.getEgz() << endl;
        }


        if  (atsakymas != "g")
        {
            cout << "Iveskite egzamino ivertinima: ";
            while (true)
                    {
                        int egzaminas;
                        cin >> egzaminas;

                        if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Klaida! Iveskite skaiciu nuo 1 iki 10: \n";
                    } else if (egzaminas < 1 || egzaminas > 10) {
                        cout << "Klaida! Iveskite skaiciu nuo 1 iki 10: \n";
                    } else {
                        naujasStudentas.setEgz(egzaminas);
                        break;
                        }
                    }

        }
        else{}

        cout << "Galutinio balo skaiciavimui norite naudoti vidurki ar mediana? (Iveskite 'vid' arba 'med'  )" << endl;

        string reikalavimas;
            cin >> reikalavimas;
            reikalavimas = tolowers(reikalavimas);

            naujasStudentas.setReikalavimas(reikalavimas);

            while (naujasStudentas.getReikalavimas() != "vid" && naujasStudentas.getReikalavimas() != "med") {
                cout << "Klaidingas ivedimas, bandykite dar karta (Iveskite vid arba med): ";
                cin >> reikalavimas;
                reikalavimas = tolowers(reikalavimas);

                naujasStudentas.setReikalavimas(reikalavimas);
}


studentai.push_back(naujasStudentas);


    }


   for (auto& studentas : studentai) {
    if (studentas.getReikalavimas() == "vid") {
        galutinis_balas_vid(studentai);
    } else if (studentas.getReikalavimas() == "med") {
        galutinis_balas_med(studentai);
    }

}
}
//----------------------------------------------------
void duomenys_list(list<Studentas>& studentai_list) {
    int studentuSkaicius;

    while (true) {
        cout << "Kiek studentu norite ivesti? \n";
        cin >> studentuSkaicius;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Klaidingas ivedimas, bandykite dar karta (Iveskite tik skaiciu): \n";
        } else {
            break;
        }
    }

       for (int i = 0; i < studentuSkaicius; i++) {
        Studentas naujasStudentas;


        string vardas;
        cout << "Iveskite studento varda: ";
        cin >> vardas;
        naujasStudentas.setVardas(capitalize(vardas));

        string pavarde;
        cout << "Iveskite studento pavarde: ";
        cin >> pavarde;
        naujasStudentas.setPavarde(capitalize(pavarde));

        string atsakymas;
        cout << "Ar jau zinote kiek pazymiu norite ivesti? ('Taip'  'Ne'  'G' - Generuoja pazymius)\n";
        cin >> atsakymas;
        atsakymas = tolowers(atsakymas);

        while (atsakymas != "taip" && atsakymas != "ne" && atsakymas != "g") {
            cout << "Klaidingas ivedimas, bandykite dar karta (Iveskite 'Taip' arba 'Ne' arba 'G'): \n";
            cin >> atsakymas;
            atsakymas = tolowers(atsakymas);
        }

        if (atsakymas == "taip") {
            int nd_count;
            while (true) {
                cout << "Kiek namu darbu ivertinimu norite ivesti? \n";
                cin >> nd_count;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Klaidingas ivedimas, bandykite dar karta (Iveskite tik skaiciu): \n";
                } else {
                    cout << "Iveskite namu darbu ivertinimus (atskiriant ENTER): \n";
                    for (int j = 0; j < nd_count; j++) {
                    int nd_verte;
                    while (true) {
                        cin >> nd_verte;
                        if (cin.fail() || nd_verte < 1 || nd_verte > 10) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Klaida! Iveskite skaiciu nuo 1 iki 10: \n";
                        } else {

                            naujasStudentas.addNd(nd_verte);
                            break;
                            }
                        }
                    }
                    break;
                }
            }
        } else if (atsakymas == "ne") {
            cout << "Iveskite namu darbu ivertinimus (baigus iveskite '0'): \n";
            int input;
            while (true) {
                cin >> input;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Klaidingas ivedimas, bandykite dar karta (Iveskite tik skaiciu): \n";
                } else if (input == 0) {
                    break;
                } else if (input < 1 || input > 10) {
                    cout << "Klaida! Iveskite skaiciu nuo 1 iki 10: \n";
                } else {
                    naujasStudentas.addNd(input);
                }
            }
        } else if (atsakymas == "g") {
            int nd_count = rand() % 5 + 3;
            cout << "Generuojami " << nd_count << " namu darbu ivertinimai: ";
            for (int j = 0; j < nd_count; j++) {
                int nd_verte = rand() % 10 + 1;
                naujasStudentas.addNd(nd_verte);
                cout << nd_verte << " ";
            }
            cout << endl;
            naujasStudentas.setEgz(rand() % 10 + 1);
            cout << "Generuojamas egzamino ivertinimas: " << naujasStudentas.getEgz() << endl;
        }

        if (atsakymas != "g") {
            cout << "Iveskite egzamino ivertinima: ";
            while (true) {
                    int egz_verte;
                    cin >> egz_verte;
                    if (cin.fail() || egz_verte < 1 || egz_verte > 10) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Klaida! Iveskite skaiciu nuo 1 iki 10: \n";
                    } else {
                        naujasStudentas.setEgz(egz_verte);
                        break;
                }
            }
        }

        cout << "Galutinio balo skaiciavimui norite naudoti vidurki ar mediana? (Iveskite 'vid' arba 'med')\n";
        string reikalavimas;
        cin >> reikalavimas;
        reikalavimas = tolowers(reikalavimas);


            while (reikalavimas != "vid" && reikalavimas != "med") {
                cout << "Klaidingas ivedimas, bandykite dar karta (Iveskite vid arba med): ";
                cin >> reikalavimas;
                reikalavimas = tolowers(reikalavimas);
            }


            naujasStudentas.setReikalavimas(reikalavimas);


            studentai_list.push_back(naujasStudentas);
    }


            for (auto& studentas : studentai_list) {
            if (studentas.getReikalavimas() == "vid") {
                galutinis_balas_vid_list(studentai_list);
            } else if (studentas.getReikalavimas() == "med") {
                galutinis_balas_med_list(studentai_list);
            }
    }
}

//----------------------------------------------------
void skaityti(vector<Studentas>& studentai, string name, string kriterijus) {
    ifstream fin;

    try {
        fin.open(name);
        if (!fin.is_open()) {
            throw runtime_error("Nepavyko atidaryti failo.");
        }
    } catch (const ifstream::failure& e) {
        cerr << "Nepavyko atidaryti failo: " << name << endl;
        cerr << "Klaida: " << e.what() << endl;
        return;
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
        return;
    }

    try {
        string ignore;
        getline(fin, ignore);
        string line;

        while (getline(fin, line)) {
            istringstream iss(line);
            Studentas stud;
            string pavarde, vardas;

            if (!(iss >> pavarde >> vardas )) {
                cerr << "Klaida: Netinkamas failo formatas" << endl;
                continue;
            }


            stud.setVardas(vardas);
            stud.setPavarde(pavarde);

            int pazymys;
            vector<int> pazymiai;
            while (iss >> pazymys) {
                pazymiai.push_back(pazymys);
            }

            if (!pazymiai.empty()) {

                stud.setEgz(pazymiai.back());
                pazymiai.pop_back();
                stud.setNd(pazymiai);
            }

            studentai.push_back(stud);
        }

        fin.close();
    } catch (const ifstream::failure& e) {
        cerr << "Nepavyko nuskaityti failo: " << e.what() << endl;
    }

    for (auto& studentas : studentai) {
        studentas.setReikalavimas(kriterijus);
    }

    if (kriterijus == "vid") {
        galutinis_balas_vid(studentai);
    } else if (kriterijus == "med") {
        galutinis_balas_med(studentai);
    }
}
//----------------------------------------------------
void skaityti_list(list<Studentas>& studentai_list, const string& name, const string& kriterijus) {
    ifstream fin;

    try {
        fin.open(name);
        if (!fin.is_open()) {
            throw runtime_error("Nepavyko atidaryti failo.");
        }
    } catch (const ifstream::failure& e) {
        cerr << "Nepavyko atidaryti failo: " << name << endl;
        cerr << "Klaida: " << e.what() << endl;
        return;
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
        return;
    }

    try {
        string ignore;
        getline(fin, ignore);
        string line;

        while (getline(fin, line)) {
            istringstream iss(line);
            Studentas stud_list;
            string vardas, pavarde;

            if (!(iss >> vardas >> pavarde)) {
                //cerr << "Klaida" << endl;
                continue;
            }

            stud_list.setVardas(vardas);
            stud_list.setPavarde(pavarde);

            int pazymys;
            list<int> pazymiai;
            while (iss >> pazymys) {
                pazymiai.push_back(pazymys);
            }

            if (!pazymiai.empty()) {
                stud_list.setEgz(pazymiai.back());
                pazymiai.pop_back();


                vector<int> pazymiaiVector(pazymiai.begin(), pazymiai.end());
                stud_list.setNd(pazymiaiVector);
            }

            studentai_list.push_back(stud_list);
        }

        fin.close();
    } catch (const ifstream::failure& e) {
        cerr << "Nepavyko nuskaityti failo: " << e.what() << endl;
    }

    for (auto& studentas : studentai_list) {
        studentas.setReikalavimas(kriterijus);
    }

    if (kriterijus == "vid") {
        galutinis_balas_vid_list(studentai_list);
    } else if (kriterijus == "med") {
        galutinis_balas_med_list(studentai_list);
    }
}


//------------------------------------------------------
void patikrinimas(vector<Studentas>& studentai)
{



    cout << left
         << setw(15) << "Pavarde"
         << setw(15) << "Vardas"
         << setw(6)  << "ND1"
         << setw(6)  << "ND2"
         << setw(6)  << "ND3"
         << setw(6)  << "ND4"
         << setw(6)  << "ND5"
         << setw(10) << "Egzaminas"
         << endl;
    cout << string(60, '-') << endl;


    for (const auto& studentas : studentai) {

        cout << left
             << setw(15) << studentas.getPavarde()
             << setw(15) << studentas.getVardas();

        const auto& pazymiai = studentas.getNd();


        for (size_t i = 0; i < pazymiai.size(); ++i) {
            cout << setw(6) << pazymiai[i];
        }

        cout << setw(10) << studentas.getEgz() << endl;
    }


}

//------------------------------------------------------
bool compare_students(const Studentas& a, const Studentas& b) {
    if (a.getPavarde() == b.getPavarde()) {
        return a.getVardas() < b.getVardas();
    }
    return a.getPavarde() < b.getPavarde();
}
//--------------------------------------------------

void sort_students(vector<Studentas>& studentai) {
    sort(studentai.begin(), studentai.end(), compare_students);
}
//--------------------------------------------------
/*string exec(const char* cmd) {
    array<char, 128> buffer;
    string result;
    unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}*/

