/*
 * frequancy_meter.c
 *
 * Created: 12/09/2023 04:19:03 م
 *  Author: handsa
 */ 

#include "prog init.h"
/*
#include <avr/io.h>
#include "prog init.h"
 unsigned short a,b,c,hight,period,duty;
unsigned int freq;
int main(void)
{
lcd_init();
lcd_send_cmd(disp_on_cursor_off);
TCCR1A=0;
    char str[15];
	

a=0;
b=0;
c=0;
	TCCR1B=0xc1;
	
	while((TIFR&(1<<ICF1))==0);

	a= ICR1;
		TIFR=(1<<ICF1);
	  
	TCCR1B=0x81;
	
	
while((TIFR&(1<<ICF1))==0);
	TIFR=(1<<ICF1);
	b= ICR1;
    

	TCCR1B=0xc1;
	
	while((TIFR&(1<<ICF1))==0);
	TIFR=(1<<ICF1);
	c=ICR1;
        
        TCCR1B=0;
		
		if((a<b)&&(b<c))
		{
	hight=b-a;
	period=c-a;
	duty=( ((float)hight/period)*100);
 freq=(F_CPU/(int)period);
lcd_move_cursor(1,1);
lcd_send_string("duty=");

lcd_send_char((duty/10)+48);
lcd_send_char((duty%10)+48);
//lcd_send_string(str);
lcd_send_char('%');
lcd_move_cursor(2,1);

  lcd_send_char(((freq/100000)%10)+48);
  lcd_send_char(((freq/10000)%10)+48);
  lcd_send_char(((freq/1000)%10)+48);
  lcd_send_char(((freq/100)%10)+48);
  lcd_send_char(((freq/10)%10)+48);
  lcd_send_char((freq%10)+48);
lcd_send_string("hz");
		}
	else
	{
	
	lcd_clrscrean();
	lcd_send_string("out of range");
	}	
	while(1)
    {
     
		
		
    }
}
*/
#include <avr/io.h>
#define  F_CPU  8000000Ul

#include <util/delay.h>

unsigned int a,b,c,hi,duty,period;
unsigned int freq;
int main(void)
{
	lcd_init();
lcd_send_cmd(disp_on_cursor_off);
TCCR1A=0;
char str[15];

TCCR1B=0xc1;
TIFR=(1<<ICF1);

while((TIFR&(1<<ICF1))==0);

a= ICR1;
TIFR=(1<<ICF1);

TCCR1B=0x81;


while((TIFR&(1<<ICF1))==0);
TIFR=(1<<ICF1);
b= ICR1;


TCCR1B=0xc1;

while((TIFR&(1<<ICF1))==0);
TIFR=(1<<ICF1);
c=ICR1;

TCCR1B=0;
	
	if ((a<b)&&(b<c))
	{
		hi =b-a;
		period =c-a;
		duty=((float)hi/period)*100;
		freq=(F_CPU/period);
		lcd_send_string("duty=");

		lcd_send_char((duty/10)+48);
		lcd_send_char((duty%10)+48);

		lcd_send_char('%');
		lcd_move_cursor(2,1);
		lcd_send_char(((freq/100000)%10)+48);
		lcd_send_char(((freq/10000)%10)+48);
		lcd_send_char(((freq/1000)%10)+48);
		lcd_send_char(((freq/100)%10)+48);
		lcd_send_char(((freq/10)%10)+48);
		lcd_send_char((freq%10)+48);

		lcd_send_string("hz");
		
	}
	else
	{
		lcd_clrscrean();
		lcd_send_string("out of range");

	}
	while(1)
	{
		
	}
}