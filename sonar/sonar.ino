const int trigPin = 2; //Change to pin you use
const int echoPin = 3; //Here too
const int outputPin = 5;
long duration, inches, cm;
void setup() {
 // initialize serial communication:
 Serial.begin(115200);
 
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(outputPin, OUTPUT);
 digitalWrite(trigPin, LOW);
 digitalWrite(outputPin,LOW);
}

void loop()
{
 // establish variables for duration of the ping, 
 // and the distance result in inches and centimeters:
 
 digitalWrite(outputPin,LOW);
 
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);

 duration = pulseIn(echoPin, HIGH);

 // convert the time into a distance

 cm = microsecondsToCentimeters(duration);
 if(cm <= 20){
  digitalWrite(outputPin,HIGH);
 }

 Serial.print(cm);
 Serial.print("cm");
 Serial.println();
 
 delay(100);
}

long microsecondsToCentimeters(long microseconds)
{
 // The speed of sound is 340 m/s or 29 microseconds per centimeter.
 // The ping travels out and back, so to find the distance of the
 // object we take half of the distance travelled.
 return microseconds / 29 / 2;
}
