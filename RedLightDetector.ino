#include<SoftwareSerial.h>
#include<carClass.h>
  char command;
  int action = 1;
  int Left_IN1 = 10;
  int Left_IN2 = 11;
  int Right_IN3 = 8;
  int Right_IN4 = 9;
  int Right_PWM = 5;
  int Left_PWM = 6;
  int sec = 100;
  int desec = 100;
  SoftwareSerial bread(3,2);
  wheelControl car;

//void Front()
//{
//  digitalWrite(Left_IN1,HIGH);
//  digitalWrite(Left_IN2,LOW);
//  digitalWrite(Right_IN3,HIGH);
//  digitalWrite(Right_IN4,LOW);
//  analogWrite(Left_PWM,200);
//  analogWrite(Right_PWM,200);
//}
//void Stop()
//{
//  digitalWrite(Left_IN1,LOW);
//  digitalWrite(Left_IN2,LOW);
//  digitalWrite(Right_IN3,LOW);
//  digitalWrite(Right_IN4,LOW);
//  analogWrite(Left_PWM,0);
//  analogWrite(Right_PWM,0);
//}
//void Right()
//{
//  digitalWrite(Right_IN3,HIGH);
//  digitalWrite(Right_IN4,LOW);
//  analogWrite(Right_PWM,0);
//}
//void Left()
//{
//  digitalWrite(Left_IN1,HIGH);
//  digitalWrite(Left_IN2,LOW);
//  analogWrite(Left_PWM,0);
//}
//void Back()
//{
//  digitalWrite(Left_IN1,LOW);
//  digitalWrite(Left_IN2,HIGH);
//  digitalWrite(Right_IN3,LOW);
//  digitalWrite(Right_IN4,HIGH);
//  analogWrite(Left_PWM,200);
//  analogWrite(Right_PWM,200);
//}

void executeCommand(char command){
  switch(command){
	case 'F':
	  {
		car.Front();
		delay(sec);
		break;
	  } 
	case 'R':
	  {
		car.Right();
		delay(sec);
		break;
	  }
	case 'L':
	  {
		car.Left();
		delay(sec);
		break;
	  }
	case 'B':
	  {
		car.Back();
		delay(sec);
		break;
	  }
	case 'P':
	{
	  action = 0;
	  car.Front();
	  break;
	}
	case 'A':
	{
	  action = 1;
	  car.Stop();
	  break;
	}
	case 'X':
	{
	  car.Stop();
	  break;
	}
	default:
	{
	  // Serial.println("WRONG");
	  break;
	}
  }
}

void setup() {
  
  bread.begin(9600);
  Serial.begin(9600);
  //設定傳輸速度
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(Left_IN1, OUTPUT);
  pinMode(Left_IN2, OUTPUT);
  pinMode(Right_IN3, OUTPUT);
  pinMode(Right_IN4, OUTPUT);
  pinMode(Left_PWM,OUTPUT);
  pinMode(Right_PWM,OUTPUT);
  //設定腳位名稱
}

void loop() {
  int Front_Detector = analogRead(A0);
  int Right_Detector = analogRead(A1);
  int Left_Detector = analogRead(A2);
  if(bread.available())
  {
	command = bread.read();
	executeCommand(command);
	Serial.println(command);
  }
  if(action==0)
  {
	if(Left_Detector > 200 && Right_Detector > 200)
	  {
		executeCommand('A');
	  }
	else
	{
	if(Left_Detector>200)
	  {
		car.Left();
		// delay(sec);
		// Stop();
		// delay(desec);
		//左輪前進
		// if(Right_Detector>200)
		// {
		//   car.Stop();
		  // delay(sec);
		  // car.Stop();
		  // delay(desec);
		  //有輪前進
		// }
	  }
	if(Right_Detector>200)
	  {
		car.Right();
		// delay(sec);
		// car.Stop();
		// delay(desec);
		//有輪前進
		// if(Left_Detector>200)
		// {
		//   car.Stop();
		  // delay(sec);
		  // car.Stop();
		  // delay(desec);
		  //有輪前進
		// }
	  }
	  if(Front_Detector>200)
	  {
		car.Front();
	  }
	}
  }
}
