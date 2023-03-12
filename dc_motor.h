#ifndef _DC_MOTOR_H
#define _DC_MOTOR_H

#include <xc.h>

#define _XTAL_FREQ 64000000

struct DC_motor { //definition of DC_motor structure
    char power;         //motor power, out of 100
    char direction;     //motor direction, forward(1), reverse(0)
    char brakemode;		// short or fast decay (brake or coast)
    unsigned int PWMperiod; //base period of PWM cycle
    unsigned char *posDutyHighByte; //PWM duty address for motor +ve side
    unsigned char *negDutyHighByte; //PWM duty address for motor -ve side
};

struct DC_motor motorL, motorR; //declare two DC_motor structures 

int power = 30; // forward backward, turning motor power
int Turn45Delay = 220; //time delay in ms for a 45 degree turn
int RunOneBlockTime = 2000; // time delay to run one block

//function prototypes
void initDCmotorsPWM(unsigned int PWMperiod); // function to setup PWM
void setMotorPWM(struct DC_motor *m);
void stop(struct DC_motor *mL,struct DC_motor *mR);
void turnLeft(struct DC_motor *mL,struct DC_motor *mR);
void turnRight(struct DC_motor *mL,struct DC_motor *mR);
void fullSpeedAhead(struct DC_motor *mL, struct DC_motor *mR);
void timed_forward(struct DC_motor *mL, struct DC_motor *mR, int time);
void fullSpeedBack(struct DC_motor *mL,struct DC_motor *mR);

void turnRight45(struct DC_motor *mL,struct DC_motor *mR);
void turnLeft45(struct DC_motor *mL,struct DC_motor *mR);
void reverseDetect(struct DC_motor *mL,struct DC_motor *mR);
void reverseOneBlock(struct DC_motor *mL,struct DC_motor *mR);
void ForwardOneBlock(struct DC_motor *mL,struct DC_motor *mR);
void RedMove(struct DC_motor *mL,struct DC_motor *mR);
void GreenMove(struct DC_motor *mL,struct DC_motor *mR);
void BlueMove(struct DC_motor *mL,struct DC_motor *mR);
void YellowMove(struct DC_motor *mL,struct DC_motor *mR);
void PinkMove(struct DC_motor *mL,struct DC_motor *mR);
void OrangeMove(struct DC_motor *mL,struct DC_motor *mR);
void LightBlueMove(struct DC_motor *mL,struct DC_motor *mR);
void Forwardhalfblock(struct DC_motor *mL,struct DC_motor *mR);
void RetryMove(struct DC_motor *mL,struct DC_motor *mR);
void ReverseYellow(struct DC_motor *mL,struct DC_motor *mR);
void ReversePink(struct DC_motor *mL,struct DC_motor *mR);

void turnCalibration(struct DC_motor *mL,struct DC_motor *mR);
void TurnDelay(int Turn45Delay);
#endif
