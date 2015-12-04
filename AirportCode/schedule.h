
/*
plane
- Displays a plane name on the screen on a given line
*/
void plane(unsigned int planeno,unsigned int line)
{
unsigned char *planes[]={"KIGALI    ","KINSHASHA","GUANG ZOU"};
WriteTxtLcd(planes[planeno],line,12);
}

/*------------------------------------------------------------------------
Shedule function holds the logic for the airport schedule
j = current plane
k = next plane
takeoffTime = Plane takes off in these mins
beforeTakeoffTime = Time  before a plane takes off
tick = time counter;
beforeTakeoffTime= Tiem 
showBoardingMessageTime = Time to show Message that notifies a flight is boarding
gateClosingTime = time to close Gate;
takeoffAlarmDuration  = How long the takeoff alarm sounds 
*/
void RunSchedule()
{
	unsigned int j;
	unsigned int planes = 3;
	unsigned int k=0;
	unsigned int tick; 
	unsigned int TakeOffTime = 15;  
	unsigned int beforeTakeoffTime=10; 
	unsigned int showBoardingMessageTime = TakeOffTime - beforeTakeoffTime; 
	unsigned int gateClosingTime = 5;  //milliseconds
	unsigned int gateCountdownDelay= beforeTakeoffTime-gateClosingTime; //seconds
	unsigned int takeoffAlarmDuration = 250; // milliseconds
	
	//for each of the three planes
	for(j=0;j<planes;j++){
	//Every after 15 mins, a plane is flying
	plane(j,2);

	//show next plane
	WriteTxtLcd("NEXT PLANE:         ",4,1);
	k=j+1;
	if(k<3)
	  plane(k,4);
	else
		plane(0,4);
	
// Mins Before Take off
	 tick = showBoardingMessageTime;
	while(tick!=0)
	{
		DelayMs(1);
		Timer();
		tick--;
	}
	WriteTxtLcd("BOARDING:",3,1);
	plane(j,3);//status : plane boarding
	tick=gateCountdownDelay;
	while(tick!=0)
	{
		DelayMs(1);
		Timer();
		tick--;
	}
	WriteTxtLcd("GATE CLOSING IN      ",4,1);
	WriteTxtLcd("Sec",4,18);
	tick=gateClosingTime;
	while(tick!=0)
	{
		DelayMs(1);
		Timer();
		WriteNumLcd(tick,4,17);
		tick--;
	}
	
	//sound bell for 1 second
	tick=takeoffAlarmDuration;
	while(tick!=0)
	{
		buzzer();
		DelayMs(1);
		tick--;
	}
	BUZZER=0;
	
	WriteTxtLcd("TAKEOFF: ",3,1);
	plane(j,3);
	DelayMs(1000);
	WriteTxtLcd("                    ",3,1);
}
}