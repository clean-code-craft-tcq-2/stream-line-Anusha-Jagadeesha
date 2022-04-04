#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string.h>
#include <fstream>
using namespace std;

#define MAX_BMS_STREAM_READINGS 50

typedef struct batteryParam
{
    float SOC[MAX_BMS_STREAM_READINGS];
    float temperature[MAX_BMS_STREAM_READINGS];
} prepareSensorInputToSender;

bool readSensorDataFromTxt(string inputFile);
bool sendSensorDataToRx();
