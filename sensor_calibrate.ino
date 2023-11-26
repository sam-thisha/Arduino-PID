void sensor_calibrate(){
  for (int i = 0; i < 50; i++) {
    sensor.calibrate();
    moter(-75, 75);
  }
  moter(0, 0);
  delay(100);

  for (int i = 0; i < 100; i++) {
    sensor.calibrate();
    moter(150, -150);
  }
  moter(0, 0);
  delay(100);

  for (int i = 0; i < 40; i++) {
    sensor.calibrate();
    moter(-75, 75);
  }
  moter(0, 0);
  delay(1000);
}
