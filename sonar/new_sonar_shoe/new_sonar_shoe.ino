const int trig1Pin = 11; 	const int trig2Pin = 2;
const int echo1Pin = 10; 	const int echo2Pin = 3;
const int output1Pin = 4;	const int output2Pin = 5;
long distance1 = 0;			long distance2 = 0;
int i = 0;

void setup()
{
	Serial.begin(9600);
	deviceInit(trig1Pin, echo1Pin, output1Pin);
	deviceInit(trig2Pin, echo2Pin, output2Pin);
}

void loop()
{
	distance1 = readSonar(trig1Pin, echo1Pin);
	feedbackOutput(output1Pin,distance1,'v');
	//serialDisplay(distance1);

	distance2 = readSonar(trig2Pin, echo2Pin);
	feedbackOutput(output2Pin,distance2,'v');
	serialDisplay(distance1, distance2);
}

void deviceInit(int trig, int echo, int out)
{
	pinMode(trig, OUTPUT);
	pinMode(echo, INPUT);
	pinMode(out, OUTPUT);
	digitalWrite(trig, LOW);
	digitalWrite(out,LOW);
}

long readSonar(int trig, int echo)
{
	digitalWrite(trig, HIGH);
	delayMicroseconds(10);
	digitalWrite(trig, LOW);

	return (pulseIn(echo, HIGH))/ 29 / 2;
}

void serialDisplay(long cm)
{
	Serial.print(cm);
	Serial.println();

	delay(100);
}

void serialDisplay(long cm, long cmm)
{
	Serial.print(cm);
	Serial.print('\t');
	Serial.print(cmm);
	Serial.println();

	delay(100);
}

void feedbackOutput(int out,long distance,char mode)
{
	switch(mode){
	case 'b': 
		//buzzer mode
		if(distance <= 20){
			for(i = 1;i <= 10;i++){
				digitalWrite(out,HIGH);
				delay(50);
				digitalWrite(out,LOW);
				delay(50);
			}//Serial.println("FUCK!");
		}else if(distance <= 30){
			for(i = 1;i <= 4;i++){
				digitalWrite(out,HIGH);
				delay(125);
				digitalWrite(out,LOW);
				delay(125);
			}//Serial.println("30!");
		}else if(distance <= 50){
			digitalWrite(out,HIGH);
			delay(250);
			digitalWrite(out,LOW);
			delay(250);
			//Serial.println("50!");
		}else{
			delay(50);
		}	
		break;
	case 'v': 
		// vibrator mode
		if(distance <= 10){
      for(i = 1;i <= 10;i++){
        digitalWrite(out,HIGH);
        delay(50);
        digitalWrite(out,LOW);
        delay(50);
      }
    }else if(distance <= 40){
      for(i = 1;i <= 5;i++){
        digitalWrite(out,HIGH);
        delay(100);
        digitalWrite(out,LOW);
        delay(100);
      }
    }
		break;
	}
}
