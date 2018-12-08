/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "BallDispenser.h"
#include "../../include/RobotMap.h"

BallDispenser::BallDispenser() : Subsystem("BallDispenser"), upperServo(new Servo(upperServoPort)), lowerServo(new Servo(lowerServoPort)), isUpperOpen(false), isLowerOpen(false){}

void BallDispenser::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

bool BallDispenser::getLowerOpenStatus() {
  return isLowerOpen;
}

void BallDispenser::switchLowerOpenStatus() {
  if(isLowerOpen){
    isLowerOpen = false;
  }
  else{
    isLowerOpen = true;
  }
}

bool BallDispenser::getUpperOpenStatus() {
  return isUpperOpen;
}

void BallDispenser::switchUpperOpenStatus() {
  if(isUpperOpen){
    isUpperOpen = false;
  }
  else{
    isUpperOpen = true;
  }
}

void BallDispenser::setUpperPosition(double pos){
  upperServo->Set(pos);
}

void BallDispenser::setLowerPosition(double pos){
  lowerServo->Set(pos);
}

double BallDispenser::getUpperPosition(){
  upperServo->Get();
}

double BallDispenser::getLowerPosition(){
  lowerServo->Get();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
