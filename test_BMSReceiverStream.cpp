// Test driven Development. -> Define the testcase before implementation.
#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "BMS_Receiver/BMS_ReceiverStream.h"

SCENARIO("Get BMS parameters values from Sender output console and check minimum , maximuma and simple moving avarage for BMS parameters ")
{
    GIVEN("Receives the BMS parameters values line by line from the console")
    {	float Temperature[BMS_DATA] = {1 , 1.5, 2.3, 3, 10.2, 5};
		float StateOfCharge[BMS_DATA] = { 21, 22, 32.5 ,23.4, 25.5, 30.9};
		float expectedSMATemp = 3.6 ;
		float expectedSMASoc = 24.88 ;
		float expectedMinTemp = 1.0 ;
		float expectedMaxTemp = 10.2 ;
		float expectedMinSoc  = 21.0 ;
		float expectedMaxSoc  = 32.5 ;
        WHEN("reads Sender Data from console using readDataFromConsole")
        {
            readDataFromConsole();
				float Soc_SMA = calculateSMA(StateOfCharge ,NoOfEnteries);
				float Temp_SMA = calculateSMA(Temperature ,NoOfEnteries);
            THEN("check min , max and SMA for BMS parametes temperature and SOC")
            {
				REQUIRE( calculateSMA(StateOfCharge ,NoOfEnteries)) == expectedSMASoc );
				REQUIRE( calculateSMA(Temperature ,NoOfEnteries) == expectedSMATemp);
				REQUIRE( minBMSParameterValue(Temperature, BMS_DATA) == expectedMinTemp );
				REQUIRE( maxBMSParameterValue(Temperature, BMS_DATA) == expectedMaxTemp);
				REQUIRE( minBMSParameterValue(StateOfCharge, BMS_DATA) == expectedMinSoc);
				REQUIRE( maxBMSParameterValue(StateOfCharge, BMS_DATA) == expectedMaxSoc);
            }
        }
    }
}
