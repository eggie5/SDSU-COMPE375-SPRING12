#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */
#include <MC9S12C128.h> /* derivative information */
#include <math.h>
#include <stdio.h>
#include <termio.h>
#include <stdlib.h>

typedef struct {
    byte array_X;
    dword t_Start;
    dword t_Stop;
} NOTE;

enum KEYS { KEY1, KEY2, KEY3, KEYA,
            KEY4, KEY5, KEY6, KEYB,
            KEY7, KEY8, KEY9, KEYC,
            KEY_ASTERISK, KEY0, KEY_POUND, KEYD
          };

#define FIFO_SIZE 200
byte fifo[FIFO_SIZE];
word i_in = 1, i_out = 0;	// FIFO in and out index variables
byte lineBuffer[40];   // buffer to hold one print line

//////////////// Functions Prototype /////////////////////////////////

void PLAY(void);
void RECORD(void);
void PLAYback(void);
void reset_theArrays(void);
void PLAY_TRACK_1(void);
void PLAY_TRACK_2(void);
byte KEY(void);
byte getarray_X(void);
byte DIGIT(byte);
byte disPLAY_LEDS(byte);
void setback(word d);
void initialPorts(void);
void initialData(byte);
void DisPLAYBlinks(void);
void DisPLAYPatterns(void);
void setNote(void);
byte fifoIn(byte data);
byte fifoOut(void);
byte lineToFifo();

////////////////////////// Songs /////////////////////////////////////

NOTE Song1[] = {
    {60, 110, 200},
    {62, 210, 300},
    {64, 310, 400},
    {65, 410, 500},
    {67, 510, 600},
    {69, 610, 700},
    {71, 710, 800},
    {72, 810, 900},
    {74, 910, 1000},
    {76, 1010, 1100},
    {77, 1110, 1200},
    {79, 1210, 1300},
    {81, 1310, 1400},
    {83, 1410, 1500},
    {84, 1510, 1600},
    {0, 0, 0}
};


NOTE Song2[] = {
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
    {78, 2050, 2200},
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
    {66, 5250, 5400},
    {67, 5450, 5600},
    {69, 5650, 5800},
    {62, 5850, 6000},
    {66, 6050, 6200},
    {69, 6250, 6400},
    {72, 6450, 6600},
    {71, 6650, 6800},
    {69, 6850, 7000},
    {71, 7050, 7200},
    {0, 0, 0}
};


///////////////////// Global Variables //////////////////////////////////////////

byte arr_of_notes[16];

float t_Const[129];

int forever = 1;
int index_ptr = 0;

word ch6_t_Const;
word ch7_t_Const;
dword gap_for_timing = 0;
dword timing_reference = 0;
dword count_ms = 0;
dword clk0 = 0;
word pattern_Setback = 100;

int p_val_A = 100;
int p_val_B = 100;

NOTE rec_notes_arr[100];
byte signal_Key = 0xFF;

int LEDS = 0;
int ledsKeys = 0;
int Push4 = 0;
int Push5 = 0;

////////////////////////////////////////////////////////////////////////////////



void setNote(void) {
    byte startNote;
    //array_Xs correspond to a tone frequency
    startNote = getarray_X();
    if (startNote >= 21 && startNote <= 84)
        //initializes our data with the start note
        initialData(startNote);
    return;   // Returns to the comtrol mode
}


void setback(word d)
{
    int constant = 1000;
    int i;
    while (d > 0) {
        i = constant;
        while (i > 0)
        {
            i--;
        }
        d--;
    }
}

//if 0 to 9 was typed, return it as a byte
byte DIGIT(byte key) {
    if( key == KEY0 )
        return 0;
    else if( key == KEY1 )
        return 1;
    else if( key == KEY2 )
        return 2;
    else if( key == KEY3 )
        return 3;
    else if( key == KEY4 )
        return 4;
    else if( key == KEY5 )
        return 5;
    else if( key == KEY6 )
        return 6;
    else if( key == KEY7 )
        return 7;
    else if( key == KEY8 )
        return 8;
    else if( key == KEY9 )
        return 9;
    else
        return 0xFF;
}

