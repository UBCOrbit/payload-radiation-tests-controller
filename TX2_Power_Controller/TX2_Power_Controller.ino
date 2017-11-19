#define PIN_POWER_TRANSISTOR 13
#define PIN_PNL 7

#define SIGNAL_POWER_CYCLE "POWER_CYCLE"

void setup()
{
  pinMode(PIN_POWER_TRANSISTOR, OUTPUT);
  pinMode(PIN_PNL, OUTPUT);
  
  Serial.begin(9600);
  Serial1.begin(9600);

  digitalWrite(PIN_PNL, HIGH);
  digitalWrite(PIN_POWER_TRANSISTOR, HIGH);
}

void cycleTX2Power()
{
  // "Disconnect" the power supply
  Serial.println("Turning power supply OFF");
  digitalWrite(PIN_POWER_TRANSISTOR, LOW);
  
  // Wait for power to turn off
  delay(5000);
  
  // "Connect" the power supply
  Serial.println("Turning power supply ON...");
  digitalWrite(PIN_POWER_TRANSISTOR, HIGH);
  
  // Wait for power supply to "connect"
  delay(1000);
  
  // "Press" the "power button"
  Serial.println("Setting PNL to LOW...");
  digitalWrite(PIN_PNL, LOW);
  
  // Hold the "power button" down for a little bit
  delay(2500);
  
  // "Release" the "power button"
  Serial.println("Setting PNL to HIGH");
  digitalWrite(PIN_PNL, HIGH);
}

void loop()
{
  /*int serialByte;
  int serial1Byte;
  if (Serial1.available()) {
    int inByte = Serial1.read();
  }
  
  if (Serial.available()) {
    int inByte = Serial.read();
    Serial1.write(inByte);
  }
  
  Serial.write(inByte);*/
  
  String readString;
  
  while(Serial.available())
  {
    delay(3);  //delay to allow buffer to fill 

    char c;
    if(Serial.available() > 0)
    {
      char c = Serial.read();  //gets one byte from serial buffer
      
      if(c == '\n')
      {
        if(readString == SIGNAL_POWER_CYCLE)
        {
          cycleTX2Power();
        }
        else
        {
          Serial.println("Invalid command");
        }
        readString = "";
      }
      else
      {
        readString += c;
      }
    }
  }
}
