// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>

#include "photonlib/PhotonCamera.h"
#include "photonlib/PhotonUtils.h"

class CameraSubsystem : public frc2::SubsystemBase {
 public:
  CameraSubsystem();

  /**
   * Example command factory method.
   */
  frc2::CommandPtr GetBestID();

  /**
   * An example method querying a boolean state of the subsystem (for example, a
   * digital sensor).
   *
   * @return value of some boolean subsystem state, such as a digital sensor.
   */
  bool CheckForTargets();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  photonlib::PhotonCamera limelightCamera{"limelight1"};

};