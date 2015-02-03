#include <ICSC.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 6); // RX, TX
#define DE_PIN 3
// uncomment to be slave
#define MASTER
#define NODE_ID 1




void setup() {
  Serial.begin(57600);
  // put your setup code here, to run once:
  ICSC.begin(NODE_ID, 57600, &mySerial, DE_PIN);
  ICSC.registerCommand('D', &demo);
}

void demo(unsigned char src, char command, unsigned char len, char *data)
{
  Serial.print(millis());
  Serial.print(": ");
  Serial.print(src);
  Serial.print(";");
  Serial.print(command);
  Serial.print(";");
  Serial.print(len);
  Serial.print(";");
  Serial.println(data);

}

unsigned long last_sent = 0;

void loop() {
  // put your main code here, to run repeatedly:
  ICSC.process();


  // send D message every second
  if ((millis() - last_sent) > 1000) {
    char b[10];
    sprintf(b, "%ld", last_sent);
    Serial.print("Sending ");
    Serial.println(b);
    ICSC.send(2, 'D', 10, b);
    last_sent = millis();
  }


}
