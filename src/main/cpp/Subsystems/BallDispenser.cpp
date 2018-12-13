/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems/BallDispenser.h"
#include "../../include/RobotMap.h"

BallDispenser::BallDispenser() : Subsystem("BallDispenser"), servo(new Servo(lowerServoPort)), isOpen(false){}

void BallDispenser::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}



/*-------------------------------
For all "int servo" parameters:
1 corresponds to the lower servo
2 (or really any other number) corresponds to the upper servo
-------------------------------*/

bool BallDispenser::getOpenStatus() {
    return isOpen;
}

void BallDispenser::switchOpenStatus() {
    if(isOpen){
      isOpen = false;
    }
    else{
      isOpen = true;
    }
}

void BallDispenser::setPosition(double pos){
    servo->Set(pos);
}

double BallDispenser::getPosition(){
    servo->Get();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
