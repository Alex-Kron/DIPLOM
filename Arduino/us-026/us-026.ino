const int pingPin = 6; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 7; // Echo Pin of Ultrasonic Sensor
const int cameraPin = 4;

void setup() {
  Serial.begin(9600);
  pinMode(pingPin, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  
}

void loop()
{
long duration, inches, cm;
digitalWrite(pingPin, LOW);
digitalWrite(cameraPin, LOW);
delayMicroseconds(2);
digitalWrite(pingPin, HIGH);
delayMicroseconds(10);
digitalWrite(pingPin, LOW);
duration = pulseIn(echoPin, HIGH);
cm = microsecondsToCentimeters(duration);

if (cm < 20) {
    digitalWrite(cameraPin, HIGH);
    digitalWrite(2, HIGH);
} else {
    digitalWrite(cameraPin, LOW);
    digitalWrite(2, LOW);
}
delay(500);
Serial.print("Camera = ");
Serial.print(digitalRead(cameraPin));
Serial.print("\n");
}
long microsecondsToCentimeters(long microseconds)
{
return microseconds / 29 / 2;
}
