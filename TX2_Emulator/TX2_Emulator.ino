#define PIN_BUTTON 7

#define SIGNAL_HEARTBEAT "HEARTBEAT"

int count = 0;

int heartbeatCount = 4;

void setup()
{
  pinMode(PIN_BUTTON, INPUT);
  Serial.begin(9600);
}

void loop()
{
  if(digitalRead(PIN_BUTTON) == HIGH)
  {
    if(heartbeatCount == 4)
    {
      Serial.println(SIGNAL_HEARTBEAT);
      heartbeatCount = 0;
    }
    heartbeatCount++;
    
    char message[25];
    sprintf(message, "TX2 Output = %d", count);
    Serial.println(message);
    
    count++;
  }
  
  delay(250);
}
