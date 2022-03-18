#pragma once
#ifndef mdhl_Mp
#define mdhl_Mp
#include <iostream>
#include <fstream>
#include <windows.h>
#include "mdhl_Tools.h"
#include "mdhl_MP_Items.h"


struct O_Format
{
    std::string VAV;
    std::string Input;
};





O_Format IO_Format(std::string sInput, std::string sAdresseFormat, int iNavnFormatInn)
{
    size_t pos;
    int iSize = 0;
    std::string sVAV = "test";

    switch (iNavnFormatInn)
    {
    case 1:     // Type 1: 563.3A301-SQ401

        pos = sInput.find(".");     //Finner neste punktum. posisjonen i stringet hvor verdien vi leser inn ender
        iSize = ((sInput.size()) - pos - 1);     //Bestemmer størelsen det vi sletter fra stringet (posisjon på punktum - 1(punktumet))
        sInput = sInput.substr(pos + 1, iSize);       //Fjerner verdien fra input variabelen

        pos = sInput.find("-");     //Finner neste bindestrek posisjonen i stringet hvor verdien vi leser inn ender
        iSize = ((sInput.size()) - pos - 1);     //Bestemmer størelsen på stringet vi lagrer verdien i (posisjon på bindestreken - 1(bindestreken))
        sVAV = (sInput.substr(0, pos));       //Lagrer verdi i Tilhørende variabel
        sInput = sInput.substr(pos + 1, iSize);       //Fjerner verdien fra input variabelen

        pos = sInput.find("\t");     //Finner neste tab. posisjonen i stringet hvor verdien vi leser inn ender
        iSize = ((sInput.size()) - pos - 1);     //Bestemmer størelsen på stringet vi lagrer verdien i (posisjon på mellomrom - 1(mellomromet))

        sVAV += ("_" + (sInput.substr(0, pos)));       //Type 3: 3A301_SQ501

        sInput = sInput.substr(pos + 1, iSize);       //Fjerner verdien fra input variabelen
        break;


    case 2:     //Type 2: 563.3A301.SQ401

        pos = sInput.find(".");     //Finner neste punktum. posisjonen i stringet hvor verdien vi leser inn ender
        iSize = ((sInput.size()) - pos - 1);     //Bestemmer størelsen det vi sletter fra stringet (posisjon på punktum - 1(punktumet))
        sInput = sInput.substr(pos + 1, iSize);       //Fjerner verdien fra input variabelen

        pos = sInput.find(".");     //Finner neste Punktum posisjonen i stringet hvor verdien vi leser inn ender
        iSize = ((sInput.size()) - pos - 1);     //Bestemmer størelsen på stringet vi lagrer verdien i (posisjon på Punktum - 1(Punktumet))
        sVAV = (sInput.substr(0, pos));       //Lagrer verdi i Tilhørende variabel
        sInput = sInput.substr(pos + 1, iSize);       //Fjerner verdien fra input variabelen

        pos = sInput.find("\t");     //Finner neste tab. posisjonen i stringet hvor verdien vi leser inn ender
        iSize = ((sInput.size()) - pos - 1);     //Bestemmer størelsen på stringet vi lagrer verdien i (posisjon på mellomrom - 1(mellomromet))

        sVAV += ("_" + (sInput.substr(0, pos)));       //Type 3: 3A301_SQ501

        sInput = sInput.substr(pos + 1, iSize);       //Fjerner verdien fra input variabelen
        break;

    case 3:     //Type 3: 563-3A301-SQ401

        pos = sInput.find("-");     //Finner neste punktum. posisjonen i stringet hvor verdien vi leser inn ender
        iSize = ((sInput.size()) - pos - 1);     //Bestemmer størelsen det vi sletter fra stringet (posisjon på punktum - 1(punktumet))
        sInput = sInput.substr(pos + 1, iSize);       //Fjerner verdien fra input variabelen

        pos = sInput.find("-");     //Finner neste bindestrek posisjonen i stringet hvor verdien vi leser inn ender
        iSize = ((sInput.size()) - pos - 1);     //Bestemmer størelsen på stringet vi lagrer verdien i (posisjon på bindestreken - 1(bindestreken))
        sVAV = (sInput.substr(0, pos));       //Lagrer verdi i Tilhørende variabel
        sInput = sInput.substr(pos + 1, iSize);       //Fjerner verdien fra input variabelen

        pos = sInput.find("\t");     //Finner neste tab. posisjonen i stringet hvor verdien vi leser inn ender
        iSize = ((sInput.size()) - pos - 1);     //Bestemmer størelsen på stringet vi lagrer verdien i (posisjon på mellomrom - 1(mellomromet))

        sVAV += ("_" + (sInput.substr(0, pos)));       //Type 3: 3A301_SQ501

        sInput = sInput.substr(pos + 1, iSize);       //Fjerner verdien fra input variabelen
        break;

    case 4:     //Type 4: 563_3A301_SQ401

        pos = sInput.find("_");     //Finner neste understrek. posisjonen i stringet hvor verdien vi leser inn ender
        iSize = ((sInput.size()) - pos - 1);     //Bestemmer størelsen det vi sletter fra stringet (posisjon på understrek - 1(understrek))
        sInput = sInput.substr(pos + 1, iSize);       //Fjerner verdien fra input variabelen

        pos = sInput.find("_");     //Finner neste understrek posisjonen i stringet hvor verdien vi leser inn ender
        iSize = ((sInput.size()) - pos - 1);     //Bestemmer størelsen på stringet vi lagrer verdien i (posisjon på understrek - 1(understreken))
        sVAV = (sInput.substr(0, pos));       //Lagrer verdi i Tilhørende variabel
        sInput = sInput.substr(pos + 1, iSize);       //Fjerner verdien fra input variabelen

        pos = sInput.find("\t");     //Finner neste tab. posisjonen i stringet hvor verdien vi leser inn ender
        iSize = ((sInput.size()) - pos - 1);     //Bestemmer størelsen på stringet vi lagrer verdien i (posisjon på mellomrom - 1(mellomromet))

        sVAV += ("_" + (sInput.substr(0, pos)));       //Type 3: 3A301_SQ501

        sInput = sInput.substr(pos + 1, iSize);       //Fjerner verdien fra input variabelen
        break;

    case 5:     //Type 5: 3A301.SQ401

        pos = sInput.find(".");     //Finner neste Punktum posisjonen i stringet hvor verdien vi leser inn ender
        iSize = ((sInput.size()) - pos - 1);     //Bestemmer størelsen på stringet vi lagrer verdien i (posisjon på Punktum - 1(Punktumet))
        sVAV = (sInput.substr(0, pos));       //Lagrer verdi i Tilhørende variabel
        sInput = sInput.substr(pos + 1, iSize);       //Fjerner verdien fra input variabelen

        pos = sInput.find("\t");     //Finner neste tab. posisjonen i stringet hvor verdien vi leser inn ender
        iSize = ((sInput.size()) - pos - 1);     //Bestemmer størelsen på stringet vi lagrer verdien i (posisjon på mellomrom - 1(mellomromet))

        sVAV += ("_" + (sInput.substr(0, pos)));       //Type 3: 3A301_SQ501

        sInput = sInput.substr(pos + 1, iSize);       //Fjerner verdien fra input variabelen
        break;

    case 6:     //Type 6: 3A301-SQ401

        pos = sInput.find("-");     //Finner neste bindestrek posisjonen i stringet hvor verdien vi leser inn ender
        iSize = ((sInput.size()) - pos - 1);     //Bestemmer størelsen på stringet vi lagrer verdien i (posisjon på bindestreken - 1(bindestreken))
        sVAV = (sInput.substr(0, pos));       //Lagrer verdi i Tilhørende variabel
        sInput = sInput.substr(pos + 1, iSize);       //Fjerner verdien fra input variabelen

        pos = sInput.find("\t");     //Finner neste tab. posisjonen i stringet hvor verdien vi leser inn ender
        iSize = ((sInput.size()) - pos - 1);     //Bestemmer størelsen på stringet vi lagrer verdien i (posisjon på mellomrom - 1(mellomromet))

        sVAV += ("_" + (sInput.substr(0, pos)));       //Type 3: 3A301_SQ501

        sInput = sInput.substr(pos + 1, iSize);       //Fjerner verdien fra input variabelen
        break;

    case 7:     //Type 7: 3A301_SQ401

        pos = sInput.find("_");     //Finner neste Understrek posisjonen i stringet hvor verdien vi leser inn ender
        iSize = ((sInput.size()) - pos - 1);     //Bestemmer størelsen på stringet vi lagrer verdien i (posisjon på Understrek - 1(Understreken))
        sVAV = (sInput.substr(0, pos));       //Lagrer verdi i Tilhørende variabel
        sInput = sInput.substr(pos + 1, iSize);       //Fjerner verdien fra input variabelen

        pos = sInput.find("\t");     //Finner neste tab. posisjonen i stringet hvor verdien vi leser inn ender
        iSize = ((sInput.size()) - pos - 1);     //Bestemmer størelsen på stringet vi lagrer verdien i (posisjon på mellomrom - 1(mellomromet))

        sVAV += ("_" + (sInput.substr(0, pos)));       //Type 3: 3A301_SQ501

        sInput = sInput.substr(pos + 1, iSize);       //Fjerner verdien fra input variabelen
        break;

    default:
        std::cout << "ERROR: Navneformat (" << iNavnFormatInn << ") out of range (1-7)" << std::endl;
        Sleep(10000);
        abort();
    }
    O_Format Out = { (sAdresseFormat +"_" + sVAV), sInput };
    return Out;
}







