/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/communication-between-two-esp32
 * Clean - 0x84, 0xcc, 0xa8, 0x7a, 0x66, 0x90
 */

// ARDUINO #1: TCP CLIENT + A BUTTON/SWITCH
#include <SPI.h>
#include <Ethernet.h>

const int serverPort = 4080;

int gre = 5;
int yel = 16;
int red = 17;

byte mac[] = {0x84, 0xcc, 0xa8, 0x7a, 0x66, 0x90};
IPAddress serverAddress(192, 168, 28, 182);
EthernetClient TCPclient;

void setup() {
  pinMode (5, OUTPUT);
  pinMode (16, OUTPUT);
  pinMode (17, OUTPUT);
  
  Serial.begin(115200);
  Serial.println("ARDUINO #1: TCP CLIENT + A BUTTON/SWITCH");

  // Initialize Ethernet Shield:
  if (Ethernet.begin(mac) == 0)
    Serial.println("Failed to configure Ethernet using DHCP");

  // connect to TCP server (Arduino #2)
  if (TCPclient.connect(serverAddress, serverPort))
    Serial.println("Connected to TCP server");
  else
    Serial.println("Failed to connect to TCP server");
}

void loop() {
  
  if (!TCPclient.connected()) {
    Serial.println("Connection is disconnected");
    TCPclient.stop();

    // reconnect to TCP server (Arduino #2)
    if (TCPclient.connect(serverAddress, serverPort))
      Serial.println("Reconnected to TCP server");
    else
      Serial.println("Failed to reconnect to TCP server");
  }

  digitalWrite(17, LOW);
  digitalWrite(5, HIGH);
  TCPclient.write('1');
  TCPclient.flush();
  Serial.println("- The button is pressed,  sent command: 1");
  delay(5000);
  
  digitalWrite(5, LOW);
  digitalWrite(16, HIGH);
  TCPclient.write('0');
  TCPclient.flush();
  Serial.println("- The button is released, sent command: 0");
  delay(3000);
  
  digitalWrite(16, LOW);
  digitalWrite(17, HIGH);
  delay(5000);

}
