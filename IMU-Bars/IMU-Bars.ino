// define must ahead #include <M5Stack.h>
#define M5STACK_MPU6886 
// #define M5STACK_MPU9250 
// #define M5STACK_MPU6050
// #define M5STACK_200Q

#include <M5Stack.h>
#include "BarStatus.h"

float accX = 0.0F;
float accY = 0.0F;
float accZ = 0.0F;

float gyroX = 0.0F;
float gyroY = 0.0F;
float gyroZ = 0.0F;

float pitch = 0.0F;
float roll  = 0.0F;
float yaw   = 0.0F;

float temp = 0.0F;

int8_t power = 0;


BarStatus gyroXBar(0, 0, 319, 4, -50, 50, TFT_GREEN, TFT_WHITE, TFT_RED, TFT_BLACK);
BarStatus gyroYBar(0, 5, 319, 4, -50, 50, TFT_GREEN, TFT_WHITE, TFT_RED, TFT_BLACK);
BarStatus gyroZBar(0, 10, 319, 4, -50, 50, TFT_GREEN, TFT_WHITE, TFT_RED, TFT_BLACK);

BarStatus accXBar(0, 45, 319, 4, -2, 2, TFT_GREEN, TFT_WHITE, TFT_RED, TFT_BLACK);
BarStatus accYBar(0, 50, 319, 4, -2, 2, TFT_GREEN, TFT_WHITE, TFT_RED, TFT_BLACK);
BarStatus accZBar(0, 55, 319, 4, -2, 2, TFT_GREEN, TFT_WHITE, TFT_RED, TFT_BLACK);

BarStatus degXBar(0, 90, 319, 4, -180, 180, TFT_GREEN, TFT_WHITE, TFT_RED, TFT_BLACK);
BarStatus degYBar(0, 95, 319, 4, -180, 180, TFT_GREEN, TFT_WHITE, TFT_RED, TFT_BLACK);
BarStatus degZBar(0, 100, 319, 4, -180, 180, TFT_GREEN, TFT_WHITE, TFT_RED, TFT_BLACK);

BarStatus tempBar(0, 146, 319, 4, 30, 80, TFT_GREEN, TFT_WHITE, TFT_RED, TFT_BLACK);
BarStatus powerBar(0, 170, 100, 10, 0, 100, TFT_GREEN, TFT_WHITE, TFT_RED, TFT_BLACK);

// the setup routine runs once when M5Stack starts up
void setup(){
  
  // Initialize the M5Stack object
  M5.begin();
  /*
    Power chip connected to gpio21, gpio22, I2C device
    Set battery charging voltage and current
    If used battery, please call this function in your project
  */
  M5.Power.begin();
    
  M5.IMU.Init();

  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextColor(GREEN , BLACK);
  M5.Lcd.setTextSize(1);
}

// the loop routine runs over and over again forever
void loop() {
  // put your main code here, to run repeatedly:
  M5.IMU.getGyroData(&gyroX,&gyroY,&gyroZ);
  M5.IMU.getAccelData(&accX,&accY,&accZ);
  M5.IMU.getAhrsData(&pitch,&roll,&yaw);
  M5.IMU.getTempData(&temp);


  gyroXBar.draw(gyroX);
  gyroYBar.draw(gyroY);
  gyroZBar.draw(gyroZ);
  M5.Lcd.setCursor(0, 20);
  M5.Lcd.printf("%6.2f  %6.2f  %6.2f      ", gyroX, gyroY, gyroZ);
  M5.Lcd.setCursor(220, 20);
  M5.Lcd.print(" o/s");

  accXBar.draw(accX);
  accYBar.draw(accY);
  accZBar.draw(accZ);
  M5.Lcd.setCursor(0, 65);
  M5.Lcd.printf(" %5.2f   %5.2f   %5.2f   ", accX, accY, accZ);
  M5.Lcd.setCursor(220, 65);
  M5.Lcd.print(" G");

  degXBar.draw(pitch);
  degYBar.draw(roll);
  degZBar.draw(yaw);
  M5.Lcd.setCursor(0, 110);
  M5.Lcd.printf(" %5.2f   %5.2f   %5.2f   ", pitch, roll, yaw);
  M5.Lcd.setCursor(220, 110);
  M5.Lcd.print(" degree");

  tempBar.draw(temp);
  M5.Lcd.setCursor(0, 155);
  M5.Lcd.printf("Temperature : %.2f C", temp);

  power = M5.Power.getBatteryLevel();
  powerBar.draw(power);
  M5.Lcd.setCursor(0, 185);
  M5.Lcd.printf("Battery : %u %%", (uint8_t)power);

  delay(1);
}
