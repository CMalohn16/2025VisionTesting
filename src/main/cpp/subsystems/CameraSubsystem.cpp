// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/CameraSubsystem.h"

  CameraSubsystem::CameraSubsystem() {
    // Implementation of subsystem constructor goes here.
  }

  bool CameraSubsystem::CheckForTargets() {
    photon::PhotonPipelineResult result = limelightCamera.GetLatestResult();
    return result.HasTargets();
  }