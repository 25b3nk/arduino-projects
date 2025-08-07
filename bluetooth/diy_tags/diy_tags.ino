// Define the device ID. This can be changed to a unique name for each tag.
#define DEVICE_ID "MyTag-01"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
   {
      char data= Serial.read(); // reading the data received from the bluetooth module

      // The commands are kept as single characters to be compatible with the
      // 'Arduino Bluetooth controller' Android app mentioned in the bt_blink project.
      switch(data)
      {
        case '1': 
        {
          digitalWrite(LED_BUILTIN, HIGH);
          Serial.print("ID:");
          Serial.print(DEVICE_ID);
          Serial.println(",STATUS:ON");
          break;
        }
        case '2': 
        {
          digitalWrite(LED_BUILTIN, LOW);
          Serial.print("ID:");
          Serial.print(DEVICE_ID);
          Serial.println(",STATUS:OFF");
          break;
        }
        case '3':
        {
          Serial.print("ID:");
          Serial.print(DEVICE_ID);
          Serial.println(",STATUS:FINDING");
          for (int i = 0; i < 5; i++) {
            digitalWrite(LED_BUILTIN, HIGH);
            delay(200);
            digitalWrite(LED_BUILTIN, LOW);
            delay(200);
          }
          break;
        }
        default : break;
      }
   }
   delay(50);
}
