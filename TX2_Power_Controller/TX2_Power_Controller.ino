#define LED_PIN 7

#define SIGNAL_POWER_CYCLE "POWER_CYCLE"

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
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
          Serial.println("Cycling Power on TX2...");
          for(int i = 0; i < 5; i++)
          {
            // TODO actually trigger a power cycle
            // For now just flash an LED
            digitalWrite(LED_PIN, HIGH);
            delay(100);
            digitalWrite(LED_PIN, LOW);
            delay(100);
          }
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
