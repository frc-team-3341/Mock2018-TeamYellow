/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/OpenCloseDispenser.h"


#include "../../include/Robot.h"
#include "../../include/OI.h"
#include "WPILib.h"

OpenCloseDispenser::OpenCloseDispenser(double p) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  pos = p;
  Requires(Robot::m_ballDispenser);
}

// Called just before this Command runs the first time
void OpenCloseDispenser::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void OpenCloseDispenser::Execute() {
  Robot::m_ballDispenser->setPosition(pos);
}

// Make this return true when this Command no longer needs to run execute()
bool OpenCloseDispenser::IsFinished() { return false; }

// Called once after isFinished returns true
void OpenCloseDispenser::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void OpenCloseDispenser::Interrupted() {}
