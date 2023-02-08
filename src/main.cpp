#include <Arduino.h>
#include <float.h>
#include <stdio.h>
#include <stdbool.h>
// Potentiometer is connected to GPIO 34 (Analog ADC1_CH6)
const int potPin = 15;
const int heatPin = 4;
const int Tmin=37;
const int Tmax=40;
int connected = false;
float getVoltageFromAnalogReading(float value)
{
  return 3300 * (value / 4096);
}

float getResistanceFormVoltage(float Va)
{
  float Vcc = 3300;
  float R0 = 102.9; // k Divider resistor
  // Va=Vcc*Rntc/(R0+Rntc)
  float Rntc = -(R0 * Va) / (Va - Vcc);
  return Rntc;
}
float getTemperatureFormResistance(float Rntc, bool kelvin = false)

{
  float K = 273.15;
  float T1, T2 = K + 25;
  float B = 3950.0;
  float R = 100; // T2 resistance
  float Temp;

  T1 = 1 / ((log(Rntc / R)) / B + 1 / T2);
  if (kelvin)
    return T1;
  else
    return T1 - K;
}
float readTemperature(int potPin)
{
  // variable for storing the potentiometer value
  int potValue;
  float T;
  potValue = analogRead(potPin);
  T = getTemperatureFormResistance(getResistanceFormVoltage(getVoltageFromAnalogReading(potValue)));
  return T;
}

void setup()
{
  Serial.begin(115200);
  delay(1000);

  pinMode(heatPin, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(potPin, INPUT);
}

void loop()
{
  // Reading potentiometer value
  int potValue;
  float T, Rntc, Vntc, temp;
  potValue = analogRead(potPin);
  Vntc = getVoltageFromAnalogReading(potValue);
  Rntc = getResistanceFormVoltage(Vntc);
  temp = getTemperatureFormResistance(Rntc);
  // Serial.print("Vntc:");
  // Serial.println(Vntc);
  // Serial.print("Rntc:");
  // Serial.println(Rntc);
  Serial.print("temp:");
  // Serial.println(temp);
  Serial.println(readTemperature(potPin));
  Serial.println(temp);

  if (temp < Tmin)
  {
    
    // digitalWrite(23,HIGH);
    analogWrite(23, 64);

    analogWrite(heatPin, 0);
    // dital
    Serial.println("heating start");
  }
  if (temp > Tmax)
  {
    // digitalWrite(heatPin,HIGH);
    // digitalWrite(23,LOW);
    analogWrite(23, 0);

    analogWrite(heatPin, 255);
    Serial.println("heating stop");
  }

  delay(1000);
}
