#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include <stdio.h>
#include <termio.h>
#include <stdlib.h>

//float asciiToFloat(byte* line);

#define FreqClockA 2000000 // Value on Reset (PWMPRCLK = 0x00)


//assigns values to the PWM registers
//and returns the actual frequency of the signal generated by those values.
float setPWM(float frequency, float duty_cycle)
{
    float actualFrequency;
    int quotent=(1000000/frequency);
    int s,p;
    int freq;

    for(s=1; s<254; s++)
    {
        for(p=1; p<254; p++)
        {
            if(s*p==quotent)
            {
                printf("s=%d, p=%d\r\n",s,p);
                //actualFrequency = 2000000 / (2 * ((float)PWMPER5 * (float)PWMSCLA));
                actualFrequency = 2000000 / (2 * ((float)p * (float)s));

                freq=1000000/(s*p);
                PWMSCLA = s; //PWMSCLA;
                PWMDTY5 = (duty_cycle*p)/100;
                PWMPER5 =  (PWMDTY5/duty_cycle)*100;//1/freq;///255;//p; //1000000/p;

                return actualFrequency;
            }
        }
    }
}



float asciiToFloat(char line [])
{
    //unsigned num = 0,  digit;

    //unsigned i=0;

    //while(line[i]!=0x00 && line[i]<0x3A)
    //{
    //    digit=line[i]-0x30;
    //    num=num*10+digit;
    //    i++;
    //}


    return atof(line);
}


byte getChar()
{
    char input;
    while( SCISR1_RDRF == 0 ) {};
    input = (char) SCIDRL;
    return input;
}


byte* getLine()
{
    byte line [80];
    char input;
    int i=0;

    while(1)
    {
        input = getChar();
        if(input =='\r' || input =='\n')
            return line;

        line[i]=input;
        i++;
    }
}

void delay(word d)
{
    int constant=350;
    int i;
    while(d>0)
    {
        i = constant;
        while(i>0)
            i--;
        d--;
    }
}

void initializePorts()
{


    ///////////// Serial port ///////////////////////////
    SCIBD = 52;     // 2400 baud if SCI clock is 2 MHz
    SCICR2 = 0x0C;   // Enable receiver and transmitter

    ///////  PWM module ///////////////////////////////////
    PWMCLK_PCLK5 = 1; 	// Select Clock SA for channel 5
    PWMPRCLK = 0x00;   // Set Clock A = BusClock = 2 MHz

    PWMSCLA = 10;    // Set Clock SA = Clock A / (2 * 10)
    PWMPER5 = 200;  // Set period of channel 5; output freq = freq of ClkA / period
    PWMDTY5 = 150;    // Set Duty Cycle of channel 5

    PWMPOL_PPOL5 = 1;  // Make first part of period high; switch to low when
    // count = duty.  This means motor speed will be low for
    // small values of duty and high for large values of duty.
    PWME_PWME5 = 1;    // Enable PWM channel 5 (connect PWM output to PP5)

    ;

}


void main(void)
{


    float actualFrequency;
    float actualDutyCycle;
    float frequency;
    float duty_cycle;
    byte line[80];
    byte * freq_input;
    byte * duty_input;
    int test=1000;





    initializePorts();


    printf("\r\n\r\nDay 19 Demo\r\n");

    actualFrequency = 2000000 / (2 * ((float)PWMPER5 * (float)PWMSCLA));
    sprintf(line, "Actual Frequency = %.2f\r\n", actualFrequency);
    printf(line);
    actualDutyCycle = 100.0 * PWMDTY5 / PWMPER5;
    sprintf(line, "Actual Duty Cycle = %.2f\r\n", actualDutyCycle);
    printf(line);



    while (1)
    {

        printf("\r\nEnter Frequency");
        freq_input=getLine(); //Hz
        frequency=asciiToFloat(freq_input);
        sprintf(line, "=%f\r\n", frequency);
        printf(line);


        printf("Enter Duty Mode");
        duty_input=getLine(); // %
        duty_cycle=asciiToFloat(duty_input);
        printf("=%f\r\n", duty_cycle);

        actualFrequency=setPWM(frequency, duty_cycle);

        printf("PWMPER5=%d\r\n", PWMPER5);
        printf("PWMDTY5=%d\r\n", PWMDTY5);
        printf("PWMSCLA=%d\r\n", PWMSCLA);


        sprintf(line, "Actual Frequency = %.2f\r\n", actualFrequency);
        printf(line);


        actualDutyCycle = (float)((float)PWMDTY5/(float)PWMPER5) * 100;
        sprintf(line, "Actual Duty Cycle = %.2f\r\n", actualDutyCycle);
        printf(line);


    }// End while

}  // End main


