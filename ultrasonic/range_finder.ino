// ---------------------------------------------------------------- //
// Arduino based Range finder
// Using HC-SR04 Module
// ---------------------------------------------------------------- //

// Pin definitions
#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04

// Serial communication settings
#define SERIAL_BAUD_RATE 9600       // Baud rate for serial output

// HC-SR04 timing constants (microseconds)
#define TRIG_SETUP_DELAY_US 2       // Initial trigger pin low delay
#define TRIG_PULSE_WIDTH_US 10      // Trigger pulse duration (10us required by HC-SR04)

// Physics constants for distance calculation
#define SOUND_SPEED_CM_US 0.034     // Speed of sound in cm/microsecond (343 m/s at 20°C)
#define ROUND_TRIP_DIVISOR 2        // Divide by 2 because sound travels to object and back

// Measurement timing
#define MEASUREMENT_DELAY_MS 10     // Delay between distance measurements (milliseconds)

long duration; // duration of sound wave travel in microseconds
int distance;  // distance measurement

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT);  // Sets the echoPin as an INPUT
  Serial.begin(SERIAL_BAUD_RATE);
  Serial.println("Ultrasonic Sensor HC-SR04 Test");
  Serial.println("with Arduino UNO R3");
}
void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(TRIG_SETUP_DELAY_US);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(TRIG_PULSE_WIDTH_US);
  digitalWrite(trigPin, LOW);
  // The pulseIn function times the signal return after bouncing off the object
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * SOUND_SPEED_CM_US / ROUND_TRIP_DIVISOR; // Speed of sound wave divided by 2 (wave goes and comes back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(MEASUREMENT_DELAY_MS);
}
