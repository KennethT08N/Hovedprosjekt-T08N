//
const float R_PULLUP = 33.8;                      // DENNE MÅ JUSTERES ETTER HVILKDEN MCU SOM BRUKES!! 
//
const int maxADCVerdi = 1023;                     // Maximum value of the analog-to-digital converter (ADC)

const int maalinger = 5;  // Antall målinger pr. funksjonskall til kapasitansmålingene.

const int P_COM_W = A0;  // 14
const int P1_W = A1;     // 15
const int P2_W = A2;     // 16
const int P3_W = A3;     // 17
const int P4_W = A4;     // 18
const int maalepinnerKapasitans[4] = { P1_W, P2_W, P3_W, P4_W };
float kapasitansVerdi[4] = { 0.0, 0.0, 0.0, 0.0 }; // Array som holder på alle kapasitansverdiene

void setup() {
  Serial.begin(115200);

  for (int i = 14; i <= 18; i++) {                // Analoge pinner. Alle som ikke er i bruk ved måling må stå som INPUT!
    pinMode(i, INPUT);
  }

  for (int j = 2; j <= 6; j++) {                  // Alle som ikke er i bruk ved måling må stå som INPUT!
    pinMode(j, INPUT);
  }
}


void loop() {

  // Utfører måling og streamer data til Excel
  kapasitans();
  Serial.print(kapasitansVerdi[0]);
  Serial.print(",");
  Serial.print(kapasitansVerdi[1]);
  Serial.print(",");
  Serial.print(kapasitansVerdi[2]);
  Serial.print(",");
  Serial.print(kapasitansVerdi[3]);
  Serial.print(",");
  Serial.print("\n");
  delay(200);
}

void kapasitans() {
  for (int pinneIndeks = maalepinnerKapasitans[0]; pinneIndeks <= maalepinnerKapasitans[3]; pinneIndeks++) {
    float sum = 0.0;
    for (int i = 1; i <= maalinger; i++) {

      pinMode(pinneIndeks, OUTPUT);
      pinMode(P_COM_W, INPUT_PULLUP);
      unsigned long u1 = micros();
      unsigned long t;
      int digitalVerdi;

      do {
        digitalVerdi = digitalRead(P_COM_W);
        unsigned long u2 = micros();
        t = abs(u2 - u1);
      } while ((digitalVerdi < 1) && (t < 400000L));

      pinMode(P_COM_W, INPUT);
      int ADCVerdi = analogRead(P_COM_W);
      digitalWrite(pinneIndeks, HIGH);
      int utladningstid = (int)(t / 1000L) * 5;
      delay(utladningstid);
      pinMode(P_COM_W, OUTPUT);
      pinMode(pinneIndeks, OUTPUT);
      digitalWrite(P_COM_W, LOW);
      digitalWrite(pinneIndeks, LOW);
      delay(utladningstid);
      pinMode(P_COM_W, INPUT);
      pinMode(pinneIndeks, INPUT);

      float kapasitans = -(float)t / R_PULLUP / log(1.0 - (float)ADCVerdi / (float)maxADCVerdi);
      sum = sum + kapasitans;
      delay(10);
    }  // snittmåling slutt

    kapasitansVerdi[pinneIndeks - 15] = sum / maalinger;  // oppdaterer arrayet. Det magiske tallet 15 er offset mellom maalepinnerKapasitans[] og kapasitansVerdi[]
  }

}  // Slutt på funksjonen kapasitans()






//