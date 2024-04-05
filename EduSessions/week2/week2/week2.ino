int sensor_pin = 6;
int sensor_value;
int led_pin = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(sensor_pin, INPUT);
  pinMode(led_pin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensor_value = digitalRead(sensor_pin) ;
  digitalWrite(led_pin, bool(sensor_value>40));
}
