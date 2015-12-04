#include <reg52.h>
#include <stdio.h>
#include <stdlib.h>
#include "ioconfig.h"
#include "delay.h"
#include "buzzer.h"
#include "lcd.h"
#include "time.h"
#include "schedule.h"

void main()
{
	Init();
	P2 = 0;
	BUZZER = 1;
	while(1)
	{
		WriteTxtLcd("TIME: ",1,1);
		WriteTxtLcd("PLANE NOW: ",2,1);
		RunSchedule();
	
	}
}