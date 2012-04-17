#include <stdio.h>
#include <stdlib.h>


float asciiToInt(char line [])
{
    volatile unsigned num = 0.0,  digit;

    unsigned i=0;

    while(line[i]!=0x00 && line[i]<0x3A)
    {
        digit=line[i]-0x30;
        num=num*10+digit;
        i++;
    }


    return atof(line);
}



int main (int argc, char const *argv[])
{
	int dty5=200;
	int per5=250;
	float per=(float)((float)dty5/(float)per5);
	printf("per=%f\n\n",per);
	
	//test ascii to float
	char ascii[]="1000.43=8M888\r\n8M8B…òs";
	float num=(float)asciiToInt(ascii);
	printf("num=%f",num);
	return 0;
}