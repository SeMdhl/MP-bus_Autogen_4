#pragma once
#ifndef mdhl_Knx_Items
#define mdhl_Knx_Items
#include <iostream>;
#include <fstream>;
#include <windows.h>;
#include "mdhl_Tools.h"











//----------------------------------------------------------------------------------------------------------------------------------------
void Mp_cfc_Master(std::string& sPath, std::string& sGvl, int& iLinje, int* iCfc_Order, int* iCfc_Id, int& iCfc_y)
{
    std::ofstream fOutput(sPath, std::ios::app);

   //Inputs
    fOutput << "<inVariable localId=\"" << (1 + *iCfc_Id) << "\">\n\t";

    if (iLinje == 1)
        fOutput << "<position x=\"23\" y=\"" << (9 + iCfc_y) << "\" />\n\t";
    else
        fOutput << "<position x=\"22\" y=\"" << (9 + iCfc_y) << "\" />\n\t";

    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    if (iLinje == 1)
        fOutput << "<expression>IoConfig_Globals.MP_Bus_Master</expression>\n\t";
    else
        fOutput << "<expression>IoConfig_Globals.MP_Bus_Master_" << iLinje-1 << "</expression>\n\t";

    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"0\" y=\"" << (0 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";

    if (iLinje == 1)
        fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"IoConfig_Globals.MP_Bus_Master\" />\n\t";
    else
        fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"IoConfig_Globals.MP_Bus_Master_" << iLinje-1 << "\" />\n\t";


    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<inVariable localId=\"" << (3 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"34\" y=\"" << (10 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>" << iLinje << "</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (4 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"0\" y=\"" << (0 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (3 + *iCfc_Id) << "\" formalParameter=\"" << iLinje << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    //Block

    fOutput << "<block localId=\"" << (5 + *iCfc_Id) << "\" executionOrderId=\"" << (1 + *iCfc_Order) << "\" typeName=\"FbMpBusMaster\" instanceName=\"FbMpbusMaster_" << iLinje << "\">\n\t";

    fOutput << "<position x=\"39\" y=\"" << (7 + iCfc_y) << "\" />\n\t";
    fOutput << "<inputVariables>\n\t";

    fOutput << "<variable formalParameter=\"I_Port\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"" << (0 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "<variable formalParameter=\"bPortMpBus\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"" << (1 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (4 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "</inputVariables>\n\t";

    fOutput << "<inOutVariables />\n\t";

    fOutput << "<outputVariables>\n\t";
    fOutput << "<variable formalParameter=\"oStatus\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"" << (0 + iCfc_y) << "\" />\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "<variable formalParameter=\"sStatus\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"" << (1 + iCfc_y) << "\" />\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "</outputVariables>\n\t";
    fOutput << "<addData>\n\t";
    fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
    fOutput << "<CallType xmlns=\"\">functionblock</CallType>\n\t";
    fOutput << "</data>\n\t";
    fOutput << "</addData>\n\t";
    fOutput << "</block>\n\t";


    //Output connectors
    fOutput << "<connector localId=\"" << (6 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"0\" y=\"" << (0 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (5 + *iCfc_Id) << "\" formalParameter=\"sStatus\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<connector localId=\"" << (7 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"0\" y=\"" << (0 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (5 + *iCfc_Id) << "\" formalParameter=\"oStatus\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";


    //Outputs
    fOutput << "<outVariable localId=\"" << (8 + *iCfc_Id) << "\" executionOrderId=\"" << (2 + *iCfc_Order) << "\">\n\t";
    fOutput << "<position x=\"52\" y=\"" << (9 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"" << (0 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "<expression>oStatus_M" << iLinje << "</expression>\n\t";
    fOutput << "</outVariable>\n\t";

    fOutput << "<outVariable localId=\"" << (9 + *iCfc_Id) << "\" executionOrderId=\"" << (3 + *iCfc_Order) << "\">\n\t";
    fOutput << "<position x=\"52\" y=\"" << (10 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"" << (0 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (6 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "<expression>sStatus_M" << iLinje << "</expression>\n\t";
    fOutput << "</outVariable>\n\t";




    (*iCfc_Id) += 9;
    (*iCfc_Order) += 3;
    fOutput.close();
    return;
}

void Mp_cfc_Vav(std::string& sPath, std::string& sGvl, std::string& sVav, int& iLinje, std::string& sAdr, int* iCfc_Order, int* iCfc_Id, int& iCfc_y)
{
    std::ofstream fOutput(sPath, std::ios::app);

    //Comment
    fOutput << "<comment localId=\"" << (1 + *iCfc_Id) << "\" height=\"0\" width=\"0\">\n\t";
    fOutput << "<position x=\"" << (36) << "\" y=\"" << (18 + iCfc_y) << "\" />\n\t";
    fOutput << "<content>\n\t";
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">" <<  sVav << "</xhtml>\n\t";
    fOutput << "</content>\n\t";
    fOutput << "</comment>\n\t";

    //Enable
    fOutput << "<inVariable localId=\"" << (2 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (13) << "\" y=\"" << (25 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>" << sGvl << "." << sVav << ".xEnable" << "</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (3 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (1) << "\" y=\"" << (101 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" formalParameter=\"" << sGvl << "." << sVav << ".xEnable" << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    //Port
    fOutput << "<inVariable localId=\"" << (4 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (31) << "\" y=\"" << (26 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>" << iLinje << "</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (5 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (1) << "\" y=\"" << (1 + 102 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (4 + *iCfc_Id) << "\" formalParameter=\"" << iLinje  << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    //Address
    fOutput << "<inVariable localId=\"" << (6 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (31) << "\" y=\"" << (27 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>" << sAdr << "</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (7 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (1) << "\" y=\"" << (101 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (6 + *iCfc_Id) << "\" formalParameter=\"" << sAdr << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    //Cycle time
    fOutput << "<inVariable localId=\"" << (8 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (28) << "\" y=\"" << (28 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>" << "t#500ms" << "</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (9 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (1) << "\" y=\"" << (101 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (8 + *iCfc_Id) << "\" formalParameter=\"" << "t#500ms" << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    //Airvolume
    fOutput << "<inVariable localId=\"" << (10 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (11) << "\" y=\"" << (29 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>" << sGvl << "." << sVav << ".rAirVolume_SP" << "</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (11 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (1) << "\" y=\"" << (101 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (10 + *iCfc_Id) << "\" formalParameter=\"" << sGvl << "." << sVav << ".rAirVolume_SP" << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    //Min air volume
    fOutput << "<inVariable localId=\"" << (12 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (31) << "\" y=\"" << (30 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>"<< "0" << "</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (13 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (1) << "\" y=\"" << (101 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (12 + *iCfc_Id) << "\" formalParameter=\"" << "0" << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    //Max air volume
    fOutput << "<inVariable localId=\"" << (14 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (30) << "\" y=\"" << (31 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>" << "100" << "</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (15 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (1) << "\" y=\"" << (101 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (14 + *iCfc_Id) << "\" formalParameter=\"" << "100" << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    //Set
    fOutput << "<inVariable localId=\"" << (16 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (30) << "\" y=\"" << (32 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>" << "xSet" << "</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (17 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (1) << "\" y=\"" << (101 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (16 + *iCfc_Id) << "\" formalParameter=\"" << "xSet" << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    //Read
    fOutput << "<inVariable localId=\"" << (18 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (29) << "\" y=\"" << (33 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>" << "xRead" << "</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (19 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (1) << "\" y=\"" << (101 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (18 + *iCfc_Id) << "\" formalParameter=\"" << "xRead" << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    //Sensor type
    fOutput << "<inVariable localId=\"" << (20 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (31) << "\" y=\"" << (34 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>" << "0" << "</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (21 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (1) << "\" y=\"" << (101 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (20 + *iCfc_Id) << "\" formalParameter=\"" << "0" << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    //Manual open
    fOutput << "<inVariable localId=\"" << (22 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (11) << "\" y=\"" << (35 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>" << sGvl << "." << sVav << ".xManualOpen" << "</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (23 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (1) << "\" y=\"" << (101 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (22 + *iCfc_Id) << "\" formalParameter=\"" << sGvl << "." << sVav << ".xManualOpen" << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    //Manual close
    fOutput << "<inVariable localId=\"" << (24 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (11) << "\" y=\"" << (36 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>" << sGvl << "." << sVav << ".xManualClose" << "</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (25 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (1) << "\" y=\"" << (101 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (24 + *iCfc_Id) << "\" formalParameter=\"" << sGvl << "." << sVav << ".xManualClose" << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";


    //Block
    fOutput << "<block localId=\"" << (26 + *iCfc_Id) << "\" executionOrderId=\"" << (1 + *iCfc_Order) << "\" typeName=\"FbMpBusVav\" instanceName=\"FbMpbus_" << sAdr << "\">\n\t";
    fOutput << "<position x=\"36\" y=\"" << (23 + iCfc_y) << "\" />\n\t";
    fOutput << "<inputVariables>\n\t";
    fOutput << "<variable formalParameter=\"xEnable\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"" << (0 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (3 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "<variable formalParameter=\"bPortMpBus\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"" << (1 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (5 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "<variable formalParameter=\"bAddress\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"" << (2 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "<variable formalParameter=\"tCycleTime\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"" << (3 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (9 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "<variable formalParameter=\"rAirVolume\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"" << (4 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (11 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "<variable formalParameter=\"rMinAirVolume\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"" << (5 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (13 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "<variable formalParameter=\"rMaxAirVolume\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"" << (6 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (15 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "<variable formalParameter=\"xSet\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"" << (7 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (17 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "<variable formalParameter=\"xRead\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"" << (8 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (19 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "<variable formalParameter=\"bSensorType\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"" << (9 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (21 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "<variable formalParameter=\"xManualOpen\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"" << (10 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (23 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "<variable formalParameter=\"xManualClose\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"" << (11 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (25 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "<variable formalParameter=\"xReset\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"" << (12 + iCfc_y) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "</inputVariables>\n\t";

    fOutput << "<inOutVariables />\n\t";

    fOutput << "<outputVariables>\n\t";
    fOutput << "<variable formalParameter=\"oStatus\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"" << (0 + iCfc_y) << "\" />\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "<variable formalParameter=\"sStatus\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"" << (1 + iCfc_y) << "\" />\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "<variable formalParameter=\"xReady\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"" << (2 + iCfc_y) << "\" />\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "<variable formalParameter=\"rOutPosition\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"" << (3 + iCfc_y) << "\" />\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "<variable formalParameter=\"rOutAirVolume_perc\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"" << (4 + iCfc_y) << "\" />\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "<variable formalParameter=\"rOutAirVolume_m3_h\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"" << (5 + iCfc_y) << "\" />\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "<variable formalParameter=\"wSensorValue\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"" << (6 + iCfc_y) << "\" />\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "<variable formalParameter=\"rVmin\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"" << (7 + iCfc_y) << "\" />\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "<variable formalParameter=\"rVmax\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"" << (8 + iCfc_y) << "\" />\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "<variable formalParameter=\"xControlRangeIncreased\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"" << (9 + iCfc_y) << "\" />\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "<variable formalParameter=\"xMecanicalOverload\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"" << (10 + iCfc_y) << "\" />\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "<variable formalParameter=\"xActuatorHunting\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"" << (11 + iCfc_y) << "\" />\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "<variable formalParameter=\"xSensorError\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"" << (12 + iCfc_y) << "\" />\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "</outputVariables>\n\t";

    fOutput << "<addData>\n\t";
    fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
    fOutput << "<CallType xmlns=\"\">functionblock</CallType>\n\t";
    fOutput << "</data>\n\t";
    fOutput << "</addData>\n\t";
    fOutput << "</block>\n\t";

    
    //Outputs
    //oStatus
    fOutput << "<connector localId=\"" << (27 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"1\" y=\"" << (101 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (26 + *iCfc_Id) << "\" formalParameter=\"oStatus\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<outVariable localId=\"" << (28 + *iCfc_Id) << "\" executionOrderId=\"" << (2 + *iCfc_Order) << "\">\n\t";
    fOutput << "<position x=\"55\" y=\"" << (25 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"" << (0 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (27 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "<expression>oStatus_" << sAdr << "</expression>\n\t";
    fOutput << "</outVariable>\n\t";


    //sStatus
    fOutput << "<connector localId=\"" << (29 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"1\" y=\"" << (101 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (26 + *iCfc_Id) << "\" formalParameter=\"sStatus\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<outVariable localId=\"" << (30 + *iCfc_Id) << "\" executionOrderId=\"" << (3 + *iCfc_Order) << "\">\n\t";
    fOutput << "<position x=\"55\" y=\"" << (26 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"" << (0 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (29 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "<expression>sStatus_" << sAdr << "</expression>\n\t";
    fOutput << "</outVariable>\n\t";


    //xReady
    fOutput << "<connector localId=\"" << (31 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"1\" y=\"" << (101 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (26 + *iCfc_Id) << "\" formalParameter=\"xReady\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<outVariable localId=\"" << (32 + *iCfc_Id) << "\" executionOrderId=\"" << (4 + *iCfc_Order) << "\">\n\t";
    fOutput << "<position x=\"55\" y=\"" << (27 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"" << (0 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (31 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "<expression>" << sGvl << "." << sVav << ".xReady</expression>\n\t";
    fOutput << "</outVariable>\n\t";

    //rOutPosition
    fOutput << "<connector localId=\"" << (33 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"1\" y=\"" << (101 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (26 + *iCfc_Id) << "\" formalParameter=\"rOutPosition\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<outVariable localId=\"" << (34 + *iCfc_Id) << "\" executionOrderId=\"" << (5 + *iCfc_Order) << "\">\n\t";
    fOutput << "<position x=\"55\" y=\"" << (28 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"" << (0 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (33 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "<expression>" << sGvl << "." << sVav << ".rOutPosition</expression>\n\t";
    fOutput << "</outVariable>\n\t";


    //rOutAirVolume_perc
    fOutput << "<connector localId=\"" << (35 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"1\" y=\"" << (101 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (26 + *iCfc_Id) << "\" formalParameter=\"rOutAirVolume_perc\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<outVariable localId=\"" << (36 + *iCfc_Id) << "\" executionOrderId=\"" << (6 + *iCfc_Order) << "\">\n\t";
    fOutput << "<position x=\"55\" y=\"" << (29 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"" << (0 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (35 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "<expression>" << sGvl << "." << sVav << ".rOutAirVolume_perc</expression>\n\t";
    fOutput << "</outVariable>\n\t";


    //rOutAirVolume_m3_h
    fOutput << "<connector localId=\"" << (37 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"1\" y=\"" << (101 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (26 + *iCfc_Id) << "\" formalParameter=\"rOutAirVolume_m3_h\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<outVariable localId=\"" << (38 + *iCfc_Id) << "\" executionOrderId=\"" << (7 + *iCfc_Order) << "\">\n\t";
    fOutput << "<position x=\"55\" y=\"" << (30 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"" << (0 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (37 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "<expression>" << sGvl << "." << sVav << ".rOutAirVolume_m3h</expression>\n\t";
    fOutput << "</outVariable>\n\t";



    //wSensorValue
    fOutput << "<connector localId=\"" << (39 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"1\" y=\"" << (101 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (26 + *iCfc_Id) << "\" formalParameter=\"wSensorValue\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<outVariable localId=\"" << (40 + *iCfc_Id) << "\" executionOrderId=\"" << (8 + *iCfc_Order) << "\">\n\t";
    fOutput << "<position x=\"55\" y=\"" << (31 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"" << (0 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (39 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "<expression>" << sGvl << "." << sVav << ".wSensorValue</expression>\n\t";
    fOutput << "</outVariable>\n\t";


    //rVmin
    fOutput << "<connector localId=\"" << (41 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"1\" y=\"" << (101 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (26 + *iCfc_Id) << "\" formalParameter=\"rVmin\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<outVariable localId=\"" << (42 + *iCfc_Id) << "\" executionOrderId=\"" << (9 + *iCfc_Order) << "\">\n\t";
    fOutput << "<position x=\"55\" y=\"" << (32 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"" << (0 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (41 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "<expression>" << sGvl << "." << sVav << ".rVmin</expression>\n\t";
    fOutput << "</outVariable>\n\t";


    //rVmax
    fOutput << "<connector localId=\"" << (43 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"1\" y=\"" << (101 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (26 + *iCfc_Id) << "\" formalParameter=\"rVmax\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<outVariable localId=\"" << (44 + *iCfc_Id) << "\" executionOrderId=\"" << (10 + *iCfc_Order) << "\">\n\t";
    fOutput << "<position x=\"55\" y=\"" << (33 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"" << (0 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (43 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "<expression>" << sGvl << "." << sVav << ".rVmax</expression>\n\t";
    fOutput << "</outVariable>\n\t";


    //xCRI
    fOutput << "<connector localId=\"" << (45 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"1\" y=\"" << (101 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (26 + *iCfc_Id) << "\" formalParameter=\"xControlRangeIncreased\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<outVariable localId=\"" << (46 + *iCfc_Id) << "\" executionOrderId=\"" << (11 + *iCfc_Order) << "\">\n\t";
    fOutput << "<position x=\"55\" y=\"" << (34 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"" << (0 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (45 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "<expression>" << sGvl << "." << sVav << ".xControlRangeIncreased</expression>\n\t";
    fOutput << "</outVariable>\n\t";


    //xMachanicalOverload
    fOutput << "<connector localId=\"" << (47 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"1\" y=\"" << (101 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (26 + *iCfc_Id) << "\" formalParameter=\"xMecanicalOverload\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<outVariable localId=\"" << (48 + *iCfc_Id) << "\" executionOrderId=\"" << (12 + *iCfc_Order) << "\">\n\t";
    fOutput << "<position x=\"55\" y=\"" << (35 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"" << (0 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (47 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "<expression>" << sGvl << "." << sVav << ".xMecanicalOverload</expression>\n\t";
    fOutput << "</outVariable>\n\t";


    //xActuatorHunting
    fOutput << "<connector localId=\"" << (49 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"1\" y=\"" << (101 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (26 + *iCfc_Id) << "\" formalParameter=\"xActuatorHunting\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<outVariable localId=\"" << (50 + *iCfc_Id) << "\" executionOrderId=\"" << (13 + *iCfc_Order) << "\">\n\t";
    fOutput << "<position x=\"55\" y=\"" << (36 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"" << (0 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (49 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "<expression>" << sGvl << "." << sVav << ".xActuatorHunting</expression>\n\t";
    fOutput << "</outVariable>\n\t";


    //xSensorError
    fOutput << "<connector localId=\"" << (51 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"1\" y=\"" << (101 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (26 + *iCfc_Id) << "\" formalParameter=\"xSensorError\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<outVariable localId=\"" << (52 + *iCfc_Id) << "\" executionOrderId=\"" << (14 + *iCfc_Order) << "\">\n\t";
    fOutput << "<position x=\"55\" y=\"" << (37 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"" << (0 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (51 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "<expression>" << sGvl << "." << sVav << ".xSensorError</expression>\n\t";
    fOutput << "</outVariable>\n\t";


    (*iCfc_Id) += 52;
    (*iCfc_Order) += 14;
    fOutput.close();
    return;
}

#endif