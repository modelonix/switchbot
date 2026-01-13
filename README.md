# switchbot
An ESP32-C3 based automatic light switch controller that responds to specific IR remote commands.

## Features
- **IR Remote Control**: Flip light switches using any IR remote
- **Code Filtering**: Only responds to specific IR signature (protocol, address, command)
- **State Tracking**: Alternates between ON (135°) and OFF (45°) positions
- **Repeat Signal Filtering**: Ignores duplicate button presses
- **Visual Feedback**: LED blink patterns for status indication
- **Auto-return**: Servo returns to neutral (90°) after each flip

## Hardware
- ESP32-C3 development board
- IR receiver module (TSOP38238/VS1838B) on GPIO6
- SG90 micro servo motor on GPIO4
- Built-in LED on GPIO8 for status

## IR Protocol
- Protocol: NEC
- Address: 0xEF00
- Command: 0x(EB)14

## Power
- USB-C 5V 3A power supply recommended
- Suitable for continuous operation

## Operation
1. Press configured IR remote button
2. Servo flips switch (alternates UP/DOWN)
3. LED blinks 3 times to confirm
4. System ready for next command after 500ms debounce

............................................................................

esp32, esp32-c3, ir-remote, servo-motor, home-automation, arduino, 
smart-home, iot, switch-automation, infrared