//records a series of songs
void RECORD(void) {
    byte key;
    NOTE note;
    byte RECORD_on = FALSE;
    int nextNote = 0;  // pointer for rec_notes_arr
    TIE = 0xF8;     //1111 1000 - timer 5 and 6 interrupts only
    TIOS = 0xF8;    // output compare mode
    clk0 = 0;	  //clock starts at 0

    while(forever) {
        key = KEY();

        if (key == KEYB) {
            setback(5);
            while (KEY() != 0xFF)
                ;
            setback(5);
            TCTL1 = 0x00;
            TIE = 0x38;
            signal_Key = KEYB;
            return;
        }

        //if we recording keystrokes..
        if (RECORD_on) {
            //and key == 0xFF, then terminates recording
            if (key == 0xFF) {
                TCTL1 = 0x00;
                //stop recording timing
                note.t_Stop = clk0;
                rec_notes_arr[nextNote] = note;
                nextNote++;
                RECORD_on = FALSE;
            }

        }
        //if we are not recording then
        else {
            //turn on recording
            if ( key != 0xFF) {
                ch6_t_Const = (int)t_Const[arr_of_notes[key]];
                //enable ch6 sound
                TCTL1 = 0x10;
                //start timing for recording
                note.t_Start = clk0;
                note.array_X = arr_of_notes[key];
                RECORD_on = TRUE;
            }
        }
    }
}
/* display_LEDS

  The following 3 functions handle the LED's and their functionality.
*/
byte disPLAY_LEDS(byte mode) {
    byte key = 0xFF;
    while(1)
    {
        setback(30);
        //if mode == 0 then PORTA == 0xFF else, 0x00
        PORTA = mode==0 ? 0xFF : 0x00 ;
        setback(30);
        PORTA = 0x00;
        key = KEY();
        if ( key != 0xFF) {
            setback(5);
            while (KEY() != 0xFF)
                ;
            setback(5);
            return key;
        }
    }
}

//simply turn the LED's off and then back on.
void DisPLAYBlinks(void) {
    while(forever) {
        PORTA = 0xFF;
        setback(200);
        PORTA = 0x00;
        setback(200);
        if (KEY() != 0xFF) {
            setback(5);
        }
    }
}

//pattern of disPLAY for the LED's
void DisPLAYPatterns() {
    int i;
    while(forever) {
        //if port value B is between 0 and 8 then
        if ((p_val_B >= 0) || (p_val_B <= 8)) {
            PORTA = count_ms >> p_val_A;
        }
        //blink the disPLAYs
        if (KEY() == 7) {
            setback(5);
            DisPLAYBlinks();
        }
        if (p_val_B > 8) {
            pattern_Setback = p_val_A;
            PORTA = 0x00;
            index_ptr = 0;
            while(index_ptr < 8) {
                PORTA = ((PORTA <<= 1) + 1);
                setback(pattern_Setback);
                if (KEY() == 7) {
                    setback(5);
                    DisPLAYBlinks();
                }
                index_ptr++;
            }
            index_ptr = 0;
            while(index_ptr < 8) {
                PORTA = (PORTA >>= 1);
                setback(pattern_Setback);
                if (KEY() == 7) {
                    setback(5);
                    DisPLAYBlinks();
                }
                index_ptr++;
            }
        }
    }
}

