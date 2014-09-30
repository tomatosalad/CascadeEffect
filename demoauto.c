#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     driveleft,     tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     driveright,    tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Servo,  srvo_S1_C2_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.

int leftspeed = 0;
int rightspeed = 0;


void initializeRobot()
{
  // Place code here to sinitialize servos to starting positions.
	nMotorEncoder[driveleft] = 0;
	nMotorEncoder[driveright] = 0;

}

void speedup() //add an if statement re: one motor reaching 50 before the other
{
	while(leftspeed <= 50 && rightspeed <= 50) {
		motor[driveleft] = leftspeed;
		motor[driveright] = rightspeed;
		leftspeed++;
		rightspeed++;
		wait1Msec(50);
	}
}

void topoff()		//rewrite this
{
	while(leftspeed <=100 && rightspeed <=100) {
		motor[driveleft] = leftspeed;
		motor[driveright] = rightspeed;
		if(leftspeed < 100) {
			leftspeed++;
		}
		if(rightspeed < 100) {
			rightspeed++;
		}
		wait1Msec(50);
	}
}

void slowdown() //add if statement to prevent negative motion
{
	while(leftspeed != 0 && rightspeed != 0) {
		motor[driveleft] = leftspeed;
		motor[driveright] = rightspeed;
		leftspeed--;
		rightspeed--;
		wait1Msec(50);
	}
}


task main()
{
  getJoystickSettings(joystick);

	initializeRobot();

  waitForStart(); // Wait for the beginning of autonomous phase.

  speedup();

	/*
  while(nMotorEncoder[driveleft] || nMotorEncoder[driveright] <=100) {
  	motor[driveleft] = 50;
  	motor[driveright] = 50;
  }
  */
  //slowdown();
}
