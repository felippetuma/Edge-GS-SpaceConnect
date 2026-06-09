#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#define trigger 13
#define echo 8

#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2);

int umi = 0;
int temp = 0;
int dist = 0;


void setup() {
  Serial.begin(9600);
  lcd.init();                     
  lcd.backlight();
  dht.begin();
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  
  dist = pulseIn(echo, HIGH);
  
  dist = dist / 58;
  temp = dht.readTemperature();
  umi = dht.readHumidity();
  
  if(dist > 7) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("ALERTA!!!");
    lcd.setCursor(0,3);
    lcd.print("Alagamento Detectado");
    lcd.setCursor(0,2);
    lcd.print("Profundidade: ");
    lcd.print(dist);
    lcd.print("cm");
    delay(2000); 
  } else {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Sistema Orbita");
    lcd.setCursor(0,3);
    lcd.print("Nenhuma Alagamento");
    delay(2000); 
  } 
  if(temp > 30) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("ALERTA!!!");
    lcd.setCursor(0,3);
    lcd.print("Temperatura Alta");
    lcd.setCursor(0,2);
    lcd.print("Temperatura: ");
    lcd.print(temp);
    lcd.print("C");
    delay(2000); 
  } else if(temp < 18 ) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("ALERTA!!!");
    lcd.setCursor(0,1);
    lcd.print("Temperatura Baixa");
    lcd.setCursor(0,2);
    lcd.print("Temperatura: ");
    lcd.print(temp);
    lcd.print("C");
    delay(2000); 
  } else {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Sistema Orbita");
    lcd.setCursor(0,3);
    lcd.print("Temperatura Amena");
    lcd.setCursor(0,2);
    lcd.print("Temperatura: ");
    lcd.print(temp);
    lcd.print("C");
    delay(2000); 
  }
  if(umi > 40) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("ALERTA!!!");
    lcd.setCursor(0,1);
    lcd.print("Umidade Alta");
    lcd.setCursor(0,2);
    lcd.print("Umidade: ");
    lcd.print(umi);
    lcd.print("%");
    delay(2000); 
  } else if(umi < 10) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("ALERTA!!!");
    lcd.setCursor(0,1);
    lcd.print("Umidade Baixa");
    lcd.setCursor(0,2);
    lcd.print("Umidade: ");
    lcd.print(umi);
    lcd.print("%");
    delay(2000); 
  } else {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Sistema Orbita");
    lcd.setCursor(0,1);
    lcd.print("Umidade Normal");
    lcd.setCursor(0,2);
    lcd.print("Umidade: ");
    lcd.print(umi);
    lcd.print("%");
    delay(2000); 
  }
}
