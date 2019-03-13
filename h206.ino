#define H206_DPIN 2

uint16_t t0 = 1, t1 = 0;
uint16_t t = 1;

void h206_begin() {
  pinMode(H206_DPIN, INPUT);
}

float h206_speed_sps() {
  return 1.0/t*1000;
}

void h206_updateSpeed() {
  if (digitalRead(H206_DPIN) == HIGH) {
    t0 = millis();
  } else {
    t1 = millis();
  }
  t = abs(t0 - t1);
}
