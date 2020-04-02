// Import required libraries

#include <Arduino.h>
#include <SoftwareSerial.h>

/**************************************************************************
 *          OBIEKTY
 *************************************************************************/
#define RELAY_PIN 5
#define LED_PIN 6

SoftwareSerial SerialSpy (2,3); // Input (data from devices)
char buffor;
String commandString;
String commandStop1 = "STO\r";
String commandStop2 = "STOP";
String commandRun1 = "RUN\r";

bool relayState;

//Funkcje
void  parseAndDoCommand (String command);


/**************************************************************************
 *          AKCJA !!!
 *************************************************************************/
void setup() {
    // Serial port for debugging purposes
    Serial.begin(2400);
    SerialSpy.begin(2400);
    Serial.println("Spy is spying...");
    pinMode(RELAY_PIN, OUTPUT);
    pinMode(LED_PIN, OUTPUT);
    delay(1000);
    digitalWrite(RELAY_PIN, HIGH);
    Serial.println("Relay is ON");
    digitalWrite(LED_PIN, HIGH);
}

void loop() {
    while (SerialSpy.available()) {
        buffor = SerialSpy.read();
        if (buffor=='\n') {
            //Serial.print("Spy said: ");
            // Serial.println(commandString);
            parseAndDoCommand(commandString);
            commandString = "";
        } else if (buffor == '\r') {
            // ignore it!
        } else {
            commandString += buffor;
        }
    }

    // Sprawdzam stan przekaznika, jesli on - zaswiecam diode
    relayState ? digitalWrite(LED_PIN, HIGH) : digitalWrite(LED_PIN, LOW);

}

void parseAndDoCommand (String command) {
    Serial.print("COMMAND: "); Serial.println(command);
  if (command == "STO") {
        Serial.println ("Spy turns compressor OFF");
        digitalWrite(RELAY_PIN, LOW);
        relayState = false;
    } else if (command == "RUN") {
    // Relay to 1
        Serial.println ("Spy turns compressor ON");
        digitalWrite(RELAY_PIN, HIGH);
        relayState = false;
    } else {
        //Serial.println ("Spy doesn't know what to do");
    }
}

