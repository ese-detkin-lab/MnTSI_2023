#define BLYNK_TEMPLATE_ID "TMPL2p9wJ0rmO"
#define BLYNK_TEMPLATE_NAME "LCD MKR 1010"
#define BLYNK_AUTH_TOKEN "3io2qrjoiVVBVE4cF2IGg324jB1GPWPB"

// include the library code:
#include <SPI.h>
#include <WiFiNINA.h>
#include <BlynkSimpleWiFiNINA.h>


// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Halo i bims der FritZ";
char pass[] = "Keine#Hose!Wlan42";

#include <DHT.h>
#define DHTPIN 4

DHT dht(DHTPIN, DHT11);
float h;
float t;

void setup() {
 
  Serial.begin(9600);
  dht.begin();
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  Serial.println("starting");
  Blynk.virtualWrite(V0, "temp");
  Blynk.virtualWrite(V1, "humidity");
}


void loop() {
  Blynk.run();
  // Wait a few seconds between measurements.
  delay(2000);
  h = dht.readHumidity();
  t = dht.readTemperature();
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)

  Serial.print("Temperature: ");
  Serial.println(t);
  Blynk.virtualWrite(V0, t);
  
  delay(100);
  
  Serial.print("Humidity: ");
  Serial.println(h);
  Blynk.virtualWrite(V1, h);
  
}
