//Alex Egg Lab 13

#include <hidef.h>      /* common defines and macros */
#include <MC9S12C128.h>     /* derivative information */
#include <math.h>

byte LED_PATTERNS[]= {0x00,0x01,0x03,0x07,0x0F,0x1F,0x3F,0x7F,0xFF,0x7F,0x1F,0x0F,0x07,0x03,0x01,0x00};
int LED_INDEX=0;
word LEDS_LAST_TIME=0;

int NOTES[16]= {60,62,64,65,67,69,71,0,72,74,76,77,79,81,83,84}; //key to note lookup table

volatile word MS_COUNT = 0;

volatile word LED_PATTERN_DELAY=0x0080;
int CURRENT_MODE;

typedef struct {
    byte number; // MIDI note number
    word startTime;
    word stopTime; //unsigned char
} NOTE;

NOTE RB[100];
int iRB = 0;

NOTE Song1[] =  // Two octaves of major scale, 5 notes per second
{
    { 60, 200, 350 },
    { 62, 400, 550 },
    { 64, 600, 750 },
    { 65, 800, 950 },
    { 67, 1000, 1150 },
    { 69, 1200, 1350 },
    { 71, 1400, 1550 },
    { 72, 1600, 1750 },
    { 74, 1800, 1950 },
    { 76, 2000, 2150 },
    { 77, 2200, 2350 },
    { 79, 2400, 2550 },
    { 81, 2600, 2750 },
    { 83, 2800, 2950 },
    { 84, 3000, 3150 },
    { 0, 0, 0 }
};

NOTE Song2[] =
{
    {67, 50, 200},
    {69, 250, 400},
    {71, 450, 600},
    {74, 650, 800},
    {72, 850, 1000},
    {72, 1050, 1200},
    {76, 1250, 1400},
    {74, 1450, 1600},
    {74, 1650, 1800},
    {79, 1850, 2000},
    {76, 2050, 2200},
    {79, 2250, 2400},
    {74, 2450, 2600},
    {71, 2650, 2800},
    {67, 2850, 3000},
    {69, 3050, 3200},
    {71, 3250, 3400},
    {72, 3450, 3600},
    {74, 3650, 3800},
    {76, 3850, 4000},
    {74, 4050, 4200},
    {72, 4250, 4400},
    {71, 4450, 4600},
    {69, 4650, 4800},
    {71, 4850, 5000},
    {67, 5050, 5200},
    {64, 5250, 5400},
    {67, 5450, 5600},
    {69, 5650, 5800},
    {62, 5850, 6000},
    {64, 6050, 6200},
    {69, 6250, 6400},
    {72, 6450, 6600},
    {71, 6650, 6800},
    {69, 6850, 7000},
    {71, 7050, 7200},
    {0, 0, 0}
};



enum modes {
    PLAY    = 0,
    RECORD = 1,
    PLAYBACK   = 2,
    SONG1 = 4,
    SONG2 = 5,
    CONTROL   = 7
};

enum KEYS
{
    KEYB=7,
    NOKEY=0xFF
};



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
    byte scan_code=NOKEY;
    word lt=0;
    int i=0;

    PORTA=0x00;

    while(scan_code==NOKEY || scan_code==KEYB) //no press
    {

        word delta_from_last_update=MS_COUNT-lt;
        if(delta_from_last_update>=200)
        {

            PORTA=~PORTA;
            i++;
            lt=MS_COUNT;
        }

        scan_code = get_keypad_scancode();
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


    TCTL1_OL7=1;
    while ((current_note_time=MS_COUNT-start_time)<=duration) {  //keep playing!

        if (TFLG1_C7F == 1) // if PT7 has toggled:
        {
            TC7 += tc;
            TFLG1_C7F = 1; // clear channel 7 compare flag
        }
    }; //end while
    TCTL1_OL7=0;

}


//FIX: This needs to play w/ inturrupts
//becuase it blocks the thread until finished
void playback(NOTE notes[], int len)
{
    int i;
    word note_duration, start_time, elapsed_time, wait_time=0;

    for(i=0; i<len; i++)
    {
        start_time=MS_COUNT;

        note_duration=notes[i].stopTime - notes[i].startTime;
        play_with_duration(notes[i].number, note_duration);

        //sleep between notes
        if(i<len-1)
        {
            wait_time=notes[i+1].startTime - notes[i].stopTime;
            wait_time+=100; //HACK: cause playback seems a little fast

            // sleep
            elapsed_time=0;//ms
            while(elapsed_time<=wait_time)
            {
                elapsed_time=MS_COUNT-start_time;
            }
        }


    }
}


