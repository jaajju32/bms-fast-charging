// Battery Management System - Fast Charging Logic (Arduino Nano)
#define TEMP_PIN A0
#define CELL1_PIN A1
#define CELL2_PIN A2
#define CELL3_PIN A3
#define CURRENT_PIN A4

int relayPin = 3; // MOSFET control
float temp, cell1, cell2, cell3, current;
float totalVoltage, avgVoltage;
int soc = 0;

void setup() {
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); // Start OFF
}

void loop() {
  temp = analogRead(TEMP_PIN) * (5.0 / 1023.0) * 100;
  cell1 = analogRead(CELL1_PIN) * (5.0 / 1023.0) * 4.2;
  cell2 = analogRead(CELL2_PIN) * (5.0 / 1023.0) * 4.2;
  cell3 = analogRead(CELL3_PIN) * (5.0 / 1023.0) * 4.2;
  totalVoltage = cell1 + cell2 + cell3;
  avgVoltage = totalVoltage / 3.0;

  soc = map(totalVoltage * 100, 9.0 * 100, 12.6 * 100, 0, 100);

  if (temp > 50 || cell1 > 4.2 || cell2 > 4.2 || cell3 > 4.2) {
    digitalWrite(relayPin, LOW);
  } else if (soc < 50) {
    analogWrite(relayPin, 255); // 200W equivalent full ON
  } else if (soc < 80) {
    analogWrite(relayPin, 200); // ~150W
  } else if (soc < 90) {
    analogWrite(relayPin, 130); // ~100W
  } else {
    analogWrite(relayPin, 50);  // ~50W
  }

  delay(1000);
}
