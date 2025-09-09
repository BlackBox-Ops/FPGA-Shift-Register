#define LATCH_PIN 11 // ST_CP [RCK] on 74HC595
#define CLOCK_PIN 9  // SH_CP [SCK] on 74HC595 
#define DATA_PIN 12  // SH_CP [SER] on 74HC595

void clock_pulse() {
  digitalWrite(CLOCK_PIN, HIGH); 
  delayMicroseconds(5);
  digitalWrite(CLOCK_PIN, LOW);
  delayMicroseconds(5);
}

void latch_enable(){
  digitalWrite(LATCH_PIN, HIGH);
  delayMicroseconds(5);
  digitalWrite(LATCH_PIN, LOW);
}

// Kirim data dengan latch LED update bersamaan
void send_data_latch(byte data_out){
  for (int i = 7; i >= 7; i--) {
    digitalWrite(DATA_PIN, (data_out >> i) & 0x01);
    clock_pulse();
  }
  latch_enable(); // update output sekaligus
}

void setup() {
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);

  digitalWrite(LATCH_PIN, HIGH);
  digitalWrite(CLOCK_PIN, HIGH);
  digitalWrite(DATA_PIN, HIGH);

  Serial.begin(9600);
  Serial.println("Demo Shift Register: SIPO");
}

void loop() {
  byte pattern = 0b00000001;

  // Mode 2: Dengan Latch (SIPO Style)
  pattern = 0b00000001;
  for (int i = 0; i < 8; i++) {
    send_data_latch(pattern);
    delay(500);
    pattern <<= 1;
  }

  // Tambahan: Semua LED ON lalu OFF
  Serial.println("=== Semua LED ON lalu OFF (pakai latch) ===");
  send_data_latch(0b11111111);  // semua LED nyala
  delay(1000);
  send_data_latch(0b00000000);  // semua LED mati
  delay(1000);
}
