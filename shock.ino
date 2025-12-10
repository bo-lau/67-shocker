// 4‑channel relay module, channel 1 on IN1
// IN1 is wired to Arduino digital pin 7
// Module is assumed ACTIVE-LOW: LOW = relay ON, HIGH = relay OFF

const int RELAY_PIN = 7;

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);   // start with relay OFF
  Serial.begin(9600);
  Serial.println("TENS relay on D7. Type 1=ON, 0=OFF, p=pulse");
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();

    if (c == '1') {                 // keep relay ON
      digitalWrite(RELAY_PIN, LOW); // relay closes COM1-NO1
      Serial.println("Relay ON");
    }
    else if (c == '0') {            // keep relay OFF
      digitalWrite(RELAY_PIN, HIGH);
      Serial.println("Relay OFF");
    }
    else if (c == 'p') {            // 300 ms pulse
      Serial.println("Pulse");
      digitalWrite(RELAY_PIN, LOW); // ON
      delay(1000);
      digitalWrite(RELAY_PIN, HIGH); // OFF
    }
  }
}
