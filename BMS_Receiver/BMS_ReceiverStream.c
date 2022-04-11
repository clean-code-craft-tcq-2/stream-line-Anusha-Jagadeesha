#include "BMS_ReceiverStream.h"

float Temp[BMS_DATA] = {};
float Soc[BMS_DATA] = {};
float min, max;

void getDataFromConsole()
{
	for (int i = 0; i < 5; i++)
	{
		scanf("%f\t%f\n", &Temp[i], &Soc[i]);
	}
}

float minBMSParameterValue(float Temp[] , int size)
{
	min = Temp[0];
	for (int i = 0; i < BMS_DATA; i++)
	{
		if (Temp[i] < min)
			min = Temp[i];
	}
	return min;
}

float maxBMSParameterValue(float Temp[] , int size)
{
	max = Temp[0];
	for (int i = 0; i < BMS_DATA; i++)
	{
		if (Temp[i] > max)
			max = Temp[i];
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

	printf("min temp :%f\n", minBMSParameterValue(Temp,BMS_DATA));
	printf("max temp :%f\n", maxBMSParameterValue(Temp,BMS_DATA));
	printf("min Soc:%f\n",  minBMSParameterValue(Soc,BMS_DATA));
	printf("max Soc :%f\n", maxBMSParameterValue(Soc,BMS_DATA));
}