void  initialPorts() {
    /////////////////// Keypad ///////////////////////
    DDRT = 0x00; // PT<7:0> - inputs - keypad columns
    DDRP = 0x0F;  // PP<3:0> - outputs - keypad rows
    // The following two lines provide internal pull-up
    // resistors on lines PT<3:0>.
    PERT = 0x0F;	// Enables Registers
    PPST = 0x00;		// Sets Pull UP's

    /////////////////////////// LEDs ////////////////////////
    DDRA = 0xFF;  // // Sets Leds To Outputs
    ////////////////////// Timer ////////////////////////////
    TIE = 0x38;     // Turn off Timer interrupts 00011 1000
    //   Turn on when needed during execution
    TSCR1 = 0x80;   // Sets Timer Clock Freq To Normal
    TSCR2 = 0x01;   // Sets Bus Clock
    TIOS = 0xF8;    // Sets The Timer To Output
    // Input-Capture).
    TCTL1 = 0x00;   // Enables Speakers

    TCTL2 = 0x00;   // Disconnect IOC<3:0> from PT<3:0>
    // Do not change this register during execution.
    /////////////////////////////////////////////////////
    
      SCIBD = 52;     // 2400 baud if SCI clock is 2 MHz
    SCICR2 = 0x0C;   // Enable receiver and transmitter
}

void PLAY(void) {
    byte key;
    TIE = 0xF8;     // Turn on Timer 6 interrupt; disable others

    while(forever) {
        key = KEY();

        if (key == KEYB) {
            setback(5);
            while (KEY() != 0xFF)
                ;
            setback(5);
            signal_Key = KEYB;
			
            TCTL1 = 0x00;   // Stop sound
            return;
        }

        if (key == 0xFF) {
            TCTL1 = 0x00;   // Stop sound
        }
        else {
			printf("Note %d start: %d\r\n",arr_of_notes[key], clk0);
            // Get here only if a note key is pressed
            ch6_t_Const = (int)t_Const[arr_of_notes[key]];  // Exact frequency for selected note
            TCTL1 = 0x10;   // Start sound	 (OM6:OL6 = 01)

            //push to FIFO queue

        }
    }
}

void reset_theArrays(void) {
    int i;
    for (i=0; i<100; i++)
    {
        rec_notes_arr[i].array_X = 0;
        rec_notes_arr[i].t_Start = 0;
        rec_notes_arr[i].t_Stop = 0;
    }
}

void PLAYback(void) {
    byte key;
    NOTE note;
    byte RECORD_on = FALSE;
    int nextNote = 0;

    TIE = 0xF8;     // Turn on Timer5,6 and 7 interrupts; disable others
    TCTL1 = 0x00;   // Stop sound on channels 4 - 7
    clk0 = 0;

    while(1) {
        ///////////////// Check keypad ///////////////////////////////
        key = KEY();
        if (key == KEYB) {
            setback(5);
            while (KEY() != 0xFF)
                ;
            setback(5);
            TCTL1 = 0x00;   // Stop sound on all channels
            TIE = 0x00;     // Disable Timer interrupts
            return;
        }

        if (key == 0xFF) {
            TCTL1_OL6 = 0;   // Stop sound  on channel 6 (OM6:OL6 = 00)
        }
        else {   // Get here only if key other than B is pressed
            ch6_t_Const = (int)t_Const[arr_of_notes[key]];  // Get timer constant
            TCTL1_OL6 = 1;   // Start sound  on channel 6	 (OM6:OL6 = 01)
        }

        //////////////////// check RECORD Buffer ////////////////////
        note = rec_notes_arr[nextNote];
        if (note.array_X == 0) {
            continue; // No song in buffer
        }

        if (!RECORD_on && (clk0 > note.t_Start) ) {
            ch7_t_Const = (int)t_Const[note.array_X];  // Get timer constant
			printf("\t\t\tNote %d start:--\r\n", note.array_X);
            TCTL1_OL7 = 1;   // Start sound  on channel 7 (OM7:OL7 = 01)
            RECORD_on = TRUE;
            continue;
        }
        else if(RECORD_on && (clk0 > note.t_Stop) ) {
            TCTL1_OL7 = 0;  // stop sound on channel 7 (OM7:OL7 = 00)
            RECORD_on = FALSE;
            nextNote++;
            note = rec_notes_arr[nextNote];
            if (note.array_X == 0) {
                nextNote = 0;	 // Start song over
                clk0 = 0;
            }
        }
    }
}



