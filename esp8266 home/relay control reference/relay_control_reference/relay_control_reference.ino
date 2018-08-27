//#define BLYNK_DEBUG
#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266_HardSer.h>
#include <BlynkSimpleShieldEsp8266_HardSer.h>
#include <SimpleTimer.h>
#include <SPI.h>

// Set ESP8266 Serial object
#define EspSerial Serial

////Relay in Pin XX
//#define Relay10 6
//#define Relay11 7
//#define Relay12 12
//#define Relay13 13
//
//ESP8266 wifi(EspSerial);
//SimpleTimer timer;
//WidgetLCD lcd(V31);

// You should get Auth Token in the Blynk App.
char auth[] = "1e9e38e2197c46f79bbce0b7d0ee412b";

SimpleTimer timer;   // allocate a name (timer) to the timer

int relay1 = 5;
int relay2 = 6;
int relayVButton1 = 0;
int relayVButton2 = 0;




WidgetLED led1(10); //virtual led 
WidgetLED led2(11); //virtual led


void setup() 
{
  Serial.begin(9600); // See the connection status in Serial Monitor
  Blynk.begin(auth); //insert here your SSID and password
  timer.setInterval(600L, somefunction);
 
  pinMode(relay1, OUTPUT);
 
  pinMode(relay2, OUTPUT);

 
  
  digitalWrite(relay1, 1);
  digitalWrite(relay2, 1);
  
} 

void somefunction()
{

//

BLYNK_WRITE(V4)
{
   relayVButton1 = param.asInt(); // Get the state of the VButton
}
BLYNK_WRITE(V5)
{
    relayVButton2 = param.asInt(); // Get the state of the VButton
} 


void loop() 
{
  Blynk.run(); 
  timer.run();                 // call the simple timer routine
}
