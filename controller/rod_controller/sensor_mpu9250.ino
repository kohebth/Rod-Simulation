void mpu9250Setup() {
  accelSetup();
  gyroSetup();
  magSetup();
  // Low pass filter 20Hz
  mpu.setDlpfBandwidth(MPU9250::DLPF_BANDWIDTH_20HZ);
  // Update Rate 100Hz
  mpu.setSrd(10);
  mpu.begin();
}

void gyroSetup() {
  mpu.setGyroRange(MPU9250::GYRO_RANGE_1000DPS);
  mpu.setGyroBiasX_rads(-0.000339);
  mpu.setGyroBiasY_rads(-0.026297);
  mpu.setGyroBiasZ_rads(0.015550);
}

void accelSetup() {
  mpu.setAccelRange(MPU9250::ACCEL_RANGE_8G);
}

void magSetup() {
  
}

void magCalibrate() {
  mpu.calibrateMag();
}

void getAccel() {
  a[0] = mpu.getAccelX_mss();
  a[1] = mpu.getAccelY_mss();
  a[2] = mpu.getAccelZ_mss();
}

void getGyro() {
  g[0] = mpu.getGyroX_rads();
  g[1] = mpu.getGyroY_rads();
  g[2] = mpu.getGyroZ_rads();
}

void getMag() {
  m[0] = mpu.getMagX_uT()*0.08 + m[0]*0.92;
  m[1] = mpu.getMagY_uT()*0.08 + m[1]*0.92;
  m[2] = mpu.getMagZ_uT()*0.08 + m[2]*0.92;
}

void getAngle() {
  ang[0] = atan2(a[0], sqrt(a[1]*a[1] + a[2]*a[2]));
  ang[1] = atan2(-a[1], sqrt(a[0]*a[0] + a[2]*a[2]));
  float hY = (m[1]*cos(ang[1])) - (m[2]*sin(ang[1]));
  float hX = (m[0]*cos(ang[0])) + (m[1]*sin(ang[1])*sin(ang[0])) + (m[2]*cos(ang[1])*sin(ang[0]));
  ang[2] = atan2(hY, hX);
}
