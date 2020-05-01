
/*
 * Right microphone is connected to A0
 * LEft microphone is connected to A1
 * Right motor pin 13
 * Left motor pin 14
*/

// Declare storage for ADC values
  int micR = 0;
  int micL = 0;
// Declare constants
  int THRESHOLD = 850;

void setup() {
  // initialize serial communication at 9600 baud rate
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  // Read the analog value from pin A0 and A1
  int micR = analogRead(A0);
  int micL = analogRead(A1);

  // Once values are gathered, determine if they pass threshhold
  if (micR > THRESHOLD) {
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }
  if (micL > THRESHOLD) {
    digitalWrite(12, HIGH);
  } else {
    digitalWrite(12, LOW);
  }

  // print the value at serial monitor
  Serial.print(micR);
  Serial.print(" ; ");
  Serial.println(micL);
  delay(10);       // delay in between reads for stability
}
