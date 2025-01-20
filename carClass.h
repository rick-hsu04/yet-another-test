#include<SoftwareSerial.h>

class wheelControl
{
public:
	wheelControl();
	void Stop();
	void Front();
	void Right();
	void Left();
	void Back();
private:
	int Left_IN1;
	int Left_IN2;
	int Right_IN3;
	int Right_IN4;
	int Right_PWM;
	int Left_PWM;
};

wheelControl::wheelControl()
{
	Left_IN1 = 10;
	Left_IN2 = 11;
	Right_IN3 = 8;
	Right_IN4 = 9;
	Right_PWM = 5;
	Left_PWM = 6;
}

inline void wheelControl::Stop()
{
	digitalWrite(Left_IN1, LOW);
	digitalWrite(Left_IN2, LOW);
	digitalWrite(Right_IN3, LOW);
	digitalWrite(Right_IN4, LOW);
	analogWrite(Left_PWM, 0);
	analogWrite(Right_PWM, 0);
}

inline void wheelControl::Front()
{
	digitalWrite(Left_IN1, HIGH);
	digitalWrite(Left_IN2, LOW);
	digitalWrite(Right_IN3, HIGH);
	digitalWrite(Right_IN4, LOW);
	analogWrite(Left_PWM, 200);
	analogWrite(Right_PWM, 200);
}

inline void wheelControl::Right()
{
	digitalWrite(Right_IN3, HIGH);
	digitalWrite(Right_IN4, LOW);
	analogWrite(Right_PWM, 0);
}

inline void wheelControl::Left()
{
	digitalWrite(Left_IN1, HIGH);
	digitalWrite(Left_IN2, LOW);
	analogWrite(Left_PWM, 0);
}

inline void wheelControl::Back()
{
	digitalWrite(Left_IN1, LOW);
	digitalWrite(Left_IN2, HIGH);
	digitalWrite(Right_IN3, LOW);
	digitalWrite(Right_IN4, HIGH);
	analogWrite(Left_PWM, 200);
	analogWrite(Right_PWM, 200);
}