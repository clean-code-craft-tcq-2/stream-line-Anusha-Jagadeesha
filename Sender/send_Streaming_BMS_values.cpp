#include "send_Streaming_BMS_values.h"

prepareSensorInputToSender m_prepareSensorInputToSender;

bool readSensorDataFromTxt(string inputFile)
{
    ifstream inData;
    string line;
    float Soc;
    float Temperature;
    int i = 0;
    inData.open(inputFile);

    if (!inData)
    {
        return false;
    }

    while (getline(inData, line))
    {
        stringstream linestream(line);
        linestream >> Soc >> Temperature;
        m_prepareSensorInputToSender.SOC[i] = Soc;
        m_prepareSensorInputToSender.temperature[i] = Temperature;
        i++;
    }
    inData.close();
    return true;
}

bool sendSensorDataToRx()
{
    bool isSensorDataReadSuccessfully = readSensorDataFromTxt("./Sender/sensorStreamlineData.txt");
    std::fstream outData;
    outData.open("sensorStreamlineOutData.txt",ios::out);
    outData << "SOC" << "," << "Temprature" << endl;
    for (int line = 0; line < MAX_BMS_STREAM_READINGS; line++)
    {
        cout << m_prepareSensorInputToSender.SOC[line] << " , " << m_prepareSensorInputToSender.temperature[line] << endl;
        outData << m_prepareSensorInputToSender.SOC[line] << "," << m_prepareSensorInputToSender.temperature[line] << endl;
    }
    //outData.write("writing in this file.\n", sizeof("writing in this file.")); 
    outData.close();
    return isSensorDataReadSuccessfully;
}
