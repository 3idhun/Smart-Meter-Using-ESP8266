#include <BlynkSimpleEsp8266.h>
#define BLYNK_TEMPLATE_ID "TMPL3fwV5fdU4"
#define BLYNK_TEMPLATE_NAME "LDR MINIPRO"
#define BLYNK_AUTH_TOKEN "sKm467qu1T1NIP5p-j48xaGlmq9h8y_f"

#define BLYNK_PRINT Serial

const char* ssid = "Redmi";
const char* password = "debugging78";
const char* auth = "sKm467qu1T1NIP5p-j48xaGlmq9h8y_f";

const int ldrPin = A0; // LDR sensor pin
int sensorValue = 0; // variable to store sensor reading
float voltage = 0; // variable to store voltage reading
float current = 0; // variable to store current reading
float power = 0; // variable to store power reading
float energy = 0; // variable to store energy reading
unsigned long lastTime = 0; // variable to store last measurement time
float kWh = 0; // variable to store total energy consumption in kWh

float unitCost = 0; // variable to store the cost per unit of electricity
float totalCost = 0; // variable to store the total cost of electricity consumed
float additionalCharges = 0; // variable to store the additional charges (10% of the total cost)

void setup() {
  Serial.begin(115200); // initialize serial communication
  Blynk.begin(auth, ssid, password); // initialize Blynk
}

void loop() {
  Blynk.run();
  unsigned long now = millis(); // current time in milliseconds
  if (now - lastTime >= 1000) { // take measurement every second
    sensorValue = analogRead(ldrPin); // read LDR sensor value
    voltage = sensorValue * 5.0 / 1023.0; // convert sensor value to voltage
    current = voltage / 100.0; // assume 100 ohm load resistor
    power = voltage * current; // calculate power
    energy += power / 3600.0; // calculate energy in Wh
    kWh = energy / 1000.0; // calculate total energy consumption in kWh

    // Calculate the unit cost based on the consumed units
    if (kWh <= 50) {
      unitCost = 2.0;
    } else if (kWh <= 100) {
      unitCost = 2.50;
    } else if (kWh <= 150) {
      unitCost = 2.75;
    } else if (kWh <= 250) {
      unitCost = 5.25;
    } else if (kWh <= 500) {
      unitCost = 6.30;
    } else if (kWh <= 800) {
      unitCost = 7.10;
    } else {
      unitCost = 7.10;
    }

    // Calculate the total cost and additional charges
    totalCost = kWh * unitCost;
    additionalCharges = totalCost * 0.10;

    Serial.print("Voltage: ");
    Serial.print(voltage, 2);
    Serial.print(" V, Current: ");
    Serial.print(current, 2);
    Serial.print(" A, Power: ");
    Serial.print(power, 2);
    Serial.print(" W, Energy: ");
    Serial.print(energy, 2);
    Serial.print(" kWh, Total Cost: Rs. ");
    Serial.print(totalCost, 2);
    Serial.print(", Additional Charges: Rs. ");
    Serial.println(additionalCharges, 2);
    lastTime = now;
    Blynk.virtualWrite(V0, voltage); 
    Blynk.virtualWrite(V1, current);
    Blynk.virtualWrite(V2, power);
    Blynk.virtualWrite(V3, energy);
    Blynk.virtualWrite(V4, kWh);
    Blynk.virtualWrite(V5, additionalCharges); 
  }
}
