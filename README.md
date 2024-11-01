# objektinis-programavimas
Programa nuskaito studentu duomenis, skaiciuoja galutini ivertinima pagal pasirinkta metoda, rusioja studentus i 2 grupes atsizvelgiant i ju galutini ivertinima ir iraso juos i skirtingus failus.

Diegimo ir paleidimo proceso instrukcija:  
1. Atsisiuskyte zip faila
2. Sukurkyte direktorija su pavadinimu "Sort" ir idekite i ja atsiustus failus
3. Kad programa veiktu turi buti idiegta CMake (galite ja atsisiusti cia: https://cmake.org/download/)
4. Atidarykite direktorija "build" (yra tarp atsiustu failu), dešiniuoju pelės klavišu spauskite "Open in Terminal" arba paieskoj suraskite "Terminal" ir parasykite "cd path/to/your_project" (nurodykite kelia iki projekto direktorijos build)
5. Terminale komandineje eiluteje parasykite "cmake -G "MinGW Makefiles" .."
6. Terminale komandineje eiluteje parasykite "mingw32-make"
7. "build"direktorijoje atsirado "Sort.exe" failas, programa galite atidaryti paspausdus ant jo arba  Terminale komandineje eiluteje parasykite "./Sort.exe" (pirma karta paleisdami programa ir atlikdami analize reikia butinai generuoti naujus failus) 

Bendras veikimo laikas naudojant skirtingus konteinerius:


|   Strategija    | Konteineris |     1000    |    10000    |    100000    |   1000000   |   10000000  |
|-----------------|-------------|-------------|-------------|--------------|-------------|-------------|
|        1        | Std::Vector | 0 sek| 0 sek|  0.0221533 sek | 0.220326 sek | 9.08241 sekk |
|        1        | Std::List   | 0 sek | 0 sek| 0.0479485 sek | 0.299235 sek  |  25.4008 sek|
|        2        | Std::Vector |0 sek| 0 sekk|  0.0111158 sek | 0.0860013 sek | 1.02397 sek |
|        2        | Std::List   |0 sek |0 sek| 0.012883 sek |0.138116 sek  | 4.435 sek |
|        3        | Std::Vector |0 sek| 0 sekk|  0.0101177 sek |  0.0361211 sek | 3.984 sek |
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


