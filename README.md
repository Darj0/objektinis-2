Versijoje 1.1 duomenų tipas „struct“ pakeistas į „class“. Visos klasės „Studentas“ kintamieji ir duomenys yra privatūs. Šie kintamieji yra prieinami tik pačios klasės viduje ir negali būti tiesiogiai naudojami iš kodo, esančio už klasės ribų. Prieiga prie privačių klasės narių vykdoma per „setter“ ir „getter“ metodus. Pagrindu buvo paimti 1.0 versijos failai, o funkcijos pakoreguotos, kad naudotų privačius duomenis. Naudojimo, įdiegimo ir paleidimo instrukciją parengiau versijoje 1.0: https://github.com/Darj0/objektinis-programavimas/blob/V1.0/README.md

Atlikta 1.0 ir 1.1 versijų bendro vykdymo laiko palyginimas su strategija 3 naudojant 100000 ir 1000000 dydžio failus.

|     Versija     | konteineris |     Strategija    |   100000    |   1000000   |
|-----------------|-------------|-------------|-------------|-------------|
|     v1.0        | Std::Vector | 3| 0.778585 sek|  2.96613 sek  | 
|     v1.1        | Std::Vector   | 3 |  1.01583 sek| 10.7946 sek | 


Eksperimentinė analizė buvo atlikta priklausomai nuo kompiliatoriaus optimizavimo lygio, nurodyto naudojant 01, 02, 03 žymas programoje CodeBlocks.


|                    | -01  | -02  | -03  |
|--------------------|------|------|------|
| exe failo dydis v1.0 |   139 KB   |   139 KB   |   139 KB   |
| exe failo dydis v1.1 |  124 KB   |  124 KB    |   124 KB   |
| greitis 100000 v1.0  |   0.778585 sek    |  0.750486 sek    |    0.764 sek   |
| greitis 100000 v1.1  |   1.03555 sek   |  1.01113 sek    |    1.01323 sek   |
| greitis 1000000 v1.0 | 2.96613 sek     |   2.92903 sek   |    3.06559 sek   |
| greitis 1000000 v1.1 |   5.47798 sek    |   4.994 sek   |   6.0111 sek   |


