const int coin = 2;
//const int led = 8;
volatile int state = LOW;

void setup() {
  //pinMode(led, OUTPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(coin), blink, RISING);
}

void loop() {
}

void blink() {
  Serial.println("coin!");
}