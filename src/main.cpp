// Import required libraries

#include <Arduino.h>
#include <SoftwareSerial.h>

/**************************************************************************
 *          OBIEKTY
 *************************************************************************/
#define RELAY_PIN 5
#define RELAY_LED_PIN 6
#define MANUAL_BUTTON_PIN 8


SoftwareSerial SerialSpy(2, 3); // Input (data from devices)
unsigned char buffor;
String commandString;
//String commandStop1 = "STO\r";
//String commandStop2 = "STOP";
//String commandRun1 = "RUN\r";

bool relayState;
int manualButtonState = LOW;


// Debouncing
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 200;    // the debounce time; increase if the output flickers

//Funkcje
void parseAndDoCommand(const String& command);


/**************************************************************************
 *          AKCJA !!!
 *************************************************************************/
void setup() {
    // Serial port for debugging purposes
    Serial.begin(2400);
    SerialSpy.begin(2400);
    Serial.println("Spy is spying...");

    // Set input/output
    pinMode(RELAY_PIN, OUTPUT);
    pinMode(RELAY_LED_PIN, OUTPUT);

    // Drugi pin guzika do masy, normalny stan przycisku = HIGH
    pinMode(MANUAL_BUTTON_PIN, INPUT_PULLUP);       // Pin podciągniety do VCC przez rezystor.

    //delay(1000);

    // Ustalam poczatkowe wartosci pinow
    digitalWrite(RELAY_PIN, LOW);
    relayState = false;
    manualButtonState = LOW;
}

void loop() {
    while (SerialSpy.available()) {
        buffor = SerialSpy.read();
        if (buffor == '\n') {
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

    // TODO check it!
    // Sprawdzam czy stan przekaźnika zostal zmieniony przez COM, jesli tak, zmieniam diodę i status na buttonie
    if (relayState) {
        digitalWrite(RELAY_LED_PIN, HIGH);
        manualButtonState = true;
    } else {
        digitalWrite(RELAY_LED_PIN, LOW);
        manualButtonState = false;
    }

    int readButtonState = digitalRead(MANUAL_BUTTON_PIN);
    // sprawdzam, czy nacisnieto guzik i przytrzymano go > delayDeboucne
    if (readButtonState == LOW && millis() - lastDebounceTime > debounceDelay) {
        relayState = !manualButtonState;
        lastDebounceTime = millis();
    }
}
// Odbieramy 'command' jako referencje - czyli odbieramy sam adres do obiektu command (nie jest przesyłana kopia obiektu)
// ale traktujemy go jako zwykly obiekt ( a nie jako adres). Alias const, mówi iż, obiekt nie będzie zmieniany w tej funkcji.
void parseAndDoCommand(const String& command) {
    Serial.print("RECEIVED COMMAND: ");
    Serial.println(command);
    if (command == "STO") {
        // Relay to 0
        Serial.println("\tSpy turns compressor OFF");
        digitalWrite(RELAY_PIN, LOW);
        relayState = false;
    } else if (command == "RUN") {
        // Relay to 1
        Serial.println("\tSpy turns compressor ON");
        digitalWrite(RELAY_PIN, HIGH);
        relayState = true;
    } else {
        //Serial.println ("Spy doesn't know what to do");
    }
}

