int line_detect[] = {2, 3};	//pin 2 is front and pin 3 is back
int IR[] = {8, 9, 10};		//pin 8, 9 and 10 are left, mid and right 
int E1 = 5;  
int M1 = 4; 
int E2 = 6;                      
int M2 = 7; 

void setup()
{
	Serial.begin(115200);

	pinMode(line_detect[0], INPUT);
	pinMode(line_detect[1], INPUT);
	pinMode(IR[0], INPUT);
	pinMode(IR[1], INPUT);
	pinMode(IR[2], INPUT);
	pinMode(M1, OUTPUT);   
    pinMode(M2, OUTPUT); 
    // stop the car first
    while(digitalRead(IR[1]) == HIGH){
        analogWrite(E1, 0);
		analogWrite(E2, 0);
    }
    
}

void loop()	{
	//Step 1: test the five sensor and adjust them
	Serial.print(digitalRead(line_detect[0]));
	Serial.print(", ");
	Serial.print(digitalRead(line_detect[1]));
	Serial.print(", ");
	Serial.print(digitalRead(IR[0]));
	Serial.print(", ");
	Serial.print(digitalRead(IR[1]));
	Serial.print(", ");
	Serial.println(digitalRead(IR[2]));

	//Step 2: test the direction of motor
	//       adjust the M1 and M2 if the motor is not forward at first
	forward();  

	//Step 3: add 2 interrup, make sure the car will not rush out the region
	if(digitalRead(line_detect[1]) == LOW){		//back line detect trigger
	    forward();
	}

	else if(digitalRead(line_detect[0]) == LOW){		//front line detect trigger
	    backward();
	    delay(500);
	    turn_left();
	    delay(800);
	    forward();
	}

	//Step 4: track the other car if IR sensor trigger
	else if(digitalRead(IR[0]) == LOW){
		turn_left();
	}
	else if(digitalRead(IR[2]) == LOW){
		turn_right();
	}
	else if(digitalRead(IR[1]) == LOW){
	    forward();
	}
	else {
		turn_left();
	}
}

void forward() {
  	digitalWrite(M1, HIGH);
	digitalWrite(M2, HIGH);
	analogWrite(E1, 255);
	analogWrite(E2, 255);
}

void turn_left()  {
  	digitalWrite(M1, LOW);
	digitalWrite(M2, HIGH);
	analogWrite(E1, 127);
	analogWrite(E2, 127);
}

void backward()	{
	digitalWrite(M1, LOW);
	digitalWrite(M2, LOW);
	analogWrite(E1, 255);
	analogWrite(E2, 255);
}

void turn_right()	{
	digitalWrite(M1, HIGH);
	digitalWrite(M2, LOW);
	analogWrite(E1, 127);
	analogWrite(E2, 127);
}
