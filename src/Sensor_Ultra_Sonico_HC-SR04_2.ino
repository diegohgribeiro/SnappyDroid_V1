#include <Ultrasonic.h>
#include <Wire.h>  // Comes with Arduino IDE
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

  LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

//Define os pinos para o trigger e echo
  #define pino_trigger 4
  #define pino_echo 5

//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);

void setup(){

  Serial.begin(9600);

  Serial.println("Lendo dados do sensor...");
  lcd.begin(20, 4);
  lcd.clear();
  lcd.backlight(); //Ativa a luz de fundo
  lcd.setCursor(0, 0); //seta o cursor na coluna 0 linha 1
  }

void loop()

{ 
  //Le as informacoes do sensor, em cm e pol
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
  //Exibe informacoes no serial monitor
  lcd.clear();
  //delay(500);
  //lcd.home ();
  lcd.setCursor(0, 0);
  lcd.print("Distancia em cm: ");
  lcd.setCursor(0, 1);
  lcd.print(cmMsec);
  //lcd.setCursor(0, 1);
  //lcd.print("Pol: ");
  //lcd.println(inMsec);
  //Serial.println(inMsec);
  //lcd.clear();

  delay(500);

}


