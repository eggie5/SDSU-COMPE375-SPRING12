#include <stdio.h>
void minMax(int x1[], int size);
int min;
int max;

void main(void)
{
	min=0;
	max=0;
int a[] = {100, -100, 200, -200, 500, -500, 400, -400, 300, -300};
minMax(a, 10);
//for(;;) {} /* wait forever */

printf("min=%d\n", min);
printf("max=%d", max);
}

void minMax(int x[], int size)
{
	int i;
	for(i=0; i<size;i++)
	{
		if(x[i] < min)
		{
			min=x[i];
		}
		else if(x[i] > max)
		{
			max=x[i];
		}
			
	}

}