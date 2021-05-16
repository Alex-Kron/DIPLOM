const int pingPin = 6; 
const int cameraPin = 8;
const int echoPin = 7;
const int lightsPin = 3;
long duration, cm;

void setup() {
  Serial.begin(9600);
  pinMode(pingPin, OUTPUT);
  pinMode(lightsPin, OUTPUT);
  pinMode(cameraPin, OUTPUT);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
}

void loop()
{
digitalWrite(pingPin, LOW);
digitalWrite(cameraPin, LOW);
digitalWrite(lightsPin, LOW);
delayMicroseconds(2);
digitalWrite(pingPin, HIGH);
delayMicroseconds(10);
digitalWrite(pingPin, LOW);
duration = pulseIn(echoPin, HIGH);
cm = microsecondsToCentimeters(duration);

if (cm < 30 && cm > 4) {
    digitalWrite(lightsPin, HIGH);
    digitalWrite(cameraPin, HIGH);
    Serial.print(digitalRead(cameraPin));
    delay(1000);
} else {
    digitalWrite(lightsPin, LOW);
    digitalWrite(cameraPin, LOW);
    Serial.print(digitalRead(cameraPin));
    delay(100);
}
}

long microsecondsToCentimeters(long microseconds)
{
return microseconds / 29 / 2;
}
