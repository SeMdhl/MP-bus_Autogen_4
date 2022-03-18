#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <chrono>
#include "mdhl_Tools.h"
#include "mdhl_Mp_v4.h"






std::string sFilPath, sPath2;      //Adresse til mappe hvor exe fil er lagret
std::string sSource;     //Variabel som velger filnavn på fil som skal leses
std::string sInput[200];        //Input verdier, hver linje i hver variabel i arrayet
bool bUsed[200];       //Viser om Inputen faktisk er brukt, eller om det er tomt. For å ungå å ta inn tomme linjer
std::string sInfo = "STLV80_563\tSTLV80_A_563_";
std::string sGVL = "STLV80_360"; //ønsket navn på GVL
std::string sAdresseFormat = "STLV80_A_360_";
int iNavnFormatInn = 1;
std::string sNavnFormat = "";
std::string sVAV[200];      //Navn på vaver
std::string sPort[200];     //Porten/linjen på VAV-en
std::string sAdresse[200];      //Adressen til VAV-en
std::string sSerieNrYW[200];       //Første verdien som skal i serieNr arrayet
std::string sSerieNrDN[200];        //Andre verdien som skal i serieNr arrayet
std::string sSerieNrTID[200];       //Tredje verdien som skal i serieNr arrayet
std::string sSerieNrTS[200];        //Fjerde verdien som skal i serieNr arrayet
std::string sMin[200];       //Første verdien som skal i serieNr arrayet
std::string sNorm[200];        //Andre verdien som skal i serieNr arrayet
std::string sMax[200];       //Tredje verdien som skal i serieNr arrayet
std::string sSize[200];        //Fjerde verdien som skal i serieNr arrayet


void OpenFile()
{
    //sSource = "1.txt";        //Variabel som velger filnavn på fil som skal leses
    std::cout << "Filnavn: ";      //Spør etter filnavn
    std::cin >> sSource;       //Tar inn filnavn og lagrer på sSource

    sFilPath = (sPath2 + sSource);       //Den fulle adressen til filen som skal leses fra
    std::cout << sFilPath << "\n";                   //test


    std::ifstream fInput(sFilPath + ".txt");      //Åpner fil som skal leses fra

     //fInput.open(sFilPath);        //test
    if (fInput.is_open() == false)       //Sjekker om filen ble åpnet
    {
        std::cout << "Cant open file\n\tHusk Ikke run program i 'rare' mapper (mtp. adresse)\n";     //Melder ifra om feil hvis fil ikke ble åpnet
        //Sleep(10000);
        OpenFile();
        return;
    }

    fInput.close();

    std::cout << "File found\n";
    /*std::cout << "Skriv inn GVL navn\n\teksempel: STLV80_360\n\tGVL navn: ";      //Spør etter GVL navn eks. STLV80_360
    std::cin >> sGVL;       //Tar inn GVL Navn
    std::cout << "Skriv inn adresseformat\n\teksempel: STLV80_A_360_[VAV]\t IKKE ta med VAV\n\tAdresseformat: ";      //Spør etter adresse format eks. STLV80_563.STLV80_A_563_
    std::cin >> sAdresseFormat;*/      //Tar inn adresseformat 
    std::cout << "\nVAV Navnformat (Input)?\n\tType 1: 360.3A301-SQ401\n\tType 2: 360.3A301.SQ401\n\tType 3: 360-3A301-SQ401\n\tType 4: 360_3A301_SQ401\n\tType 5: 3A301.SQ401\n\tType 6: 3A301-SQ401\n\tType 7: 3A301_SQ401\n\n1-7: ";        //Spør etter navn inn format eks. 3A301.SQ501
    std::cin >> iNavnFormatInn;       //Tar inn navnformat  
    //Sleep(2000);
}
void Read() //Spør etter navn på fil som skal leses, og leser deretter inn hver linje og lagrer dem i egne variabler.
{
    std::ifstream fInput(sFilPath + ".txt");      //Åpner fil som skal leses fra

    getline(fInput, sInfo);     //Leser inn første linje hvor info skal være

    for (int i = 0; i < 200; i++)        //Går gjennom hver variabel i arrayet
    {
        int j = (i - 1);        //Variabel for å sjekke om forgje linje er lik neste (isåfall avsluttes lese delen av programmet)
        getline(fInput, sInput[i]);     //Leser inn en linje og lagrer den i sInput[for loop var]
        if (sInput[i] == sInput[j] || sInput[i] == "")      //Sjekker om linje er lik den forgje, bryter isåfall ut av loopen og avslutter lese delen av programmet
        {
            bUsed[i] = false;
            break;
        }
        else
            bUsed[i] = true;        //markerer Input som brukt (for å ungå å prossesere og skrive ut mer verdier enn vi trenger)
    }
    fInput.close();     //Lukker fil som vi leste fra

}

