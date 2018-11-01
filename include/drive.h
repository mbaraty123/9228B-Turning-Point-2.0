/**
 * @brief Basic drive definitions and functions
 * @file drive.h
 **/
 #ifndef _DRIVE_H_
 #define _DRIVE_H_

 /**
  * @brief defines the directions in which a set of motors can be moving
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
 * @brief defines the minimum reading from the joysticks to avoid underpowering the motors
 * @author Michael Baraty
 * @date 10/25/2018
**/
#define THRESHOLD 10

/**
 * @brief sets the spped of the motors according to a joystick taking into account the threshold
 * @param channel
 * @param speed
 * @author Michael Baraty
 * @date 10/25/2018
 */
void motorSpeedStick(unsigned char channel, int speed);

/**
 * @brief sets the speed for the robot to drive forward for a given amount of time(s)
 * @param speed
 * @param time
 * @author Michael Baraty
 * @date 10/26/2018
 */
void robotDriveForward(int speed, double time);

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

void robotSpin(Direction dir);

#endif
