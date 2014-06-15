byte line_detect[] = {2, 3};	//pin 2 is front and pin 3 is back
byte IR[] = {8, 9, 10};		//pin 8, 9 and 10 are left, mid and right 

void setup()
{
	pinMode(line_detect[0], INPUT);
	pinMode(line_detect[1], INPUT);
	pinMode(IR[0], INPUT);
	pinMode(IR[1], INPUT);
	pinMode(IR[2], INPUT);
	Serial.begin(115200);
}

void loop()
{
	Serial.print(digitalRead(line_detect[0]));
	Serial.print(", ");
	Serial.print(digitalRead(line_detect[1]));
	Serial.print(", ");
	Serial.print(digitalRead(IR[0]));
	Serial.print(", ");
	Serial.print(digitalRead(IR[1]));
	Serial.print(", ");
	Serial.println(digitalRead(IR[2]));
}
