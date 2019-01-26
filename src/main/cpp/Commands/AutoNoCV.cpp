/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/AutoNoCV.h"
#include "Commands/AutoTurn.h"
#include "Commands/AutoMoveForward.h"
#include "RobotMap.h"

AutoNoCV::AutoNoCV(int first) {
  // AddSequential(new AutoMoveForward(-(robotDiagnal - robotLength + 5))); // drive forward so when we turn we don't hit corner of robot against wall
  // AddSequential(new AutoTurn(-90)); // facing left wall
  // AddSequential(new AutoMoveForward(72 - robotDiagnal - 5)); // driving towards leftwall
  // AddSequential(new AutoTurn(90)); // facing forward
  // AddSequential(new AutoMoveForward(141 - (robotDiagnal + 5) - 33 - robotDiagnal - 5)); // driving to crates (33 is distance from center to our end of crate)
  // AddSequential(new AutoTurn(90)); // facing right wall
  
  // AddSequential(new AutoMoveForward(17.5 - (robotDiagnal + 5) + (first-1)*16 + 13/2)); // driving to crates (17.5 is distance from left wall to first crate)  
  // AddSequential(new AutoTurn(-90)); // turn to face crate head on
  // // TODO Add release mechanism for ball dispenser
  // AddSequential(new AutoTurn(180)); // turn to face right wall
  // AddSequential(new AutoMoveForward(-(141 - 33 - (robotDiagnal + 5) - 84))); // Back in auto zone

  AddSequential(new AutoMoveForward((84-robotLength)));

  // Add Commands here:
  // e.g. AddSequential(new Command1());
  //      AddSequential(new Command2());
  // these will run in order.

  // To run multiple commands at the same time,
  // use AddParallel()
  // e.g. AddParallel(new Command1());
  //      AddSequential(new Command2());
  // Command1 and Command2 will run in parallel.

  // A command group will require all of the subsystems that each member
  // would require.
  // e.g. if Command1 requires chassis, and Command2 requires arm,
  // a CommandGroup containing them would require both the chassis and the
  // arm.
}
