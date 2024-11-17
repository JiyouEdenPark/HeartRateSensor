#include <Wire.h>
#include "MAX30105.h"
#include <Servo.h>

MAX30105 particleSensor;

// Servo servo1;
// Servo servo2;
Servo servo3;

void setup()
{
  Serial.begin(115200);
  Serial.println("Initializing...");

  // Initialize sensor / 센서 초기화
  if (!particleSensor.begin(Wire, I2C_SPEED_FAST))
  {
    Serial.println("MAX30105 was not found. Please check wiring/power.");
    while (1);
  }
  Serial.println("Place your index finger on the sensor with steady pressure.");

  particleSensor.setup(); // Configure basic settings / 센서 기본 설정
  particleSensor.setPulseAmplitudeRed(0x0A); // Set red LED / 빨간 LED 설정
  particleSensor.setPulseAmplitudeGreen(0);  // Turn off green LED / 녹색 LED 끄기

  // Initialize servo motors / 서보 모터 초기화
  // servo1.attach(9); // Connect servo motor 1 (pin 3) / 서보 모터 1 연결 (핀 3)
  // servo2.attach(8); // Connect servo motor 2 (pin 5) / 서보 모터 2 연결 (핀 5)
  servo3.attach(7); // Connect servo motor 3 (pin 6) / 서보 모터 3 연결 (핀 6)

  // Set initial servo positions / 서보 모터 초기 위치 설정
  // servo1.write(90);
  // servo2.write(90);
  servo3.write(90);
}

void loop()
{
  int irValue = particleSensor.getIR();

  // Scale irValue by dividing by 1000 / irValue를 1000으로 나누어 스케일링
  int scaledIrValue = irValue / 1000;

  // Determine range / 범위 결정
  // int range = 0; // 1: LOW, 2: MID, 3: HIGH

  // if (scaledIrValue >= 80 && scaledIrValue <= 90)
  //   range = 1; // LOW
  // else if (scaledIrValue >= 91 && scaledIrValue <= 100)
  //   range = 2; // MID
  // else if (scaledIrValue > 100)
  //   range = 3; // HIGH

  // If heart rate exceeds 80, operate servo motor / 평균 심박수가 80을 넘으면 서보 모터 작동
  if (scaledIrValue > 80)
  {
    // Move servo motor to 180 degrees / 서보 모터를 180도로 이동
    servo3.write(180);
  }
  else
  {
    // Return servo motor to 90 degrees / 서보 모터를 90도로 복귀
    servo3.write(90);
  }

  // Operate servo motor for the corresponding range / 해당 범위의 서보 모터 작동
  // if (range != 0)
  // {
  //   operateServo(range);
  //   delay(3000); // Wait for 3 seconds before receiving next value / 3초 동안 대기 후 다음 값 수신
  // }

  // Output for debugging / 디버깅을 위한 출력
  Serial.print("IR=");
  Serial.print(scaledIrValue);
  if (irValue < 50000)
    Serial.print(" No finger?");

  Serial.println();

  delay(100); // Short delay to prevent serial monitor spam / 시리얼 모니터 스팸 방지를 위한 짧은 딜레이
}

// void operateServo(int range)
// {
//   switch (range)
//   {
//     case 1: // LOW 범위
//       servo1.write(0);
//       delay(1000);
//       servo1.write(180);
//       delay(1000);
//       servo1.write(90);
//       break;
//     case 2: // MID 범위
//       servo2.write(0);
//       delay(1000);
//       servo2.write(180);
//       delay(1000);
//       servo2.write(90);
//       break;
//     case 3: // HIGH 범위
//       servo3.write(0);
//       delay(1000);
//       servo3.write(180);
//       delay(1000);
//       servo3.write(90);
//       break;
//     default:
//       // 범위에 해당하지 않는 경우 아무 것도 하지 않음
//       break;
//   }
//}
