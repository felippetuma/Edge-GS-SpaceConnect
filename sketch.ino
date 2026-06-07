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
  // put your main code here, to run repeatedly:

}
