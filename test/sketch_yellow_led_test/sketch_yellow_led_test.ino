#define pyroelectric 14

void setup() {
Serial.begin(9900);
pinMode(pyroelectric, INPUT);
}

void loop() {
boolean pyroelectric_val = digitalRead(pyroelectric);
Serial.print("pyroelectric value = ");
Serial.println(pyroelectric_val);
delay(1000);
}