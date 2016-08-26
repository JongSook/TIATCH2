#define trigPin01 = 3;
#define echoPin01 = 4;

#define trigPin02 = 8;
#define echoPin02 = 9;

#define vibrate01 = 10;
#define vibrate02 = 11;
long duration01, cm01, duration02, cm02;

void setup() {
  // put your setup code here, to run once:
	Serial.begin(9600);

	pinMode(trigPin01, OUTPUT);
 	pinMode(echoPin01, INPUT);
 	digitalWrite(trigPin01, LOW);

 	pinMode(trigPin02, OUTPUT);
 	pinMode(echoPin02, INPUT);
 	digitalWrite(trigPin02, LOW);

 	pinMode(vibrate01, OUTPUT);
 	pinMode(vibrate01, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
	digitalWrite(trigPin01, HIGH);
 	delayMicroseconds(10);
	digitalWrite(trigPin01, LOW);

	duration01 = pulseIn(echoPin01, HIGH);

	cm01 = microsecondsToCentimeters(duration01);

	digitalWrite(trigPin02, HIGH);
 	delayMicroseconds(10);
	digitalWrite(trigPin02, LOW);

	duration02 = pulseIn(echoPin02, HIGH);

	cm02 = microsecondsToCentimeters(duration02);
 
 	Serial.print(cm01);
 	Serial.print("cm, ");
 	Serial.print(cm01);
 	Serial.print("cm");
 	Serial.println();
 
 	delay(500);

}

long microsecondsToCentimeters(long microseconds)
{
 // The speed of sound is 340 m/s or 29 microseconds per centimeter.
 // The ping travels out and back, so to find the distance of the
 // object we take half of the distance travelled.
 return microseconds / 29 / 2;
}
