#ifndef FAILAI_H_INCLUDED
#define FAILAI_H_INCLUDED
#include "Mylib.h"
#include "Studentas.h"
string generuoti_varda(int indeksas);
string generuoti_pavarde(int indeksas);
void kurti_faila(vector<Studentas>& studentai, string failo_priedas);
void generuoti_sarasus(int n, vector<Studentas>& studentai);
void rusiavimas_2_grupes(const vector<Studentas>& studentai, vector<Studentas>& vargsiukai, vector<Studentas>& kietiakiai);
void darbas_su_failais(string failas, int duom_sk, string reikalavimas);
void surusioti_failai(vector<Studentas>& studentai, string name);
void sort_students_by_surname(vector<Studentas>& studentai);
bool compare_by_surname(const Studentas& a, const Studentas& b);
void sort_students_by_name(vector<Studentas>& studentai);
bool compare_by_name(const Studentas& a, const Studentas& b);



#endif // FAILAI_H_INCLUDED
