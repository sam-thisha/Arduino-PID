/*created by >>thisha<<
 * Rahula College Matara
 */
 
//.......motor control pins...............
#define M1F 52  //left motor >>      IN1
#define M1R 50  //left motor <<      IN2
#define M1S 9  //left motor speed   ENA
#define M2F 48  //Right motor >>     IN3 
#define M2R 46  //Right motor <<     IN4
#define M2S 10  //Right motor speed  ENB

//.......Ultrasonic..................
/*#define trigPin 6   //trig pin
#define echoPin 12  //echo pin
float duration=0;
float distance=0; 

int lVal=0;
int count=0;
int count_left=0;
int count_right=0;

//.................Servo..................
#include <Servo.h> */

#include <BeeLineSensorPro.h>

BeeLineSensorPro sensor = BeeLineSensorPro((unsigned char[]) {
  A0, A1, A2, A3, A4, A5, A6, A7
}, LINE_BLACK);

void setup() {
  Serial.begin(115200);

//.......motor control pins...............
  pinMode(M1F, OUTPUT);
  pinMode(M1R, OUTPUT);
  pinMode(M1S, OUTPUT);
  pinMode(M2F, OUTPUT);
  pinMode(M2R, OUTPUT);
  pinMode(M2S, OUTPUT);

/*  pinMode(trigPin, INPUT);
  pinMode(echoPin, OUTPUT);*/

  sensor_calibrate();
}

//.....pid.......
float kP = 1 ; //changeble    
float kD = 0  ;     
int last_value;     

void loop() {
  int err = sensor.readSensor();
  Serial.println(err);
  int m1 = 60; //changeble
  int m2 = 60 ;

  int diff = err * kP + (err-last_value)*kD;
  last_value = err;

  moter(m1 - diff, m2 + diff);
 
  /*distance=ultrasonic();

  if(distance<=7) {
    moter(-75,-75);
    delay(100);
  }
  count = (ultrasonic_left + ultrasonic_right);*/

 
}
