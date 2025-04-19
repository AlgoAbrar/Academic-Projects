/*
Smart Home System:
1. Create base class called SmartDevice with:
        i. deviceID (string)
        ii. deviceName (string)
        iii. status (ON/OFF)

2. create two derived classes:
        i. SmartLight
        ii. SmartFan

3. In each class, create overloaded versions of a function called controlDevice():
    Overloaded Versions:
        i. controlDevice(ON/OFF) - sets the device status to ON/OFF
        ii. controlDevice(int level)- sets brightness for lights or speed for fans
        iii. controlDevice(string mode, int duration)- Applies a mode like "eco" or "turbo" for a given time
*/
#include <bits/stdc++.h>
using namespace std;

class SmartDevice
{
public:
    string deviceID;
    string deviceName;
    string status;

    SmartDevice(string id, string name)
    {
        deviceID = id;
        deviceName = name;
        status = "OFF";
    }

    void displayStatus()
    {
        cout << "Device ID: " << deviceID << ", Device Name: " << deviceName << ", Status: " << status << endl;
    }
};

class SmartLight : public SmartDevice
{
public:
    SmartLight(string id, string name) : SmartDevice(id, name) {}
    void controlDevice(string cmd)
    {
        if (cmd == "ON")
        {
            status = "ON";
        }
        else if (cmd == "OFF")
        {
            status = "OFF";
        }
    }

    void controlDevice(int brightness)
    {
        if (status == "ON")
        {
            cout << "Setting brightness to " << brightness << "%" << endl;
        }
        else
        {
            cout << "Light is OFF. Cannot set brightness." << endl;
        }
    }

    void controlDevice(string mode, int duration)
    {
        if (status == "ON")
        {
            cout << "Setting light to " << mode << " mode for " << duration << " minutes." << endl;
        }
        else
        {
            cout << "Light is OFF. Cannot set mode." << endl;
        }
    }
};
class SmartFan : public SmartDevice
{
public:
    SmartFan(string id, string name) : SmartDevice(id, name) {}
    void controlDevice(string cmd)
    {
        if (cmd == "ON")
        {
            status = "ON";
        }
        else if (cmd == "OFF")
        {
            status = "OFF";
        }
    }

    void controlDevice(int speed)
    {
        if (status == "ON")
        {
            cout << "Setting fan speed to " << speed << "%" << endl;
        }
        else
        {
            cout << "Fan is OFF. Cannot set speed." << endl;
        }
    }

    void controlDevice(string mode, int duration)
    {
        if (status == "ON")
        {
            cout << "Setting fan to " << mode << " mode for " << duration << " minutes." << endl;
        }
        else
        {
            cout << "Fan is OFF. Cannot set mode." << endl;
        }
    }
};
int main()
{
    SmartLight light("L001", "Living Room Light");
    SmartFan fan("F001", "Bedroom Fan");

    cout << "Smart Home System" << endl;

    light.controlDevice("ON");
    fan.controlDevice("ON");
    cout << "---------------------------" << endl;

    light.displayStatus();
    fan.displayStatus();
    cout << "---------------------------" << endl;

    light.controlDevice(75);
    fan.controlDevice(50);
    cout << "---------------------------" << endl;

    light.controlDevice("eco", 30);
    fan.controlDevice("turbo", 15);
    cout << "---------------------------" << endl;

    light.controlDevice("OFF");
    fan.controlDevice("OFF");
    cout << "---------------------------" << endl;

    light.displayStatus();
    fan.displayStatus();
    cout << "---------------------------" << endl;

    light.controlDevice(75);
    fan.controlDevice(50);
    cout << "---------------------------" << endl;

    light.controlDevice("eco", 30);
    fan.controlDevice("turbo", 15);
    cout << "---------------------------" << endl;

    return 0;
}

/*
Saiyedul Abrar
Year: 2nd, Semester: 1st,
Department of Computer Science and Engineering, 
Bangladesh Army University of Engineering & Technology (BAUET), 
Qadirabad Cantonment, Natore-6431, Rajshahi, Bangladesh,
Phone: +8801719718686, E-mail: saiyedul.abrar1430@gmail.com
*/