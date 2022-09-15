#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "LCD_interface.h"
#define F_CPU 8000000UL
#include <util/delay.h>
u8 Walking[] = {
		 0x00,
		  0x1C,
		  0x1C,
		  0x1C,
		  0x08,
		  0x0C,
		  0x0A,
		  0x08
};
u8 Rest_Walking[] = {
		  0x08,
		  0x08,
		  0x0C,
		  0x0A,
		  0x09,
		  0x09,
		  0x09,
		  0x00
};
u8 Close_Walking[] = {
		0x08,
		  0x08,
		  0x08,
		  0x08,
		  0x08,
		  0x08,
		  0x00,
		  0x00
};
u8 customChar[] = {
		 0x00,
		  0x0E,
		  0x0A,
		  0x0E,
		  0x04,
		  0x0E,
		  0x15,
		  0x04
};
u8 Hello[] = {
  0x00,
  0x0E,
  0x0A,
  0x0E,
  0x04,
  0x14,
  0x0C,
  0x07
};
u8 rest_customChar[] = {
		0x04,
		  0x04,
		  0x0E,
		  0x0A,
		  0x0A,
		  0x0A,
		  0x0A,
		  0x00
};
u8 Play_customChar[] = {
		  0x04,
		  0x04,
		  0x0E,
		  0x0A,
		  0x0A,
		  0x12,
		  0x02,
		  0x00
};
u8 Face_Play[] = {
		0x00,
		  0x02,
		  0x07,
		  0x07,
		  0x01,
		  0x05,
		  0x03,
		  0x01
};
 u8 Rest_Foot[] = {
		 0x00,
		  0x00,
		  0x00,
		  0x00,
		  0x00,
		  0x06,
		  0x07,
		  0x00
};
 u8 Hands[] = {
   0x00,
   0x00,
   0x00,
   0x00,
   0x00,
   0x00,
   0x01,
   0x00
 };
 u8 Ball1 [] = { 0x00,
 		        0x00,
 		        0x00,
 		        0x00,
 		        0x00,
 		        0x06,
 		        0x07,
 		        0x00 };

 u8 Ball2 [] = { 0x00,
 		        0x00,
 		        0x06,
 		        0x06,
 		        0x00,
 		        0x00,
 		        0x01,
 		        0x00 };



 u8 Ball4 [] = { 0x00,
 		        0x00,
 		        0x00,
 		        0x00,
 		        0x00,
 		        0x06,
 		        0x06,
 		        0x00 };

 u8 Ball5 [] = { 0x00,
 		        0x00,
 		        0x06,
 		        0x06,
 		        0x00,
 		        0x00,
 		        0x00,
 		        0x00 };


u8 Clear[] = {
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00
};
 u8 Apstrophe[] = {
  0x02,
  0x02,
  0x04,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00
};
u8 SmileFace[] = {
		0x04,
		  0x0A,
		  0x0E,
		  0x04,
		  0x00,
		  0x01,
		  0x02,
		  0x1C
};
u8 Rest_SmileFace[] = {
		 0x04,
		  0x0A,
		  0x0E,
		  0x04,
		  0x00,
		  0x10,
		  0x08,
		  0x07
};
u8 Gun[] = {
		0x00,
		  0x00,
		  0x1F,
		  0x1F,
		  0x14,
		  0x1C,
		  0x10,
		  0x10
};
u8 Surrender[] = {
  0x00,
  0x0E,
  0x0A,
  0x0E,
  0x04,
  0x15,
  0x0E,
  0x04
};
u8 Shoot1[] = {
		 0x00,
		  0x08,
		  0x00,
		  0x00,
		  0x00,
		  0x00,
		  0x00,
		  0x00
};
u8 Shoot2[] = {
		 0x00,
		  0x02,
		  0x00,
		  0x00,
		  0x00,
		  0x00,
		  0x00,
		  0x00
};

