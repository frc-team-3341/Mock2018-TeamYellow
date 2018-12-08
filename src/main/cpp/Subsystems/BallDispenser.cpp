/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems/BallDispenser.h"
#include "../../include/RobotMap.h"

BallDispenser::BallDispenser() : Subsystem("BallDispenser"), upperServo(new Servo(upperServoPort)), lowerServo(new Servo(lowerServoPort)), isUpperOpen(false), isLowerOpen(false){}

void BallDispenser::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}



/*-------------------------------
For all "int servo" parameters:
1 corresponds to the lower servo
2 (or really any other number) corresponds to the upper servo
-------------------------------*/

bool BallDispenser::getOpenStatus(int servo) {
  if(servo == 1){
    return isLowerOpen;
  }
  else{
    return isUpperOpen;
  }
}

void BallDispenser::switchOpenStatus(int servo) {
  if(servo == 1){
    if(isLowerOpen){
      isLowerOpen = false;
    }
    else{
      isLowerOpen = true;
    }
  }
  else{
    if(isUpperOpen){
      isUpperOpen = false;
    }
    else{
      isUpperOpen = true;
    }
  }
}

void BallDispenser::setPosition(int servo, double pos){
  if(servo == 1){
    lowerServo->Set(pos);
  }
  else{
    upperServo->Set(pos);
  }
}

double BallDispenser::getPosition(int servo){
  if(servo == 1){
    lowerServo->Get();
  }
  else{
    upperServo->Get();
  }
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
