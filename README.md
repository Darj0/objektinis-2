# objektinis-programavimas
Naudojimosi instrukcija:
1. Pasirinkite ar norite ivesti studentus(spauskite 1), nuskaityti is failo(spauskite 2)
ar stebeti failu nuskaitimo ir kurimo spartuma (spauskite 3).

2.1 Paspausdus 1 pasirinkite norite naudoti list arba vector; pasirinkite kiek studentu norite ivesti; iveskite studenti varda, pavarde; toliau jeigu norite generuoti paztmius iveskite "g", jeigu zinote kiek pazimiu norite ivesti, iveskite "taip", jei dar nezinote - "ne". Toliau siekite programoje pateiktas pazimiu ivedimo instrukcijas; pasirinkite ar galutinio balo skaiciavimui norite naudoti vidurki ar mediana.  

2.2 Paspausdus 2 reikes ivesti filo kuri norite nuskaityti kelia, arba jei jis guli toj pacioj direktorijoj - pavadinima. Pasirinkite ar galutinio balo skaiciavimui norite naudoti vidurki ar mediana.  

2.3 Paspaudus 3 pasirinkite norite naudoti jau sukurtus failus, ar generuoti naujus (pirma karta paleidus programa butinai reikia generuoti failus, nes neturesit duomenu nuskaitimui); pasirinkite pagal koki parametra norite rusuoti studentus (pagal varda, pavarde ar galutini ivertinima); pasirinkite ar galutinio balo skaiciavimui norite naudoti vidurki ar mediana; pasirinkite norite naudoti vector ar list; pasirinkite viena is 3 strategiju.  



