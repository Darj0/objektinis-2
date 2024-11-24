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

![image](https://github.com/user-attachments/assets/45c164d8-643d-4f48-a8c3-9a413c3e3a40)

![image](https://github.com/user-attachments/assets/e27784ac-3f0c-4e40-ba73-beeb6df928df)

![image](https://github.com/user-attachments/assets/0115155a-ade0-4fe1-b7a9-f3375443789b)

![image](https://github.com/user-attachments/assets/583228b4-d40e-4f98-b7b1-3b7df58cdf18)







