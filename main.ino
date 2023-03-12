// C++ code
//

#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

const int sensor = A0;
int tempc;
float tempf;
float vout;
float adc;
int pinbuzz = 3;
int pinLampuMerah = 13;
int pinLampuBiru = 12;
int song[]= {500};
int durasi[]= {1200};

void setup()
{
  lcd.begin(16, 2);
  pinMode(pinbuzz, OUTPUT);
  
}

void loop()
{
  lcd.setBacklight(1);
  lcd.clear();
  adc = analogRead(sensor);
  vout = adc / 1023 * 5;
  tempc = vout * 100;
  tempf = (tempc * 1.8) + 32;
  lcd.print(tempc);
  lcd.print(" C");
  lcd.setCursor(0,1);
  lcd.print(tempf);
  lcd.print(" F");
  pinMode(pinLampuBiru, OUTPUT);
  pinMode(pinLampuMerah, OUTPUT);
  if(tempc > 76) {
  	for (int note = 0; note <1; note ++){
      tone(pinbuzz, song[note], durasi[note]);
      digitalWrite(pinLampuMerah, HIGH);
      
  	}
  }
  else {
    digitalWrite(pinLampuBiru, HIGH);
  }
  delay(2000);
  digitalWrite(pinLampuMerah, LOW);
  digitalWrite(pinLampuBiru, LOW);
}
