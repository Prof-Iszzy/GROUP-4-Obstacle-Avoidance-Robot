#include <LiquidCrystal.h>
int trig = 1;
int echo = 0;
int ma1 = 7;
int ma2 = 6;
int mb1 = 3;
int mb2 = 2;
int led = 4;

const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void Right() {
  lcd.setCursor(0, 1);
  lcd.print("OBSTACLE FOUND");
  delay(250);
  lcd.setCursor(0, 1);
  lcd.print("TURNING........");

  digitalWrite(ma1, HIGH);
  digitalWrite(ma2, LOW); 
  digitalWrite(mb1, LOW);
  digitalWrite(mb2, HIGH); 
  analogWrite(5, 225);
}

void Left() {
  lcd.setCursor(0, 1);
  lcd.print("LEFT......");

  digitalWrite(ma1, LOW);
  digitalWrite(ma2, HIGH); 
  digitalWrite(mb1, HIGH);
  digitalWrite(mb2, LOW); 
  analogWrite(5, 225);
}

void Forward() {
  lcd.setCursor(0, 1);
  lcd.print("MOVING FOWARD");

  digitalWrite(ma1, HIGH);
  digitalWrite(ma2, LOW); 
  digitalWrite(mb1, HIGH);
  digitalWrite(mb2, LOW); 
  analogWrite(5, 225);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(ma1, OUTPUT);
  pinMode(ma2, OUTPUT);
  pinMode(mb1, OUTPUT);
  pinMode(mb2, OUTPUT);
  pinMode(led, OUTPUT);

  randomSeed(analogRead(0));

}

void loop() {
  digitalWrite(trig, LOW);
  delay(3);
  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);
  // put your main code here, to run repeatedly:
  int duration = pulseIn(echo, HIGH);
  int distance = duration * 0.034/2;
    lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Distance: ");
  lcd.print(distance);

  if (distance >= 500) {
    Forward();
    digitalWrite(led, HIGH);
  }

  else {
    Right();
    digitalWrite(led, LOW);
    delay(150);
    digitalWrite(led, HIGH);
    delay(150);
 /*   digitalWrite(led, LOW);
    delay(150);
    digitalWrite(led, HIGH);
    delay(150);
    digitalWrite(led, LOW);
    delay(150);
    digitalWrite(led, HIGH);
    delay(150);
    digitalWrite(led, LOW);
    delay(150);
    digitalWrite(led, HIGH);
    delay(150);

    Left();
    digitalWrite(led, LOW);
    delay(150);
    digitalWrite(led, HIGH);
    delay(150);
    digitalWrite(led, LOW);
    delay(150);
    digitalWrite(led, HIGH);
    delay(150);
    digitalWrite(led, LOW);
    delay(150);
    digitalWrite(led, HIGH);
    delay(150);
    digitalWrite(led, LOW);
    delay(150);
    digitalWrite(led, HIGH);
    delay(150);*/
  }

}
