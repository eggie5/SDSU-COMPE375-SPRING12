#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#define SL 16 //sequence length


//word is unsigned int
void delay(word d);
byte getkey ();
void block_LEDS (byte scan_code);

word delayTime=2000/SL; //125 ms



byte getkey () {
    int i;
    byte scan_code = 0xff; //off code
    PTP = 0x0E ;            //0111
    for (i = 0; i<4; i++) {

        if (PTT_PTT0 == 0) {
            scan_code = i*4+0;
            break;
        }
        else if (PTT_PTT1 == 0) {
            scan_code = i*4+1;
            break;
        }
        else if (PTT_PTT2 == 0) {
            scan_code = i*4+2;
            break;
        }
        else if (PTT_PTT3 == 0) {
            scan_code = i*4+3;

            break;
        }
        PTP = PTP<<1;          //shift PTP to check the next row PTP *2
        PTP = PTP+1;            //add1 1 to PTP
    }

    return scan_code;
}

void block_LEDS (byte scan_code) {
    PORTA = scan_code;
    while (getkey()==scan_code) {  //block LEDs until key release
    };
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

void readButtons()
{
    word delta=500/SL; //32.12 ms

    if(PTM_PTM4 == 0)
    {
        delay(10);
        while(PTM_PTM4==0) 	{
            ;
        }
        delay(10);

        if(delayTime>=delta)
            delayTime-=delta;
        else
            delayTime=0;
    }
    else if(PTM_PTM5==0)
    {
        delay(10);
        while (PTM_PTM5==0)
        {
            ;
        }
        delay(10);

        delayTime+=delta;

    }
}

void main(void) {

    byte patterns[]= {0x00,0x01,0x03,0x07,0x0F,0x1F,0x3F,0x7F,0xFF,0x7F,0x1F,0x0F,0x07,0x03,0x01,0x00};
    int i;
    byte scan_code;
    DDRA = 0xFF;
    PERT = 0x0F; //pull up resistor?
    PORTA = 0xff;
    DDRP = 0x0f; //pull up resistor?




    //use the folowing to calibrate the delay functions
    //PORTA=0xFF;
    //delay2(10000);
    //PORTA=0x00;

    while(1)
    {
        for(i=0; i<SL; i++)
        {
            PORTA=patterns[i];
            delay(delayTime);

            readButtons();


            scan_code = getkey ();
            if (scan_code != 0xff) //if keyboard press
                block_LEDS(scan_code);

        }//end for
    }//end while



    EnableInterrupts;


    for(;;) {
        _FEED_COP(); /* feeds the dog */
    } /* loop forever */
    /* please make sure that you never leave main */
}


