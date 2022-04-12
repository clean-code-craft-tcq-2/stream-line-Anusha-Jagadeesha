// Test driven Development. -> Define the testcase before implementation.
#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "BMS_Receiver/BMS_ReceiverStream.h"

SCENARIO("Get BMS parameters values from Sender output console and check minimum , maximuma and simple moving avarage for BMS parameters ")
{
    GIVEN("Receives the BMS parameters values line by line from the console")
    {	
	    	float Temperature[] = {1 , 1.5, 2.3, 3, 10.2, 5};
		float StateOfCharge[] = { 21, 22, 32.5 ,23.4, 25.5, 30.9};
	    	int NoOfTempSample = sizeof(Temperature) / sizeof(Temperature[0]);
	    	int NoOfSocSample = sizeof(StateOfCharge) / sizeof(StateOfCharge[0]) ;
		float expectedSMATemp = 3.6f ;
		float expectedSMASoc = 24.88f ;
		float expectedMinTemp = 1.0 ;
		float expectedMaxTemp = 10.2 ;
		float expectedMinSoc  = 21.0 ;
		float expectedMaxSoc  = 32.5 ;
     		int NoOfEnteries = 5;
        WHEN("reads Sender Data from console using readDataFromConsole")
        {
            readDataFromConsole();
            THEN("check min , max and SMA for BMS parametes temperature and SOC")
            {
		REQUIRE( minBMSParameterValue(Temperature, NoOfTempSample) == expectedMinTemp );
		REQUIRE( maxBMSParameterValue(Temperature, NoOfTempSample) == expectedMaxTemp);
		REQUIRE( minBMSParameterValue(StateOfCharge, NoOfSocSample) == expectedMinSoc);
		REQUIRE( maxBMSParameterValue(StateOfCharge, NoOfSocSample) == expectedMaxSoc);
		REQUIRE( calculateSMA(Temperature, NoOfEnteries) == expectedSMATemp);
		//REQUIRE( calculateSMA(StateOfCharge, NoOfEnteries) == expectedSMASoc );
		printData();
            }
	    
        }
    }
}
