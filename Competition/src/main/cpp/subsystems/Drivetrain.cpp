#include "subsystems/Drivetrain.h"

#define MAX_OUTPUT 1.0
#define DEADBAND 0.05
#define P_VALUE 0.005
#define I_VALUE 0
#define D_VALUE 0
#define ARCADE_MODE true
#define DRIVER_SQUARED true

Drivetrain::Drivetrain() : leftDriveA{CAN_ID_LEFT_A, rev::CANSparkMax::MotorType::kBrushless},
                           leftDriveB{CAN_ID_LEFT_B, rev::CANSparkMax::MotorType::kBrushless},
                           leftDriveC{CAN_ID_LEFT_C, rev::CANSparkMax::MotorType::kBrushless},
                           rightDriveA{CAN_ID_RIGHT_A, rev::CANSparkMax::MotorType::kBrushless},
                           rightDriveB{CAN_ID_RIGHT_B, rev::CANSparkMax::MotorType::kBrushless},
                           rightDriveC{CAN_ID_RIGHT_C, rev::CANSparkMax::MotorType::kBrushless}
{
    drive.SetMaxOutput(MAX_OUTPUT);
    drive.SetDeadband(DEADBAND);

    leftDrive.SetInverted(!leftDrive.GetInverted());
    rightDrive.SetInverted(!rightDrive.GetInverted());

    leftDriveA.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    leftDriveB.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    leftDriveC.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    rightDriveA.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    rightDriveB.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    rightDriveC.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
}

void Drivetrain::Periodic() { }

void Drivetrain::Move(double leftInput, double rightInput) {
    drive.ArcadeDrive(leftInput, -rightInput * .5, true);
}

void Drivetrain::Stop() {
    drive.StopMotor();
}