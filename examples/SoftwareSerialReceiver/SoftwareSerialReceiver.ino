#include <ICSC.h>
#include <SoftwareSerial.h>


SoftwareSerial mySerial(6, 5);
#define DE_PIN A1
#define NODE_ID 2




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

long last_sent = 0;


void loop() {
  // put your main code here, to run repeatedly:
  ICSC.process();


}
