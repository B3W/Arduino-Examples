const uint8_t LED_PIN = 2;
bool ledOn = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (ledOn)
  {
    ledOn = false;
    digitalWrite(LED_PIN, LOW);  // Turn LED off
  }
  else
  {
    ledOn = true;
    digitalWrite(LED_PIN, HIGH); // Turn LED off
  }

  delay(500U);
}
