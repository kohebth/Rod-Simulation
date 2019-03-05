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
  mp.calibrateGyro();
  x += mp.getGyroBiasX_rads();
  y += mp.getGyroBiasY_rads();
  z += mp.getGyroBiasZ_rads();
  ++cnt;
}

void averageMagBias() {
  /*
   * While calibrating,
   * slowly move the sensor in an 8-figure.
   */
  mp.calibrateMag();
  x += mp.getMagBiasX_uT();
  y += mp.getMagBiasY_uT();
  z += mp.getMagBiasZ_uT();
  sfX += mp.getMagScaleFactorX();
  sfY += mp.getMagScaleFactorY();
  sfZ += mp.getMagScaleFactorZ();
  ++cnt;
}
