#define BLYNK_TEMPLATE_ID "TMPLVHbfo3EI"
#define BLYNK_DEVICE_NAME "HomeAutomation"
#define BLYNK_AUTH_TOKEN "BGrbtGR_2pedGHJAhDSO-nQhqAt1uWMc"

#define RelayPin1 5  //D1
#define RelayPin2 4  //D2
#define RelayPin3 14  //D5
#define RelayPin4 12  //D6

#define wifiLed   16   //D0

#define VPIN_BUTTON_1    V0 
#define VPIN_BUTTON_2    V1
#define VPIN_BUTTON_3    V2 
#define VPIN_BUTTON_4    V3

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char AUTH[] = BLYNK_AUTH_TOKEN;

char WIFI_SSID[] = "WIFI_SSID";     
char WIFI_PASS[] = "WIFI_PASS";
int wifiFlag = 1;

BlynkTimer timer; // Creating a timer object


void myTimerEvent() // This loop defines what happens when timer is triggered
{
  bool isconnected = Blynk.connected();
  if (isconnected == false) {
    wifiFlag = 1;
    digitalWrite(wifiLed, HIGH); //Turn off WiFi LED
  }
  if (isconnected == true) {
    wifiFlag = 0;
    digitalWrite(wifiLed, LOW); //Turn on WiFi LED
  }
}

void setup()
{
  Serial.begin(115200);
  
  pinMode(RelayPin1, OUTPUT);
  pinMode(RelayPin2, OUTPUT);
  pinMode(RelayPin3, OUTPUT);
  pinMode(RelayPin4, OUTPUT);
  pinMode(wifiLed, OUTPUT);

  digitalWrite(RelayPin1,1);
  digitalWrite(RelayPin2,1);
  digitalWrite(RelayPin3,1);
  digitalWrite(RelayPin4,1);
  
  Blynk.begin(AUTH, WIFI_SSID, WIFI_PASS);
  timer.setInterval(1000L, myTimerEvent);
}

BLYNK_CONNECTED() {
  // Request the latest state from the server
  Blynk.syncVirtual(VPIN_BUTTON_1);
  Blynk.syncVirtual(VPIN_BUTTON_2);
  Blynk.syncVirtual(VPIN_BUTTON_3);
  Blynk.syncVirtual(VPIN_BUTTON_4);
}

BLYNK_WRITE(V0) // Executes when the value of virtual pin 0 changes
{
  if(param.asInt() == 1)
  {
    // execute this code if the switch widget is now ON
    digitalWrite(RelayPin1,0);  // Set digital pin 2 HIGH
  }
  else
  {
    // execute this code if the switch widget is now OFF
    digitalWrite(RelayPin1,1);  // Set digital pin 2 LOW    
  }
}

BLYNK_WRITE(V1) // Executes when the value of virtual pin 0 changes
{
  if(param.asInt() == 1)
  {
    // execute this code if the switch widget is now ON
    digitalWrite(RelayPin2,0);  // Set digital pin 2 HIGH
  }
  else
  {
    // execute this code if the switch widget is now OFF
    digitalWrite(RelayPin2,1);  // Set digital pin 2 LOW    
  }
}

BLYNK_WRITE(V2) // Executes when the value of virtual pin 0 changes
{
  if(param.asInt() == 1)
  {
    // execute this code if the switch widget is now ON
    digitalWrite(RelayPin3, 0);  // Set digital pin 2 HIGH
  }
  else
  {
    // execute this code if the switch widget is now OFF
    digitalWrite(RelayPin3, 1);  // Set digital pin 2 LOW    
  }
}

BLYNK_WRITE(V3) // Executes when the value of virtual pin 0 changes
{
  if(param.asInt() == 1)
  {
    // execute this code if the switch widget is now ON
    digitalWrite(RelayPin4, 0);  // Set digital pin 2 HIGH
  }
  else
  {
    // execute this code if the switch widget is now OFF
    digitalWrite(RelayPin4, 1);  // Set digital pin 2 LOW    
  }
}


void loop()
{
  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.println("WiFi Not Connected");
  }
  else
  {
    Serial.println("WiFi Connected");
    Blynk.run();
  }

  timer.run(); // Initiates SimpleTimer  
}
