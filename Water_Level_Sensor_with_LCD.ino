//Name: Arduino Water Level Sensor with LCD
//Author: ZHYiNan
//Version: 1.0
//Website: https://github.com/ZHYiNan/Arduino-Water-Level-Sensor-with-LCD
//Copyright: This work is licensed under CC BY-NC-SA 4.0 
#include<LiquidCrystal_I2C.h>//Install library LiquidCrystal I2C by Frank de Brabander
LiquidCrystal_I2C lcd(0x27,16,2);//0x27 is the I2C bus address of the LCD
int WaterLevel;//Declare a integer variable, to store the analog value
void setup(){//The codes here run once to set everything up
  Serial.begin (9600);//Set up Serial, for debug purpose
  lcd.init();//Initialize the LCD
  lcd.backlight();//Turn on the backlight
  pinMode(A0,INPUT);//Set pin A0 as output, this is one of the water level sensor
  pinMode(A1,INPUT);//Set pin A1 as output, this is one of the water level sensor
  pinMode(8,OUTPUT);//Set pin 8 as input, this is a red LED, it lits up when water level is high
  pinMode(9,OUTPUT);//Set pin 9 as input, this is a yellow LED, it lits up when water level is medium
  pinMode(10,OUTPUT);//Set pin 10 as input, this is a green LED, it lits up when water level is low
}
void loop(){//The codes here repeats forever
  lcd.clear();//Clear the LCD screen
  WaterLevel=(analogRead(A0)+analogRead(A1))/2;//Calculate the average value of the 2 water level sensor
  Serial.println(WaterLevel);//Output the value to serial, for debug purpose
  lcd.setCursor(0,0);//Set LCD Cursor to (0,0), that is the top left corner of the screen
  lcd.print("Water Level:");//Output text "Water Level:" to the screen
  lcd.setCursor(0,1);//Set LCD Cursor to (0,1), that is the bottom left corner of the screen
  if(WaterLevel<=580){//If the value is lower or equal to 580, water level is low, edit this constant as needed
    lcd.print("LOW");//Output text "LOW" to the screen
    digitalWrite(8,HIGH);//Turn off the red LED, which indicates high water level
    digitalWrite(9,HIGH);//Turn off the yellow LED, which indicates medium water level
    digitalWrite(10,LOW);//Turn on the green LED, which indicates medium water level
  }else if(WaterLevel>580&&WaterLevel<=600){//If the value is greater than 580 but lower or equal to 600, water level is low, edit this constant as needed
    lcd.print("MEDIUM");//Output text "MEDIUM" to the screen
    digitalWrite(8,HIGH);//Turn off the red LED, which indicates high water level
    digitalWrite(9,LOW);//Turn on the yellow LED, which indicates medium water level
    digitalWrite(10,HIGH);//Turn of the green LED, which indicates medium water level
  }else{//If the value is greater than 600, water level is low, edit this constant as needed
    lcd.print("HIGH");//Output text "HIGH" to the screen
    digitalWrite(8,LOW);//Turn on the red LED, which indicates high water level
    digitalWrite(9,HIGH);//Turn off the yellow LED, which indicates medium water level
    digitalWrite(10,HIGH);//Turn off the green LED, which indicates medium water level
  }
  lcd.setCursor(8,1);//Set LCD Cursor to (8,1), that is the bottom center of the screen
  lcd.print(WaterLevel);//Output the value to the screen
  delay(1000);//Wait 1 second between tests, edit this constant as needed
}
