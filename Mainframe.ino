#include   <Servo.h>
#define servo_Pin 9
#define motor_speed 6
#define motor_1 11
#define motor_2 8
#define sensor_left 4
#define sensor_right 5
int sensor_right_position;
int sensor_left_position;
int servo_degree = 82;

Servo degree;
 
void setup()
{
  pinMode(motor_speed, OUTPUT);
  pinMode(motor_1, OUTPUT);
  pinMode(motor_2, OUTPUT);
  pinMode(sensor_left, INPUT);
  pinMode(sensor_right, INPUT); 
}

void motor_start()
{
    digitalWrite(motor_1, LOW);
    digitalWrite(motor_2, HIGH);
    analogWrite(motor_speed, 230);
}
    
void motor_stop()
{
    digitalWrite(motor_1, LOW);
    digitalWrite(motor_2, LOW);
}

void turn()
{
    degree.write(servo_degree);
    degree.attach(servo_Pin);
}

void go_forward()
{
    degree.write(servo_degree);
    degree.attach(servo_Pin);
}
void motor_turning()
{
    digitalWrite(motor_1, LOW);
    digitalWrite(motor_2, HIGH);
    analogWrite(motor_speed, 220);
}

void loop()
{
 sensor_right_position = digitalRead(sensor_right);
 sensor_left_position = digitalRead(sensor_left);
 if (sensor_right_position == 0)
 {
  if (sensor_left_position == 0)
  {
    go_forward();
    motor_start(); 
  }
  else 
  {
    if (sensor_left_position == 1)
    {
      if (servo_degree >= 60)
      {
        servo_degree -= 5;
     
      }
      if (servo_degree < 85)
      {
        turn();
        delay(15);
        motor_stop();
        motor_turning();
      }
    }
  }
 }
 else
 {
  if (sensor_right_position == 1)
  {
    if (sensor_left_position != 1)
    {
      if (servo_degree <= 115)
      {
        servo_degree += 5;
      }
      if (servo_degree > 85)
      { 
        turn();
        delay(15);
        motor_stop();
        motor_turning();
      }
    }
  }
 }
 if (sensor_right_position == 1)
 {
  if (sensor_left_position == 1)
  {
    motor_stop();
    go_forward(); 
  }
 }
}
