Versijoje 1.2 Studentu klase patobulinta ir atitinka visiems reikalavimas "Rule of three" (destruktorius, kopijavimo konstruktorius ir kopijavimo priskyrimo operatorius). Realizuoti įvesties/išvesties operatoriai (pateiktas metodu demonstravimas). Taip pat patobulinta pradine pasirinkimu menu.

Naudojimo, įdiegimo ir paleidimo instrukciją parengiau versijoje 1.0: https://github.com/Darj0/objektinis-programavimas/blob/V1.0/README.md

1.0 ir 1.1 versijų bendro vykdymo laiko palyginima su strategija 3 naudojant 100000 ir 1000000 dydžio failus galima rasti cia: https://github.com/Darj0/objektinis-2/blob/V1.1/README.md

Perdengti metodai

Ivesties:  
Studenta galima ivesti rankiniu budu (Metodo iskvietimo komandos: Studentas s; cin >> s; studentai.push_back(s);)  
Studento duomenis galima generuoti (Metodo iskvietimo komandos: Studentas s = Studentas::generuotiStudenta(); studentai.push_back(s);)   
Studento duomenis galima nuskaitti is failo(Metodo iskvietimo komandos: cin >> failoVardas;  studentai = Studentas::nuskaitytiIsFailo(failoVardas);)

Išvesties:  
Studenta galima isvesti i ekrana (Metodo iskvietimo komandos: for (const auto& s : studentai) {cout << s;})  
Studenta galima isvesti i faila (Metodo iskvietimo komandos: cin >> failoVardas; Studentas::rasytiIFaila(studentai, failoVardas);)


"Rule of three" metodu demonstravimas:  

![image](https://github.com/user-attachments/assets/2b5392ad-f5e1-402b-96a1-0bbf74718059)

![image](https://github.com/user-attachments/assets/50d75cec-7ce2-4387-ab47-6a15d212f38b)

![image](https://github.com/user-attachments/assets/6de501b2-836f-4930-9e28-2f4796cc1f9e)

![image](https://github.com/user-attachments/assets/52735c77-9a79-474c-9a9a-33926ba1560c)




