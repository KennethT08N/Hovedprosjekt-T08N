// Th = 0.693 *(R1+R2) * C    -->  C1 = Th / (0.693 * (R1+R2) )
// Tl = 0.693 * (R2) * C      -->  C1 = Tl / (0.693 * R2 )
// f =  1.44 / ( (R1 + (2*R2)) * C )

const int inputPin = 2;  
float C1 = 0.0;
const float K = 0.693;
const float R1 = 99900.0;
const float R2 = 100100.0;


void setup() {
  Serial.begin(115200);
  Serial.println("\nTLC555IP-kapasitansmåling\n");
  
}

void loop() {
  unsigned long pulseHIGH = pulseIn(inputPin, HIGH);
  C1 = (pulseHIGH / 1e6) / (K * (R1 + R2));
  C1 = C1 * 1e9;
  if (C1 < 1.8 || C1 > 3.5) {
    Serial.println("Error");
  } else {
    Serial.print(C1);
    Serial.print(",");
    Serial.print("\n");
    delay(100);
  }
}



//