void Prossesering() //Bruker Input variablene og deler dem opp i sepparate variabler for ventil navn og serie nr. Bytter også + til -
{
    size_t pos;
    int iSize = 0;

    for (int i = 0; i < 2; i++)
    {
        while (sInfo.substr(0, 1) == " " || sInfo.substr(0, 1) == "\t")        //Fjerner evt. mellomrom/tabs som er før verdiene
        {
            iSize = ((sInfo.size()) - 1);
            sInfo = (sInfo.substr(1, iSize));
        }

        if (sInfo.find(" ") < sInfo.find("\t"))
            pos = sInfo.find(" ");
        else
            pos = sInfo.find("\t");
        if (i == 0)
        {
            iSize = ((sInfo.size()) - pos - 1);     //Bestemmer størelsen på stringet vi lagrer verdien i (posisjon på understrek - 1(understreken))
            sGVL = (sInfo.substr(0, pos));       //Lagrer verdi i Tilhørende variabel
            sInfo = sInfo.substr(pos + 1, iSize);       //Fjerner verdien fra input variabelen
        }
        else
        {
            iSize = ((sInfo.size()) - pos - 1);     //Bestemmer størelsen på stringet vi lagrer verdien i (posisjon på understrek - 1(understreken))
            sAdresseFormat = (sInfo.substr(0, pos));       //Lagrer verdi i Tilhørende variabel
            sInfo = sInfo.substr(pos + 1, iSize);       //Fjerner verdien fra input variabelen
        }
    }


    for (int i = 0; i < 200; i++)      //Går igjennom alle variabler
    {
        if (bUsed[i])       //Bryter ut av loop hvis variabelen ikke er bruke
        {
            iSize = 0;


            for (int j = 0; j < 3; j++)      //Går gjennom og deler opp etter Navn, Port, Adresse
            {
                while (sInput[i].substr(0, 1) == "\t")        //Fjerner evt. mellomrom/tabs som er før verdiene
                {
                    iSize = ((sInput[i].size()) - 1);
                    sInput[i] = (sInput[i].substr(1, iSize));
                }

                pos = sInput[i].find("\t");      //Finner neste mellomrom
                if (pos < 1)        //Melder om feil og avbryter hvis mellomrom(før verdier) ikke ble fjernet
                {
                    std::cout << "\n\nError: line 80.\n\n";
                    abort();
                }
                else
                {
                    pos = sInput[i].find("\t");     //Finner neste tab. posisjonen i std::stringet hvor verdien vi leser inn ender
                    iSize = ((sInput[i].size()) - pos - 1);     //Bestemmer størelsen på std::stringet vi lagrer verdien i (posisjon på mellomrom - 1(mellomromet))
                    switch (j)
                    {
                    case 0:     //Første verdi (Navn)

                        sVAV[i] = IO_Format(sInput[i], sAdresseFormat, iNavnFormatInn).VAV;
                        sInput[i] = IO_Format(sInput[i], sAdresseFormat, iNavnFormatInn).Input;
                        break;

                    case 1:     //Andre verdi (Port)

                        sPort[i] = (sInput[i].substr(0, pos));      //Lagrer verdi i Tilhørende variabel
                        sInput[i] = sInput[i].substr(pos + 1, iSize);       //Fjerner verdien fra input variabelen
                        break;

                    case 2:     //Tredje verdi (Adresse)

                        sAdresse[i] = (sInput[i].substr(0, pos));       //Lagrer verdi i Tilhørende variabel
                        sInput[i] = sInput[i].substr(pos + 1, iSize);       //Fjerner verdien fra input variabelen
                        break;

                    default:
                        break;
                    }
                }

            }


            for (int j = 0; j < 8; j++)     //Går gjennom serie nr. og deler den opp i 4 variabler
            {
                while (sInput[i].substr(0, 1) == " " || sInput[i].substr(0, 1) == "\t" || sInput[i].substr(0, 1) == "+")        //fjerner evt. mellomrom/tabs/+ som er før selve verdien
                {
                    iSize = ((sInput[i].size()) - 1);
                    sInput[i] = (sInput[i].substr(1, iSize) == " ");
                }



                switch (j)
                {
                case 0:     //Første verdi (Year and Week)
                    if (sInput[i].find("+") < sInput[i].find("-"))//Finner neste + (enden av verdien)
                        pos = sInput[i].find("+");
                    else
                        pos = sInput[i].find("-");

                    iSize = ((sInput[i].size()) - pos - 1);     //Bestemmer størelsen på std::stringet verdien skal lagres i
                    sSerieNrYW[i] = (sInput[i].substr(0, pos));     //Lagrer verdien i rett variabel
                    sInput[i] = sInput[i].substr(pos + 1, iSize);       //Fjerner verdi vra input variabel
                    break;

                case 1:     //Andre verdi (Day and Number)
                    if (sInput[i].find("+") < sInput[i].find("-"))//Finner neste + (enden av verdien)
                        pos = sInput[i].find("+");
                    else
                        pos = sInput[i].find("-");

                    iSize = ((sInput[i].size()) - pos - 1);     //Bestemmer størelsen på std::stringet verdien skal lagres i
                    sSerieNrDN[i] = (sInput[i].substr(0, pos));     //Lagrer verdien i rett variabel
                    sInput[i] = sInput[i].substr(pos + 1, iSize);       //Fjerner verdi vra input variabel
                    break;

                case 2:     //Tredje verdi (Type ID)
                    if (sInput[i].find("+") < sInput[i].find("-"))//Finner neste + (enden av verdien)
                        pos = sInput[i].find("+");
                    else
                        pos = sInput[i].find("-");

                    iSize = ((sInput[i].size()) - pos - 1);     //Bestemmer størelsen på std::stringet verdien skal lagres i
                    sSerieNrTID[i] = (sInput[i].substr(0, pos));        //Lagrer verdien i rett variabel
                    sInput[i] = sInput[i].substr(pos + 1, iSize);       //Fjerner verdi vra input variabel
                    break;

                case 3:     //Fjerde verdi (Test station)
                    pos = sInput[i].find("\t");
                    iSize = (sInput[i].size()) - pos - 1;     //Bestemmer størelsen på std::stringet verdien skal lagres i (Input variabel inneholder nå kun den fjerde verdien, trenger derfor ikke å lete etter +)
                    sSerieNrTS[i] = (sInput[i].substr(0, pos));       //Lagrer verdien i rett variabel
                    sInput[i] = sInput[i].substr(pos + 1, iSize);     //Fjerner resten av info lagret i variabel
                    break;

                case 4:     //Fjerde verdi (Min)

                    pos = sInput[i].find("\t");
                    iSize = (sInput[i].size()) - pos - 1;
                    sMin[i] = (sInput[i].substr(0, pos));       //Lagrer verdi i Tilhørende variabel
                    sInput[i] = sInput[i].substr(pos + 1, iSize);       //Fjerner verdien fra input variabelen
                    break;

                case 5:     //Femte verdi (Norm)

                    pos = sInput[i].find("\t");
                    iSize = (sInput[i].size()) - pos - 1;
                    sNorm[i] = (sInput[i].substr(0, pos));       //Lagrer verdi i Tilhørende variabel
                    sInput[i] = sInput[i].substr(pos + 1, iSize);       //Fjerner verdien fra input variabelen
                    break;

                case 6:     //Syvende verdi (Size)

                    pos = sInput[i].find("\t");
                    iSize = (sInput[i].size()) - pos - 1;
                    sMax[i] = (sInput[i].substr(0, pos));       //Lagrer verdi i Tilhørende variabel
                    sInput[i] = sInput[i].substr(pos + 1, iSize);       //Fjerner verdien fra input variabelen
                    break;

                case 7:     //Tredje verdi (Adresse)
                    sSize[i] = sInput[i];       //Lagrer verdi i Tilhørende variabel
                    sInput[i] = "";       //Fjerner verdien fra input variabelen
                    break;

                default:
                    break;

                }

            }
            //Skriver ut navn i console slik at du kan se feil før du går til txt fil
            std::cout << "\n\t" << sVAV[i] << "\t" << sPort[i] << "\t" << sAdresse[i] << "\n\t"
                << sSerieNrYW[i] << "\t" << sSerieNrDN[i] << "\t" << sSerieNrTID[i] << "\t" << sSerieNrTS[i] << "\n\t"
                << sMin[i] << "\t" << sNorm[i] << "\t" << sMax[i] << "\t" << sSize[i] << "\n\n";
        }
        else
            break;
    }
}



