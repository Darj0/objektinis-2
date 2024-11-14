#ifndef FAILAI_H_INCLUDED
#define FAILAI_H_INCLUDED
#include "Mylib.h"
#include "Studentas.h"

void kurti_faila(const std::vector<Studentas>& studentai, const std::string& failo_priedas);
void generuoti_sarasus(int n, vector<Studentas>& studentai);
void rusiavimas_2_grupes(const vector<Studentas>& studentai, vector<Studentas>& vargsiukai, vector<Studentas>& kietiakiai, int strategija);
void darbas_su_failais(string failas, int duom_sk, string reikalavimas, string kriterijus, int strategija);
void surusioti_failai(vector<Studentas>& studentai, string name);
void sort_students_by_surname(vector<Studentas>& studentai);
bool compare_by_surname(const Studentas& a, const Studentas& b);
void sort_students_by_name(vector<Studentas>& studentai);
bool compare_by_name(const Studentas& a, const Studentas& b);
void sort_students_by_grade(vector<Studentas>& studentai);
bool compare_by_grade(const Studentas& a, const Studentas& b);
//void print_memory_usage(const vector<Studentas>& v, const string& name);

void rusiavimas_2_grupes_list(const list<Studentas>& studentai_list, list<Studentas>& vargsiukai_list, list<Studentas>& kietiakiai_list, int strategija);
void darbas_su_failais_list(string failas, int duom_sk, string reikalavimas, string kriterijus, int strategija);
void surusioti_failai_list(list<Studentas>& studentai_list, const string& name);
void sort_students_by_name_list(list<Studentas>& studentai_list);
void sort_students_by_surname_list(list<Studentas>& studentai_list);
void sort_students_by_grade_list(list<Studentas>& studentai_list);
//void print_memory_usage_list(const vector<Studentas>& v, const string& name);

#endif // FAILAI_H_INCLUDED
