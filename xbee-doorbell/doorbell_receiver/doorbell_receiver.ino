#include <XBee.h>

XBee xbee = XBee();
XBeeResponse response = XBeeResponse();
ZBRxResponse rx = ZBRxResponse();
ModemStatusResponse msr = ModemStatusResponse();

int bellPin = 12;

void setup() {
  pinMode(bellPin,  OUTPUT);
  Serial.begin(9600);
  xbee.begin(Serial);
}

void alert() {
  digitalWrite(bellPin, HIGH);
  delay(50);
  digitalWrite(bellPin, LOW);
}

void loop() {
    
    xbee.readPacket();
    
    if (xbee.getResponse().isAvailable()) {     
      if (xbee.getResponse().getApiId() == ZB_RX_RESPONSE) {
         xbee.getResponse().getZBRxResponse(rx);
        if (rx.getData(0) == 0x16) {
          alert();
        } 
      } 
    }
}
