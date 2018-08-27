// Robo India Tutorial 
// Simple Home Automation 
// Hardware: NodeMCU Blynk Board


#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


char auth[] ="Your Auth. Key";// You should get Auth Token in the Blynk App.
                              // Go to the Project Settings (nut icon).
const int R1  = 5;            // Output Relay 1 GPI0 05 (D1)
const int R2  = 4;            // Output Relay 2 GPI0 04 (D2)


char ssid[] = "WorkStation";     // Your WiFi credentials.
char pass[] = "#Google.com";   // Set password to "" for open networks.

void setup()
{
  Serial.begin(9600);         // Debug console
  Blynk.begin(auth, ssid, pass);
  pinMode(R1,OUTPUT);
  pinMode(R2,OUTPUT);
}

void loop()
{
  Blynk.run();
  
}

