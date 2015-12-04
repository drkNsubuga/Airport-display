/*
	*	Simulate a Real 24 hour clock
	*	00 : 00 : 00
*/
unsigned short hours=0,mins=0,secs=0;
void Timer(){
	DelayMs(1000);
	secs++;
	if(secs<10){
		WriteNumLcd(0,1,12);
		WriteNumLcd(secs,1,13);
	}else{
		WriteNumLcd(secs,1,12);
	}
	WriteTxtLcd(":",1,8);
	if(secs==59){
			mins++;
			secs=0;
	}
	if(mins<10){
	WriteNumLcd(0,1,9);
	WriteNumLcd(mins,1,10);
	}else{
						WriteNumLcd(mins,1,9);
			}
	WriteTxtLcd(":",1,11);
	if(mins==59){
						hours++;
						hours=0;
	}
	if(hours<10){
				WriteNumLcd(0,1,6);
				WriteNumLcd(hours,1,7);
	}else{
				WriteNumLcd(hours,1,6);
	}
	if(hours==24){
							hours=mins=secs=0;
				}
}
				
