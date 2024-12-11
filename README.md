Naudojimosi instrukcija:

Pasirinkite ar norite ivesti studentus(spauskite 1), nuskaityti is failo(spauskite 2), stebeti failu nuskaitimo ir kurimo spartuma (spauskite 3), pmatyti 'Rule of Three' demonstracija (spauskite 4),  pamatyti bazines ir isvestines klasiu objektu kurima (spauskite 5), ar iseiti (spauskyte 0 ir programa bus nutraukta).
2.1 Paspausdus 1 pasirinkite norite naudoti list arba vector; pasirinkite kiek studentu norite ivesti; iveskite studenti varda, pavarde; toliau jeigu norite generuoti paztmius iveskite "g", jeigu zinote kiek pazimiu norite ivesti, iveskite "taip", jei dar nezinote - "ne". Toliau siekite programoje pateiktas pazimiu ivedimo instrukcijas; pasirinkite ar galutinio balo skaiciavimui norite naudoti vidurki ar mediana.

2.2 Paspausdus 2 reikes ivesti filo kuri norite nuskaityti kelia, arba jei jis guli toj pacioj direktorijoj - pavadinima. Pasirinkite ar galutinio balo skaiciavimui norite naudoti vidurki ar mediana.

2.3 Paspaudus 3 pasirinkite norite naudoti jau sukurtus failus, ar generuoti naujus (pirma karta paleidus programa butinai reikia generuoti failus, nes neturesit duomenu nuskaitimui); pasirinkite pagal koki parametra norite rusuoti studentus (pagal varda, pavarde ar galutini ivertinima); pasirinkite ar galutinio balo skaiciavimui norite naudoti vidurki ar mediana; pasirinkite norite naudoti vector ar list; pasirinkite viena is 3 strategiju.

2.4 Paspausdus 4 iveskyte studento duomenis rankiniu (1) budu arba sugeneruokyte (2) ir stebekyte rezultata.

2.5 Paspausdus 5 stebekyte objekto kurimo rezultata.



Diegimo ir paleidimo proceso instrukcija:

Atsisiuskyte zip faila
Sukurkyte direktorija su pavadinimu "Sort" ir idekite i ja atsiustus failus
Kad programa veiktu turi buti idiegta CMake (patikrinkite ar jau turite sia programa: paieskoj suraskite "Terminal" ir parasykite "cmake --version", jei programos neturite galite ja atsisiusti cia: https://cmake.org/download/ (windows); "brew install cmake" (macOS); "sudo apt-get install cmake" (Linux))
Atidarykite direktorija "build" (yra tarp atsiustu failu), dešiniuoju pelės klavišu spauskite "Open in Terminal" arba paieskoj suraskite "Terminal" ir parasykite "cd path/to/Sort/build" (nurodykite kelia iki projekto direktorijos build)
Terminalo komandineje eiluteje parasykite "cmake" arba jei idiegtas MinGW rasykite "cmake -G "MinGW Makefiles" .."
Terminalo komandineje eiluteje parasykite "make" arba "mingw32-make"
"build" direktorijoje atsiras "Sort.exe" failas. Programa galite paleisti paspausdus ant jo arba Terminalo komandineje eiluteje parasykite "./Sort.exe" (pirma karta paleisdami programa ir atlikdami analize reikia butinai generuoti naujus failus)
Releases:

Release v0.1: Programa nuskaito ivestu studentu (rankiniu budu arba nuskaito iš failo) duomenis ir skaiciuoja galutini ivertinima pagal pasirinkta metoda(nauduojant mediana arba vidurki)

Release v0.2: Programa papildomai gali generuoti atsitiktinius studentu failus, dalinti studentus i 2 grupes (kriu ivertinimas >=5 arba <5) ir issaugo i failus sugrupotus studentus. Taip pat atlikita programos veikimo greičio (spartos) analizę. (Daugiausiai laiko uztrunka duomenu nuskaitimas bei rusiavimas, maziausiai - studentu skirstymas i 2 grupes)

Release v0.3: Programa papildyta to kad galima pasirinkti nauduoti vektor ar list konteineri studentu saugojimui, atlikita programos veikimo greičio (spartos) analizę naudojant skirtingus konteinerius (Rezultatas: list konteineris efektivesnis, darbas su jo uzima maziau laiko, nes duomenis saugojimi atsitiktinai). Dabar galima matyti kiekvieno studento(objekto) saugojimo adresa atmintije.

Release v1.0: Programa papildyta strategijomis. Dalinti studentus i 2 grupes galima 3 strategijomis:
1 strategija: Bendro studentai konteinerio (vector ir list tipų) skaidymas į du naujus to paties tipo konteinerius: "vargšiukų" ir "kietiakų"
2 strategija: Bendro studentų konteinerio (vector ir list) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "vargšiukai"
3 strategija: Bendro studentų konteinerio skaidymas (rūšiavimas) panaudojant 2 strategiją įtraukiant į ją "efektyvius" darbo su konteineriais metodus (std::partition)
Taip pat atlikta panaudotos atminties analize kuri aprasyta zemiau (naudojant 2 arba 3 strategija panaudojama maziau vietos).
Pats efektiviausia strategija - 3 naudojant list.

Release v1.1: Programoje vietoj strukturos sukurta klase.(Issiaiskinta jog su klase programa veikia leciau).

Release v1.2: Programa papildyta, realizuoti visi reikiami "Rule of three" (distruktorius, kopijavimo konstruktorius bei priskirimo konstruktorius) ir įvesties/išvesties operatoriai. 

Release v1.5: Programa patobulinta. Sukurta abstrakti klase (bazine), Studento klase tavo jos isvestine.

Release v2.0: Sukurkite dokumentaciją panaudojant Doxygen. Dokumentacija pateikta HTML ir pdf pavydalu.
