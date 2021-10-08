//Micro Lab Project P10 - Smart Traffic System
//Done by: Mohammed Jawwadul Islam - 011 181 182, MD Fahad Al Rafi - 011 181 201, Aysha Siddika - 011 181 204
//Section: A

#include <Servo.h>

Servo myservo;
int pos = 0;

int red = 6;
int yellow = 7;
int green = 8;

int button13 = 13;
int button12 = 12;
int button11 = 11;
int button10 = 10;

void setup() {
  // put your setup code here, to run once:

  myservo.attach(4); //attach motor to pin 4

  //pin 6,7,8 will be output pins
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);

  //setup pin 13,12,11 as input pin
  pinMode(button13, INPUT_PULLUP);
  pinMode(button12, INPUT_PULLUP);
  pinMode(button11, INPUT_PULLUP);
  pinMode(button10, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:

  //check if switches are pressed
  int input13 = digitalRead(button13);
  int input12 = digitalRead(button12);
  int input11 = digitalRead(button11);
  int input10 = digitalRead(button10);

  if (input13 == LOW)
  {
    //turn on red led
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    delay(500);
  }
  else {
    //turn off red led
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    delay(500);
  }

  if (input12 == LOW) {
    //turn on yellow red
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    delay(500);

    //motor rotates at preset slow speed
    for (pos = 0; pos <= 180; pos += 1)
    {
      myservo.write(pos);
      delay(50);
    }
    for (pos = 180; pos >= 0; pos -= 1)
    {
      myservo.write(pos);
      delay(50);
    }
  }
  else {
    //turn off yellow led
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    delay(500);
  }

  if (input11 == LOW) {
    //Turn on green led
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    delay(500);

    //motor rotates at high speed
    myservo.write(0);
    delay(500);
    myservo.write(180);
    delay(500);
  }
  else {
    //turn off green led
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    delay(500);
  }

  //lights will turn on sequentially
  if (input10 == LOW) {
    digitalWrite(red, HIGH);
    delay(3000);
    digitalWrite(red, LOW);
    delay(50);

    //turn on green led
    digitalWrite(green, HIGH);

    //motor rotates at high speed
    myservo.write(0);
    delay(500);
    myservo.write(180);
    delay(500);

    myservo.write(180);
    delay(500);
    myservo.write(0);
    delay(500);

    myservo.write(0);
    delay(500);
    myservo.write(180);
    delay(500);

    myservo.write(180);
    delay(500);
    myservo.write(0);
    delay(500);

    delay(1000);
    digitalWrite(green, LOW);
    delay(50);

    //Turn on yellow led
    digitalWrite(yellow, HIGH);
    delay(3000);

    //motor rotates at preset slow speed
    for (pos = 0; pos <= 180; pos += 1)
    {
      myservo.write(pos);
      delay(50);
    }
    for (pos = 180; pos >= 0; pos -= 1)
    {
      myservo.write(pos);
      delay(50);
    }

    digitalWrite(yellow, LOW);
    delay(50);
  }

}
