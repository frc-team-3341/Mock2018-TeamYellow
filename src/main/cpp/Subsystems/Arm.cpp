/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems/Arm.h"
#include "ctre/Phoenix.h"

Arm::Arm() : Subsystem("Arm"), isStopped(false), armMotor(new TalonSRX(4)) {
  armMotor->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative,0,10);
  armMotor->SetSelectedSensorPosition(0,0,10);
}

void Arm::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void Arm::switchArmStoppedStatus(){
  if(isStopped)
  {
    isStopped = false;
  }else{
    isStopped = true;
  }
}

bool Arm::getArmStoppedStatus(){
  return isStopped;
}

void Arm::moveArm(double s){
  armMotor->Set(ControlMode::PercentOutput, s);
}

double Arm::getArmPos(){
  double armPos = armMotor->GetSensorCollection().GetQuadraturePosition();
  return armPos;
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