Diegimo ir paleidimo proceso instrukcija:
1. Atsisiuskyte zip faila
2. Sukurkyte direktorija su pavadinimu "Sort" ir idekite i ja atsiustus failus
3. Kad programa veiktu turi buti idiegta CMake (patikrinkite ar jau turite sia programa: paieskoj suraskite "Terminal" ir parasykite "cmake --version", jei programos neturite galite ja atsisiusti cia: https://cmake.org/download/ (windows); "brew install cmake" (macOS); "sudo apt-get install cmake" (Linux))
4. Atidarykite direktorija "build" (yra tarp atsiustu failu), dešiniuoju pelės klavišu spauskite "Open in Terminal" arba paieskoj suraskite "Terminal" ir parasykite "cd path/to/Sort/build" (nurodykite kelia iki projekto direktorijos build)
5. Terminalo komandineje eiluteje parasykite "cmake" arba jei idiegtas MinGW rasykite "cmake -G "MinGW Makefiles" .."
6. Terminalo komandineje eiluteje parasykite "make" arba "mingw32-make"
7. "build" direktorijoje atsiras "Sort.exe" failas. Programa galite paleisti paspausdus ant jo arba Terminalo komandineje eiluteje parasykite "./Sort.exe" (pirma karta paleisdami programa ir atlikdami analize reikia butinai generuoti naujus failus)


Releases:

  
Release v0.1: Programa nuskaito ivestu studentu (rankiniu budu arba nuskaito iš failo) duomenis ir skaiciuoja galutini ivertinima pagal pasirinkta metoda(nauduojant mediana arba vidurki)  

Release v0.2: Programa papildomai gali generuoti atsitiktinius studentu failus, dalinti studentus i 2 grupes (kriu ivertinimas >=5 arba <5) ir issaugo i failus sugrupotus studentus. Taip pat atlikita programos veikimo greičio (spartos) analizę. (Daugiausiai laiko uztrunka duomenu nuskaitimas bei rusiavimas, maziausiai - studentu skirstymas i 2 grupes) 

Release v0.3: Programa papildyta to kad galima pasirinkti nauduoti vektor ar list konteineri studentu saugojimui, atlikita programos veikimo greičio (spartos) analizę naudojant skirtingus konteinerius (Rezultatas: list konteineris efektivesnis, darbas su jo uzima maziau laiko, nes duomenis saugojimi atsitiktinai). Dabar galima matyti kiekvieno studento(objekto) saugojimo adresa atmintije.  

Release v1.0: Programa papildyta strategijomis. Dalinti studentus i 2 grupes galima 3 strategijomis:  
1 strategija: Bendro studentai konteinerio (vector ir list tipų) skaidymas į du naujus to paties tipo konteinerius: "vargšiukų" ir "kietiakų"  
2 strategija: Bendro studentų konteinerio (vector ir list) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "vargšiukai"  
3 strategija: Bendro studentų konteinerio skaidymas (rūšiavimas) panaudojant  2 strategiją  įtraukiant į ją "efektyvius" darbo su konteineriais metodus (std::partition)  
Taip pat atlikta panaudotos atminties analize kuri aprasyta zemiau (naudojant 2 arba 3 strategija panaudojama maziau vietos).     
Pats efektiviausia strategija - 3 naudojant list.  


Studentu rūšiavimo i dvi kategorijas laikas naudojant skirtingus konteinerius ir strategijas:


|   Strategija    | Konteineris |     1000    |    10000    |    100000    |   1000000   |   10000000  |
|-----------------|-------------|-------------|-------------|--------------|-------------|-------------|
|        1        | Std::Vector | 0 sek| 0 sek|  0.0221533 sek | 0.220326 sek | 9.08241 sek |
|        1        | Std::List   | 0 sek | 0 sek| 0.0479485 sek | 0.299235 sek  |  25.4008 sek|
|        2        | Std::Vector |0 sek| 0 sek|  0.0111158 sek | 0.0860013 sek | 1.02397 sek |
|        2        | Std::List   |0 sek |0 sek| 0.012883 sek |0.138116 sek  | 4.435 sek |
|        3        | Std::Vector |0 sek| 0 sek|  0.0101177 sek |  0.0361211 sek | 3.984 sek |
|        3        | Std::List   |0 sek | 0 sek| 0.0059966 sek |0.161987 sek | 2.15097 sek |


Failas is 1000 duomenu, atminties panauduojimas:

|   Strategija    | Konteineris |Memory used by studentai|Memory used by vargsiuka|Memory used by kietiakiai|
|-----------------|-------------|-------------|-------------|--------------|
|        1        | Std::Vector | 139264 bytes| 69632 bytes|  139264 bytes| 
|        1        | Std::List   | 151848 bytes | 60648 bytes| 91200 bytes |
|        2        | Std::Vector |0 bytes| 69632 bytes| 139264 bytes | 
|        2        | Std::List   |0 bytes|60648 bytes| 91200 bytes |
|        3        | Std::Vector |0 bytes| 54264 bytes|  81600 bytes |
|        3        | Std::List   |0 bytes |60648 bytes| 91200 bytes|



Failas is 10000 duomenu, atminties panauduojimas:

|   Strategija    | Konteineris |Memory used by studentai|Memory used by vargsiuka|Memory used by kietiakiai|
|-----------------|-------------|-------------|-------------|--------------|
|        1        | Std::Vector | 2228224 bytes|557056 bytes|  1114112 bytes| 
|        1        | Std::List   |1519848 bytes |60648 bytes|  91200 bytes |
|        2        | Std::Vector |0 bytes| 557056 bytes|  2228224 bytes | 
|        2        | Std::List   |0 bytes | 610128 bytes|  909720 bytesk |
|        3        | Std::Vector |0 bytes| 545904 bytes| 813960 bytes |
|        3        | Std::List   |0 bytes |610128 bytes| 909720 bytes |


Failas is 100000 duomenu, atminties panauduojimas:

|   Strategija    | Konteineris |Memory used by studentai|Memory used by vargsiuka|Memory used by kietiakiai|
|-----------------|-------------|-------------|-------------|--------------|
|        1        | Std::Vector | 17825792 bytes|8912896 bytes|8912896 bytes| 
|        1        | Std::List   |1519848 bytes |6114808 bytes|  9085040 bytes |
|        2        | Std::Vector |0 bytes|  8912896 bytes| 17825792 bytes | 
|        2        | Std::List   |0 bytes |6114808 bytes|  9085040 bytes |
|        3        | Std::Vector |0 bytes|  5471144 bytes|  8128720 bytes |
|        3        | Std::List   |0 bytes |6114808 bytes|  9085040 bytes |



Failas is 1000000 duomenu, atminties panauduojimas:

|   Strategija    | Konteineris |Memory used by studentai|Memory used by vargsiuka|Memory used by kietiakiai|
|-----------------|-------------|-------------|-------------|--------------|
|        1        | Std::Vector |142606336 bytes|71303168 bytes|71303168 bytes| 
|        1        | Std::List   | 123394208 bytes | 49351208 bytesk| 74043000 bytes |
|        2        | Std::Vector |0 bytes| 71303168 bytes|  142606336 bytes | 
|        2        | Std::List   |0 bytes |49351208 bytes|  74043000 bytes |
|        3        | Std::Vector |0 bytes|  44156344 bytesk| 66249000 bytes |
|        3        | Std::List   |0 bytes |49351208 bytes| 74043000 bytes |


Failas is 10000000 duomenu, atminties panauduojimas:

|   Strategija    | Konteineris |Memory used by studentai|Memory used by vargsiuka|Memory used by kietiakiai|
|-----------------|-------------|-------------|-------------|--------------|
|        1        | Std::Vector |2281701376 bytes|570425344 bytes|1140850688 bytes| 
|        1        | Std::List   |1519999848 bytes | 607937984 bytes|  912061864 bytes |
|        2        | Std::Vector |0 bytes| 570425344 bytes|   2281701376 bytes | 
|        2        | Std::List   |0 bytes | 607937984 bytes|  912061864 bytes |
|        3        | Std::Vector |0 bytes| 543944512 bytes|  816055352 bytes |
|        3        | Std::List   |0 bytes |607937984 bytes| 912061864 bytes |


Testavimo sistemos parametrai:  
CPU Info:  
Name: Apple silicon  
Serdziu skaicius (NumberOfCores): 2  
Loginiu procesoriu skaicius (NumberOfLogicalProcessors): 2  
Taktine daznis (GHz) (CurrentClockSpeed): 2  

RAM Info:  
Capacity  
4294967296 (4,091 MB)  

Disk Info (SSD):
MediaType: Fixed hard disk media  
Model: VMware Virtual NVMe Disk  


<img src="https://github.com/user-attachments/assets/5f020520-7fa4-4e14-818b-8bcff8c407ea" alt="image" width="300"/>

