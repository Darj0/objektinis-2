#ifndef STUDENTAS_H_INCLUDED
#define STUDENTAS_H_INCLUDED
#include "Mylib.h"

struct Studentas {
    string vardas;
    string pavarde;
    vector<int> nd;
    int egz;
    double galutinis = 0.0;
    string reikalavimas;
};

void galutinis_balas_vid(vector<Studentas>& studentai);
void galutinis_balas_med(vector<Studentas>& studentai);
void print_results(const vector<Studentas>& studentai);
void patikrinimas(vector<Studentas>& studentai);
void skaityti(vector<Studentas>& studentai, string name, string kriterijus);
void duomenys(vector<Studentas>& studentai);
void sort_students(vector<Studentas>& studentai);
bool compare_students(const Studentas& a, const Studentas& b);
string capitalize(string var);
string tolowers(string var);

#endif // STUDENTAS_H_INCLUDED
