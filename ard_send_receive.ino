#include <SoftwareSerial.h>

SoftwareSerial XBee(2, 3); // RX, TX

byte msg[] = {,0x00,0x0A,0x01,0x01,0xFF,0xFF,,0x00,        //API command byte, from the mega to Xbee1 then transmitted to xbee2, I S (49,53) equals forced sample
                0x40,0x81,0x82,0x0D,0xFF,0xFE,0x02,0x49,0x53,0xF5};
void setup() {
   XBee.begin(9600);
  Serial.begin(9600);
  }


  Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
  Xbee.begin(4800);
  Xbee.println("Hello, world?");
}

void loop() { // run over and over
if (Serial.available()){ //  send 
    XBee.write(0x7E);
    XBee.write(0x00);
    XBee.write(0x0A);
    XBee.write(0x01);
    XBee.write(0x01);
    XBee.write(0x7F);
    XBee.write(0x7F);
    XBee.write(0x00);
    XBee.write(0x31);
    XBee.write(0x30);
    XBee.write(0x30);
    XBee.write(0xB8); /// Check sum may be wrong
  
    
  }
 
  if (Xbee.available()>12) { // get
   if(XBee.read==0x7E){

   for(int n=1; n< 10; n++)  {
               incomingByte[n] = XBee.read();
               delay(1);
             }

    if(incomingByte[7] == '0'){
      digitalWrite(13, LOW);
    }else if(incomingByte[7] == '1'){
      digitalWrite(13, HIGH);
    }    
  }

}
