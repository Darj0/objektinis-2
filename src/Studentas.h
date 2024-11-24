#ifndef STUDENTAS_H_INCLUDED
#define STUDENTAS_H_INCLUDED
#include "Mylib.h"

class Studentas {
private:
    string vardas;
    string pavarde;
    vector<int> nd;
    int egz;
    double galutinis;
    string reikalavimas;

public:
     Studentas() : vardas(" "), pavarde(" "), egz(0), galutinis(0.0), reikalavimas(" ") {}


    Studentas(const string& vardas, const string& pavarde, const vector<int>& nd, int egz, const string& reikalavimas)
        : vardas(vardas), pavarde(pavarde), nd(nd), egz(egz), reikalavimas(reikalavimas) {
        calculateGalutinis();
    }
    const string& getVardas() const { return vardas; }
    const string& getPavarde() const { return pavarde; }
    const vector<int>& getNd() const { return nd; }
    double getGalutinis() const { return galutinis; }
    int getEgz() const { return egz; }
    string getReikalavimas() const { return reikalavimas; }

    static string generuoti_varda(int indeksas) {
        return "Vardas" + to_string(indeksas);
    }


    static string generuoti_pavarde(int indeksas) {
        return "Pavarde" + to_string(indeksas);
    }


    Studentas(const Studentas& other)
        : vardas(other.vardas), pavarde(other.pavarde), nd(other.nd), egz(other.egz), galutinis(other.galutinis), reikalavimas(other.reikalavimas) {

    }


    ~Studentas() {
        nd.clear();
        //cout << "Objekto destruktorius kvieciamas " << vardas << " " << pavarde << " objektui." << std::endl;
    }


    Studentas& operator=(const Studentas& other) {
    if (this == &other) return *this;
    vardas = other.vardas;
    pavarde = other.pavarde;
    nd = other.nd;
    egz = other.egz;
    galutinis = other.galutinis;
    reikalavimas = other.reikalavimas;
    return *this;
}

    void calculateGalutinis()  {
        double vidurkis_nd = 0.0;
        if (!nd.empty()) {
            vidurkis_nd = accumulate(nd.begin(), nd.end(), 0.0) / nd.size();
        }
        galutinis = 0.4 * vidurkis_nd + 0.6 * egz;
    }

   void setReikalavimas(const string& reikalavimas_verte) {
        reikalavimas = reikalavimas_verte;
    }


    void setGalutinis(double newGalutinis) {
        galutinis = newGalutinis;
    }




    void setVardas(const string& vardas) {
        this->vardas = vardas;
    }


    void setPavarde(const string& pavarde) {
        this->pavarde = pavarde;
    }


    void setNd(const vector<int>& n) { nd = n; }

    void setNd(const list<int>& n) { nd.assign(n.begin(), n.end()); }


    void addNd(int nd_verte) {
        nd.push_back(nd_verte);
    }

    void setEgz(int egz_verte) {
        if (egz_verte >= 1 && egz_verte <= 10) {
            egz = egz_verte;
        } else {
            cout << "Egzamino ivertinimas turi buti nuo 1 iki 10." << endl;
        }
    }


     friend istream& operator>>(istream& in, Studentas& s) {
        cout << "Iveskite varda: ";
        in >> s.vardas;
        cout << "Iveskite pavarde: ";
        in >> s.pavarde;
        cout << "Iveskite egzamino pazimi: ";
        in >> s.egz;
        s.nd.clear();
        cout << "Iveskite namu darbu pazymius (spauskite 0, kad baigti): ";
        int pazymys;
        while (in >> pazymys && pazymys != 0) {
            s.nd.push_back(pazymys);
        }
        s.calculateGalutinis();
        return in;
    }


    friend ostream& operator<<(ostream& out, const Studentas& s) {
        out << "Vardas: " << s.vardas << ", Pavarde: " << s.pavarde << "\n";
        out << "Egzaminas: " << s.egz << "\n";
        out << "Namu darbu pazymiai: ";
        for (int pazymys : s.nd) {
            out << pazymys << " ";
        }
        out << "\nGalutinis: " << fixed << setprecision(2) << s.galutinis << "\n";
        return out;
    }

    static Studentas generuotiStudenta() {
        Studentas s;
        s.vardas = "Vardas" + to_string(rand() % 100 + 1);
        s.pavarde = "Pavarde" + to_string(rand() % 100 + 1);
        s.egz = rand() % 10 + 1;
        int pazymiuKiekis = rand() % 5 + 1;
        for (int i = 0; i < pazymiuKiekis; ++i) {
            s.nd.push_back(rand() % 10 + 1);
        }
        s.calculateGalutinis();
        return s;
    }


    static vector<Studentas> nuskaitytiIsFailo(const string& failoVardas) {
        ifstream failas(failoVardas);
        vector<Studentas> studentai;
        if (!failas) {
            cerr << "Nepavyko atidaryti failo: " << failoVardas << endl;
            return studentai;
        }
        Studentas s;
        while (failas >> s) {
            studentai.push_back(s);
        }
        failas.close();
        return studentai;
    }
    static void rasytiIFaila(const vector<Studentas>& studentai, const string& failoVardas) {
        ofstream failas(failoVardas);
        if (!failas) {
            cerr << "Nepavyko sukurti failo: " << failoVardas << endl;
            return;
        }
        for (const auto& s : studentai) {
            failas << s << endl;
        }
        failas.close();
    }


};

//void galutinis_balas_vid(vector<Studentas>& studentai);
//void galutinis_balas_med(vector<Studentas>& studentai);
void print_results(const vector<Studentas>& studentai);
void patikrinimas(vector<Studentas>& studentai);
void skaityti(vector<Studentas>& studentai, string name, string kriterijus);
void duomenys(vector<Studentas>& studentai);
void sort_students(vector<Studentas>& studentai);
bool compare_students(const Studentas& a, const Studentas& b);
string capitalize(string var);
string tolowers(string var);

void print_results_list(const list<Studentas>& studentai_list);
void duomenys_list(list<Studentas>& studentai_list);
//void galutinis_balas_med_list(list<Studentas>& studentai_list);
//void galutinis_balas_vid_list(list<Studentas>& studentai_list);
void skaityti_list(list<Studentas>& studentai_list, const string& name, const string& kriterijus);
//string exec(const char* cmd);



#endif // STUDENTAS_H_INCLUDED
