
/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/communication-between-two-esp32
 * Seamphore - 0x7c, 0x9e, 0xbd, 0x77, 0xb4, 0xb4
 */

// ARDUINO #2: TCP SERVER + AN LED
#include <SPI.h>
#include <Ethernet.h>

const int serverPort = 4080;

byte mac[] = {0x7c, 0x9e, 0xbd, 0x77, 0xb4, 0xb4};
EthernetServer TCPserver(serverPort);

void setup() {
  Serial.begin(115200);
  
  Serial.println("ARDUINO #2: TCP SERVER + AN LED");

  // Initialize Ethernet Shield:
  if (Ethernet.begin(mac) == 0)
    Serial.println("Failed to configure Ethernet using DHCP");

  // Print your local IP address:
  Serial.print("TCP Server IP address: ");
  Serial.println(Ethernet.localIP());
  Serial.println("-> Please update the serverAddress in Arduino #1 code");

  // Listening for a TCP client (from Arduino #1)
  TCPserver.begin();
}

void loop() {
  // Wait for a TCP client from Arduino #1:
  EthernetClient client = TCPserver.available();

  if (client) {
    // Read the command from the TCP client:
    char command = client.read();
    Serial.print("- Received command: ");
    Serial.println(command);

    if (command == '1')
      Serial.println("received: 1"); // Turn LED on
    else if (command == '0')
      Serial.println("received: 0");  // Turn LED off

    Ethernet.maintain();
  }
}
