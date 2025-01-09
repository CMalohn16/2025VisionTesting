// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/CameraSubsystem.h"

/**
 * An example command that uses an example subsystem.
 *
 * <p>Note that this extends CommandHelper, rather extending Command
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class GetBestID
    : public frc2::CommandHelper<frc2::Command, GetBestID> {
  public:
    explicit GetBestID(CameraSubsystem* subsystem);

    void Initialize() override;

 private:
  CameraSubsystem* m_camera;
};