/* RealTime Clock.
 * Global variable ms_count is incremented every millisecond by Timer
 * channel 5 Interrupt Service Routine.
 * Loop in main displays ms_count<15:12> on the module LEDs
 * and ms_count<11:4> project board LEDs.
 * Note that when a word is assigned to a byte variable, the low 8 bits
 * of the word are assigned to the byte.
 */

#include <hidef.h>      /* common defines and macros */
#include <MC9S12C128.h>     /* derivative information */


void initializePorts(void);
int notes[16]= {60,62,64,65,67,69,71,0,72,74,76,77,79,81,83,84}; //key to note lookup table
volatile word ms_count = 0;
int i=0;
word last_time=0;
volatile word delay=0x0080;


void readButtons()
{
    word delay_increment=0x10;

    if(PTM_PTM4 == 0) //up
    {

        while(PTM_PTM4==0) 	{
            ;
        }

        if(delay_increment<= delay)
        {
            delay-=delay_increment;
        }
        else
        {

            delay=0;
        }


    }
    else if(PTM_PTM5==0)//down
    {
        while (PTM_PTM5==0) 	{
            ;
        }
        delay+=delay_increment;

    }
}

void main(void) {
    initializePorts();
    EnableInterrupts;  // Equivalent to  asm CLI

    for(;;) {

        handle_hex_keypad(); //check if buttons pressed

    }
}



void leds()
{
    word delta_from_last_update=ms_count-last_time;

    if(delta_from_last_update>=delay)
    {

        PORTA=patterns[i];
        i++;
        last_time=ms_count;
    }

    if(i>13)
    {

        i=0;
    }


}
/////////////////// Timer5 Interrupt Service Routine  /////////////
void interrupt 13 ISR_Timer5(void) {
    ms_count++;


    leds();


    TC5 += 1000;   // Interrupt again in 1 ms
    TFLG1 = 0x20;  // Clear Timer5 Flag;  will not interrupt
    // again if flag is not cleared.
}

//TODO: Need to merge these settings with piano (lab 10) code
void initializePorts() {
    DDRA = 0xFF;  	// PTA<7:0> - outputs	 (LEDs)
    DDRB = 0xF0;   // Make PTB<7:4> outputs
    TIOS = 0x20;    // Make IOC5 an output.  It is NECCESSARY to make
    // a timer bit an output (not of the chip, but of the
    // internal Timer Block) in order to have it generate
    // an interrupt request.
    TSCR1 = 0x80;   // Set TEN = 1 (Enable timer)
    TIE = 0x20;     // Turn on Timer5 interrupt; disable others
    TSCR2 = 0x01;   // Set Timer prescaler bits PR<2:0> to 001
    // and disable Timer Overflow interrupt.
    // Timer counter clock = BusClock / 2 = 1MHz
}

void play(int note, byte scan_code) //really want to remove this scan_code arg -- ugly!
{
    int tc;
    int f;
    float noteRaised = 1.05946;  //Midi note raised to the 12th root (2^(1/12)

    f = 27.5 * pow(noteRaised, (note - 21) );
    tc = 1000000 / (2 * f);

    TSCR1 = 0x80; //1000 0000 -> enable timer according to docs

    while (keypad_get_scancode()==scan_code) {  //while the button is pressed
        if (TFLG1_C7F == 1) // if PT7 has toggled:
        {
            TC7 += tc;
            // set next half-period count
            TFLG1 = 0x80; // clear channel 7 compare flag
        }
        if (TFLG1_C6F == 1)
        {
            TC6 += tc;
            TFLG1 = 0x40;
        }
    }; //end while

    TSCR1 = 0x00; //disable main timer according to docs
}

void keypad_button_pressed(byte scan_code)
{
    //put functions you want to execute when a button is pressed here:
    play(notes[scan_code], scan_code);
    //leds(notes[scan_code]);
}

void handle_keypad()
{
    byte scan_code;
    scan_code = keypad_get_scancode();

    if (scan_code != 0xff) //if keypad is pressed, publish event
        keypad_button_pressed(scan_code); //press event
}

//hex keypad routine
byte keypad_get_scancode () {
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