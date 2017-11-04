/*
 * File:   motor_control.c
 * Author: Shubham
 *
 * Created on September 3, 2017, 7:08 PM
 */
#define _XTAL_FREQ 8000000

#include <xc.h>

// BEGIN CONFIG
#pragma config FOSC = HS
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config BOREN = ON 
#pragma config LVP = OFF
#pragma config CPD = OFF
#pragma config WRT = OFF 
#pragma config CP = OFF
//END CONFIG

void servoRotate0() //0 Degree
{
  unsigned int i;
  for(i=0;i<50;i++)
  {
    RB0 = 1;
    __delay_us(800);
    RB0 = 0;
    __delay_us(19200);
  }
}

void servoRotate90() //90 Degree
{
  unsigned int i;
  for(i=0;i<50;i++)
  {
    RB0 = 1;
    __delay_us(1500);
    RB0 = 0;
    __delay_us(18500);
  }
}

void servoRotate180() //180 Degree
{
  unsigned int i;
  for(i=0;i<50;i++)
  {
    RB0 = 1;
    __delay_us(2200);
    RB0 = 0;
    __delay_us(17800);
  }
}

void main()
{
  TRISB = 0; // PORTB as Ouput Port
  do
  {
    servoRotate0(); //0 Degree
    __delay_ms(2000);
    servoRotate90(); //90 Degree
    __delay_ms(2000);
    servoRotate180(); //180 Degree
  }while(1);
}

