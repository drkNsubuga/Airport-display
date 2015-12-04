/*
	*	Enable
*/
void Enable(){
   EN = 1;
   DelayMs(5);
   EN = 0;
   DelayMs(5); 
}
/*
	*Initialise : Basic LCD setup 
*/
void Init(){
RS=0; //command mode
RW=0;
EN=0;
DATAPINS = 0x38; //* 8 bit mode operation
Enable();
DATAPINS = 0x0C; // switch on lcd, cursor off
Enable();
Enable();
//DATAPINS = 0x1c; //Display shift on
DATAPINS = 0x14;//Display shift off;
Enable();
Enable();
DATAPINS= 0x01; // clear the display, home the screen
Enable();
}
/*
	*	SetLine : 
	*	Prints data on any LCD line and position
	*	Parameters: 
	*	Line Number, Maximum = 4
	* Position
*/
void SetLine(unsigned int line,unsigned int pos){
unsigned int posindex[]={0x00,0x01,0x02,0x03,0x04,
0x05,0x06,0x07,0x08,0x09,0xA,0xB,0xC,0xD,0xE,0xF,0x10,0x11,0x12,0x13};	
RS=0;
RW=0;
switch(line){
	case 1:	DATAPINS=0x80+posindex[pos-1];break;
	case 2: DATAPINS=0xC0+posindex[pos-1];break;
	case 3:	DATAPINS=0x94+posindex[pos-1];break;
	case 4: DATAPINS=0xD4+posindex[pos-1];break;
}
	Enable();
	RS=1;
}

/*
	*	Write Text To LCD
	*	Parameters: Text, LCD Line, Position Number on LCD Line
*/
void WriteTxtLcd(unsigned char *txt,unsigned int line,unsigned int lcdpos){
	unsigned int pos=0; //charcter index in text
	SetLine(line,lcdpos);
	while(txt[pos]){
				 RS = 1;
	       RW = 0;
	       EN = 1;
				 DATAPINS = txt[pos];
	       DelayUs(1);
	       EN = 0;
				 DelayUs(2);
				 pos++;
	}
}
/*
	*	Write Positive Integer To LCD
	*	Parameters: Positive Integer, LCD Line, Position Number on LCD Line
*/
void WriteNumLcd(unsigned int num,unsigned int line,unsigned int lcdpos){
		unsigned char buffer[20];
		sprintf(buffer,"%d",num);
		WriteTxtLcd(buffer,line,lcdpos);
}
/*
	*	Switch Off LCD
*/
void SwitchOffLcd(){
		RS = 0;
		RW = 0;
		EN = 1;
		DATAPINS=0x08;
		Enable();
}