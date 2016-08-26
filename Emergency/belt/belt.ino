#define trigPin = 6;
#define echoPin = 7;
#define buzzer = 10;
long duration, cm;

void setup() {
  // put your setup code here, to run once:
	Serial.begin(9600);

	pinMode(trigPin, OUTPUT);
 	pinMode(echoPin, INPUT);
 	digitalWrite(trigPin, LOW);

 	pinMode(buzzer, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
	digitalWrite(trigPin, HIGH);
 	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);

	duration = pulseIn(echoPin, HIGH);

	cm = microsecondsToCentimeters(duration);
 
 	Serial.print(cm);
 	Serial.print("cm");
 	Serial.println();

 	if (cm <= 20) {
 		digitalWrite(buzzer, HIGH);
 	}
 	else if (cm > 20) {
 		digitalWrite(buzzer, LOW);
 	}
 
 	delay(500);

}

long microsecondsToCentimeters(long microseconds)
{
 // The speed of sound is 340 m/s or 29 microseconds per centimeter.
 // The ping travels out and back, so to find the distance of the
 // object we take half of the distance travelled.
 return microseconds / 29 / 2;
}
