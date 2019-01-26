/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/MoveArm.h"
#include "Robot.h"
#include "iostream"
using namespace std;

MoveArm::MoveArm(double power) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(Robot::m_arm);
  movePower = power;
}

// Called just before this Command runs the first time
void MoveArm::Initialize() {
  Robot::m_arm->switchArmStoppedStatus();
}

// Called repeatedly when this Command is scheduled to run
void MoveArm::Execute() {
  cout << Robot::m_arm->getArmPos() << endl;
  Robot::m_arm->moveArm(movePower*0.3);
}
// Make this return true when this Command no longer needs to run execute()
bool MoveArm::IsFinished() { 
  return Robot::m_arm->getArmStoppedStatus(); }

// Called once after isFinished returns true
void MoveArm::End() {
    Robot::m_arm->switchArmStoppedStatus();
}


// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveArm::Interrupted() {}