u8 Head[] = {
		0x00,
		  0x00,
		  0x00,
		  0x08,
		  0x17,
		  0x1D,
		  0x17,
		  0x08
};
u8 Bottom[] = {
		 0x00,
		  0x00,
		  0x10,
		  0x08,
		  0x04,
		  0x1F,
		  0x08,
		  0x10
};
void Title(void)
{
	LCD_voidGoToXY(0,3);
    LCD_voidSendData ('<');
    LCD_voidGoToXY(0,4);
    LCD_voidSendData ('A');
    LCD_voidGoToXY(0,5);
    LCD_voidSendData ('n');
    LCD_voidGoToXY(0,6);
    LCD_voidSendData ('i');
    LCD_voidGoToXY(0,7);
    LCD_voidSendData ('m');
    LCD_voidGoToXY(0,8);
    LCD_voidSendData ('a');
    LCD_voidGoToXY(0,9);
    LCD_voidSendData ('t');
    LCD_voidGoToXY(0,10);
    LCD_voidSendData ('i');
    LCD_voidGoToXY(0,11);
    LCD_voidSendData ('o');
    LCD_voidGoToXY(0,12);
    LCD_voidSendData ('n');
    LCD_voidGoToXY(0,13);
    LCD_voidSendData ('>');
    _delay_ms(2000);

}
void Z3bola_Walking(void)
{
	   for(u8 j=0;j<16;j=j+2)
		  {
			 LCD_voidSendCustomCharacter(Walking,1,0,j);
		     LCD_voidSendCustomCharacter(Rest_Walking,8,1,j);
		     _delay_ms(250);
		     LCD_voidSendCommand (0x01);
		     LCD_voidSendCustomCharacter(Walking,1,0,j+1);
		     LCD_voidSendCustomCharacter(Close_Walking,8,1,j+1);
		     _delay_ms(500);
	         LCD_voidSendCommand (0x01);
		  }
}
void Z3bola_Introducing_Himself(void)
{LCD_voidSendCustomCharacter(Hello,1,0,15);
LCD_voidSendCustomCharacter(rest_customChar,8,1,15);
_delay_ms(500);
LCD_voidSendCommand (0x0C);
 LCD_voidGoToXY(0,4);
LCD_voidSendData ('H');
LCD_voidGoToXY(0,5);
LCD_voidSendData ('e');
LCD_voidGoToXY(0,6);
LCD_voidSendData ('l');
LCD_voidGoToXY(0,7);
LCD_voidSendData ('l');
LCD_voidGoToXY(0,8);
LCD_voidSendData ('o');
LCD_voidGoToXY(1,0);
LCD_voidSendData ('M');
LCD_voidGoToXY(1,1);
LCD_voidSendData ('y');
LCD_voidGoToXY(1,2);
LCD_voidSendData ('N');
LCD_voidGoToXY(1,3);
LCD_voidSendData ('a');
LCD_voidGoToXY(1,4);
LCD_voidSendData ('m');
LCD_voidGoToXY(1,5);
LCD_voidSendData ('e');
LCD_voidGoToXY(1,6);
LCD_voidSendData ('i');
LCD_voidGoToXY(1,7);
LCD_voidSendData ('s');
LCD_voidGoToXY(1,8);
LCD_voidSendData ('Z');
LCD_voidGoToXY(1,9);
LCD_voidSendData ('3');
LCD_voidGoToXY(1,10);
LCD_voidSendData ('b');
LCD_voidGoToXY(1,11);
LCD_voidSendData ('o');
LCD_voidGoToXY(1,12);
LCD_voidSendData ('l');
LCD_voidGoToXY(1,13);
LCD_voidSendData ('a');
_delay_ms(3000);
LCD_voidSendCommand (0x01);
}
void Kicking_Ball(void)
{
	LCD_voidSendCommand (0x0C);
		LCD_voidSendCustomCharacter(Ball1,13,1,14);
		_delay_ms(400);
		LCD_voidSendCustomCharacter(Ball2,11,1,14);
		_delay_ms(400);
		LCD_voidSendCustomCharacter(Rest_Foot,14,1,14);
		LCD_voidSendCustomCharacter(Ball4,5,0,14);
		_delay_ms(400);
		LCD_voidSendCustomCharacter(Rest_Foot,14,1,14);
		LCD_voidSendCustomCharacter(Ball5,2,0,14);
		_delay_ms(400);
		LCD_voidSendCustomCharacter(Rest_Foot,14,1,14);
		LCD_voidSendCustomCharacter(Ball4,5,0,14);
		_delay_ms(400);
		LCD_voidSendCustomCharacter(Hands,6,0,14);
		LCD_voidSendCustomCharacter(Ball2,11,1,14);
		_delay_ms(400);
		LCD_voidSendCustomCharacter(Ball1,13,1,14);
		_delay_ms(400);
		LCD_voidSendCustomCharacter(Ball2,11,1,14);
		_delay_ms(400);
}