void initialData(byte startNote) {
    static double twoRoot12 = 1.05946309;
    int i;

    arr_of_notes[0] = startNote;
    arr_of_notes[1] = arr_of_notes[0] + 2;
    arr_of_notes[2] = arr_of_notes[1] + 2;
    arr_of_notes[3] = arr_of_notes[2] + 1;
    arr_of_notes[4] = arr_of_notes[3] + 2;
    arr_of_notes[5] = arr_of_notes[4] + 2;
    arr_of_notes[6] = arr_of_notes[5] + 2;
    arr_of_notes[7] = 0xFF;
    arr_of_notes[8] = arr_of_notes[6] + 1;
    arr_of_notes[9] = arr_of_notes[8] + 2;
    arr_of_notes[10] = arr_of_notes[9] + 2;
    arr_of_notes[11] = arr_of_notes[10] + 1;
    arr_of_notes[12] = arr_of_notes[11] + 2;
    arr_of_notes[13] = arr_of_notes[12] + 2;
    arr_of_notes[14] = arr_of_notes[13] + 2;
    arr_of_notes[15] = arr_of_notes[14] + 1;

    t_Const[21] = 500000.0 / 27.5;
    for (i=22; i<129; i++) {
        t_Const[i] = t_Const[i-1] / twoRoot12;
    }
}

byte getarray_X(void) {
    byte key, num = 0, digit;
    key = disPLAY_LEDS(1);
    digit = DIGIT(key);
    if (digit == 0xFF)
        return num; //return 0
    else
        num = digit; // first digit

    while(1) {
        PORTA = num;
        while ( (key = KEY()) == 0xFF) {
            ;
        }
        setback(5);
        while (KEY() != 0xFF)
            ;
        setback(5);

        digit = DIGIT(key);
        if (digit == 0xFF) {
            return num;
        }
        else
            num = num*10 + digit;
    }
}

void interrupt 11 ISR_Timer3(void) {
    if(p_val_A > 8) {
        if(count_ms >= p_val_A) {
            // count_ms is time lag bw the 2 leds
            if(LEDS == 0)           // LEDS OFF
                ledsKeys = 0;
            if (LEDS == 0xFF)       // LEDS ON
                ledsKeys = 1;
            if (ledsKeys == 0) {
                LEDS <<= 1;
                LEDS += 1;
            }
            if (ledsKeys == 1) {
                LEDS >>= 1;
            }
            count_ms = 0;
            PORTA = LEDS;
        }
    }
    else {
        PORTA = count_ms >> p_val_A;
    }
    TC3 += 1000;
    TFLG1 = 0x08;
}

void interrupt 12 ISR_Timer4(void) {
    if(PTM_PTM4 == 0 && Push4 == 0) { //increase the speed if push button7 pressed
        p_val_A -= 10;
        Push4 = 1;
    }
    if(PTM_PTM5 == 0 && Push5 == 0) {   //Decrease the speed if push button8 pressed
        p_val_A += 10;
        Push5 = 1;
    }
    if(p_val_A <= 0)         // Lower limit is .1 sec
        p_val_A = 10;
    if(PTM_PTM4 == 1)
        Push4 = 0;
    if(PTM_PTM5 == 1)
        Push5 = 0;
    TC4 += 1000;   // Interrupts in 1 ms
    TFLG1 = 0x10;  // Clear Timer5 Flag;  will not interrupt
    // again if flag is not cleared.
}




void interrupt 13 ISR_Timer5(void) {

    //call hyperterminal here
    //this blocks
    //move out to new interrupt later
  //  print_to_screen_from_queue();

    // Timer5 Interrupts Service Routine
    count_ms++;
    clk0++;
    TC5 += 1000;   // Interrupts in 1 ms
    TFLG1 = 0x20;   // Clear Timer5 Flag;  will not interrupt

}


