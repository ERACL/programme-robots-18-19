
#pragma config(Sensor, S1,     redButton,      sensorEV3_Touch)
#pragma config(Sensor, S2,     sensorFront,    sensorEV3_Ultrasonic)
#pragma config(Sensor, S3,     sensorBack,     sensorEV3_Ultrasonic)
#pragma config(Motor,  motorA,          motorLeft,     tmotorEV3_Medium, PIDControl, encoder)
#pragma config(Motor,  motorB,          hook,          tmotorNXT, openLoop)
#pragma config(Motor,  motorC,           ,             tmotorEV3_Medium, openLoop)
#pragma config(Motor,  motorD,          motorRight,    tmotorEV3_Medium, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define sensorFront S2
#define sensorBack S3

#include "config.c"
#include "position.c"
#include "movement.c"
#include "sonar.c"

task displayPos() {
	struct PosData pos;
	while (true) {
		getPosition(&pos);
		displayBigTextLine(1, "X : %6.2f", pos.x);
		displayBigTextLine(3, "Y : %6.2f", pos.y);
		displayBigTextLine(5, "O : %6.2f", pos.orientation);
		datalogAddValue(7, SensorValue[sensorFront]);
		writeDebugStreamLine("X:%5.1f Y:%5.1f O:%5.1f", pos.x, pos.y, pos.orientation);
		wait1Msec(50);
	}
}

task emergencyStop() {
	while (SensorValue[redButton] == 1) { wait1Msec(20); }
	stopAllTasks();
}


task main()
{
	datalogClear();
  initConfig(JOE);
  initPosition(false);
  while (SensorValue[redButton] == 0) { wait1Msec(20); }
  wait1Msec(500);
  startTask(displayPos);
  startTask(avoidObstacles);
  startTask(emergencyStop);



  moveTo_forward(700,190);
  moveTo_forward(1600,170);
  while (getMovementState() != NOMVT) {wait1Msec(20);}

  rotateTo(170);
  rotateTo(200);
  while (getMovementState() != NOMVT) {wait1Msec(20);}

  while (getMovementState() != NOMVT) {wait1Msec(20);}
  motor[hook] = 20;
  while(nMotorEncoder[hook]<180) { wait10Msec(1); }
  motor[hook] = 0;
  wait10Msec(50)

  rotateTo(60);
  while (getMovementState() != NOMVT) {wait1Msec(20);}
  motor[hook] = -20;
  while(nMotorEncoder[hook]>30) { wait10Msec(1); }
  motor[hook] = 0;
  wait10Msec(50)
  rotateTo(200);
  while (getMovementState() != NOMVT) {wait1Msec(20);}
  motor[hook] = 20;
  while(nMotorEncoder[hook]<180) { wait10Msec(1); }
  motor[hook] = 0;
  wait10Msec(50)

  rotateTo(60);

	//monter hook
  while (getMovementState() != NOMVT) {wait1Msec(20);}
  motor[hook] = -20;
  while(nMotorEncoder[hook]>30) { wait10Msec(1); }
  motor[hook] = 0;
  wait10Msec(50)
////arrive au palet gold et descendre hook
//  moveTo_forward(2100,170);
//  while (getMovementState() != NOMVT) {wait1Msec(20);}
//  rotateTo(170)
//  motor[hook] = 20;
//  while(nMotorEncoder[hook]<170) { wait10Msec(1); }
//  motor[hook] = 0;
//  wait10Msec(50)
////  reculer et ?la fois descendre hook
//  moveTo_backward(2100,100);
//  motor[hook] = 10;
//  while(nMotorEncoder[hook]<180) { wait10Msec(1); }
//  motor[hook] = 0;
//  wait10Msec(50)

////monter hook
//  motor[hook] = -20;
//  while(nMotorEncoder[hook]>30) { wait10Msec(1); }
//  motor[hook] = 0;
//  wait10Msec(50)

//// arrive ?la pente
//  moveTo_forward(200,100);
//  moveTo_forward(200,-500);
////descendre hook
//  while (getMovementState() != NOMVT) {wait1Msec(20);}
//  motor[hook] = 20;
//  while(nMotorEncoder[hook]<150) { wait10Msec(1); }
//  motor[hook] = 0;
//  wait10Msec(50)
////  reculer et ? la fois descendre hook 180
//  moveTo_backward(200,-410);
//  motor[hook] = 20;
//  while(nMotorEncoder[hook]<180) { wait10Msec(1); }
//  motor[hook] = 0;
//  wait10Msec(50)
////monter hook 150
//  while (getMovementState() != NOMVT) {wait1Msec(20);}
//  motor[hook] = -20;
//  while(nMotorEncoder[hook]>150) { wait10Msec(1); }
//  motor[hook] = 0;
//  wait10Msec(50)
////2eme palet 180
//  moveTo_forward(270,-500);
//  motor[hook] = 20;
//  while(nMotorEncoder[hook]<180) { wait10Msec(1); }
//  motor[hook] = 0;
//  wait10Msec(50)

//  moveTo_backward(260,-410);
//  motor[hook] = 20;
//  while(nMotorEncoder[hook]<180) { wait10Msec(1); }
//  motor[hook] = 0;
//  wait10Msec(50)



  while (getMovementState() != NOMVT) {wait1Msec(20);}
  stopAllTasks();
}
