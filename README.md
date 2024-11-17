# HeartRateSensor

Arduino-based heart rate monitoring system using MAX30105 sensor and servo motors.

## Hardware Requirements

- Arduino board (e.g., Arduino Uno, Nano)
- MAX30105 Heart Rate Sensor
- Servo Motor
- Jumper wires
- Breadboard (optional)

## Pin Connections

| Component | Arduino Pin |
|-----------|------------|
| MAX30105 SDA | A4 |
| MAX30105 SCL | A5 |
| Servo Motor | D7 |

## Features

- Real-time heart rate monitoring using MAX30105 sensor
- Servo motor activation based on heart rate threshold
- Serial monitor output for debugging
- Configurable heart rate thresholds

## Installation

1. Install the required libraries in Arduino IDE:
   - `Wire.h`
   - `MAX30105.h`
   - `Servo.h`

2. Connect the hardware components according to the pin connection table
3. Upload the code to your Arduino board

## Usage

1. Power up the Arduino board
2. Place your index finger on the MAX30105 sensor
3. The servo motor will activate when your heart rate exceeds the threshold (currently set to 80)
4. Monitor the serial output (115200 baud rate) for debugging information

## Code Structure

- Initialization of sensor and servo motor in `setup()`
- Continuous monitoring in `loop()`
- Heart rate threshold checking and servo control
- Debug information output to serial monitor

## Notes

- The sensor requires steady finger placement for accurate readings
- Calibration may be needed depending on individual heart rate patterns
- Additional servo motors (currently commented out in code) can be added for different heart rate ranges

## License

This project is open source and available under the MIT License.