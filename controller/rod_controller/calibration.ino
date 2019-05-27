float x, y, z;
float sfX, sfY, sfZ;
int cnt;

void initCalibration() {
  x = y = z = 0.0;
  sfX = sfY = sfZ = 0.0;
  cnt = 0;
}

void averageGyroBias() {
  /*
   * While calibrating,
   * keep the sensor stationary.
   */
  mpu.calibrateGyro();
  x += mpu.getGyroBiasX_rads();
  y += mpu.getGyroBiasY_rads();
  z += mpu.getGyroBiasZ_rads();
  ++cnt;
}

void averageMagBias() {
  /*
   * While calibrating,
   * slowly move the sensor in an 8-figure.
   */
  mpu.calibrateMag();
  x += mpu.getMagBiasX_uT();
  y += mpu.getMagBiasY_uT();
  z += mpu.getMagBiasZ_uT();
  sfX += mpu.getMagScaleFactorX();
  sfY += mpu.getMagScaleFactorY();
  sfZ += mpu.getMagScaleFactorZ();
  ++cnt;
}
