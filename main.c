/*
-------------------------------Colorful Graphic Display beside MMC-----------------------------------

Author : MOHAMAD DEHGHANI         (m.dehghani94@live.com)(m.dehghani94@gmail.com)

LCD features : ili9325 (320*240)
                 and MMC/SD
Processor features:    ATmega32
                        16 MHz clock
description:
    In this source we are going to run a SD card and a Graphic Display to show Pictures in bmp 24bits format.
*/
#include <mega32a.h>   //Header of ATmega32A
#include <delay.h>     //Header for making delays 
#include <stdio.h>
#include <pff.c>       //Headers used to read or write on MMC/SD cards 
#include <ff.h>      
#include <mmc.c>

#define xtal 16000000

//================================ LCD CONFIGURATIONS ======================================= 
 #define   PORTRAIT                /* It is defined in "tftlcd_functions.h" library  
                                                             ,you can change it to LANSCAPE*/
 
 //Define pins connected to the display
 #define LCD_CONTROLPORT_DDR  DDRD 
 #define LCD_CONTROLPORT_PORT PORTD
 #define LCD_CONTROLPORT_PIN  PIND 
 
 #define LCD_RST_DDR  DDRD
 #define LCD_RST_PORT PORTD
 #define LCD_RST_PIN  4
 
 #define LCD_RS_DDR  DDRD
 #define LCD_RS_PORT PORTD 
 #define LCD_RS_PIN  2

 #define LCD_CS_DDR  DDRD
 #define LCD_CS_PORT PORTD 
 #define LCD_CS_PIN  3
 
 #define LCD_RD_DDR  DDRD
 #define LCD_RD_PORT PORTD 
 #define LCD_RD_PIN  0
 
 #define LCD_WR_DDR  DDRD
 #define LCD_WR_PORT PORTD 
 #define LCD_WR_PIN  1
 
 #define LCD_DATAPORT_MSB_DDR   DDRA
 #define LCD_DATAPORT_MSB_PORT  PORTA 
 #define LCD_DATAPORT_MSB_PIN   PINA 
 
 #define LCD_DATAPORT_LSB_DDR   DDRC
 #define LCD_DATAPORT_LSB_PORT  PORTC
 #define LCD_DATAPORT_LSB_PIN   PINC
 
 #include "tftlcd_functions.h"    // The main header to run ili9325 display

 //================================================================ 

 //declare your global variables here
 #define BUFFER_SIZE 721               //every row is 240 R G B pixels and 240*3=720
 unsigned char buffer[BUFFER_SIZE];    //The data of every row will be saved in this buffer
 FATFS Fs;                             
 WORD w_br;                            //used in pf_read function
 FRESULT _result1;                     //used to check the result(explained in the papers)
 FRESULT res;
 WORD WriteIndex;
 unsigned long int x=0,y=0;
 unsigned char MYBUFFER[7]={0}; 
 unsigned int ADDR=0;                  //Address of data we want to read in bmp file
 unsigned int i1=0,i2=0,i3=0;          //Loop counters
 unsigned char r,g,b;                  //Used for merging pixel colors in bmp to an int number
 unsigned long int color=0,tcolor;
 unsigned char count=0xffff,count1=0;
 
 
