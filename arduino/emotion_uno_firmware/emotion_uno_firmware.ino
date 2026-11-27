#include <AFMotor.h>
#include <SoftwareSerial.h>
SoftwareSerial bt(A0,A1);
AF_DCMotor m1(1),m2(2),m3(3),m4(4);
unsigned long last=0, stopped=0; char dir='S'; byte pwm=0;
void speedSet(byte s){pwm=s;m1.setSpeed(s);m2.setSpeed(s);m3.setSpeed(s);m4.setSpeed(s);}
void stopAll(){m1.run(RELEASE);m2.run(RELEASE);m3.run(RELEASE);m4.run(RELEASE);if(dir!='S')stopped=millis();dir='S';}
void setup(){bt.begin(9600);stopAll();speedSet(0);}
void loop(){while(bt.available()){char c=bt.read();if(c=='S'){stopAll();}else if(c>='0'&&c<='9'){speedSet((c-'0')*255/10);}else if(c=='q'){speedSet(255);}else if(c=='F'||c=='B'||c=='L'||c=='R'){if(dir!=c&&dir!='S'){stopAll();continue;}if(dir=='S'&&millis()-stopped<150)continue;last=millis();if(dir!=c){m1.run(c=='F'||c=='R'?FORWARD:BACKWARD);m2.run(c=='F'||c=='R'?FORWARD:BACKWARD);m3.run(c=='F'||c=='L'?FORWARD:BACKWARD);m4.run(c=='F'||c=='L'?FORWARD:BACKWARD);dir=c;}}}if(dir!='S'&&millis()-last>=1000)stopAll();}
