#include<iostream>
using namespace std;
void duomenys(vector<Studentas>& studentai);
void galutinis_balas_vid(vector<Studentas>& studentai);
void print_results(const vector<Studentas>& studentai);

struct Studentas {
    string vardas;
    string pavarde;
    vector<int> nd;
    int egz;
    double galutinis = 0.0;
    string reikalavimas;
};
int main()
{
  vector<Studentas> studentai;
  duomenys(studentai);
  print_results(studentai);
  return 0;
}
//--------------------------------------------
void duomenys(vector<Studentas>& studentai)
{

int studentuSkaicius;

    while (true) {
        cout << "Kiek studentu norite ivesti? \n";
        cin >> studentuSkaicius;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Klaidingas ivedimas, bandykite dar karta (Iveskite tik skaiciu): \n";
        } else {
            break;
        }
    }


    for (int i = 0; i < studentuSkaicius; i++) {
        Studentas naujasStudentas;
        cout << "Iveskite studento varda: ";
        cin >> naujasStudentas.vardas;
        naujasStudentas.vardas = capitalize(naujasStudentas.vardas);
        cout << "Iveskite studento pavarde: ";
        cin >> naujasStudentas.pavarde;
        naujasStudentas.pavarde = capitalize(naujasStudentas.pavarde);

        
        int nd_count;
        while (true) {
            cout << "Kiek namu darbu ivertinimu norite ivesti? \n";
            cin >> nd_count;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << "Klaida! Iveskite skaiciu nuo 1 iki 10: \n";
                        } else if (nd_verte < 1 || nd_verte > 10) {
                            cout << "Klaida! Iveskite skaiciu nuo 1 iki 10: \n";
                        } else {
                            naujasStudentas.nd.push_back(nd_verte);
                            break;
                        }
                    }
                }
                break;
            }
        }
    
            cout << "Iveskite egzamino ivertinima: ";
            while (true)
                    {
                        cin >> naujasStudentas.egz;

                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << "Klaida! Iveskite skaiciu nuo 1 iki 10: \n";
                        } else if (naujasStudentas.egz < 1 || naujasStudentas.egz > 10) {
                            cout << "Klaida! Iveskite skaiciu nuo 1 iki 10: \n";
                        } else {
                            naujasStudentas.nd.push_back(naujasStudentas.egz);
                            break;
                        }
                    }

   for (auto& studentas : studentai) {
            galutinis_balas_vid(studentai);
        }

//-----------------------------------------------------
void galutinis_balas_vid(vector<Studentas>& studentai)
{
    for (auto& student : studentai)
    {
        double suma = 0;
        for (int nd : student.nd)
        {
            suma += nd;
        }

        double vidurkis_nd = suma / student.nd.size() ;
        student.galutinis = (vidurkis_nd*0.4 + student.egz*0.6);
    }
}
//----------------------------------------------------
void print_results(const vector<Studentas>& studentai)
{
cout << left << setw(15) << "Pavarde"
<< setw(15) << "Vardas"
<< setw(30) << "Galutinis (Vid.) " << endl;
    cout<< "----------------------------------------------------------------"<<endl;

     for (const auto& studentas : studentai) {
     
            cout << left << setw(15) << studentas.pavarde
<< setw(15) << studentas.vardas
<< setw(18) << fixed << setprecision(2) << studentas.galutinis << "-----" << endl;
         
    }
  }
