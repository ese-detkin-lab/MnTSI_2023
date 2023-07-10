#define BLYNK_TEMPLATE_ID "TMPL2dfiz3knT"
#define BLYNK_TEMPLATE_NAME "MKR1010WiFi"
#define BLYNK_AUTH_TOKEN "PzDNhmWqymtpAalEOSxXu860omyDnryL"
#include <SPI.h>
#include <WiFiNINA.h>
#include <BlynkSimpleWiFiNINA.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "HP Setup";
char pass[] = "";

const int ledPin = 2;

int val;

BlynkTimer timer;

BLYNK_WRITE(V0)
{
  val = param.asInt();
  Serial.println(val);
  digitalWrite(ledPin, val); // fetch the switch value from the app
}

void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  // You can also specify server:
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
  Blynk.run();
}
