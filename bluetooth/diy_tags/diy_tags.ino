// Device configuration
#define DEVICE_ID "MyTag-01"        // Unique identifier for this tag

// Serial communication settings
#define SERIAL_BAUD_RATE 9600       // Baud rate for Bluetooth communication (HC-05 standard)
#define LOOP_DELAY_MS 50            // Delay between serial reads (milliseconds)

// Command definitions for Bluetooth control
#define CMD_LED_ON '1'              // Command to turn LED on
#define CMD_LED_OFF '2'             // Command to turn LED off
#define CMD_FIND '3'                // Command to trigger "find my device" feature

// "Find my device" feature settings
#define FIND_BLINK_COUNT 5          // Number of times to blink when "find" is triggered
#define FIND_BLINK_ON_MS 200        // LED on duration during find blink (milliseconds)
#define FIND_BLINK_OFF_MS 200       // LED off duration during find blink (milliseconds)

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

      // The commands are kept as single characters to be compatible with the
      // 'Arduino Bluetooth controller' Android app mentioned in the bt_blink project.
      switch(data)
      {
        case CMD_LED_ON:
        {
          digitalWrite(LED_BUILTIN, HIGH);
          Serial.print("ID:");
          Serial.print(DEVICE_ID);
          Serial.println(",STATUS:ON");
          break;
        }
        case CMD_LED_OFF:
        {
          digitalWrite(LED_BUILTIN, LOW);
          Serial.print("ID:");
          Serial.print(DEVICE_ID);
          Serial.println(",STATUS:OFF");
          break;
        }
        case CMD_FIND:
        {
          Serial.print("ID:");
          Serial.print(DEVICE_ID);
          Serial.println(",STATUS:FINDING");
          for (int i = 0; i < FIND_BLINK_COUNT; i++) {
            digitalWrite(LED_BUILTIN, HIGH);
            delay(FIND_BLINK_ON_MS);
            digitalWrite(LED_BUILTIN, LOW);
            delay(FIND_BLINK_OFF_MS);
          }
          break;
        }
        default : break;
      }
   }
   delay(LOOP_DELAY_MS);
}
