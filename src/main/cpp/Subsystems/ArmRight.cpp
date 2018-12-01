/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems/ArmRight.h"
#include "../../include/RobotMap.h"

#include "ctre/Phoenix.h"

ArmRight::ArmRight() : Subsystem("ExampleSubsystem"), rightArmMotor(new TalonSRX(rightArmMotorPort)) {
}

void ArmRight::moveArmRight(double speed){
  rightArmMotor->Set(ControlMode::PercentOutput, speed);
};

double ArmRight::getPosition(){
  return rightArmMotor->GetSelectedSensorPosition(0);
};

TalonSRX* ArmRight::getArmRightMotor(){
  return rightArmMotor;
};

void ArmRight::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
