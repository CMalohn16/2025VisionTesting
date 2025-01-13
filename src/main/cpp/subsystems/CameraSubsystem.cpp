// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <subsystems/CameraSubsystem.h>
#include <frc2/command/PrintCommand.h>
#include <string>

CameraSubsystem::CameraSubsystem() {
  // Implementation of subsystem constructor goes here.
}

//Puts the ID of the best visible target in smart dashboard
frc2::CommandPtr CameraSubsystem::getBestID() {
  return RunOnce([this] { 
    photon::PhotonPipelineResult result = limelightCamera.GetLatestResult();
    if (result.HasTargets()) {
      result.GetBestTarget();
      photon::PhotonTrackedTarget bestTarget = result.GetBestTarget();
      //frc2::PrintCommand(std::to_string(bestTarget.GetFiducialId()));
      frc::SmartDashboard::PutNumber("AprilTag ID", bestTarget.GetFiducialId());
    } else {
      //frc2::PrintCommand("No Target Found.");
      frc::SmartDashboard::PutNumber("AprilTag ID", 100);
    }
  });
  //return -1
}

//finds the robot's position on the field using apriltags
// void CameraSubsystem::getPose() {
//     photon::
// }

//updates the result from photonvision limelight
void CameraSubsystem::updateResult() {
  result = limelightCamera.GetLatestResult();
}