#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BMS_DATA 50

extern void getDataFromConsole();
extern float minBMSParameterValue(float BatteryParameter[] , int size);
extern float maxBMSParameterValue(float BatteryParameter[] , int size);
extern float calculateSMA(float BatteryParameter[], int NoOfEnteries);
extern void printData();