/***declaration of subfunctions***/
  
  unsigned long int bmp_height(void){        //subfunction to get the height of bmp picture
    unsigned long int height;
    pf_lseek(0x16);                          /* The bmp file contains much information besides the  
                                                pixels' colors such as the volume and the height and 
                                                the width of the pic, and there are 4 bytes showing
                                                the height of the bmp pic in address 0x16 */
    pf_read(&buffer,4,&w_br);
    height=(long)buffer[3]*512+(long)buffer[2]*64+(long)buffer[1]+(long)buffer[0];  //calculations
    return height;   
  }  
  
  unsigned long int bmp_width(void){         //subfunction to get bmp picture width
    unsigned long int width=0;
    pf_lseek(0x12);                         /* The bmp file contains much information besides the 
                                                pixels' colors such as the volume and the height and 
                                                the width of the pic, and there are 4 bytes showing
                                                the width of the bmp pic in address 0x12 */
    pf_read(&buffer,4,&w_br);
    width=(long)buffer[3]*512+(long)buffer[2]*64+(long)buffer[1]+(long)buffer[0]; //calculations
    return width;
  }
 
 void showbmp(void){
     
        //First settings
     lcd_write_index_register(TS_INS_GRAM_ADX);
     lcd_write_wdr(0); 
     lcd_write_index_register(TS_INS_START_ADX);
     lcd_write_wdr(0);
     lcd_write_index_register(TS_INS_END_ADX);
     lcd_write_wdr(239);
     
     lcd_write_index_register(TS_INS_END_ADY);
     lcd_write_wdr(319);
     lcd_write_index_register(TS_INS_START_ADY);
     lcd_write_wdr(0);
     for(y=0;y<321;y++){        //main loop to put the image
                                //This is the fastest way to show the picture
      lcd_write_index_register(TS_INS_GRAM_ADY);
      lcd_write_wdr(y);
      lcd_write_index_register(TS_INS_RW_GRAM);
      res=pf_read(&buffer,720,&w_br);
      CS_LOW;                        //It is defined in the header ==> CS pin --> 0 volt
      RS_HIGH;                      //RS pin --> 5 volt
      
      for(i1=0;i1<720;i1+=3){           //convert 888 format to 565 .
          
                r=buffer[i1];
                g=buffer[i1+1];
                b=buffer[i1+2];
                color=r>>3;
                color<<=6;
                tcolor=g>>2;
                color+=tcolor;
                color<<=5;
                tcolor=b>>3;
                color+=tcolor;
                LCD_DATAPORT_MSB_PORT=(color>>8); 
                LCD_DATAPORT_LSB_PORT=color; 
                WR_LOW;
                WR_HIGH;
      }
      CS_HIGH;
      }
     y=0;
 }
 
 
 
void main(void)
{
//// SPI initialization to use SD card
//// SPI disabled
SPCR=(0<<SPIE) | (0<<SPE) | (0<<DORD) | (0<<MSTR) | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);

 lcd_init();                        // LCD initialization
 lcd_background_color(0xff80);      /*  Set the color of background, you can use
                                        COLOURCO website to get the colour scheme*/
 
 lcd_putsf("Designed by:",0x01ff,0,0xff80);    // Write on display(To see how it works refer to library)
 lcd_gotoxy(0,1);                              // Change the cursur position
 lcd_putsf("    Mohammad Dehghani   ",0x01ff,0,0xff80);
 delay_ms(3000);
 lcd_gotoxy(0,3);
 lcd_putsf("Read SD card",0x01ff,0,0xff80);
 delay_ms(2000);
 lcd_gotoxy(0,4);
 lcd_putsf("Init Drive",0x01ff,0,0xff80);
 while(disk_initialize() != FR_OK)   delay_ms(100);     //refer to MMC document
 lcd_putsf("   --->OK",0x01ff,0,0xff80);
 delay_ms(1000);
 lcd_gotoxy(0,5);                         
 
 ///////////////////////////////SHOW PICTURES ON DISPLAY//////////////////////////////
 //////////////////////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////////////////////
 lcd_putsf("OPEN DRIVE",0x01ff,0,0xff80); 
 while(pf_mount(&Fs)!=FR_OK) delay_ms(100);
 lcd_gotoxy(0,6);
 while(pf_open("1.bmp")!=FR_OK)   delay_ms(100);
 delay_ms(1000);
 pf_lseek(0x0A);                         /* The bmp file contains much information in addition to 
                                                pixels' colors such as the volume and the height and 
                                                the width of the pic, and the information about 
                                                pixel's colour begins at the address 0x10  */
 pf_read(&buffer,4,&w_br);
 ADDR=(long)buffer[3]*512+(long)buffer[2]*64+(long)buffer[1]+(long)buffer[0]; //calculate address
 pf_lseek(ADDR);
 showbmp();
 delay_ms(6000);
 while(pf_mount(0)!=FR_OK )  delay_ms(100); 
 while(pf_mount(&Fs)!=FR_OK) delay_ms(100);
 lcd_gotoxy(0,6);
 //////////////////////////////////////////
 while(pf_open("2.bmp")!=FR_OK)   delay_ms(100);
 delay_ms(1000);
 pf_lseek(0x0A);
 pf_read(&buffer,4,&w_br);
 ADDR=(long)buffer[3]*512+(long)buffer[2]*64+(long)buffer[1]+(long)buffer[0]; 
 pf_lseek(ADDR);
 showbmp();
 delay_ms(1000);
  for(count=0;count<254;count++){                  //circle frame
      lcd_draw_circle(120,160,count,0,0XBDD7);
      }
 //lcd_background_color(BLACK); 
 while(pf_mount(0)!=FR_OK )  delay_ms(100);
 //////////////////////////////////////////
 
      
      lcd_clear_screen();
      lcd_background_color(BLACK);
      lcd_draw_line(1,1,239,319,0x6523);
      lcd_draw_line(239,1,1,319,0x7341);
      for(count=0;count<100;count++){
      lcd_draw_rectangle(count,count,240-count,320-count,0,0XAAAA);
      }
      for(count=0;count<254;count++){
      lcd_draw_circle(120,160,count,0,0XA234);
      }