void interrupt 14 ISR_Timer6(void) {
    // Timer5 Interrupt Service Routine
    TC6 += ch6_t_Const;   // Interrupts time to toggle
    TFLG1 = 0x40;   // Clear Timer6 Flag;

}


void interrupt 15 ISR_Timer7(void) {
    // Timer5 Interrupt Service Routine
    TC7 += ch7_t_Const;   // Interrupt again at time to toggle
    TFLG1 = 0x80;   // Clear Timer7 Flag;  will not interrupt

}



byte KEY() {
    static byte scanKeys[] = {
        0x0E, 0x0D, 0x0B, 0x07
    };
    byte i, j;
    byte row;
    for (i=0; i<4; i++) {
        PTP = scanKeys[i]; // Sets scan row to 0 and others to 1
        setback(1);
        if (PTT_PTT0 == 0)
            return 4*i;
        if (PTT_PTT1 == 0)
            return 4*i + 1;
        if (PTT_PTT2 == 0)
            return 4*i + 2;
        if (PTT_PTT3 == 0)
            return 4*i + 3;
    }
    return 0xFF;
}


void PLAY_TRACK_1(void) {
    byte key;
    NOTE note;
    int i = 0;
    while(1)
    {
        TIE = 0xE0;
        TCTL1 = 0x00;   // Stops sound on channels 4 thru 7
        count_ms = 0;
        if((key = KEY()) == KEYB)
        {
            setback(5);
            while (KEY() != 0xFF)
                ;
            setback(5);

            TCTL1 = 0x00;
            TIE = 0x00;     // Disable Timer interrupts
            return;
        }
        else
        {
            for(i = 0; i < 100; i++)
            {
                rec_notes_arr[i].array_X = Song1[i].array_X;
                rec_notes_arr[i].t_Start = Song1[i].t_Start;
                rec_notes_arr[i].t_Stop = Song1[i].t_Stop;
            }
        }
    }
}


void PLAY_TRACK_2(void) {
    byte key;
    NOTE note;
    int i = 0;
    while(1)
    {
        TIE = 0xE0;     // Turn on Timer5,6 and 7 interrupts
        TCTL1 = 0x00;
        count_ms = 0;

        if((key = KEY()) == KEYB)
        {
            setback(5);
            while (KEY() != 0xFF)
                ;
            setback(5);

            TCTL1 = 0x00;   // Stop sound
            TIE = 0x00;     // Disable Timer interrupts
            return;
        }
        else
        {
            for(i = 0; i < 100; i++)
            {
                rec_notes_arr[i].array_X = Song2[i].array_X;
                rec_notes_arr[i].t_Start = Song2[i].t_Start;
                rec_notes_arr[i].t_Stop = Song2[i].t_Stop;
            }
        }
    }
}




void main(void) {

    byte key;
    initialPorts();
    initialData(60);
    EnableInterrupts;
    TSCR1_TEN = 1;       // Starts timer
    TCTL1 = 0x00;        // Disconnect timers
    
    printf("\r\n\r\nWelcome final lab!!!   \r\n");


    while (forever) {
        TIE   = 0x00;        // Disable Timer interrupts
        key = KEY();
        setback(30);
        PORTA = 0xFF;
        setback(30);
        PORTA = 0x00;
        if (key == KEY1) {
            PORTA = 0x01;
            setback(100);
            PLAY();
        }
        else if(key == KEY2) {
            PORTA = 0x03;
            setback(100);
            reset_theArrays();
            RECORD();
        }
        else if(key == KEY3) {
            PORTA = 0x07;
            setback(100);
            PLAYback();
        }
        // else if(key == KEY4) {
        //            PORTA = 0xFF;
        //            setback(100);
        //            setNote();
        //        }
        else if(key == KEY4) {
            PORTA = 0x0F;
            setback(100);
            PLAY_TRACK_1();
        }
        else if(key == KEY5) {
            PORTA = 0x1F;
            setback(100);
            PLAY_TRACK_2();
        }

    }
}
