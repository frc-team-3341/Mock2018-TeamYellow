/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

#include <WPILib.h>
#include "Commands/AutoMoveForward.h"
#include "Commands/MoveArm.h"

OI::OI() : leftJoy(new Joystick(0)), rightJoy(new Joystick(1)), up(new JoystickButton(rightJoy, 4)), down(new JoystickButton(rightJoy, 3)){
  // Process operator interface input here.
  up->WhenPressed(new MoveArm(-0.15));
  up->WhenReleased(new MoveArm(0));
  down->WhenPressed(new MoveArm(0.15));
  down->WhenReleased(new MoveArm(0));

}

Joystick* OI::getLeft(){
  return leftJoy;
}

Joystick* OI::getRight(){
  return rightJoy;
}
