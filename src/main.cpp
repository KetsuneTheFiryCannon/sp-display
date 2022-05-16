#include <Arduino.h>
#include <Wire.h>

int latchPin = 4;
int clockPin = 7;
int dataPin = 8;

String coreNumber = "";
uint8_t positions[4] = {0xF1, 0xF2, 0xF4, 0xF8};

void setup()
{
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  Serial.begin(9600);
}

void setNum(int num, uint8_t pos)
{
  if (num == 1)
  {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, ~B01100000);
    shiftOut(dataPin, clockPin, MSBFIRST, pos);
    digitalWrite(latchPin, HIGH);
  }
  else if (num == 2)
  {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, ~B11011010);
    shiftOut(dataPin, clockPin, MSBFIRST, pos);
    digitalWrite(latchPin, HIGH);
  }
  else if (num == 3)
  {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, ~B11110010);
    shiftOut(dataPin, clockPin, MSBFIRST, pos);
    digitalWrite(latchPin, HIGH);
  }
  else if (num == 4)
  {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, ~B01100110);
    shiftOut(dataPin, clockPin, MSBFIRST, pos);
    digitalWrite(latchPin, HIGH);
  }
  else if (num == 5)
  {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, ~B10110110);
    shiftOut(dataPin, clockPin, MSBFIRST, pos);
    digitalWrite(latchPin, HIGH);
  }
  else if (num == 6)
  {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, ~B10111110);
    shiftOut(dataPin, clockPin, MSBFIRST, pos);
    digitalWrite(latchPin, HIGH);
  }
  else if (num == 7)
  {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, ~B11100000);
    shiftOut(dataPin, clockPin, MSBFIRST, pos);
    digitalWrite(latchPin, HIGH);
  }
  else if (num == 8)
  {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, ~B11111110);
    shiftOut(dataPin, clockPin, MSBFIRST, pos);
    digitalWrite(latchPin, HIGH);
  }
  else if (num == 9)
  {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, ~B11110110);
    shiftOut(dataPin, clockPin, MSBFIRST, pos);
    digitalWrite(latchPin, HIGH);
  }
  else if (num == 0)
  {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, ~B11111100);
    shiftOut(dataPin, clockPin, MSBFIRST, pos);
    digitalWrite(latchPin, HIGH);
  }
}

void loop()
{
  int parts[4] = {0, 0, 0, 0};

  if (Serial.available() > 0)
  {
    String gg = Serial.readString();
    int number = gg.toInt();
    int i = 3;
    if (number > -1 && number < 10000)
    {
      while (number != 0)
      {
        int a = number % 10;
        parts[i] = a;
        number /= 10;
        i--;
      }
      while (true)
      {
        for (size_t i = 0; i < 4; i++)
        {
          setNum(parts[i], positions[i]);
          Serial.println(parts[i]);
        }
      }
    }
  }
}