void play(byte scan_code) //really want to remove this scan_code arg -- ugly!
{
    int note=NOTES[scan_code];

    int tc;
    int f;
    float noteRaised = 1.05946;  //Midi note raised to the 12th root (2^(1/12)

    f = 27.5 * pow(noteRaised, (note - 21) );
    tc = 1000000 / (2 * f);

    TCTL1_OL6=1;
    while (get_keypad_scancode()==scan_code) {  //keep playing!

        if (TFLG1_C6F == 1) // if PT7 has toggled:
        {
            TC6 += tc;
            TFLG1_C6F = 1; // clear channel 7 compare flag
        }
    }; //end while
    TCTL1_OL6=0;
}

void record(char scan_code)
{
    int note=NOTES[(int)scan_code];
    unsigned start_time;
    unsigned end_time;
    NOTE n;

    start_time=MS_COUNT;
    play(scan_code); //blocks
    end_time=MS_COUNT;

    n.number=note;
    n.startTime=start_time;
    n.stopTime=end_time;
    RB[iRB++]=n;

}

void handle_buttons()
{
    word delay_increment=0x10;

    if(PTM_PTM4 == 0) //up
    {

        while(PTM_PTM4==0) 	{
            ;
        }

        if(delay_increment<= LED_PATTERN_DELAY)
        {
            LED_PATTERN_DELAY-=delay_increment;
        }
        else
        {

            LED_PATTERN_DELAY=0;
        }


    }
    else if(PTM_PTM5==0)//down
    {
        while (PTM_PTM5==0) 	{
            ;
        }
        LED_PATTERN_DELAY+=delay_increment;

    }
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
        playback(RB, iRB); //this will block the thread till playback is done
        set_state(PLAY);
        break;
    case SONG1:
        playback(Song1, 15);
        set_state(PLAY);
        break;
    case SONG2:
        playback(Song2, 36);
        set_state(PLAY);
        break;
    }

    //else do nothing
}



void handle_keypad()
{
    byte scan_code;
    scan_code = get_keypad_scancode();

    if (scan_code != NOKEY) //if keypad is pressed, publish event
        keypad_button_pressed(scan_code); //press event
}

void initializePorts() {
    DDRA = 0xFF;  	// PTA<7:0> - outputs	 (LEDs)
    DDRB = 0xF0;   // Make PTB<7:4> outputs
    TSCR1 = 0x80;   // Set TEN = 1 (Enable timer to count up)
    //The period that the timer counts depends on the value you write in the TSCR2 register at address $4D.
    TSCR2 = 0x01;   // Set Timer prescaler bits PR<2:0> to 001
    //TIOS = 0x20 0010 0000 for timer lab 11
    //TIOS = 0xC0 1100 0000 for piano lab 10
    TIOS = 0xF0; // Make IOC5 an output.  It is NECCESSARY to make
    // a timer bit an output (not of the chip, but of the
    // internal Timer Block) in order to have it generate
    // an interrupt request.


    TIE = 0x20;     // Turn on Timer5 interrupt; disable others




    //hexkeypad
    DDRP = 0x0F;               //Set output key - for hex keypad

    PERT = 0x0F; //pull up resistor or speaker freaks out


    // DDRT = 0x00;               //Set input key
    //PPST = 0xF0;
    //PTP = 0xFE;
    //PTT = 0x0F;
}



void leds()
{
    word delta_from_last_update=MS_COUNT-LEDS_LAST_TIME;
    if(CURRENT_MODE==CONTROL) return;

    if(delta_from_last_update>=LED_PATTERN_DELAY)
    {

        PORTA=LED_PATTERNS[LED_INDEX];
        LED_INDEX++;
        LEDS_LAST_TIME=MS_COUNT;
    }

    if(LED_INDEX>13)
    {

        LED_INDEX=0;
    }


}

/////////////////// Timer5 Interrupt Service Routine  /////////////
void interrupt 13 ISR_Timer5(void) {
    MS_COUNT++;

    leds();

    PORTB=~PORTB;

    TC5 += 1000;   // Interrupt again in 1 ms
    TFLG1 = 0x20;  // Clear Timer5 Flag;  will not interrupt
    // again if flag is not cleared.
}





void main(void) {
    initializePorts();
    EnableInterrupts;  // Equivalent to  asm CLI

    //start in PLAY state
    set_state(PLAY);

    for(;;) {

        handle_buttons();
        handle_keypad(); //check if buttons pressed

    }
}



