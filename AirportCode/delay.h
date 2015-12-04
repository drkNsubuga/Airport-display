/*----------------------------------------------------------------------------------
                         void DelayUs(unsigned int n)
 ----------------------------------------------------------------------------------
 * I/P Arguments: unsigned int.
 * Return value : none
 
 * description : This function is used generate delay in us.
         It genarates a approximate delay of 10us for each count,
         if 5000 is passed as the argument then it generates a delay of apprx 50ms.
				 
-----------------------------------------------------------------------------------*/
void DelayUs(unsigned int us_count)
 {  
    while(us_count!=0)
      {
         us_count--;
       }
   }
 
 
 
 
 
/*----------------------------------------------------------------------------------
                         void DelayMs(unsigned int n)
 -----------------------------------------------------------------------------------
 * I/P Arguments: unsigned int.
 * Return value : none
 
 * description:  This function is used generate delay in ms.
     It genarates a approximate delay of 1ms for each count,
     if 1000 is passed as the argument then it generates delay of apprx 1000ms(1sec)
-----------------------------------------------------------------------------------*/
void DelayMs(unsigned int ms_count)
 {
        while(ms_count!=0)
         {
            DelayUs(112);   //delay_us is called to generate 1ms delay
             ms_count--;
            }
   }
 
 
 
 
 
 
 
 /*----------------------------------------------------------------------------------
                        void delay_sec(unsigned char sec_count)
  -----------------------------------------------------------------------------------
  * I/P Arguments: unsigned char.
  * Return value    : none
 
  * description:
      This function is used generate delay in sec .
      It genarates a approximate delay of 1sec for each count,
      if 10 is passed as the argument then it generates delay of apprx 10sec
 
    note: A max of 255 sec delay can be generated using this function.
 -----------------------------------------------------------------------------------*/
void DelaySec(unsigned char sec_count)
 {
 
 
     while(sec_count!=0)
      {
         DelayMs(1000);    //delay_ms is called to generate 1sec delay
         sec_count--;
        }
 }
/*-------------------------------------------------*/