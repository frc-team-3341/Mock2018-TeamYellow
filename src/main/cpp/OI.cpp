/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

#include <WPILib.h>

#include "Commands/MoveArm.h"
#include "Commands/DispenseBall.h"


OI::OI() : leftJoy(new Joystick(0)), rightJoy(new Joystick(1)), moveArmBut(new JoystickButton(rightJoy, 3)), dispenseBallBut(new JoystickButton(rightJoy, 1)){
  // Process operator interface input here.
  moveArmBut->WhenPressed(new MoveArm());
  dispenseBallBut->WhenPressed(new DispenseBall());
}

Joystick* OI::getLeft(){
  return leftJoy;
}

Joystick* OI::getRight(){
  return rightJoy;
}
