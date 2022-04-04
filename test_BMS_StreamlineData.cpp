// Test driven Development. -> Define the testcase before implementation.
#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "Sender/send_Streaming_BMS_values.h"

TEST_CASE("Test whether sensor inputs can be read from text file")
{
  REQUIRE(readSensorDataFromTxt("./Sender/sensorStreamlineData.txt") == true);
}
