//Alex Egg Lab 12

#include <hidef.h>      /* common defines and macros */
#include <MC9S12C128.h>     /* derivative information */
#include <math.h>


void initializePorts(void);
int notes[16]= {60,62,64,65,67,69,71,0,72,74,76,77,79,81,83,84}; //key to note lookup table
volatile word MS_COUNT = 0;
int i=0;
word last_time=0;
volatile word delay=0x0080;

typedef struct {
    byte number; // MIDI note number
    word startTime;
    word stopTime; //unsigned char
} NOTE;

NOTE RB[100];
int iRB = 0;

// Record buffer (space for 100 notes)
// Next note index


enum modes {
    PLAY    = 0,
    RECORD = 1,
    PLAYBACK   = 2,
    CONTROL   = 7
};

int CURRENT_MODE;

//hex keypad routine
byte get_keypad_scancode () {
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

byte wait_for_keypad_scancode()
{
    byte scan_code=0xff;

    while((scan_code=get_keypad_scancode())==0xff) //no press
    {
        //TODO: should blink
        PORTA= MS_COUNT; //hack to show led activity while waiting...
    }

    //at this point a button press has been captured
    return scan_code;

}

void set_state(int state)
{
    CURRENT_MODE=state;

    switch (state)
    {
    case PLAY:
        PORTA=0x11;
        break;
    case RECORD:
        //reset array

        PORTA=0x33;
        break;
    case PLAYBACK:
        PORTA=0x77;
        break;
    }
}

void toggle_state()
{
    byte new_mode=wait_for_keypad_scancode();

    set_state((int)new_mode);
}


void play_with_duration(int note, word duration)
{
    int tc;
    int f;
    word current_note_time;
    float noteRaised = 1.05946;  //Midi note raised to the 12th root (2^(1/12)
    word start_time=MS_COUNT;

    f = 27.5 * pow(noteRaised, (note - 21) );
    tc = 1000000 / (2 * f);

    //TSCR1 = 0x80; //1000 0000 -> enable timer according to docs
    TCTL1=0x50;

    while ((current_note_time=MS_COUNT-start_time)<=duration) {  //keep playing!

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

    TCTL1=0x00;
    //TSCR1 = 0x00; //disable main timer according to docs
}

void playback()
{
    int i;
    word duration;
    for(i=0; i<iRB; i++)
    {
        duration=RB[i].stopTime - RB[i].startTime ;
        play_with_duration(RB[i].number, duration);

    }
}




void play(byte scan_code) //really want to remove this scan_code arg -- ugly!
{
    int note=notes[scan_code];
    int tc;
    int f;
    float noteRaised = 1.05946;  //Midi note raised to the 12th root (2^(1/12)

    f = 27.5 * pow(noteRaised, (note - 21) );
    tc = 1000000 / (2 * f);

    //TSCR1 = 0x80; //1000 0000 -> enable timer according to docs

    TCTL1=0x50;

    while (get_keypad_scancode()==scan_code) {  //while the button is pressed

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

    TCTL1=0x00;
    //replace this w/ code that enables/disables the OM/OL bits

    //FIXME: commenting this line out allows piano function to work but there is clicking....
    //this seems to disable all the timers
    //TSCR1 = 0x00; //disable main timer according to docs
}

void record(char scan_code)
{
    int note=notes[(int)scan_code];
    unsigned start_time;
    unsigned end_time;
    NOTE n;

    start_time=MS_COUNT;
    play(scan_code);
    end_time=MS_COUNT+5; // add 5 'cause it seems too fast

    n.number=note;
    n.startTime=start_time;
    n.stopTime=end_time;
    RB[iRB++]=n;


}



void keypad_button_pressed(byte scan_code)
{
    //intercept control press
    if(scan_code==CONTROL)
    {
        CURRENT_MODE=CONTROL;
        toggle_state();
    }

    switch (CURRENT_MODE)
    {
    case PLAY:
        play(scan_code);
        break;
    case RECORD:
        record(scan_code);
        break;
    case PLAYBACK:
        playback(); //this will block the thread till playback is done
        set_state(PLAY);
        break;
    }

    //else do nothing
}



void handle_keypad()
{
    byte scan_code;
    scan_code = get_keypad_scancode();

    if (scan_code != 0xff) //if keypad is pressed, publish event
        keypad_button_pressed(scan_code); //press event
}

void main(void) {
    initializePorts();
    EnableInterrupts;  // Equivalent to  asm CLI

    //start in PLAY state
    set_state(PLAY);

    for(;;) {

        PORTB=MS_COUNT;
        handle_keypad(); //check if buttons pressed

    }
}



/////////////////// Timer5 Interrupt Service Routine  /////////////
void interrupt 13 ISR_Timer5(void) {
    MS_COUNT++;


    TC5 += 1000;   // Interrupt again in 1 ms
    TFLG1 = 0x20;  // Clear Timer5 Flag;  will not interrupt
    // again if flag is not cleared.
}



void initializePorts() {
    DDRA = 0xFF;  	// PTA<7:0> - outputs	 (LEDs)
    DDRB = 0xF0;   // Make PTB<7:4> outputs

    //TIOS = 0x20 0010 0000 for timer lab 11
    //TIOS = 0xC0 1100 0000 for piano lab 10
    TIOS = 0xE0;// 1110 0000 for lab 12
    //TIOS=0xC0;
    //TIOS = 0x20;    // Make IOC5 an output.  It is NECCESSARY to make

    // a timer bit an output (not of the chip, but of the
    // internal Timer Block) in order to have it generate
    // an interrupt request.
    TSCR1 = 0x80;   // Set TEN = 1 (Enable timer)
    TIE = 0x20;     // Turn on Timer5 interrupt; disable others
    TSCR2 = 0x01;   // Set Timer prescaler bits PR<2:0> to 001
    // and disable Timer Overflow interrupt.
    // Timer counter clock = BusClock / 2 = 1MHz


// piano timer settings from lab 10
    //TIOS = 0xC0; //1100 0000 -> enable timer 7 & 6 according to docs
    TSCR2_PR = 0x1;
    TSCR2_TOI = 0x0;
    // TCTL1 =0x50;// 0x50;//0101 0000 timer control register 1 --marino told me just chan 6
    TCTL2 = 0x00;


    DDRT = 0xF0;               //Set input key
    DDRP = 0x0F;               //Set output key
    PPST = 0xF0;
    PERT = 0x0F;

    PTP = 0xFE;
    PTT = 0x0F;
}



