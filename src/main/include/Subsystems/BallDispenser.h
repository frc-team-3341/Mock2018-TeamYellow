/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Subsystem.h>

#include "WPILib.h"

class BallDispenser : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  Servo* upperServo;
  Servo* lowerServo;

  bool isUpperOpen;
  bool isLowerOpen;

 public:
  BallDispenser();
  bool getOpenStatus(int servo);
  void switchOpenStatus(int servo);

  void setPosition(int servo, double pos);

  double getPosition(int servo);


  void InitDefaultCommand() override;
};
