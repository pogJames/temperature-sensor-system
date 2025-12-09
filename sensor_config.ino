void setup() {
  Serial.begin(9600);
}
void loop() {
  float temperature = analogRead(A0)/10.0;
  float humidity = analogRead(A1)/10.0;

  Serial.print(temperature);
  Serial.print(" °C     ");
  Serial.print(humidity);
  Serial.println("%");
  delay(1000);
}
