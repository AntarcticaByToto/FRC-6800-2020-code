#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/PWMVictorSPX.h>
#include <frc/SpeedControllerGroup.h>

#include "Constants.h"

class Hopper : public frc2::SubsystemBase {
 public:

    Hopper();

    void SetHopperPower(double power);

    void Periodic() override;

 private:
    //motor type not decided
    frc::PWMVictorSPX hopperMtrA;
    frc::PWMVictorSPX hopperMtrB;

    frc::SpeedControllerGroup hopperMtrs{hopperMtrA, hopperMtrB};

    // photo electric sensors

};
