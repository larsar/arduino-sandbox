#include <XBee.h>

XBee xbee = XBee();
uint8_t payload[] = { 0, 0 };

XBeeAddress64 addr64 = XBeeAddress64(0x00000000, 0x0000FFFF);
ZBTxRequest zbTx = ZBTxRequest(addr64, payload, sizeof(payload));
ZBTxStatusResponse txStatus = ZBTxStatusResponse();

int button = LOW;
int buttonPin = 11;


void setup() {
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  xbee.setSerial(Serial);
}

void alert() { 
  payload[0] = 0x16;
  payload[1] = 1;  
  xbee.send(zbTx);  
}


void loop() {   
  if (digitalRead(buttonPin)) {
    button = HIGH;
  }
  else {
    if (button == HIGH) {
      alert();
      button = LOW;
    }
  }

}


