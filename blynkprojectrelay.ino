
//Include the library files
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
int relay1=D0;
int relay2=D1;
int relay3=D2;
int relay4=D3;
//get the credentials from blynk cloud
#define BLYNK_TEMPLATE_ID "placeholder"
#define BLYNK_DEVICE_NAME "placeholder"
#define BLYNK_AUTH_TOKEN "placeholder"
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "testtesttest";//Enter your WIFI name
char pass[] = "123456789";//Enter your WIFI password

//Get the button value
BLYNK_WRITE(V0) {
  digitalWrite(relay1, param.asInt());
}
BLYNK_WRITE(V1){
  digitalWrite(relay2, param.asInt());
}
BLYNK_WRITE(V2){
  digitalWrite(relay3, param.asInt());
}
BLYNK_WRITE(V3){
  digitalWrite(relay4, param.asInt());
}
BLYNK_CONNECTED(){
  Blynk.syncAll();
}
void setup() {
  //Set the LED pin as an output pin
  Serial.begin(115200);
  Serial.println("Welcome to the new project");
  pinMode(D1,OUTPUT);
  pinMode(D0, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  digitalWrite(relay1,HIGH);
  digitalWrite(relay2,HIGH);
  digitalWrite(relay3,HIGH);
  digitalWrite(relay4,HIGH);
  //Initialize the Blynk library
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop() {
  //Run the Blynk library
  Blynk.run();
}
