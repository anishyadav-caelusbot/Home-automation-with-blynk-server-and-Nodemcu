


#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266_Lib.h>
#include <SoftwareSerial.h>
SoftwareSerial EspSerial(2, 3); // RX, TX
#include <BlynkSimpleShieldEsp8266.h>
#include <SimpleTimer.h> // here is the SimpleTimer library
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "YourAuthToken";
char ssid[] = "Funtoosh";
char pass[] = "ropera11";
#define EspSerial Serial

SimpleTimer timer;   // allocate a name (timer) to the timer
int relay1 = 7;
int relay2 = 8;
int relay3 = 9;
int button1 = 2;
int button2 = 3;
int button3 = 5;
int relayVButton1 = 0;
int relayVButton2 = 0;
int relayVButton3 = 0;

boolean relayState1 = 1;
boolean relayState2 = 1;
boolean relayState3 = 1;
boolean buttonState1 = 1;
boolean buttonState2 = 1;
boolean buttonState3 = 1;

WidgetLED led1(10); //virtual led 
WidgetLED led2(11); //virtual led
WidgetLED led3(12); //virtual led

// Your WiFi credentials.
// Set password to "" for open networks.

// Hardware Serial on Mega, Leonardo, Micro...


// or Software Serial on Uno, Nano...


// Your ESP8266 baud rate:
#define ESP8266_BAUD 9600

ESP8266 wifi(&EspSerial);


void setup()
{
  
  Serial.begin(9600); // See the connection status in Serial Monitor
  
  timer.setInterval(600L, somefunction);
 
  pinMode(relay1, OUTPUT);
  pinMode(button1,INPUT_PULLUP);
  pinMode(relay2, OUTPUT);
  pinMode(button2,INPUT_PULLUP);
  pinMode(relay3, OUTPUT);
  pinMode(button3,INPUT_PULLUP);
  digitalWrite(relay1, 1);
  digitalWrite(relay2, 1);
  digitalWrite(relay3, 1);
} 

void somefunction()
{

  buttonState1 = digitalRead (button1);
    if (buttonState1 < 1 || relayVButton1 > 0)
    {
    relayState1 = !relayState1;
    } 
    digitalWrite(relay1, relayState1);
    
      
  buttonState2 = digitalRead (button2);
    if (buttonState2 < 1 || relayVButton2 > 0)
    {
    relayState2 = !relayState2;
    } 
    digitalWrite(relay2, relayState2);

  buttonState3 = digitalRead (button3);
    if (buttonState3 < 1 || relayVButton3 > 0)
    {
    relayState3 = !relayState3;
    } 
    digitalWrite(relay3, relayState3);
  
  if (digitalRead(relay1) == LOW) //virtual led1
  {
   led1.on();
  }
   else
   led1.off();
  
  if (digitalRead(relay2) == LOW) //virtual led2
  {
   led2.on();
  }
   else
   led2.off();

  if (digitalRead(relay3) == LOW) //virtual led3
  {
   led3.on();
  }
   else
   led3.off();

}  

BLYNK_WRITE(V4)
{
   relayVButton1 = param.asInt(); // Get the state of the VButton
}
BLYNK_WRITE(V5)
{
    relayVButton2 = param.asInt(); // Get the state of the VButton
} 
BLYNK_WRITE(V6)
{
    relayVButton3 = param.asInt(); // Get the state of the VButton
} 
 
void loop() 
{
  Blynk.run(); 
  timer.run();                 // call the simple timer routine
}
