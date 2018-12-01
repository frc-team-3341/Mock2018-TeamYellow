/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

#include <WPILib.h>

#include "Commands/ArmLeftDown.h"
#include "Commands/ArmLeftUp.h"
#include "Commands/ArmRightDown.h"
#include "Commands/ArmRightUp.h"

OI::OI() : leftJoy(new Joystick(0)), rightJoy(new Joystick(1)), 
leftArmDownBut(new JoystickButton(leftJoy, 4)), leftArmUpBut(new JoystickButton(leftJoy, 3)), rightArmDownBut(new JoystickButton(rightJoy, 4)), rightArmUpBut(new JoystickButton(rightJoy, 3)){
  // Process operator interface input here.
  leftArmDownBut->WhenPressed(new ArmLeftDown());
	leftArmUpBut->WhenPressed(new ArmLeftUp());
  rightArmDownBut->WhenPressed(new ArmRightDown());
	rightArmUpBut->WhenPressed(new ArmRightUp());
}

Joystick* OI::getLeft(){
  return leftJoy;
}

Joystick* OI::getRight(){
  return rightJoy;
}
