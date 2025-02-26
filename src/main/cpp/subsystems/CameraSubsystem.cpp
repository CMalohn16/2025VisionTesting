// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <subsystems/CameraSubsystem.h>

CameraSubsystem::CameraSubsystem() {
  // Implementation of subsystem constructor goes here.
}

//Puts the ID of the best visible target in smart dashboard
frc2::CommandPtr CameraSubsystem::getBestID() {
  return RunOnce([this] {
    photon::PhotonPipelineResult result = limelightCamera.GetLatestResult();
    if (result.HasTargets()) {
      photon::PhotonTrackedTarget bestTarget = result.GetBestTarget();
      //frc2::PrintCommand(std::to_string(bestTarget.GetFiducialId()));
      frc::SmartDashboard::PutNumber("AprilTagID", bestTarget.GetFiducialId());
    } else {
      //frc2::PrintCommand("No Target Found.");
      frc::SmartDashboard::PutNumber("AprilTagID", 100);
    }
  });
  //return -1
}

//finds the robot's position on the field using apriltags
// void CameraSubsystem::getPose() {
//     photon::
// }

// frc2::CommandPtr CameraSubsystem::alignWithCoralTag() {
//   return RunOnce([this] {
//     photon::PhotonPipelineResult result = limelightCamera.GetLatestResult();
//     if (result.HasTargets()) {
//       photon::PhotonTrackedTarget bestTarget = result.GetBestTarget();
//     }
//   });
// }

//updates the result from photonvision limelight
// void CameraSubsystem::updateResult() {
//   CameraSubsystem::result = limelightCamera.GetLatestResult();
// }