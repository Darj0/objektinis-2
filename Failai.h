#ifndef FAILAI_H_INCLUDED
#define FAILAI_H_INCLUDED
#include "Mylib.h"
#include "Studentas.h"
string generuoti_varda(int indeksas);
string generuoti_pavarde(int indeksas);
void kurti_faila(vector<Studentas>& studentai, string failo_priedas);
void generuoti_sarasus(int n, vector<Studentas>& studentai);
void rusiavimas_2_grupes(const vector<Studentas>& studentai, vector<Studentas>& vargsiukai, vector<Studentas>& kietiakiai);
void darbas_su_failais(string failas, int duom_sk);
void surusioti_failai(vector<Studentas>& studentai, string name);



#endif // FAILAI_H_INCLUDED
