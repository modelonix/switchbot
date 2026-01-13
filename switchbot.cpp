#include <IRremote.h>
#include <ESP32Servo.h>

#define IR_RECEIVER_PIN 6
#define LED_PIN 8
#define SERVO_PIN 4

// Labels are reversed, realized after a grueling 30mins
#define LED_ON LOW 
#define LED_OFF HIGH

Servo SwitchBot;
bool LightOn = false;

void setup() {
 pinMode(LED_PIN , OUTPUT); 

 SwitchBot.attach(SERVO_PIN);
 SwitchBot.write(90);

 IrReceiver.begin(IR_RECEIVER_PIN, DISABLE_LED_FEEDBACK); //library default disabled

 //startup blinks
 for(int i = 0; i<2; i++){ 
  digitalWrite(LED_PIN, LED_ON);  
   delay(200);
     digitalWrite(LED_PIN, LED_OFF);
       delay(200);
 }      

 //ensuring LED is off so my power bill doesn't go through the roof
 digitalWrite(LED_PIN, LED_OFF);
}

void loop() {
if (IrReceiver.decode()) {
//disregard duplicate signals
  if (IrReceiver.decodedIRData.flags & IRDATA_FLAGS_IS_REPEAT) {
  IrReceiver.resume();
  return;
}

 if (IrReceiver.decodedIRData.protocol == NEC &&
     IrReceiver.decodedIRData.address == 0xEF00 &&
     IrReceiver.decodedIRData.command == 0x14) {

 
  if (!LightOn) {  //Light Off, need to switch on
   SwitchBot.write(135);
   delay(500);
   SwitchBot.write(90);
   LightOn = true;
 }

 else {           //Light On, need to switch off
   SwitchBot.write(45);
   delay(500);
   SwitchBot.write(90);
   LightOn = false;
 }

  for (int i=0; i<3; i++) {   // 3 IR Signal received blinks
   digitalWrite(LED_PIN, HIGH);
   delay(300);
   digitalWrite(LED_PIN, LOW);
   delay(300);

  }



 
 delay(500);    // refractory period
 }
IrReceiver.resume(); //clear

}
}
