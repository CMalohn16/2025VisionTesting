// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <subsystems/CameraSubsystem.h>
#include <frc2/command/PrintCommand.h>
#include <string>

CameraSubsystem::CameraSubsystem() : limelightCamera("limelight1") {
  // Implementation of subsystem constructor goes here.
}

frc2::CommandPtr CameraSubsystem::GetBestID() {
  return RunOnce([this] { 
    photon::PhotonPipelineResult result = limelightCamera.GetLatestResult();
    if (result.HasTargets()) {
      result.GetBestTarget();
      photon::PhotonTrackedTarget bestTarget = result.GetBestTarget();
      frc2::PrintCommand(std::to_string(bestTarget.GetFiducialId()));
    } else {
      frc2::PrintCommand("No Target Found.");
    }
  });
  //return -1;
}