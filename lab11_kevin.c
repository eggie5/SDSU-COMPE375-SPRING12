#include <hidef.h>
#include <MC9S12C128.h>
#include <math.h>
#pragma LINK_INFO DERIVATIVE "mc9s12c128"

void delay(word d);
void NotePlay();
void keyPress();
byte dKey(byte scanCode);
byte getKey();
void Config();

byte scanCode;
byte midi = 60;
byte newMidi = 0;
byte S0, S1, S2;
byte keyValue = 0;


int timerConst = 1911;       //Timer constant
byte noteFreq = 27.5;        //Midi note frequncy constant
float noteRaised = 1.05946;  //Midi note raised to the 12th root (2^(1/12)


void main(void)
{
    byte key;                  //Initialize Port values

    DDRA = 0xFF;               //Turn LEDs on
    DDRT = 0xF0;               //Set input key
    DDRP = 0x0F;               //Set output key
    PPST = 0xF0;
    PERT = 0x0F;

    TIOS = 0xC0;

    TSCR2_PR = 0x1;
    TSCR2_TOI = 0x0;

    TCTL1 = 0x50;
    TCTL2 = 0x00;

    PORTA = 0x00;              //LEDs off
    PTP = 0xFE;
    PTT = 0x0F;

    while(1)
    {
        NotePlay();
    }
}


void delay(word d)
{
    int i, j;
    for(j = 0; j < d; j++)
    {
        for(i = 0; i < 10000; i++) {}
    }
}

void NotePlay()
{
    while(getKey() != 0xFF)
    {
        S0 = getKey();

        if(S0 == 7)
            Config();

        else if(S0 != 0xFF && S0 != 7)
        {
            if(S0== 0 || S0== 1 || S0== 2 || S0 == 3)
            {
                newMidi = midi + (S0 * 2);
                keyPress();
            }

            else if(S0 == 4 || S0 == 5 || S0 == 6)
            {
                newMidi = midi + (S0 * 2) - 1;
                keyPress();
            }

            else if(S0 == 8 || S0 == 9 || S0 == 10 || S0 == 11)
            {
                newMidi = midi + (S0 * 2) - 4;
                keyPress();
            }

            else if(S0 == 12 || S0 == 13 || S0 == 14 || S0 == 15)
            {
                newMidi = midi + (S0 * 2) - 5;
                keyPress();
            }
        }
    }
}


void keyPress()
{
    PORTA = newMidi;
    keyValue = newMidi - 21;
    timerConst = (400000/(noteFreq*(pow(noteRaised, keyValue))));

    TSCR1 = 0x80;

    while(getKey() != 0xFF)
    {
        if (TFLG1_C7F == 1)
        {
            TC7 += timerConst;
            TFLG1 = 0x80;
        }
        if (TFLG1_C6F == 1)
        {
            TC6 += timerConst;
            TFLG1 = 0x40;
        }
    }

    TSCR1 = 0x00;
    PORTA = 0;
}

byte dKey(byte scanCode)
{
    if(scanCode >= 0 && scanCode <= 2)
        return scanCode + 1;

    else if(scanCode >= 4 && scanCode <= 6)
        return scanCode;

    else if(scanCode >= 8 && scanCode <= 10)
        return scanCode - 1;

    else if(scanCode == 13)
        return 0;
}


byte getKey()
{
    byte col, row;
    PTP = 0xFE;

    for(row = 0; row < 4; row++)   //Return scanCode key
    {
        if(PTIT_PTIT0 == 0)
        {
            col = 0;
            scanCode = 4 * row + col;
            return 4 * row + col;
        }
        else if(PTIT_PTIT1 == 0)
        {
            col = 1;
            scanCode = 4 * row + col;
            return 4 * row + col;
        }
        else if(PTIT_PTIT2 == 0)
        {
            col = 2;
            scanCode = 4 * row + col;
            return 4 * row + col;
        }
        else if(PTIT_PTIT3 == 0)
        {
            col = 3;
            scanCode = 4 * row + col;
            return 4 * row + col;
        }

        _PTP.Byte <<= 1;
        _PTP.Byte++;
    }

    scanCode = 0xFF;
    return 0xFF;               //No key press
}


void Config()
{
    int i;
    while(getKey() == 0x07 || getKey() == 0xFF)
    {
        PORTA = 0xF0;
        delay(5);

        PORTA = 0x0F;
        delay(5);
    }

    S1 = dKey(scanCode);
    delay(10);

    while(getKey() == 0xFF)
    {
        PORTA = S1;
        delay(5);
    }

    S2 = dKey(scanCode);     //Wait for key press
    delay(10);

    while(getKey() == 0xFF)
    {
        PORTA = S2;
        delay(5);
    }

    midi = S1 * 10 + S2;   //Start new Midi number
    if(midi < 21 || midi > 85)
        midi = 60;
    PORTA = 0x00;
}