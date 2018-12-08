/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "MoveLowerDispenserServo.h"

#include "../../include/Robot.h"
#include "../../include/OI.h"
#include "WPILib.h"

MoveLowerDispenserServo::MoveLowerDispenserServo() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void MoveLowerDispenserServo::Initialize() {
  isOpen = Robot::m_ballDispenser->getLowerOpenStatus();
}

// Called repeatedly when this Command is scheduled to run
void MoveLowerDispenserServo::Execute() {
  if(isOpen){
    Robot::m_ballDispenser->setLowerPosition(0.0);
  }
  else{
    Robot::m_ballDispenser->setLowerPosition(0.5);
  }
}

// Make this return true when this Command no longer needs to run execute()
bool MoveLowerDispenserServo::IsFinished() {
  if(isOpen){
    if(Robot::m_ballDispenser->getLowerPosition == 0){
		  return true;
	  }
	  else{
		  return false;
    }
  }
  else{
    if(Robot::m_ballDispenser->getLowerPosition == 0.5){
		  return true;
	  }
	  else{
		  return false;
    }
  }
}

// Called once after isFinished returns true
void MoveLowerDispenserServo::End() {
  Robot::m_ballDispenser->switchLowerOpenStatus();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveLowerDispenserServo::Interrupted() {}
