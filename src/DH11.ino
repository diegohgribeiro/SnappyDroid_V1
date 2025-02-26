#include <Wire.h>  // Comes with Arduino IDE
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);


#if defined(ARDUINO) && ARDUINO >= 100
#define printByte(args)  write(args);
#else
#define printByte(args)  print(args,BYTE);
#endif
#define DHTTYPE DHT11
#define DHT11PIN 2

DHT dht(DHT11PIN, DHTTYPE);

uint8_t bell[8]  = {0x4, 0xe, 0xe, 0xe, 0x1f, 0x0, 0x4};
uint8_t note[8]  = {0x2, 0x3, 0x2, 0xe, 0x1e, 0xc, 0x0};
uint8_t clock[8] = {0x0, 0xe, 0x15, 0x17, 0x11, 0xe, 0x0};
uint8_t heart[8] = {0x0, 0xa, 0x1f, 0x1f, 0xe, 0x4, 0x0};
uint8_t duck[8]  = {0x0, 0xc, 0x1d, 0xf, 0xf, 0x6, 0x0};
uint8_t check[8] = {0x0, 0x1, 0x3, 0x16, 0x1c, 0x8, 0x0};
uint8_t cross[8] = {0x0, 0x1b, 0xe, 0x4, 0xe, 0x1b, 0x0};
uint8_t retarrow[8] = {  0x1, 0x1, 0x5, 0x9, 0x1f, 0x8, 0x4};
byte grau[8] = { B00001100,
                 B00010010,
                 B00010010,
                 B00001100,
                 B00000000,
                 B00000000,
                 B00000000,
                 B00000000
               };

void setup()
{
  lcd.begin(20, 4);
  dht.begin();
  for (int i = 0; i < 3; i++)
  {
    lcd.backlight();
    delay(250);
    lcd.noBacklight();

  }
  lcd.backlight(); //Ativa a luz de fundo
  lcd.setCursor(0, 0); //seta o cursor na coluna 0 linha 1
  delay(2000);

}


void VerificaDisplay(int AContador) {
  if (AContador == 20000) {
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    lcd.clear();
    lcd.home ();
    lcd.setCursor(2, 0);
    lcd.print(t);
    lcd.printByte(8);
    lcd.print(" H:");
    lcd.print(h);
    lcd.print("%");
    lcd.setCursor(0, 2);
    if (t >= 25) {
      lcd.print("Muito Quente #CPBR9");
    } if(t <= 18) {
      lcd.print("Ate 25Graus e Legal");
    } if(t <=12 ){
    lcd.print("Muito Frio :(");
    }

  }
}


void loop()
{

  VerificaDisplay(20000);
  delay(1000);



}
