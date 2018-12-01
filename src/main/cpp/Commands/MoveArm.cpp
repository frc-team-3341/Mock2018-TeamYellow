/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/MoveArm.h"

#include "../../include/Robot.h"
#include "../../include/OI.h"
#include "WPILib.h"

MoveArm::MoveArm() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void MoveArm::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void MoveArm::Execute() {
  if(armDown){
    Robot::m_arm->moveArm(-0.1);
  }
  else{
    Robot::m_arm->moveArm(0.1);
  }
  
}

// Make this return true when this Command no longer needs to run execute()
bool MoveArm::IsFinished() {
  if(armDown){
    if(Robot::m_arm->getArmMotor()->GetSensorCollection().IsRevLimitSwitchClosed()){
	    //Robot::m_arm->getArmMotor()->SetSelectedSensorPosition(0, 0, 10);
      armDown = false;
		  return true;
	  }
	  else{
		  return false;
    }
  }
  else{
    if(Robot::m_arm->getArmMotor()->GetSensorCollection().IsFwdLimitSwitchClosed()){
	    //Robot::m_arm->getArmMotor()->SetSelectedSensorPosition(0, 0, 10);
      armDown = true;
		  return true;
	  }
	  else{
		  return false;
    }
  }
}

// Called once after isFinished returns true
void MoveArm::End() {
  Robot::m_arm->moveArm(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveArm::Interrupted() {}
