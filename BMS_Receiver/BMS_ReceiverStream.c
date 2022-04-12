#include "BMS_ReceiverStream.h"

float min, max;
float Temp[BMS_DATA] = {};
float Soc[BMS_DATA] = {};

int NoOfEnteries = 5;

void readDataFromConsole()
{
	for (int i = 0; i < BMS_DATA; i++)
	{
		scanf("%f\t%f\n", &Temp[i], &Soc[i]);
	}
}

float minBMSParameterValue(float BatteryParameter[] , int size)
{
	min = BatteryParameter[0];
	for (int i = 0; i < size; i++)
	{
		if (BatteryParameter[i] < min)
			min = BatteryParameter[i];
	}
	return min;
}

float maxBMSParameterValue(float BatteryParameter[] , int size)
{
	max = BatteryParameter[0];
	for (int i = 0; i < size; i++)
	{
		if (BatteryParameter[i] > max)
			max = BatteryParameter[i];
	}
	return max;
}


float calculateSMA(float BatteryParameter[], int NoOfEnteries)
{
	float BatteryParameterAvg = 0;
	float BatteryParameterSum = 0;
	for (int i = (NoOfEnteries - 5); i < NoOfEnteries ; i++)
	{
		BatteryParameterSum += BatteryParameter[i];
	}
	BatteryParameterAvg = BatteryParameterSum/5;
	return BatteryParameterAvg;
	
}
void printData()
{
	
	float SocSMA = calculateSMA(Soc ,NoOfEnteries);
	printf("Simple moving average of Temp : %0.2lf \n ", SocSMA);
	float TempSMA = calculateSMA(Temp ,NoOfEnteries);
	printf("Simple moving average of SOC : %0.2lf \n ",TempSMA);

	printf("min temp :%f\n", minBMSParameterValue(Temp, BMS_DATA));
	printf("max temp :%f\n", maxBMSParameterValue(Temp, BMS_DATA));
	printf("min Soc:%f\n",  minBMSParameterValue(Soc, BMS_DATA));
	printf("max Soc :%f\n", maxBMSParameterValue(Soc, BMS_DATA));
}