int main() //Starter med å lokalisere seg selv, og får derfor sin egen plassering som brukes i Read og Write.
{
    WCHAR wcPath[MAX_PATH];     //Lager Path variabel
    GetModuleFileNameW(NULL, wcPath, MAX_PATH);     //Lagrer sin egen lokasjon i path variabelen
    std::wstring wsPath(&wcPath[0]);     //convert to wstd::string
    std::string sPath(wsPath.begin(), wsPath.end());     //convert to std::string.
    size_t pos = sPath.find("VAV_Adressering_4.exe");     //Lokaliserer hvor i pathen selve exe filen er
    sPath2 = sPath.substr(0, pos);      //Lager en ny variabel hvor det lagres en ny variabel hvor det lagres lokasjonen til mappen som exe filen er lagret i (path - exe fil)
    //std::cout << sPath2 << "\n";       test

    OpenFile();

    auto tStart = std::chrono::high_resolution_clock::now();

    Read();
    Prossesering();
    WriteXML_MP(sGVL, sVAV, bUsed,
        sPort, sAdresse, sSerieNrYW, sSerieNrDN, sSerieNrTID, sSerieNrTS,
        sMin, sNorm, sMax, sSize,
        sAdresseFormat);

    auto tStopp = std::chrono::high_resolution_clock::now();
    auto tRuntime = std::chrono::duration_cast<std::chrono::milliseconds>(tStopp - tStart);

    std::ifstream inFile(sPath2 + "/AutGenImport.xml");

    std::cout << "Done" << std::endl << "Generated " << std::count(std::istreambuf_iterator<char>(inFile), std::istreambuf_iterator<char>(), '\n') << " lines in " << tRuntime.count() << " milliseconds" << std::endl;

    Sleep(30000);

    return 0;
}