
int ledPin = 13;
int moisturePin = A0;
int timestep = 2000;
float moistureLevel = 0.0;

void setup() {
    pinMode(ledPin, OUTPUT);
    pinMode(moisturePin, INPUT);
    Serial.begin(9600);
}

void printToSerial(char *str)
{
    Serial.print(str);
    Serial.print((int) moistureLevel);
    Serial.print("\n");
}

void flashLed()
{
    for (int i = 4; i > 0; i--) {
        digitalWrite(ledPin, HIGH);
        delay(timestep / (i * 2));
        digitalWrite(ledPin, LOW);
        delay(timestep / (i * 2));
    }
}

void loop() {
    moistureLevel = analogRead(moisturePin);

    if (moistureLevel < 900 && moistureLevel > 700) {      
        printToSerial("Lorraine feels somewhat peckish... : ");
        flashLed();
    } else if (moistureLevel <= 700) {
        printToSerial("LORRAINE HAS TEH HUNGURR: ");
        digitalWrite(ledPin, HIGH);
        delay(timestep);
    } else {
        printToSerial("Lorraine is happy: ");
        digitalWrite(ledPin, LOW);
        delay(timestep);
    }
}
