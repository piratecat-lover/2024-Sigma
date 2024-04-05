const int motor1pin1 = 3;
const int motor1pin2 = 11;
const int motor2pin1 = 5;
const int motor2pin2 = 6;
const byte irPin1 = A0;
const byte irPin2 = A1;

void setup() {
  Serial.begin(115200);
  Serial.println("Serial monitoring has begun.");
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(irPin1, INPUT);
  pinMode(irPin2, INPUT);
}

void forward() {
  analogWrite(motor1pin1, 255);
  analogWrite(motor2pin1, 255);
  analogWrite(motor1pin2, 0);
  analogWrite(motor2pin2, 0);
  delay(2000);
}

void backward() {
  analogWrite(motor1pin1, 0);
  analogWrite(motor2pin1, 0);
  analogWrite(motor1pin2, 255);
  analogWrite(motor2pin2, 255);
  delay(2000);
}

void turn_left() {
  analogWrite(motor1pin1, 255);
  analogWrite(motor2pin1, 0);
  analogWrite(motor1pin2, 0);
  analogWrite(motor2pin2, 255);
  delay(2000);
}

void turn_right() {
  analogWrite(motor1pin1, 0);
  analogWrite(motor2pin1, 255);
  analogWrite(motor1pin2, 255);
  analogWrite(motor2pin2, 0);
  delay(2000);
}

void stop() {
  analogWrite(motor1pin1, 0);
  analogWrite(motor2pin1, 0);
  analogWrite(motor1pin2, 0);
  analogWrite(motor2pin2, 0);
  delay(2000);
}

float InputVoltage(char pinNo, float inputVal) {
  float outputVal = inputVal*5.0/1023;
  if (pinNo == irPin1){
    Serial.print("Left: ");
    Serial.println(outputVal);
  } else {
    Serial.print("Right: ");
    Serial.println(outputVal);
  }
  return outputVal;
}

void loop() {
  stop();
  float input1 = analogRead(irPin1);
  float input2 = analogRead(irPin2);
  float output1 = InputVoltage(irPin1, input1);
  float output2 = InputVoltage(irPin2, input2);
  if (output1>2 && output2>2) {
    forward();
  } else if (output1<2 && output2>2) {
    turn_left();
  } else if (output1>2 && output2<2) {
    turn_right();
  } else {
    backward();
  }
}