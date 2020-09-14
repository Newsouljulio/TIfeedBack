float max_value1 = 0.00;
float max_value2 = 0.00;
float max_value3 = 0.00;
float max_value4 = 0.00;
float max_flag1 = 0;
float max_flag2 = 0;
float max_flag3 = 0;
float max_flag4 = 0;
int x;
int count = 0;
float sum_1 = 0;
float sum_2 = 0;
float sum_3 = 0;
float sum_4 = 0;
void setup() {
  // put your setup code here, to run once:
Serial.begin (19200);
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
//at first give a HIGH voltage to the relay that will leave the switch on
digitalWrite(2,LOW);
digitalWrite(3,LOW);
digitalWrite(4,LOW);
digitalWrite(5,LOW);
}
void loop() {
x=Serial.read();
unsigned long time1 = millis();
//give the command to capture the value of the 470ohm resistor
float val_1=analogRead(A0);
float val_2=analogRead(A1);
float val_3=analogRead(A2);
float val_4=analogRead(A3);

//calculate the real voltage that pass through the resistors
float volt_1=val_1*5.0/1023;
float volt_2=val_2*5.0/1023;
float volt_3=val_3*5.0/1023;
float volt_4=val_4*5.0/1023;
//Judgement on the circuit when to stop to protect, give a command to flip the switch on the relay
if(volt_1>2.0||volt_2>2.0||volt_3>2.0||curr_4>2.0){
digitalWrite(2,HIGH);
digitalWrite(3,HIGH);
digitalWrite(4,HIGH);
digitalWrite(5,HIGH);
}
// calculate the current that pass through the resistors
float curr_1=volt_1/0.496;
float curr_2=volt_2/0.484;
float curr_3=volt_3/0.464;
float curr_4=volt_4/0.464;

//calculate the max_value for a while
if (count < 100){
	sum_1 = sum_1 + curr_1;
	sum_2 = sum_2 + curr_2;
	sum_3 = sum_3 + curr_3;
	sum_4 = sum_4 + curr_4;
	//sum_1 = sum_1 + curr_1;
	count = count + 1;
}
else{
	max_value1 = 1.4142 * (sum_1) / count;max_flag1 = 1;
	max_value2 = 1.4142 * (sum_2) / count;max_flag2 = 1;
	max_value3 = 1.4142 * (sum_3) / count;max_flag3 = 1;
	max_value4 = 1.4142 * (sum_4) / count;max_flag4 = 1;
	count = 0;
}
/* if (curr_1 > max_value1){
  max_value1 = curr_1;
  }
else{
  
  }
if (curr_2 > max_value2){
  max_value2 = curr_2;
  }
else{
  
  }
if (curr_3 > max_value3){
  max_value3 = curr_3;
  }
else{
  
  }
if (curr_4> max_value4){
  max_value4 = curr_4;
  }
else{
  
  } */


// serial print the voltage capture by the arduino based on 
//  the four channels variable current to the resistor of 470ohm on your screen
// this function can only be conducted when you connect your arduino to the computer, click the right-up button and monitor the variation
//Serial.print(volt_1);Serial.print("   ");      
//Serial.print(volt_2);Serial.print("   ");
//Serial.print(volt_3);Serial.print("   ");
//Serial.print(curr_4);Serial.print("   ");
//unsigned long time2 = millis();
//Serial.print(time2-time1);Serial.print("   ");

if (max_flag1 == 1 & max_flag2 == 1 & max_flag3 == 1 & max_flag4 == 1){
Serial.print("p");//
Serial.print("  ");
Serial.print(max_value1 + max_value2,4);Serial.print("  ");      
//Serial.print(max_value2,4);Serial.print("   ");
//Serial.print(max_value3,4);Serial.print("   ");
Serial.print(max_value3 + max_value4,4);Serial.print("  ");
Serial.print('\n');
//delay();
}
/* if(x == 's'){
max_value1 = 0;
max_value2 = 0;
max_value3 = 0;
max_value4 = 0;
delay(2000);
} */
}