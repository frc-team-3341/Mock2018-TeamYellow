/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems/ArmLeft.h"
#include "../RobotMap.h"

#include "ctre/Phoenix.h"

ArmLeft::ArmLeft() : Subsystem("ExampleSubsystem"), leftArmMotor(new TalonSRX(leftArmMotorPort)) {
}

void ArmLeft::moveArmLeft(double speed){
  leftArmMotor->Set(ControlMode::PercentOutput, speed);
};

double ArmLeft::getPosition(){
  return leftArmMotor->GetSelectedSensorPosition(0);
};

TalonSRX* ArmLeft::getArmLeftMotor(){
  return leftArmMotor;
};

void ArmLeft::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
