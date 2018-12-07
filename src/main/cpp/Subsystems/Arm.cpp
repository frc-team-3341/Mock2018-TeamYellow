/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems/Arm.h"
#include "../../include/RobotMap.h"

#include "ctre/Phoenix.h"

Arm::Arm() : Subsystem("ExampleSubsystem"), ArmMotor(new TalonSRX(armMotorPort)), isArmDown(false) {
}

void Arm::moveArm(double speed){
  ArmMotor->Set(ControlMode::PercentOutput, speed);
};

double Arm::getPosition(){
  return ArmMotor->GetSelectedSensorPosition(0);
};

TalonSRX* Arm::getArmMotor(){
  return ArmMotor;
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
// Put methods for controlling this subsystem
// here. Call these from Commands.