while (1)
      {                 //It is finished, so let's play the pictures 19,20,21,22 repeatedly.
        
  //////////////////////////////////////////
 while(pf_mount(&Fs)!=FR_OK) delay_ms(100);
 lcd_gotoxy(0,6);
 while(pf_open("19.bmp")!=FR_OK)   delay_ms(100);
 delay_ms(1000);
 pf_lseek(0x0A);
 pf_read(&buffer,4,&w_br);
 ADDR=(long)buffer[3]*512+(long)buffer[2]*64+(long)buffer[1]+(long)buffer[0]; 
 pf_lseek(ADDR);
 showbmp();
 delay_ms(3000);
 while(pf_mount(0)!=FR_OK )  delay_ms(100);
 //////////////////////////////////////////
 while(pf_mount(&Fs)!=FR_OK) delay_ms(100);
 lcd_gotoxy(0,6);
 while(pf_open("20.bmp")!=FR_OK)   delay_ms(100);
 delay_ms(1000);
 pf_lseek(0x0A);
 pf_read(&buffer,4,&w_br);
 ADDR=(long)buffer[3]*512+(long)buffer[2]*64+(long)buffer[1]+(long)buffer[0]; 
 pf_lseek(ADDR);
 showbmp();
 delay_ms(3000);
 while(pf_mount(0)!=FR_OK )  delay_ms(100);
 //////////////////////////////////////////
 while(pf_mount(&Fs)!=FR_OK) delay_ms(100);
 lcd_gotoxy(0,6);
 while(pf_open("21.bmp")!=FR_OK)   delay_ms(100);
 delay_ms(1000);
 pf_lseek(0x0A);
 pf_read(&buffer,4,&w_br);
 ADDR=(long)buffer[3]*512+(long)buffer[2]*64+(long)buffer[1]+(long)buffer[0]; 
 pf_lseek(ADDR);
 showbmp();
 delay_ms(3000);
 while(pf_mount(0)!=FR_OK )  delay_ms(100);
 //////////////////////////////////////////
 while(pf_mount(&Fs)!=FR_OK) delay_ms(100);
 lcd_gotoxy(0,6);
 while(pf_open("22.bmp")!=FR_OK)   delay_ms(100);
 delay_ms(1000);
 pf_lseek(0x0A);
 pf_read(&buffer,4,&w_br);
 ADDR=(long)buffer[3]*512+(long)buffer[2]*64+(long)buffer[1]+(long)buffer[0]; 
 pf_lseek(ADDR);
 showbmp();
 delay_ms(3000);
 while(pf_mount(0)!=FR_OK )  delay_ms(100);       
      

}

}


/* this source is programmed by MOHAMMAD DEHGHANI
