//Rutina para alinear verticalmente en una pantalla LCD, valores flotantes
//Realizada por Jaime Ernesto Mora Velasco. CEO de Electronic Tech SAS. Cel: +573163791269 Mail: ceo@electronictech.com.co

#include "lcd.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void print_alig(float valf);
void sep_4dig(uint32_t valbin);
void shw_4dig(void);

float volt_r=123.3;
float volt_s=124.5;
float volt_t=126.6;
float curr_r=1.3;
float curr_s=1.2;
float curr_t=1.6;
uint32_t vald=0;
uint8_t umil=0;
uint8_t cent=0;
uint8_t dece=0;
uint8_t unid=0;

short modo=0;     //Inicializar en 0, para usar sprintf con formatos o en 1, para usar la rutina de alineacion de flotantes


main
{     LCD_init();
	     
	
	while(1)
	{
		 if(modo==0)
		 {
		  LCD_Clear();
		
	    LCD_SetPos(0,0);
			sprintf(cadena,"Vr:%3.1f Vs:%3.1f Vt:%3.1f",vol_r,vol_s,vol_t);
			LCD_SetPos(0,1);
			sprintf(cadena,"Ir:%3.1f Is:%3.1f It:%3.1f",cur_r,cur_s,cur_t);
			HAL_Delay(500);
		 }
		 
			else
			{
				LCD_Clear();
				
				LCD_SetPos(0,0);
				print_alig(vol_r);
				print_alig(vol_s);
				print_alig(vol_t);
				
				LCD_SetPos(0,1);
				print_alig(cur_r);
				print_alig(cur_s);
				print_alig(cur_t);
	      HAL_Delay(500);
			}
	}
			
}

//Funciones del algoritmo

void print_alig(float valf)
{
	uint32_t vald=0;
	vald=valf*10;
	sep_4dig(vald);
	shw_4dig();
}

void sep_4dig(uint32_t valbin)
{
	umil=0;
	cent=0;
	dece=0;
	unid=0;
	
	if(valbin > 999)
	{
		umil=(valbin/1000);
		valbin=(valbin-(umil*1000));
	}
	if(valbin > 99)
	{
		cent=(valbin/100);
		valbin=(valbin-(cent*100));
	}
	if(valbin > 9)
	{
		dece=(valbin/10);
		valbin=(valbin-(dece*10));
	}
	unid=valbin;
}

void shw_4dig(void)
{
	short fizq=0;
		
	 if(umil==0)
		{
			LCD_SendChar(32);
		}
		else
		{
		  LCD_SendChar(umil+48);
			fizq=1;
		}
		
	 if(fizq==0)
	 {
	  if(cent==0)
		{
			LCD_SendChar(32);
		}
		else
		{
		  LCD_SendChar(cent+48);
			fizq=1;
		}
	 }
	 else
	  {
		 LCD_SendChar(cent+48);
	  }
		
		 LCD_SendChar(dece+48);   //Imprime el ascii del valor decimal, al sumarle 48, que es el valor ascii de "0"
	   LCD_SendChar(44);				//Imprime la coma
     LCD_SendChar(unid+48);   //Imprime el ascii del valor decimal, al sumarle 48, que es el valor ascii de "0"
	   LCD_SendChar(32);  			//Imprime el espacio final
}