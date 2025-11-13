// Configuration constants
#define SERIAL_BAUD_RATE 9600       // Baud rate for Bluetooth communication (HC-05 standard)
#define LOOP_DELAY_MS 50            // Delay between serial reads (milliseconds)

// Command definitions for Bluetooth control
#define CMD_LED_ON '1'              // Command to turn LED on
#define CMD_LED_OFF '2'             // Command to turn LED off

void setup() {
  // put your setup code here, to run once:
  Serial.begin(SERIAL_BAUD_RATE);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
   {     
      char data= Serial.read(); // reading the data received from the bluetooth module
      switch(data)
      {
        case CMD_LED_ON:
        {
          digitalWrite(LED_BUILTIN, HIGH);
          break;
        }
        case CMD_LED_OFF:
        {
          digitalWrite(LED_BUILTIN, LOW);
          break;
        }
        default : break;
      }
      Serial.println(data);
   }
   delay(LOOP_DELAY_MS);
}
