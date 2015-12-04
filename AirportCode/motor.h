/*
	*	Run Motor
	*	Steps			 = 8
	*	Step angle = 360/8 = 45
*/
//void RunMotor(unsigned int stepdelay){
void RunMotor(){
	unsigned int i,index=0,steps=8,delay=50;
	unsigned char MotorStep[]={0x09,0x08,0x0c,0x04,0x06,0x02,0x03,0x01};
	if(SW==0){
	for(i=0;i<steps;i++){
					MOTOR = MotorStep[index];
					DelayMs(delay);
					index++;
		}
	}
}
