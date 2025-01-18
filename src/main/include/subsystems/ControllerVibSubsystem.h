#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>
#include <frc/XboxController.h>

#include "Constants.h"

class ControllerVibSubsystem : public frc2::SubsystemBase {
 public:
  ControllerVibSubsystem();

  frc2::CommandPtr vibrate();
  frc2::CommandPtr endVibrate();
  
 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  frc2::CommandXboxController m_driverController{
    OperatorConstants::kDriverControllerPort};

};