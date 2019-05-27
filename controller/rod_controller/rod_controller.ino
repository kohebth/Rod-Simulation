#include <SoftwareSerial.h>
#include "MPU9250.h"

#define HC05_RX_PIN 11
#define HC05_TX_PIN 10
SoftwareSerial bt(HC05_RX_PIN, HC05_TX_PIN);

#define MPU_REG_ADDR 0x68
MPU9250 mpu(Wire, MPU_REG_ADDR);

float ang[3], oldAng[3]; // angle roll pitch yaw (x, y, z)
float a[3]; // accelerometer (x, y, z) m/ss
float g[3]; // gyroscope (x, y, z) rad/s
float m[3]; // magnetometer (x, y, z) m/ss
int reel; // reel rotating
//float dt; // differential by time
//int lastU; // last time update
int lastO; // last time output
int i; // others

void setup() {
  Serial.begin(9600);
  ky040Setup();
  hc05Setup();
  mpu9250Setup();
}

void loop() {
  mpu.readSensor();
  oldAng[0] = ang[0];
  oldAng[1] = ang[1];
  oldAng[2] = ang[2];
  getAccel();
  getMag();
  getAngle();
//  dt = micros() - lastU;
  if (millis() - lastO > 20) {
    for (i = 0; i < 3; ++i) {
      Serial.print(oldAng[i]*0.6 + ang[i]*0.4, 3);
      Serial.print(',');
    }
    Serial.print(reel);
    Serial.print('\n');
    lastO = millis();
//    Serial.println(1.0f/dt, 2);
  }
//  lastU = micros();
}
