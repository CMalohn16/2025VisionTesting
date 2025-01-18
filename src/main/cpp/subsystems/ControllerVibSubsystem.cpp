#include "subsystems/ControllerVibSubsystem.h"

ControllerVibSubsystem::ControllerVibSubsystem() {
  // Implementation of subsystem constructor goes here.
}

frc2::CommandPtr ControllerVibSubsystem::vibrate() {
  return RunOnce([this] {
    m_driverController.SetRumble(frc::GenericHID::RumbleType::kBothRumble, 1);
  });
}

frc2::CommandPtr ControllerVibSubsystem::endVibrate() {
  return RunOnce([this] {
    m_driverController.SetRumble(frc::GenericHID::RumbleType::kBothRumble, 0);
  });
}