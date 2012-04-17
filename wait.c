#include <stdio.h>
#include <math.h>
char TSCR1;
char TFLG1_C7F;
char TC7;
char TFLG1;

int notes[16]= {60, 62};

void play(char scan_code)
{
    char note;
    int tc;
    int f;
    float noteRaised = 1.05946;  //Midi note raised to the 12th root (2^(1/12)

	note=notes[scan_code];
    f = 27.5 * pow(noteRaised, (note - 21) );
    tc = 1000000 / (2 * f);

	TSCR1 = 0x80; //enable timer

   // while (1) {  //while the button is pressed
        if (TFLG1_C7F == 1) // if PT7 has toggled:
        {
            TC7 += tc;
            // set next half-period count
            TFLG1 = 0x80; // clear channel 7 compare flag
        }
    //}; //end while

	TSCR1 = 0x00; //disable timer?
	
	printf("note = %d\n", note);
	printf("f = %d\n", f);
	printf("tc = %d\n", tc);
}

int main (int argc, char const *argv[])
{

	play(0x002);

	return 0;
}


