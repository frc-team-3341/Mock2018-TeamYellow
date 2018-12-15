/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems/Arm.h"
#include "../../include/RobotMap.h"

#include "ctre/Phoenix.h"

Arm::Arm() : Subsystem("Arm"), armMotor(new TalonSRX(armMotorPort)), isArmDown(false), isStopped(true) {
}

  /*----------------
  Unused commands: MoveArm
  Unused methods: getPosition, getArmMotor, getArmDownStatus, switchArmDownStatus
  -----------------*/

void Arm::moveArm(double speed){
  armMotor->Set(ControlMode::PercentOutput, speed);
};

double Arm::getPosition(){
  return armMotor->GetSelectedSensorPosition(0);
};

TalonSRX* Arm::getArmMotor(){
  return armMotor;
};

void Arm::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

bool Arm::getArmDownStatus(){
  return isArmDown;
}

void Arm::switchArmDownStatus(){
  if(isArmDown){
    isArmDown = false;
  }
  else{
    isArmDown = true;
  }
}

bool Arm::getStoppedStatus(){
  return isStopped;
}

void Arm::switchStoppedStatus(){
  if(isStopped){
    isArmDown = false;
  }
  else{
    isStopped = true;
  }
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