void WriteXML_MP(std::string sGVL, std::string VAV[200], bool bUsed[200],
    std::string Port[200], std::string adr[200],
    std::string SN1[200], std::string SN2[200], std::string SN3[200], std::string SN4[200],
    std::string sMin[200], std::string sNorm[200], std::string sMax[200], std::string sSize[200],
    std::string &sAdresseFormat)
{

    WCHAR wcPath[MAX_PATH];     //Lager Path variabel
    GetModuleFileNameW(NULL, wcPath, MAX_PATH);     //Lagrer sin egen lokasjon i path variabelen
    std::wstring wsPath(&wcPath[0]);     //convert to wstring
    std::string sPath(wsPath.begin(), wsPath.end());     //convert to string.
    size_t pos = sPath.find("VAV_Adressering_4.exe");     //Lokaliserer hvor i pathen selve exe filen er
    sPath = sPath.substr(0, pos);      //Lager en ny variabel hvor det lagres en ny variabel hvor det lagres lokasjonen til mappen som exe filen er lagret i (path - exe fil)
    sPath = sPath + "AutGenImport.xml";

    //Kopierer adressen til XML filen
    const char* output = sPath.c_str();
    const size_t len = strlen(output) + 1;
    HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);
    memcpy(GlobalLock(hMem), output, len);
    GlobalUnlock(hMem);
    OpenClipboard(0);
    EmptyClipboard();
    SetClipboardData(CF_TEXT, hMem);
    CloseClipboard();

    //Lager xml filen
    std::ofstream fOutput(sPath);

    if (fOutput.is_open() == false)
    {
        std::cout << "Fatal error: cant open outputfile.\nLine: 186";
        Sleep(10000);
        abort();
    }

    fOutput << "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n";
    fOutput << "<project xmlns=\"http://www.plcopen.org/xml/tc6_0200\">\n\t";
    fOutput << "<fileHeader companyName=\"WAGO\" productName=\"e!COCKPIT\" productVersion=\"e!COCKPIT\" creationDateTime=\"2021-01-18T14:20:23.2110188\" />\n\t";
    fOutput << "<contentHeader name=\"Adressering.ecp\" modificationDateTime=\"2021-01-18T11:51:27.6823754\">\n\t\t";
    fOutput << "<coordinateInfo>\n" + Tabs(3);
    fOutput << "<fbd>\n" + Tabs(4);
    fOutput << "<scaling x = \"1\" y = \"1\" />\n" + Tabs(3);
    fOutput << "</fbd>\n" + Tabs(3);
    fOutput << "<ld>\n" + Tabs(4);
    fOutput << "<scaling x = \"1\" y = \"1\" />\n" + Tabs(3);
    fOutput << "</ld>\n" + Tabs(3);
    fOutput << "<sfc>\n" + Tabs(4);
    fOutput << "<scaling x=\"1\" y=\"1\" />\n" + Tabs(3);
    fOutput << "</sfc>\n\t\t";
    fOutput << "</coordinateInfo>\n\t\t";
    fOutput << "<addData>\n" + Tabs(3);
    fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/projectinformation\" handleUnknown=\"implementation\">\n" + Tabs(4);
    fOutput << "<ProjectInformation />\n" + Tabs(3);
    fOutput << "</data>\n\t\t";
    fOutput << "</addData>\n\t";
    fOutput << "</contentHeader>\n\t";
    fOutput << "<types>\n\t\t";
    
    fOutput << "<dataTypes >\n\t\t";
    fOutput << "<dataType name=\"typVAV\">\n" + Tabs(3);
    fOutput << "<baseType>\n" + Tabs(4);
    fOutput << "<struct>\n" + Tabs(5);
    //DTU
    fOutput << "<variable name=\"xReady\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<BOOL/>\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(6);
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Status adr.</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput << "<variable name=\"xEnable\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<BOOL/>\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(6);
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Enable MP blokk</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput << "<variable name=\"xAddress\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<BOOL/>\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(6);
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Adresserer VAV</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput << "<variable name=\"xFailed\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<BOOL/>\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(6);
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Tilbakemelding adressering (True = SerieNr inn og ut ikke stemmer)</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput << "<variable name=\"sSetStatus\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<string />\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(6);
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Status tilbakemelding naar adresseringen er i SET step</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>" << std::endl << Tabs(5);

    fOutput << "<variable name=\"sGetStatus\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<string />\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(6);
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Status tilbakemelding naar adresseringen er i GET step</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput << "<variable name=\"iSerialNr\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<derived name=\"typSerialNo\" />\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(6);
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Serie NR</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput << "<variable name=\"bPort\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<BYTE />\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(6);
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">VAV Port</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput << "<variable name=\"bAddress\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<BYTE />\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(6);
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">VAV Address</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput << "<variable name=\"rAirVolume_SP\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<REAL />\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(6);
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Settpunkt 0-100%</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput << "<variable name=\"rOutPosition\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<REAL />\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(6);
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Vinkel</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput << "<variable name=\"rOutAirVolume_perc\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<REAL />\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(6);
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Luftmengde i prosent</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput << "<variable name=\"rOutAirVolume_m3h\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<REAL />\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(6);
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Luftmengde i m3h</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput << "<variable name=\"wSensorValue\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<WORD />\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput << "<variable name=\"rVmin\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<REAL />\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput << "<variable name=\"rVmax\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<REAL />\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(6);
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Max vinkel</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput << "<variable name=\"xControlRangeIncreased\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<BOOL/>\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput << "<variable name=\"xMecanicalOverload\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<BOOL/>\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput << "<variable name=\"xActuatorHunting\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<BOOL/>\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput << "<variable name=\"xSensorError\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<BOOL/>\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput << "<variable name=\"xManualOpen\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<BOOL/>\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput << "<variable name=\"xManualClose\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<BOOL/>\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput << "<variable name=\"vMin\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<REAL />\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(6);
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Min luftmengde SP / 0-100</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput << "<variable name=\"vNorm\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<REAL />\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(6);
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\"> Settpunkt ved bevegelse / 0-100 </xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput << "<variable name=\"vMax\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<REAL />\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(6);
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Maks luftmengde SP / 0-100 </xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput << "<variable name=\"vSize\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<REAL />\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(6);
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Max kubikk</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput << "<variable name=\"vSetpoint_m3h\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<REAL />\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(6);
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">SP%</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput << "<variable name=\"xdontoptimize\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<BOOL/>\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(6);
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Fjerner VAV fra Optimizer</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>" << std::endl << Tabs(4);

    fOutput << "</struct>\n" + Tabs(3);
    fOutput << "</baseType>\n" + Tabs(3);
    fOutput << "<addData/>\n" + Tabs(2);
    fOutput << "</dataType>\n" + Tabs(1);
    fOutput << "</dataTypes>\n" + Tabs(1);
    //FB
    fOutput << "<pous>\n" + Tabs(2);
    fOutput << "<pou name=\"fbAutAd\" pouType=\"functionBlock\">\n" + Tabs(3);
    fOutput << "<interface>\n" + Tabs(4);
    fOutput << "<inputVars>\n" + Tabs(5);
    //In Var
    fOutput << "<variable name=\"iSerialNr\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<derived name=\"typSerialNo\" />\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput << "<variable name=\"bPort\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<BYTE />\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput << "<variable name=\"bAddress\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<BYTE />\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput << "<variable name=\"xReset\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<BOOL/>\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput << "<variable name=\"xNext\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<BOOL/>\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput << "</inputVars>\n" + Tabs(4);
    fOutput << "<outputVars>\n" + Tabs(5);                              //Output var fb

    fOutput << "<variable name=\"i\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<INT/>\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(6);
    fOutput << "<initialValue>\n" + Tabs(7);
    fOutput << "<simpleValue value=\"0\" />\n" + Tabs(6);
    fOutput << "</initialValue>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput << "<variable name=\"xFailed\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<BOOL/>\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput << "<variable name=\"sSetStatus\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<string />\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput << "<variable name=\"sGetStatus\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<string />\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(4);

    fOutput << "</outputVars>\n" + Tabs(4);
    fOutput << "<localVars>\n" + Tabs(5);

    fOutput << "<variable name=\"xLearn\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<BOOL/>\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput << "<variable name=\"xRetry\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<BOOL/>\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput << "<variable name=\"VAV_Addressing\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<derived name=\"fbMpBusAddressing\" />\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput << "</localVars>\n" + Tabs(3);
    fOutput << "</interface>\n" + Tabs(3);
    fOutput << "<body>\n" + Tabs(2);
    fOutput << "<ST>" << std::endl << Tabs(1);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">";
    //ST
    fOutput << "//Resetter forgje VAVs verdier\n\t";
    fOutput << "IF xReset THEN\n\t\t";
    fOutput << "i:= 0;\n\t\t";
    fOutput << "xRetry:= FALSE;\n\t\t";
    fOutput << "xFailed:= FALSE;\n\t\t";
    fOutput << "sSetStatus:= '';\n\t\t";
    fOutput << "sGetStatus:= '';\n\n";

    fOutput << "//Begynner paa neste VAV\n\t";
    fOutput << "ELSIF i&lt;1 AND xNext THEN\n\t\t";
    fOutput << "VAV_Addressing\n\t\t";
    fOutput << "(\n\t\t\t";
    fOutput << "bPortMpBus:= bPort,\n\t\t\t";
    fOutput << "bAddress:= bAddress,\n\t\t\t";
    fOutput << "typINSerialNo:= iSerialNr,\n\t\t\t";
    fOutput << "xLearn:= xLearn\n\t\t";
    fOutput << ");\n\t\t";
    fOutput << "i:= 1;\n\n";

    fOutput << "//Skriver rett port og adresse til VAV naar blokken er klar\n\t";
    fOutput << "ELSIF VAV_Addressing.xReady AND i=1 THEN\n\t\t";
    fOutput << "VAV_Addressing\n\t\t";
    fOutput << "(\n\t\t\t";
    fOutput << "xSet:= TRUE,\n\t\t\t";
    fOutput << "xLearn:= xLearn\n\t\t";
    fOutput << ");\n\t\t";
    fOutput << "i:= 2;\n\n";

    fOutput << "//Spoer etter serie nr som hoerer til port og adresse\n\t";
    fOutput << "ELSIF VAV_Addressing.xReady AND i=2 THEN\n\t\t";
    fOutput << "sSetStatus:= VAV_Addressing.sStatus;\n\t\t";
    fOutput << "VAV_Addressing\n\t\t";
    fOutput << "(\n\t\t\t";
    fOutput << "xGetSerialNO:= TRUE,\n\t\t\t";
    fOutput << "xLearn:= xLearn\n\t\t";
    fOutput << ");\n\t\t";
    fOutput << "i:= 3;\n\n";

    fOutput << "//Sjekker om serie nr. som tilhoerer port og adressen stemmer\n\t";
    fOutput << "ELSIF VAV_Addressing.xReady AND i=3 THEN\n\t\t";
    fOutput << "sGetStatus:= VAV_Addressing.sStatus;\n\t\t";
    fOutput << "//Sjekker om serie nr stemmer\n\t\t";
    fOutput << "IF xRetry AND VAV_Addressing.typOUTSerialNo.wYearAndWeek &lt;&gt; iSerialNr.wYearAndWeek OR VAV_Addressing.typOUTSerialNo.wDayAndNumber &lt;&gt; iSerialNr.wDayAndNumber OR VAV_Addressing.typOUTSerialNo.bTypeID &lt;&gt; iSerialNr.bTypeID OR VAV_Addressing.typOUTSerialNo.bTestStation &lt;&gt; iSerialNr.bTestStation THEN" << std::endl << "\t\t\t";
    fOutput << "xRetry:= FALSE;\n\t\t\t";
    fOutput << "xFailed:= TRUE;\n\t\t\t";
    fOutput << "i:=4;\n\t\t";
    fOutput << "ELSIF VAV_Addressing.typOUTSerialNo.wYearAndWeek &lt;&gt; iSerialNr.wYearAndWeek OR VAV_Addressing.typOUTSerialNo.wDayAndNumber &lt;&gt; iSerialNr.wDayAndNumber OR VAV_Addressing.typOUTSerialNo.bTypeID &lt;&gt; iSerialNr.bTypeID OR VAV_Addressing.typOUTSerialNo.bTestStation &lt;&gt; iSerialNr.bTestStation THEN" << std::endl << "\t\t\t";
    fOutput << "xRetry:= TRUE;\n\t\t\t";
    fOutput << "i:=1;\n\t\t";
    fOutput << "ELSE\n\t\t\t";
    fOutput << "i:=4;\n\t\t";
    fOutput << "END_IF\n\n";


    fOutput << "//Resetter xSet og xGet, og Setter Port, adresse og serie nr. og henter status\n\t";
    fOutput << "ELSE\n\t\t";
    fOutput << "VAV_Addressing\n\t\t";
    fOutput << "(\n\t\t\t";
    fOutput << "bPortMpBus:= bPort,\n\t\t\t";
    fOutput << "bAddress:= bAddress,\n\t\t\t";
    fOutput << "typINSerialNo:= iSerialNr,\n\t\t\t";
    fOutput << "xLearn:= xLearn,\n\t\t\t";
    fOutput << "xSet:= FALSE,\n\t\t\t";
    fOutput << "xGetSerialNO:= FALSE,\n\t\t\t";
    fOutput << "xLearn:= xLearn\n\t\t";
    fOutput << ");\n\t";
    fOutput << "END_IF</xhtml>" << std::endl << Tabs(4);

    fOutput << "</ST>\n" + Tabs(3);
    fOutput << "</body>\n" + Tabs(3);
    fOutput << "<addData/>\n" + Tabs(2);
    fOutput << "</pou>\n" + Tabs(2);
    //PRG
    fOutput << "<pou name=\"PRG_360_VAV_Adressering\" pouType=\"program\">\n" + Tabs(3);
    fOutput << "<interface>\n" + Tabs(4);
    fOutput << "<localVars>\n" + Tabs(5);
    //Local Var
    fOutput << "<variable name=\"xReset\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<BOOL/>\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput << "<variable name=\"xRun\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<BOOL/>\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput << "<variable name=\"xInit\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<BOOL/>\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(6);
    fOutput << "<initialValue>\n" + Tabs(7);
    fOutput << "<simpleValue value=\"TRUE\" />\n" + Tabs(6);
    fOutput << "</initialValue>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput << "<variable name=\"Auto\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<derived name=\"fbAutAd\" />\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput << "<variable name=\"iLinje\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<INT/>\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(6);
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Linje som skal adresseres</xhtml>\n" + Tabs(6);       //Kommentar
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput << "<variable name=\"iVAV\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<INT/>\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(6);
    fOutput << "<initialValue>\n" + Tabs(7);
    fOutput << "<simpleValue value=\"1\" />\n" + Tabs(6);
    fOutput << "</initialValue>\n" + Tabs(6);
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">VAV(adr.) som adresseres</xhtml>\n" + Tabs(6);      //Kommentar
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(4);

    fOutput << "</localVars>\n" + Tabs(3);
    fOutput << "</interface>\n" + Tabs(3);
    fOutput << "<body>\n" + Tabs(4);
    fOutput << "<ST>" << std::endl << Tabs(5);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">";
    //ST
    fOutput << "IF xReset THEN\n\t";
    fOutput << "Auto(xReset:= TRUE);\n\t";
    fOutput << "xInit:= TRUE;\n\t";
    fOutput << "xReset:= FALSE;\n";

    fOutput << "ELSIF xRun THEN\n\n\t";

    fOutput << "IF ";
    for (int i = 0; i < 200; i++)
    {
        if (bUsed[i])
        {
            fOutput << sGVL << "." << VAV[i] << ".xAddress OR (iLinje = " << Port[i] << " AND iVAV = " << adr[i] << ") THEN\n\n\t\t";
            fOutput << "IF xInit THEN\n" + Tabs(3);
            fOutput << sGVL << "." << VAV[i] + ".xEnable:= FALSE;\n" + Tabs(3);
            fOutput << "Auto(\n" + Tabs(4);
            fOutput << "bPort:= " << sGVL << "." << VAV[i] + ".bPort,\n" + Tabs(4);
            fOutput << "bAddress:= " << sGVL << "." << VAV[i] + ".bAddress,\n" + Tabs(4);
            fOutput << "iSerialNr:= " << sGVL << "." << VAV[i] + ".iSerialNr,\n" + Tabs(4);
            fOutput << "xNext:= TRUE,\n" + Tabs(4);
            fOutput << "xReset:= FALSE\n" + Tabs(4);
            fOutput << ");\n" + Tabs(3);
            fOutput << "xInit:= FALSE;\n\n" + Tabs(2);

            fOutput << "ELSIF Auto.i=4 THEN\n" + Tabs(3);
            fOutput << sGVL << "." << VAV[i] + ".sSetStatus:= Auto.sSetStatus;\n" + Tabs(4);
            fOutput << sGVL << "." << VAV[i] + ".sGetStatus:= Auto.sGetStatus;\n" + Tabs(4);
            fOutput << sGVL << "." << VAV[i] + ".xFailed:= Auto.xFailed;\n" + Tabs(4);
            fOutput << sGVL << "." << VAV[i] + ".xAddress:= FALSE;\n" + Tabs(4);
            fOutput << sGVL << "." << VAV[i] + ".xEnable:= TRUE;\n" + Tabs(4);
            fOutput << "xReset:= TRUE;\n" + Tabs(4);
            fOutput << "iVAV:=iVAV+1;\n\n" + Tabs(3);

            fOutput << "ELSE\n" + Tabs(4);
            fOutput << "Auto(xNext:= FALSE);\n" + Tabs(3);
            fOutput << "END_IF\n\n" + Tabs(1);
            if (bUsed[(i + 1)] == true)
            {
                fOutput << "ELSIF ";
            }
        }
        else
            break;
    }
    fOutput << "ELSIF iVAV > 8 THEN\n\t\t\t";
    fOutput << "iVAV:= 0;\n\t\t";
    fOutput << "ELSIF iVAV > 0  THEN\n\t\t\t";
    fOutput << "iVAV:= (iVAV+1);\n\t\t";
    fOutput << "END_IF\n";
    fOutput << "END_IF" << std::endl;

    fOutput << "</xhtml>\n" + Tabs(4);
    fOutput << "</ST>\n" + Tabs(3);
    fOutput << "</body>\n" + Tabs(3);
    fOutput << "<addData/>\n" + Tabs(2);
    fOutput << "</pou>\n" + Tabs(1);




    int iLinjer = 0;
    for (int i = 0; i < 200; i++)
    {
        if (bUsed[i])
        {
            if (std::stoi(Port[i]) > iLinjer)
                iLinjer = std::stoi(Port[i]);
        }
        else
            break;
    }
    //PRG


    //Variabler brukt i CFC autogen
    int iCfc_Order = 0, iCfc_Id = 0, iCfc_y = 0;

    for (int i = 1; i <= iLinjer; i++)
    {
        if (fOutput.is_open() == false)
        {
            fOutput.open(sPath, std::ios::app);
        }
        iCfc_Order = 0;
        iCfc_Id = 0;
        iCfc_y = 0;

        fOutput << "<pou name=\"PRG_360_MP" << i << "\" pouType=\"program\">\n" + Tabs(3);
        fOutput << "<interface>\n" + Tabs(4);

        //Local Var
        fOutput << "<localVars>\n" + Tabs(5);

        //Felles
        fOutput << "<variable name=\"xSet\">\n" + Tabs(6);
        fOutput << "<type>\n" + Tabs(7);
        fOutput << "<BOOL/>\n" + Tabs(6);
        fOutput << "</type>\n" + Tabs(5);
        fOutput << "<documentation>\n" + Tabs(7);
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Felles</xhtml>\n" + Tabs(6);      //Kommentar
        fOutput << "</documentation>\n" + Tabs(5);
        fOutput << "</variable>\n" + Tabs(5);

        fOutput << "<variable name=\"xRead\">\n" + Tabs(6);
        fOutput << "<type>\n" + Tabs(7);
        fOutput << "<BOOL/>\n" + Tabs(6);
        fOutput << "</type>\n" + Tabs(5);
        fOutput << "</variable>\n" + Tabs(5);

        //Master
        fOutput << "<variable name=\"FbMpbusMaster_" << i << "\">\n" + Tabs(6);
        fOutput << "<type>\n" + Tabs(7);
        fOutput << "<derived name=\"FbMpbusMaster\"/>\n" + Tabs(6);
        fOutput << "</type>\n" + Tabs(5);
        fOutput << "<documentation>\n" + Tabs(7);
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Master</xhtml>\n" + Tabs(6);      //Kommentar
        fOutput << "</documentation>\n" + Tabs(5);
        fOutput << "</variable>\n" + Tabs(5);

        fOutput << "<variable name=\"oStatus_M" << i << "\">\n" + Tabs(6);
        fOutput << "<type>\n" + Tabs(7);
        fOutput << "<derived name=\"WagoSysErrorBase.FbResult\"/>\n" + Tabs(6);
        fOutput << "</type>\n" + Tabs(5);
        fOutput << "</variable>\n" + Tabs(5);

        fOutput << "<variable name=\"sStatus_M" << i << "\">\n" + Tabs(6);
        fOutput << "<type>\n" + Tabs(7);
        fOutput << "<string/>\n" + Tabs(6);
        fOutput << "</type>\n" + Tabs(5);
        fOutput << "</variable>\n" + Tabs(5);

        //VAV-er
        for (int j = 0; j < 200; j++)
        {
            if (bUsed[j] && std::stoi(Port[j]) == i)
            {
                fOutput << "<variable name=\"FbMpbus_" << adr[j] << "\">\n" + Tabs(6);
                fOutput << "<type>\n" + Tabs(7);
                fOutput << "<derived name=\"FbMpBusVav\"/>\n" + Tabs(6);
                fOutput << "</type>\n" + Tabs(5);
                fOutput << "<documentation>\n" + Tabs(7);
                fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Linje " << i << ". Adresse " << adr[j] << ". VAV " << VAV[j] << "</xhtml>\n" + Tabs(6);      //Kommentar
                fOutput << "</documentation>\n" + Tabs(5);
                fOutput << "</variable>\n" + Tabs(5);

                fOutput << "<variable name=\"oStatus_" << adr[j] << "\">\n" + Tabs(6);
                fOutput << "<type>\n" + Tabs(7);
                fOutput << "<derived name=\"WagoSysErrorBase.FbResult\"/>\n" + Tabs(6);
                fOutput << "</type>\n" + Tabs(5);
                fOutput << "</variable>\n" + Tabs(5);

                fOutput << "<variable name=\"sStatus_" << adr[j] << "\">\n" + Tabs(6);
                fOutput << "<type>\n" + Tabs(7);
                fOutput << "<string/>\n" + Tabs(6);
                fOutput << "</type>\n" + Tabs(5);
                fOutput << "</variable>\n" + Tabs(5);
            }
            else if (bUsed[j] != true)
                break;
        }

        fOutput << "</localVars>\n" + Tabs(3);
        fOutput << "</interface>\n" + Tabs(3);

        //CFC
        fOutput << "<body>\n" + Tabs(4);
        fOutput << "<ST>\n" << Tabs(5);
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\"/>\n" << Tabs(5);
        fOutput << "</ST>\n" << Tabs(4);
        fOutput << "<addData>\n" << Tabs(5);
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfc\" handleUnknown=\"implementation\">\n" << Tabs(4);
        fOutput << "<CFC>\n\t";

        
        //Lukker fil før funksjoner kjøres
        fOutput.close();


        Mp_cfc_Master(sPath, sGVL, i, &iCfc_Order, &iCfc_Id, iCfc_y);
        for (int j = 0; j < 200; j++)
        {
            if (bUsed[j] && std::stoi(Port[j]) == i)
            {
               Mp_cfc_Vav(sPath, sGVL, VAV[j], i, adr[j], &iCfc_Order, &iCfc_Id, iCfc_y);
               iCfc_y += 30;
            }
            else if (!bUsed[j])
                break;
        }
        fOutput.open(sPath, std::ios::app);
        fOutput << "</CFC>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</body>\n\t";
        fOutput << "<addData/>\n\t";
        fOutput << "</pou>\n\t";
    }

    //Nytt
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    pos = VAV[0].find("SQ") + 2;
    bool xFirst = true;

    fOutput << "<pou name=\"PRG_360_VAV_Max\" pouType=\"program\">\n" + Tabs(3);
    fOutput << "<interface>\n" + Tabs(4);
    fOutput << "<localVars>\n" + Tabs(5);
    fOutput << "</localVars>\n" + Tabs(3);
    fOutput << "</interface>\n" + Tabs(3);
    fOutput << "<body>\n" + Tabs(4);
    fOutput << "<ST>" << std::endl << Tabs(5);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">";



    //Lager max for tilluftsspjeld
    fOutput << "//Max spjeld vinkel for tilluftsspjeld\n";
    fOutput << sGVL << "." << sAdresseFormat << "_001_OU001_SQ401_Max:=MAX\n(\n\t";

    for (int i = 0; i < 200; i++)
    {
        if (bUsed[i])
        {
            if (VAV[i].substr(pos, 1) == "4" && (sMin[i] != sNorm[i] || sNorm[i] != sMax[i]))
            {
                if (xFirst)
                {
                    fOutput << "SEL(" << sGVL << "." << VAV[i] << ".xdontoptimize, " << sGVL << "." << VAV[i] << ".rOutPosition, 0)";
                    xFirst = false;
                }
                else
                {
                    fOutput << ",\n\t";
                    fOutput << "SEL(" << sGVL << "." << VAV[i] << ".xdontoptimize, " << sGVL << "." << VAV[i] << ".rOutPosition, 0)";
                }
            }
        }
        else
            break;
    }
    fOutput << "\n);\n\n";
    xFirst = true;

    //Lager max for avtrekksspjeld
    fOutput << "//Max spjeld vinkel for avtrekksspjeld\n";
    fOutput << sGVL << "." << sAdresseFormat << "_001_OU001_SQ501_Max:=MAX\n(\n\t";

    for (int i = 0; i < 200; i++)
    {
        if (bUsed[i])
        {
            if (VAV[i].substr(pos, 1) == "5" && (sMin[i] != sNorm[i] || sNorm[i] != sMax[i]))
            {
                if (xFirst)
                {
                    fOutput << "SEL(" << sGVL << "." << VAV[i] << ".xdontoptimize, " << sGVL << "." << VAV[i] << ".rOutPosition, 0)";
                    xFirst = false;
                }
                else
                {
                    fOutput << ",\n\t";
                    fOutput << "SEL(" << sGVL << "." << VAV[i] << ".xdontoptimize, " << sGVL << "." << VAV[i] << ".rOutPosition, 0)";
                }
            }
        }
        else
            break;

    }
    fOutput << "\n);\n\n";
    xFirst = true;


    fOutput << "</xhtml>\n" + Tabs(4);
    fOutput << "</ST>\n" + Tabs(3);
    fOutput << "</body>\n" + Tabs(3);
    fOutput << "<addData/>\n" + Tabs(2);
    fOutput << "</pou>\n" + Tabs(1);



    fOutput << "</pous>\n";
    fOutput << "</types>\n";
    fOutput << "<instances>\n" + Tabs(1);
    fOutput << "<configurations />\n";
    fOutput << "</instances>\n";
    fOutput << "<addData>\n" + Tabs(1);
    fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/globalvars\" handleUnknown=\"implementation\">\n" + Tabs(2);
    fOutput << "<globalVars name=\"" << sGVL << /*"\" retain=\"true\" persistent=\"true\*/"\">\n" + Tabs(3);


    //Nytt
    ///////////////////////

    fOutput << "<variable name=\"" << sAdresseFormat << "_001_OU001_SQ401_Max\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<REAL/>\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(5);
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Max spjeldvinkel tilluft</xhtml>\n" + Tabs(6);      //Kommentar
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput << "<variable name=\"" << sAdresseFormat << "_001_OU001_SQ501_Max\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<REAL/>\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(5);
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">max spjeldvinkel avtrekk</xhtml>\n" + Tabs(6);      //Kommentar
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);
    ////////////////////////

    for (int i = 0; i < 200; i++)
    {
        if (bUsed[i])
        {

            fOutput << "<variable name=\"" + VAV[i] + "\">\n" + Tabs(4);
            fOutput << "<type>\n" + Tabs(5);
            fOutput << "<derived name=\"typVAV\" />\n" + Tabs(4);
            fOutput << "</type>\n" + Tabs(4);
            fOutput << "<documentation>\n" + Tabs(4);
            fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">\n/</xhtml>\n" + Tabs(3);
            fOutput << "</documentation>\n" + Tabs(3);
            fOutput << "<initialValue>\n" + Tabs(5);
            fOutput << "<structValue>\n" + Tabs(6);

            fOutput << "<value member=\"xEnable\">\n" + Tabs(7);
            fOutput << "<simpleValue value=\"TRUE\" />\n" + Tabs(6);
            fOutput << "</value>\n" + Tabs(6);

            fOutput << "<value member=\"vMin\">\n" + Tabs(7);
            fOutput << "<simpleValue value=\"" + sMin[i] + "\" />\n" + Tabs(6);
            fOutput << "</value>\n" + Tabs(6);

            fOutput << "<value member=\"vNorm\">\n" + Tabs(7);
            fOutput << "<simpleValue value=\"" + sNorm[i] + "\" />\n" + Tabs(6);
            fOutput << "</value>\n" + Tabs(6);

            fOutput << "<value member=\"vMax\">\n" + Tabs(7);
            fOutput << "<simpleValue value=\"" + sMax[i] + "\" />\n" + Tabs(6);
            fOutput << "</value>\n" + Tabs(6);

            fOutput << "<value member=\"vSize\">\n" + Tabs(7);
            fOutput << "<simpleValue value=\"" + sSize[i] + "\" />\n" + Tabs(6);
            fOutput << "</value>\n" + Tabs(6);

            fOutput << "<value member=\"bPort\">\n" + Tabs(7);
            fOutput << " <simpleValue value=\"" + Port[i] + "\" />\n" + Tabs(6);
            fOutput << "</value>\n" + Tabs(6);

            fOutput << "<value member=\"bAddress\">\n" + Tabs(7);
            fOutput << "<simpleValue value=\"" + adr[i] + "\" />\n" + Tabs(6);
            fOutput << "</value>\n" + Tabs(6);

            fOutput << "<value member=\"iSerialNr\">\n" + Tabs(7);
            fOutput << "<structValue>\n" + Tabs(8);

            fOutput << "<value member=\"wYearAndWeek\">\n" + Tabs(9);
            fOutput << "<simpleValue value=\"" + SN1[i] + "\" />\n" + Tabs(8);
            fOutput << "</value>\n" + Tabs(8);

            fOutput << "<value member=\"wDayAndNumber\">\n" + Tabs(9);
            fOutput << "<simpleValue value=\"" + SN2[i] + "\" />\n" + Tabs(8);
            fOutput << "</value>\n" + Tabs(8);

            fOutput << "<value member=\"bTypeID\">\n" + Tabs(9);
            fOutput << "<simpleValue value=\"" + SN3[i] + "\" />\n" + Tabs(8);
            fOutput << "</value>\n" + Tabs(8);

            fOutput << "<value member=\"bTestStation\">\n" + Tabs(9);
            fOutput << "<simpleValue value=\"" + SN4[i] + "\" />\n" + Tabs(8);
            fOutput << "</value>\n" + Tabs(7);

            fOutput << "</structValue>\n" + Tabs(6);
            fOutput << "</value>\n" + Tabs(5);
            fOutput << "</structValue>\n" + Tabs(4);
            fOutput << "</initialValue>\n" + Tabs(3);
            fOutput << "</variable>\n" + Tabs(3);
        }
        else
            break;
    }
    fOutput << "<addData>" << std::endl << Tabs(4);

    fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/attributes\" handleUnknown=\"implementation\">\n" + Tabs(5);
    fOutput << "<Attributes>\n" + Tabs(6);
    fOutput << "<Attribute Name=\"qualified_only\" Value=\"\" />\n" + Tabs(5);
    fOutput << "</Attributes>\n" + Tabs(4);
    fOutput << "</data>\n" + Tabs(4);

    fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/buildproperties\" handleUnknown=\"implementation\">\n" + Tabs(5);
    fOutput << "<BuildProperties>\n" + Tabs(6);
    fOutput << "<LinkAlways>true</LinkAlways>\n" + Tabs(5);
    fOutput << "</BuildProperties>\n" + Tabs(4);
    fOutput << "</data>\n" + Tabs(3);
    fOutput << "</addData>\n" + Tabs(2);
    fOutput << "</globalVars>\n" + Tabs(1);
    fOutput << "</data>\n";
    fOutput << "</addData>\n";
    fOutput << "</project>" << std::endl;

    fOutput.close();
}

#endif