void Z3bola_Playing(void)

{LCD_voidSendCustomCharacter(customChar,1,0,15);
LCD_voidSendCustomCharacter(Play_customChar,8,1,15);
LCD_voidSendCustomCharacter(Rest_Foot,13,1,14);

	    LCD_voidGoToXY(0,0);
		LCD_voidSendData ('I');
		LCD_voidGoToXY(0,2);
		LCD_voidSendData ('C');
		LCD_voidGoToXY(0,3);
		LCD_voidSendData ('a');
		LCD_voidGoToXY(0,4);
		LCD_voidSendData ('n');
		LCD_voidGoToXY(0,6);
		LCD_voidSendData ('P');
		LCD_voidGoToXY(0,7);
		LCD_voidSendData ('l');
		LCD_voidGoToXY(0,8);
		LCD_voidSendData ('a');
		LCD_voidGoToXY(0,9);
		LCD_voidSendData ('y');
		LCD_voidGoToXY(1,1);
		LCD_voidSendData ('F');
		LCD_voidGoToXY(1,2);
		LCD_voidSendData ('o');
		LCD_voidGoToXY(1,3);
		LCD_voidSendData ('o');
		LCD_voidGoToXY(1,4);
		LCD_voidSendData ('t');
		LCD_voidGoToXY(1,5);
		LCD_voidSendData ('b');
		LCD_voidGoToXY(1,6);
		LCD_voidSendData ('a');
		LCD_voidGoToXY(1,7);
		LCD_voidSendData ('l');
		LCD_voidGoToXY(1,8);
		LCD_voidSendData ('l');
		Kicking_Ball();

		LCD_voidSendCommand (0x01);
}
void Lets_Play(void)
{

		 LCD_voidSendCustomCharacter(Apstrophe,0,0,4);
         LCD_voidSendCustomCharacter(SmileFace,9,1,10);
         LCD_voidSendCustomCharacter(Rest_SmileFace,10,1,9);
			    LCD_voidGoToXY(0,1);
			    LCD_voidSendData ('L');
			    LCD_voidGoToXY(0,2);
			    LCD_voidSendData ('e');
			    LCD_voidGoToXY(0,3);
			    LCD_voidSendData ('t');


			    LCD_voidGoToXY(0,5);
			    LCD_voidSendData ('s');
			    LCD_voidGoToXY(0,7);
			    LCD_voidSendData ('P');
			    LCD_voidGoToXY(0,8);
			    LCD_voidSendData ('l');
			    LCD_voidGoToXY(0,9);
			    LCD_voidSendData ('a');
			    LCD_voidGoToXY(0,10);
			    LCD_voidSendData ('y');
			    LCD_voidGoToXY(0,12);
			    LCD_voidSendData ('a');
			    LCD_voidGoToXY(1,3);
			    LCD_voidSendData ('G');
			    LCD_voidGoToXY(1,4);
			    LCD_voidSendData ('a');
			    LCD_voidGoToXY(1,5);
			    LCD_voidSendData ('m');
			    LCD_voidGoToXY(1,6);
			    LCD_voidSendData ('e');
			    _delay_ms(3000);
			    LCD_voidSendCommand (0x01);
}
void Gun_Threating(void)
{

	        LCD_voidSendCustomCharacter(Gun,2,0,0);

		    LCD_voidSendCustomCharacter(Surrender,1,0,15);
		    LCD_voidSendCustomCharacter(rest_customChar,8,1,15);

	        LCD_voidSendCustomCharacter(Apstrophe,6,1,3);

		   	LCD_voidGoToXY(0,3);
		   	LCD_voidSendData ('P');

		   	LCD_voidGoToXY(0,4);
		   	LCD_voidSendData ('l');

		   	LCD_voidGoToXY(0,5);
		   	LCD_voidSendData ('e');

		   	LCD_voidGoToXY(0,6);
		   	LCD_voidSendData ('a');

		   	LCD_voidGoToXY(0,7);
		   	LCD_voidSendData ('s');

		   	LCD_voidGoToXY(0,8);
		   	LCD_voidSendData ('e');

		   	LCD_voidGoToXY(1,0);
		   	LCD_voidSendData ('D');

		   	LCD_voidGoToXY(1,1);
		   	LCD_voidSendData ('o');

		   	LCD_voidGoToXY(1,2);
		   	LCD_voidSendData ('n');


		   	LCD_voidGoToXY(1,4);
		   	LCD_voidSendData ('t');

		   	LCD_voidGoToXY(1,6);
		   	LCD_voidSendData ('K');

		   	LCD_voidGoToXY(1,7);
		   	LCD_voidSendData ('i');

		   	LCD_voidGoToXY(1,8);
		   	LCD_voidSendData ('l');


		   	LCD_voidGoToXY(1,9);
		   	LCD_voidSendData ('l');

		   	LCD_voidGoToXY(1,11);
		   	LCD_voidSendData ('M');
		   	LCD_voidGoToXY(1,12);
		   	LCD_voidSendData ('e');



	        _delay_ms(3000);
	        LCD_voidSendCommand (0x01);
}
void shooting(void)
{

	for(u8 m=2 ;m<15;m=m+1)
	            {
	            	LCD_voidSendCustomCharacter(Gun,2,0,0);
	            		LCD_voidSendCustomCharacter(Surrender,1,0,15);
	            		LCD_voidSendCustomCharacter(rest_customChar,8,1,15);
	            	LCD_voidSendCustomCharacter(Shoot1,3,0,m);
	            _delay_ms(250);
	            LCD_voidSendCommand (0x01);

	          LCD_voidSendCustomCharacter(Gun,3,0,0);
	                        		LCD_voidSendCustomCharacter(Surrender,1,0,15);
	                        		LCD_voidSendCustomCharacter(rest_customChar,8,1,15);
	                        	LCD_voidSendCustomCharacter(Shoot2,5,0,m);
	                        _delay_ms(250);
	                        LCD_voidSendCommand (0x01);

	            }
	            LCD_voidSendCommand (0x01);
	            LCD_voidSendCustomCharacter(Head,11,1,15);
	            LCD_voidSendCustomCharacter(Bottom,10,1,14);
            LCD_voidGoToXY(0,0);
            LCD_voidSendData ('P');
            LCD_voidGoToXY(0,1);
            LCD_voidSendData ('r');
            LCD_voidGoToXY(0,2);
            LCD_voidSendData ('a');
            LCD_voidGoToXY(0,3);
            LCD_voidSendData ('y');
            LCD_voidGoToXY(0,5);
            LCD_voidSendData ('f');
            LCD_voidGoToXY(0,6);
            LCD_voidSendData ('o');
            LCD_voidGoToXY(0,7);
            LCD_voidSendData ('r');
            LCD_voidGoToXY(1,4);
            LCD_voidSendData ('Z');
            LCD_voidGoToXY(1,5);
            LCD_voidSendData ('3');
            LCD_voidGoToXY(1,6);
            LCD_voidSendData ('b');
            LCD_voidGoToXY(1,7);
            LCD_voidSendData ('o');
            LCD_voidGoToXY(1,8);
            LCD_voidSendData ('l');
            LCD_voidGoToXY(1,9);
            LCD_voidSendData ('a');






}
void Thanks(void)
{LCD_voidSendData ('T');
LCD_voidGoToXY(0,1);
LCD_voidSendData ('h');
LCD_voidGoToXY(0,2);
LCD_voidSendData ('a');
LCD_voidGoToXY(0,3);
LCD_voidSendData ('n');
LCD_voidGoToXY(0,4);
LCD_voidSendData ('k');
LCD_voidGoToXY(0,5);
LCD_voidSendData ('s');
LCD_voidGoToXY(0,7);
LCD_voidSendData ('f');
LCD_voidGoToXY(0,8);
LCD_voidSendData ('o');
LCD_voidGoToXY(0,9);
LCD_voidSendData ('r');
LCD_voidGoToXY(1,4);
LCD_voidSendData ('W');
LCD_voidGoToXY(1,5);
LCD_voidSendData ('a');
LCD_voidGoToXY(1,6);
LCD_voidSendData ('t');
LCD_voidGoToXY(1,7);
LCD_voidSendData ('c');
LCD_voidGoToXY(1,8);
LCD_voidSendData ('h');
LCD_voidGoToXY(1,9);
LCD_voidSendData ('i');
LCD_voidGoToXY(1,10);
LCD_voidSendData ('n');
LCD_voidGoToXY(1,11);
LCD_voidSendData ('g');
_delay_ms(2000);

}
void End(void)
{

	        _delay_ms(3000);
	        LCD_voidSendCommand (0x01);
	        _delay_ms(2000);
	        for (u8 k=0;k<14;k++)
	        { LCD_voidSendCustomCharacter(customChar,3,0,1);
		     LCD_voidSendCustomCharacter(rest_customChar,8,1,1);

	        LCD_voidGoToXY(0,3);
	        LCD_voidSendData ('<');
	        LCD_voidGoToXY(0,4);
	        LCD_voidSendData ('T');
	        LCD_voidGoToXY(0,5);
	        LCD_voidSendData ('h');
	        LCD_voidGoToXY(0,6);
	        LCD_voidSendData ('e');
	        LCD_voidGoToXY(0,8);
	        LCD_voidSendData ('E');
	        LCD_voidGoToXY(0,9);
	        LCD_voidSendData ('n');
	        LCD_voidGoToXY(0,10);
	        LCD_voidSendData ('d');
	        LCD_voidGoToXY(0,11);
	        LCD_voidSendData ('>');

			 LCD_voidSendCustomCharacter(customChar,3,0,13);
		     LCD_voidSendCustomCharacter(rest_customChar,8,1,13);
	        LCD_voidSendCommand (0x1C);
	        _delay_ms(400);
	        }
	         LCD_voidSendCommand (0x01);
	        _delay_ms(1000);
}
void Directed(void)
{
	for(u8 z=0;z<20;z++)

        {
        LCD_voidGoToXY(0,0);
        LCD_voidSendData ('D');
        LCD_voidGoToXY(0,1);
        LCD_voidSendData ('i');
        LCD_voidGoToXY(0,2);
        LCD_voidSendData ('r');
        LCD_voidGoToXY(0,3);
        LCD_voidSendData ('e');
        LCD_voidGoToXY(0,4);
        LCD_voidSendData ('c');
        LCD_voidGoToXY(0,5);
        LCD_voidSendData ('t');
        LCD_voidGoToXY(0,6);
        LCD_voidSendData ('e');
        LCD_voidGoToXY(0,7);
        LCD_voidSendData ('d');
        LCD_voidGoToXY(0,8);
        LCD_voidSendData (' ');
        LCD_voidGoToXY(0,9);
        LCD_voidSendData ('b');
        LCD_voidGoToXY(0,10);
        LCD_voidSendData ('y');
        LCD_voidGoToXY(0,11);
        LCD_voidSendData (':');
        LCD_voidGoToXY(1,0);
        LCD_voidSendData ('N');
        LCD_voidGoToXY(1,1);
        LCD_voidSendData ('a');
        LCD_voidGoToXY(1,2);
        LCD_voidSendData ('d');
        LCD_voidGoToXY(1,3);
        LCD_voidSendData ('i');
        LCD_voidGoToXY(1,4);
        LCD_voidSendData ('n');
        LCD_voidGoToXY(1,5);
        LCD_voidSendData ('e');
        LCD_voidGoToXY(1,6);
        LCD_voidSendData (' ');
        LCD_voidGoToXY(1,7);
        LCD_voidSendData ('A');
        LCD_voidGoToXY(1,8);
        LCD_voidSendData ('s');
        LCD_voidGoToXY(1,9);
        LCD_voidSendData ('h');
        LCD_voidGoToXY(1,10);
        LCD_voidSendData ('r');
        LCD_voidGoToXY(1,11);
        LCD_voidSendData ('a');
        LCD_voidGoToXY(1,12);
        LCD_voidSendData ('f');
        LCD_voidSendCommand (0x1C);
        _delay_ms(700);
        }
        LCD_voidSendCommand (0x01);
}
void main (void)
{
	LCD_voidInit();

	while (1)
	{
		Title();
		Z3bola_Walking();
	Z3bola_Introducing_Himself();

	Z3bola_Playing();

	Lets_Play();


	Gun_Threating();
	shooting();


	End();
	Thanks();
	Directed();


	}
}
