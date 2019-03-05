#include <MPU9250.h>

MPU9250 mp(Wire, 0x68);

float x, y, z;
float sfX, sfY, sfZ;
int cnt;

void gyroSetup() {
  mp.setGyroRange(MPU9250::GYRO_RANGE_1000DPS);
  mp.setGyroBiasX_rads(-0.000339);
  mp.setGyroBiasY_rads(-0.026297);
  mp.setGyroBiasZ_rads(0.015550);
}

//void magSetup() {
//  mp.setRange(MPU9250::GYRO_RANGE_1000DPS);
//  mp.setMagCalX();
//  mp.setMagCalY();
//  mp.setMagCalZ();
//}

void setup() {
//  initCalibration();
//  averageMagBias();
  Serial.begin(9600);
//  gyroSetup();
//  mp.begin();
  h206_begin();
}

void loop() {
  h206_updateSpeed();
  Serial.print(h206_speed_sps(), 6);
//  int t = millis();
//  mp.readSensor();
//  x = mp.getGyroX_rads();
//  y = mp.getGyroY_rads();
//  z = mp.getGyroZ_rads();
//  t = millis() - t + 14;
//  Serial.print(float(x*t/1000), 3);
//  Serial.print(' ');
//  Serial.print(float(y*t/1000), 3);
//  Serial.print(' ');
//  Serial.print(float(z*t/1000), 3);
  Serial.print('\n');
  delay(20);
}
