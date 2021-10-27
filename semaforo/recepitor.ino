#include <WiFi.h>

const char* ssid = "internet";
const char* password =  "ilarilarie";

int gre = 5;
int yel = 16;
int red = 17;

WiFiServer server(80);
WiFiClient cl;
void setup() {
  pinMode (5, OUTPUT);
  pinMode (16, OUTPUT);
  pinMode (17, OUTPUT);

  Serial.begin(115200);
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
}

void loop () {

  digitalWrite(17, LOW);
  digitalWrite(5, HIGH);
  delay(5000);
  digitalWrite(5, LOW);
  digitalWrite(16, HIGH);
  delay(3000);
  digitalWrite(16, LOW);
  digitalWrite(17, HIGH);
  delay(5000);
}
