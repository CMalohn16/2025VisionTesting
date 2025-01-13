// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/apriltag/AprilTagFieldLayout.h>
#include <string_view>

#include "photon/PhotonCamera.h"
#include "photon/PhotonUtils.h"

class CameraSubsystem : public frc2::SubsystemBase {
 public:
  CameraSubsystem();

  /**
   * Example command factory method.
   */
  frc2::CommandPtr getBestID();

  void getPose();
  //frc2::CommandPtr alignWithCoralTag();
  void updateResult();
  
 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  frc::AprilTagFieldLayout aprilTagFieldLayout = frc::LoadAprilTagLayoutField(frc::AprilTagField::k2024Crescendo);
  photon::PhotonCamera limelightCamera{"limelight1"};
  
  photon::PhotonPipelineResult result = limelightCamera.GetLatestResult();
};