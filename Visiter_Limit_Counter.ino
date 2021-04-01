#include  <Servo.h>
#include <LCD_I2C.h>

Servo myservo;
LCD_I2C lcd(0x27);
const int button = 9;
const int trig = 10;
const int echo = 11;
int buttonstate, count, penambah, duration, distance = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(button, INPUT);
pinMode(echo, INPUT);
pinMode(trig, OUTPUT);

myservo.attach(8);
myservo.write(0);

lcd.begin();
lcd.backlight();
delay(200);

lcd.setCursor(2,0);
lcd.print("Starting the");
lcd.setCursor(5,1);
lcd.print("System");
delay(1000);
}

void masuk(){
digitalWrite(trig, LOW);
delayMicroseconds(2);
digitalWrite(trig, HIGH); 
delayMicroseconds(10);
digitalWrite(trig, LOW);

duration = pulseIn(echo, HIGH);
distance = duration*(0.034/2);

Serial.print("distance: ");
Serial.println(distance);
delay(200);

  if (distance<=20 && distance>=0){
  count = count + penambah;
  delay(200);
  penambah = 0;
  delay(200);
if(count>7){
  count == 7;
  delay(200);
}
}
else if (distance>25){
  penambah = 1;
  delay(200);
}

Serial.print("Jumlah orang: ");
Serial.println(count);
delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
masuk();
if(count >=7){
  myservo.write(0);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("The room is full");
  lcd.setCursor(0,1);
  lcd.print("Please wait");
  delay(200);
}
else{
myservo.write(90);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Maximum 7 people");
lcd.setCursor(0,1);
lcd.print("Total =");
lcd.setCursor(9,1);
lcd.print(count);
delay(200);
}
buttonstate = digitalRead(button);
if(buttonstate == HIGH){
  count = 0;
}
}
