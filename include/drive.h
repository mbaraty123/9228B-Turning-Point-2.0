/**
 * @brief Basic drive definitions and functions
 * @file drive.h
 **/
 #ifndef _DRIVE_H_
 #define _DRIVE_H_

 #include <API.h>
 #include "motor_ports.h"
 #include "controller.h"
 #include "gyro.h"



 /**
  * @brief defines the directions in which the drive base can be moving
  * @author Michael Baraty
  * @date 10/31/2018
 **/
typedef enum {
  forward,
  reverse,
  clockwise,
  counterclockwise
} Direction;

/**
 * @brief defines the directions in which the intake mechanism can move
 * @author Michael Baraty
 * @date 11/10/2018
**/
typedef enum {
  up,
  down
} FlipperDirection;

/**
 * @brief defines the minimum reading from the joysticks to avoid underpowering the motors
 * @author Michael Baraty
 * @date 10/25/2018
**/
#define THRESHOLD 20

/**
 * @brief sets the speed of the motors according to a joystick taking into account the threshold
 * @param channel
 * @param speed
 * @author Michael Baraty
 * @date 10/25/2018
 */
void motorSpeedStick(unsigned char channel, int speed);

/**
 * @brief stops the robot drivebase
 * @author Michael Baraty
 * @date 10/26/2018
 */
void robotStop();

/**
 * @brief sets the speed for the flywheel
 * @param speed
 * @author Michael Baraty
 * @date 10/26/2018
 */
void flywheelSet(int speed);

/**
  * @brief stops the flywheel
  * @author Michael Baraty
  * @date 10/26/2018
  */
void flywheelStop();

/**
  * @brief activates the intake mechanism at a certain speed
  * @author Michael Baraty
  * @date 10/31/2018
  */
void intakeSet(Direction dir);

/**
   * @brief disables the intake mechanism
   * @author Michael Baraty
   * @date 10/26/2018
  */
void intakeStop();

/**
    * @brief drives the robot
    * @author Michael Baraty
    * @date 10/26/2018
    */
void drive();

/**
   * @brief spins the robot in a given direction at a given speed
   * @param dir
   * @param speed
   * @author Michael Baraty
   * @date 11/6/2018
  */
void robotSpin(Direction dir, int speed);

/**
   * @brief straightens the robot to face the starting direction
   * @author Michael Baraty
   * @date 11/6/2018
  */
void robotStraighten();

/**
   * @brief drives the robot forward at half speed
   * @author Michael Baraty
   * @date 11/6/2018
  */
void robotDriveForward();

/**
   * @brief drives the robot straight in a given direction
   * @param dir
   * @author Michael Baraty
   * @date 11/6/2018
  */
void robotDriveStraight(Direction dir);

/**
   * @brief drives the robot backwards at half speed
   * @author Michael Baraty
   * @date 11/6/2018
  */
void robotDriveReverse();

/**
   * @brief moves the flipper in a certain direction
   * @param dir
   * @author Michael Baraty
   * @date 11/6/2018
  */
void flipperMove(FlipperDirection dir);

/**
   * @brief stops the cap flipper
   * @author Michael Baraty
   * @date 11/10/2018
  */
void flipperStop();

/**
  * @brief sets the speed for the right motors
  * @param speed
  * @author Michael Baraty
  * @date 12/4/2018
  */
void motorSetRight(int speed);

/**
  * @brief sets the speed for the left motors
  * @param speed
  * @author Michael Baraty
  * @date 12/4/2018
  */
void motorSetLeft(int speed);

#endif
