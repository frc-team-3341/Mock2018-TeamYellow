/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/BallServoClose.h"

#include "../../include/Robot.h"
#include "../../include/OI.h"
#include "WPILib.h"

#include <iostream>
using namespace std;

BallServoClose::BallServoClose() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(Robot::m_ballDispenser);
}

// Called just before this Command runs the first time
void BallServoClose::Initialize() {
    Robot::m_ballDispenser->switchOpenStatus();
    Robot::m_ballDispenser->setPosition(0.0);
    std::cout << "close" << std::endl;
}

// Called repeatedly when this Command is scheduled to run
void BallServoClose::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool BallServoClose::IsFinished() {
  if(Robot::m_ballDispenser->getOpenStatus()){
    return true;
  }
  else{
    return false; 
  }
}

// Called once after isFinished returns true
void BallServoClose::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BallServoClose::Interrupted() {}
