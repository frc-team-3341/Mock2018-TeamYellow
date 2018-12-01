/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

#include <WPILib.h>

#include "Commands/ArmDown.h"
#include "Commands/ArmUp.h"

OI::OI() : leftJoy(new Joystick(0)), rightJoy(new Joystick(1)), 
ArmDownBut(new JoystickButton(rightJoy, 3)), ArmUpBut(new JoystickButton(rightJoy, 5)){
  // Process operator interface input here.
  ArmDownBut->WhenPressed(new ArmDown());
	ArmUpBut->WhenPressed(new ArmUp());
}

Joystick* OI::getLeft(){
  return leftJoy;
}

Joystick* OI::getRight(){
  return rightJoy;
}
