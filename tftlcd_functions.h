//----------------------------------------------------------------------------------------------------
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//----------------------------------------------------------------------------------------------------
/*
                           ....::::: In The Name Of GOD :::::....

    TFT LCD (ILI9325-ILI9320 LCD Driver) Functions (ECA 2.8 inch LCD Module)
        Version : 1.0
    By Ali Imanifar                    11/06/2013
        
        ECA Corporation........www.ECA.ir
        ECA Eshop..............www.Eshop.ECA.ir
        ECA Forum..............www.ECA.ir/Forum2
        ECA Video Center.......www.TV.ECA.ir
        ECA Blog...............www.Blog.ECA.ir
        
    Important Note :
    DO NOT Change LCD Register Definitions And LCD Command Codes 
*/
//----------------------------------------------------------------------------------------------------
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//----------------------------------------------------------------------------------------------------

#define HIGH 1
#define LOW  0

#define RST_LOW       LCD_CONTROLPORT_PORT.LCD_RST_PIN=LOW
#define RST_HIGH      LCD_CONTROLPORT_PORT.LCD_RST_PIN=HIGH
#define RS_LOW        LCD_CONTROLPORT_PORT.LCD_RS_PIN=LOW
#define RS_HIGH       LCD_CONTROLPORT_PORT.LCD_RS_PIN=HIGH
#define CS_LOW        LCD_CONTROLPORT_PORT.LCD_CS_PIN=LOW
#define CS_HIGH       LCD_CONTROLPORT_PORT.LCD_CS_PIN=HIGH
#define RD_LOW        LCD_CONTROLPORT_PORT.LCD_RD_PIN=LOW
#define RD_HIGH       LCD_CONTROLPORT_PORT.LCD_RD_PIN=HIGH
#define WR_LOW        LCD_CONTROLPORT_PORT.LCD_WR_PIN=LOW
#define WR_HIGH       LCD_CONTROLPORT_PORT.LCD_WR_PIN=HIGH

#define LCD_DATAPORT_INPUT          LCD_DATAPORT_MSB_DDR=0x00;LCD_DATAPORT_LSB_DDR=0x00
#define LCD_DATAPORT_OUTPUT         LCD_DATAPORT_MSB_DDR=0xFF;LCD_DATAPORT_LSB_DDR=0xFF
#define LCD_DATAPORT_CLEAR          LCD_DATAPORT_MSB_PORT=0x00;LCD_DATAPORT_LSB_PORT=0x00

#define TS_INS_START_OSC             0x00
#define TS_INS_DRIV_OUT_CTRL         0x01
#define TS_INS_DRIV_WAV_CTRL         0x02
#define TS_INS_ENTRY_MOD             0x03
#define TS_INS_RESIZE_CTRL           0x04
#define TS_INS_DISP_CTRL1            0x07
#define TS_INS_DISP_CTRL2            0x08
#define TS_INS_DISP_CTRL3            0x09
#define TS_INS_DISP_CTRL4            0x0A
#define TS_INS_RGB_DISP_IF_CTRL1     0x0C
#define TS_INS_FRM_MARKER_POS        0x0D
#define TS_INS_RGB_DISP_IF_CTRL2     0x0F
#define TS_INS_POW_CTRL1             0x10
#define TS_INS_POW_CTRL2             0x11
#define TS_INS_POW_CTRL3             0x12
#define TS_INS_POW_CTRL4             0x13
#define TS_INS_GRAM_HOR_AD           0x20
#define TS_INS_GRAM_VER_AD           0x21
#define TS_INS_RW_GRAM               0x22
#define TS_INS_POW_CTRL7             0x29
#define TS_INS_FRM_RATE_COL_CTRL     0x2B
#define TS_INS_GAMMA_CTRL1           0x30
#define TS_INS_GAMMA_CTRL2           0x31
#define TS_INS_GAMMA_CTRL3           0x32
#define TS_INS_GAMMA_CTRL4           0x35 
#define TS_INS_GAMMA_CTRL5           0x36
#define TS_INS_GAMMA_CTRL6           0x37
#define TS_INS_GAMMA_CTRL7           0x38
#define TS_INS_GAMMA_CTRL8           0x39
#define TS_INS_GAMMA_CTRL9           0x3C
#define TS_INS_GAMMA_CTRL10          0x3D
#define TS_INS_HOR_START_AD          0x50
#define TS_INS_HOR_END_AD            0x51
#define TS_INS_VER_START_AD          0x52
#define TS_INS_VER_END_AD            0x53
#define TS_INS_GATE_SCAN_CTRL1       0x60
#define TS_INS_GATE_SCAN_CTRL2       0x61
#define TS_INS_GATE_SCAN_CTRL3       0x6A
#define TS_INS_PART_IMG1_DISP_POS    0x80
#define TS_INS_PART_IMG1_START_AD    0x81
#define TS_INS_PART_IMG1_END_AD      0x82
#define TS_INS_PART_IMG2_DISP_POS    0x83
#define TS_INS_PART_IMG2_START_AD    0x84
#define TS_INS_PART_IMG2_END_AD      0x85
#define TS_INS_PANEL_IF_CTRL1        0x90
#define TS_INS_PANEL_IF_CTRL2        0x92
#define TS_INS_PANEL_IF_CTRL3        0x93
#define TS_INS_PANEL_IF_CTRL4        0x95
#define TS_INS_PANEL_IF_CTRL5        0x97
#define TS_INS_PANEL_IF_CTRL6        0x98           


#ifdef LANDSCAPE
#define TS_SIZE_X					320
#define TS_SIZE_Y					240
#define TS_VAL_ENTRY_MOD			0x0028
#define TS_INS_GRAM_ADX				TS_INS_GRAM_VER_AD
#define TS_INS_GRAM_ADY				TS_INS_GRAM_HOR_AD
#define TS_INS_START_ADX   			TS_INS_VER_START_AD
#define TS_INS_END_ADX   			TS_INS_VER_END_AD
#define TS_INS_START_ADY   			TS_INS_HOR_START_AD
#define TS_INS_END_ADY   			TS_INS_HOR_END_AD
#else
#define TS_SIZE_X                    240
#define TS_SIZE_Y                    320
#define TS_VAL_ENTRY_MOD             0x0030
#define TS_INS_GRAM_ADX              TS_INS_GRAM_HOR_AD
#define TS_INS_GRAM_ADY              TS_INS_GRAM_VER_AD
#define TS_INS_START_ADX             TS_INS_HOR_START_AD
#define TS_INS_END_ADX               TS_INS_HOR_END_AD
#define TS_INS_START_ADY             TS_INS_VER_START_AD
#define TS_INS_END_ADY               TS_INS_VER_END_AD
#endif


#define RGB2COL(red, green, blue)		((unsigned int)(((blue >> 3) << 11) | ((green >> 2) << 5) | (red >> 3)))


//RGB Colors												(  R ,  G  ,  B  ) from PhotoShop!!!
#define BLACK                       RGB2COL(0x00, 0x00, 0x00)
#define GRAY                        RGB2COL(0x95, 0x95, 0x95)
#define WHITE                       RGB2COL(0xFF, 0xFF, 0xFF)

#define RED                         RGB2COL(0xFF, 0x00, 0x00)
#define LIGHT_RED              			RGB2COL(0xF2, 0x6C, 0x4E)
#define DARK_RED          	  			RGB2COL(0x79, 0x00, 0x00)
	
#define GREEN                       RGB2COL(0x00, 0xFF, 0x00)
#define LIGHT_GREEN            	    RGB2COL(0x3B, 0xB8, 0x78)
#define DARK_GREEN        			    RGB2COL(0x00, 0x58, 0x25)
	
#define BLUE                        RGB2COL(0x00, 0x00, 0xFF)
#define LIGHT_BLUE                 	RGB2COL(0x00, 0xBF, 0xF3)
#define DARK_BLUE           	     	RGB2COL(0x00, 0x5B, 0x7F)

#define YELLOW                      RGB2COL(0xFF, 0xFF, 0x00)
#define LIGHT_YELLOW           	    RGB2COL(0xFF, 0xF4, 0x68)
#define DARK_YELLOW        			    RGB2COL(0xAB, 0xA0, 0x00)
	
#define MAGENTA                     RGB2COL(0xFF, 0x00, 0xFF)
#define CYAN                        RGB2COL(0x00, 0xFF, 0xFF)
#define BROWN                  		  RGB2COL(0xA6, 0x7C, 0x51)
#define SILVER                      RGB2COL(0xCC, 0xCC, 0xCC)
#define GOLD                        RGB2COL(0xD7, 0xCD, 0x19)
#define PURPLE                      0xF81F




#include <delay.h> 
#include <stdio.h> 
#include <math.h>

#include "PE & EN font1.h"
#include "FAmap.h"




int font_color,x_font,y_font;
char highlight,fa_num;
char effect = 0 , italic = 0;
unsigned int highlight_color;
/* Global Variables */
int x_base=0;

unsigned char x_text=0,y_text=0;

#pragma used+

void lcd_write_index_register(char);
void lcd_write_wdr(int);
int lcd_read_rdr(void);
void lcd_write_command(int,int);
void lcd_fill(int);
void lcd_imshow(int,int,int,int,const unsigned short *);
void lcd_set_area(int,int,int,int,int,int);
void lcd_set_font_color(int);
void lcd_fa_num(void);
void lcd_en_num(void);
void lcd_font_effect(int);
void lcd_italic_on(void);
void lcd_italic_off(void);
void lcd_put_char(char);
void lcd_put_bold_char(char , int);
void lcd_goto_xy(int,int);
void lcd_text_highlight_on(void);
void lcd_text_highlight_off(void);
void lcd_text_highlight_color(unsigned int);
void lcd_putsf_mix(const unsigned char * , int);

void lcd_clear(void);
void lcd_init(void);
void lcd_write_pixel(int,int,int);
int lcd_read_pixel(int,int);
void lcd_draw_line(int,int,int,int,int);
void lcd_draw_line2(int,int,int,int,int,int);
void lcd_draw_rectangle(int,int,int,int,char,int);
void lcd_draw_round_rectangle(int x0,int y0,int x1,int,int,char,int);
void lcd_draw_circle(int,int,int,char,int);
void lcd_draw_elliptic(int,int,int,int,char,int);
void lcd_write_pic(int,int,flash unsigned short *);
void init_lcd_for_picture(void);
void lcd_gotoxy(int,int);
void lcd_putchar(char,int,char,int);
void lcd_putsf(flash char *,int,char,int);
void lcd_puts(char *,int,char,int);

void lcd_draw_button(int,int,int,int,int,char *);
void lcd_pattern(void);

void unicode2ascii(char * , char *);






//-----------------------------------------------------------------------
	// send a word data to the lcd
//-----------------------------------------------------------------------
void lcd_write_index_register(char ins)
    {
    CS_LOW;
    RS_LOW;
    LCD_DATAPORT_MSB_PORT=0x00; 
    LCD_DATAPORT_LSB_PORT=ins;
    WR_LOW; 
    WR_HIGH;
    CS_HIGH;        
    }
	
//-----------------------------------------------------------------------
	// write a word data into the WDR lcd register
//-----------------------------------------------------------------------
void lcd_write_wdr(int data)
    { 
    CS_LOW;
    RS_HIGH;
    LCD_DATAPORT_MSB_PORT=(data>>8); 
    LCD_DATAPORT_LSB_PORT=data; 
    WR_LOW;
    WR_HIGH;
    CS_HIGH;           
    }
	
//-----------------------------------------------------------------------
	// read data from rdr lcd register
//-----------------------------------------------------------------------
int lcd_read_rdr(void)
    { 
    int data_lsb,data_msb,rdr_data;  
    LCD_DATAPORT_CLEAR;
    LCD_DATAPORT_INPUT;
    RD_LOW;
	WR_HIGH;
	CS_LOW;
    //RS_HIGH;
    data_lsb=LCD_DATAPORT_LSB_PIN;
    data_msb=LCD_DATAPORT_MSB_PIN;
	rdr_data=((data_msb<<8)|data_lsb);
    CS_HIGH;
    RD_HIGH;
	WR_HIGH;
	LCD_DATAPORT_OUTPUT;
    return rdr_data;
    }


//-----------------------------------------------------------------------
	// clears the lcd panel
//-----------------------------------------------------------------------
void lcd_clear_screen(void)
    {  
    unsigned long int counter;
    lcd_write_index_register(TS_INS_GRAM_ADX);
    lcd_write_wdr(0);
    lcd_write_index_register(TS_INS_GRAM_ADY);
    lcd_write_wdr(0);             
    lcd_write_index_register(TS_INS_START_ADX);
    lcd_write_wdr(0);
    lcd_write_index_register(TS_INS_END_ADX);
    #ifdef PORTRAIT
    lcd_write_wdr(239);
    #else
    lcd_write_wdr(319); 
    #endif
    lcd_write_index_register(TS_INS_START_ADY);
    lcd_write_wdr(0);
    lcd_write_index_register(TS_INS_END_ADY);
    #ifdef PORTRAIT
    lcd_write_wdr(319);
    #else
    lcd_write_wdr(239); 
    #endif 
    lcd_write_index_register(TS_INS_RW_GRAM);
    for(counter=0;counter<76800;counter++)
      lcd_write_wdr(0xFFFF); 
    }
//-----------------------------------------------------------------------
	// set background color
//-----------------------------------------------------------------------
void lcd_background_color(int color)
    {  
    unsigned long int counter;
    lcd_write_index_register(TS_INS_GRAM_ADX);
    lcd_write_wdr(0);
    lcd_write_index_register(TS_INS_GRAM_ADY);
    lcd_write_wdr(0);             
    lcd_write_index_register(TS_INS_START_ADX);
    lcd_write_wdr(0);
    lcd_write_index_register(TS_INS_END_ADX);
    #ifdef PORTRAIT
    lcd_write_wdr(239);
    #else
    lcd_write_wdr(319); 
    #endif
    lcd_write_index_register(TS_INS_START_ADY);
    lcd_write_wdr(0);
    lcd_write_index_register(TS_INS_END_ADY);
    #ifdef PORTRAIT
    lcd_write_wdr(319);
    #else
    lcd_write_wdr(239); 
    #endif 
    lcd_write_index_register(TS_INS_RW_GRAM);
    for(counter=0;counter<76800;counter++)
      lcd_write_wdr(color); 
    } 
    
    
//----------------------------------------------------------------------------------------------------
//************************************* ECA 2.8 inch LCD Module **************************************
//----------------------------------------------------------------------------------------------------
// Write A Command 
//----------------------------------------------------------------------------------------------------
void lcd_write_command(int index,int argument)
{
    lcd_write_index_register(index);
    lcd_write_wdr(argument);
}
//----------------------------------------------------------------------------------------------------
//************************************* ECA 2.8 inch LCD Module **************************************
//----------------------------------------------------------------------------------------------------
// Fill the LCD with the specific color
//----------------------------------------------------------------------------------------------------
    void lcd_fill(int color)
{
    int counter;
    
    lcd_write_command(TS_INS_START_ADX,0);
    lcd_write_command(TS_INS_END_ADX,TS_SIZE_X - 1);
    lcd_write_command(TS_INS_GRAM_ADX,0);
    lcd_write_command(TS_INS_START_ADY,0);
    lcd_write_command(TS_INS_END_ADY,TS_SIZE_Y - 1);
    lcd_write_command(TS_INS_GRAM_ADY,0);
      
  lcd_write_index_register(TS_INS_RW_GRAM);
    
  for(counter = 0;counter < 76800;counter++)
    lcd_write_wdr(color);
    
}
//----------------------------------------------------------------------------------------------------
//************************************* ECA 2.8 inch LCD Module **************************************
//----------------------------------------------------------------------------------------------------
// Disply an image on the LCD
// x0,y0 : Start point (left up corner)
// N : Factor of Resizing(1/N). just made the image smaller   N:1,2,3,...
// gray : Show the gray scale version     (Gray:1 , Color:0)
// img : Image to be shown
//----------------------------------------------------------------------------------------------------
    void lcd_imshow(int x0,int y0,int N,int gray,const unsigned short *img)
{
    unsigned int counter=0,X_S=0,Y_S=0,col=0,H,V,DX,DY,raw_counter=0;
    
    
    X_S = (int)*img++;
    Y_S = (int)*img++;
    H = X_S % N;
    V = Y_S % N;
    DX = (unsigned int)(X_S - H)/N;
    DY = (unsigned int)(Y_S - V)/N;
    
    if(x0 < 0)
        x0 = 0;
    if(y0 < 0)
        y0 = 0;
    
    if((x0 + DX) >= TS_SIZE_X) 
        x0 = TS_SIZE_X - DX;
    if((y0 + DY) >= TS_SIZE_Y) 
        y0 = TS_SIZE_Y - DY;
    
    
    lcd_write_command(TS_INS_START_ADX,x0);
    lcd_write_command(TS_INS_END_ADX,x0 + DX - 1);
    lcd_write_command(TS_INS_GRAM_ADX,x0);
    
    
    
        
    #ifdef PORTRAIT
        lcd_write_command(TS_INS_VER_START_AD,y0);
        lcd_write_command(TS_INS_VER_END_AD,y0 + DY - 1);
        lcd_write_command(TS_INS_GRAM_ADY,y0);
  #endif
        
    #ifdef LANDSCAPE
        lcd_write_command(TS_INS_START_ADY,TS_SIZE_Y-(y0 + DY));
        lcd_write_command(TS_INS_END_ADY,TS_SIZE_Y - y0);
        lcd_write_command(TS_INS_GRAM_ADY,TS_SIZE_Y - y0);
  #endif

    
    if(gray)
        for(counter=0;counter<DY;counter++)
        {
            for(raw_counter=0;raw_counter<DX;raw_counter++)
            {
                col = (int)(((*img >> 8) & 0xFF) + ((*img >> 3) & 0xFF) + ((*img << 3) & 0xFF))/3;
                col = RGB2COL(col,col,col);
                lcd_write_command(TS_INS_RW_GRAM,col); 
                img += N;
            }
                img += (((N - 1) * X_S) + H);
        }
    else
        for(counter=0;counter<DY;counter++)
        {
            for(raw_counter=0;raw_counter<DX;raw_counter++)
            {
                lcd_write_command(TS_INS_RW_GRAM,(int)*img); 
                img += N;
            }
                img += (((N - 1) * X_S) + H);
        }
    
    lcd_set_area(0,0,TS_SIZE_X - 1,TS_SIZE_Y - 1,0,0);        
}

//----------------------------------------------------------------------------------------------------
//************************************* ECA 2.8 inch LCD Module **************************************
//----------------------------------------------------------------------------------------------------
// Set the Refreshing area for LCD
//----------------------------------------------------------------------------------------------------
void lcd_set_area(int X0,int Y0,int DX,int DY,int S_X,int S_Y)
{
    lcd_write_command(TS_INS_HOR_START_AD,X0);
    lcd_write_command(TS_INS_HOR_END_AD,(X0 + DX - 1));
    lcd_write_command(TS_INS_GRAM_ADX,S_X);
    lcd_write_command(TS_INS_VER_START_AD,Y0);
    lcd_write_command(TS_INS_VER_END_AD,(Y0 + DY - 1));
    lcd_write_command(TS_INS_GRAM_ADY,S_Y);

}
//----------------------------------------------------------------------------------------------------
//************************************* ECA 2.8 inch LCD Module **************************************
//----------------------------------------------------------------------------------------------------
// Set Farsi font color
//----------------------------------------------------------------------------------------------------
void lcd_set_font_color(int color)
{
    font_color = color;
}
//----------------------------------------------------------------------------------------------------
//************************************* ECA 2.8 inch LCD Module **************************************
//----------------------------------------------------------------------------------------------------
// Set number format to farsi
//----------------------------------------------------------------------------------------------------
void lcd_fa_num(void)
{
    fa_num = 1;
}
//----------------------------------------------------------------------------------------------------
//************************************* ECA 2.8 inch LCD Module **************************************
//----------------------------------------------------------------------------------------------------
// Set number format to english
//----------------------------------------------------------------------------------------------------
void lcd_en_num(void)
{
    fa_num = 0;
}

//----------------------------------------------------------------------------------------------------
//************************************* ECA 2.8 inch LCD Module **************************************
//----------------------------------------------------------------------------------------------------
// Set efect of the farsi font
// ef : effect number            ef:1,2,...,5
//----------------------------------------------------------------------------------------------------
void lcd_font_effect(int ef)
{
    if(ef >= 0 && ef <= 5)
        effect = ef;
}

//----------------------------------------------------------------------------------------------------
//************************************* ECA 2.8 inch LCD Module **************************************
//----------------------------------------------------------------------------------------------------
// Enable Italic effect for farsi font 
//----------------------------------------------------------------------------------------------------
void lcd_italic_on(void)
{
    italic = 1;
}

//----------------------------------------------------------------------------------------------------
//************************************* ECA 2.8 inch LCD Module **************************************
//----------------------------------------------------------------------------------------------------
// Disable Italic effect for farsi font 
//----------------------------------------------------------------------------------------------------
void lcd_italic_off(void)
{
    italic = 0;
}

//----------------------------------------------------------------------------------------------------
//************************************* ECA 2.8 inch LCD Module **************************************
//----------------------------------------------------------------------------------------------------
// Puts a Farsi Character On The LCD Screen      simlpe
//----------------------------------------------------------------------------------------------------
void lcd_put_char(char character)
{
    //x_text
    int counter_x,counter_y;
    char letter_length,flag_p;

    letter_length = font12x16[character][0]>>12;
     for(counter_y=0;counter_y<16;counter_y++)
        for(counter_x=0;counter_x<letter_length;counter_x++)
            {
                flag_p = font12x16[character][counter_y]>>(counter_x);
                flag_p = flag_p&0x01;
                if(flag_p)
                lcd_write_pixel(TS_SIZE_X - 3 -(x_font+(counter_x)),y_font+counter_y,font_color);
                else if(highlight)
                lcd_write_pixel(TS_SIZE_X - 3 -(x_font+(counter_x)),y_font+counter_y,highlight_color);
            }

    x_font += letter_length;
    if(x_font > TS_SIZE_X - 1)
    {
        x_font = x_base;
        y_font += 16;
        if(y_font > TS_SIZE_Y-0)
            y_font = 0;
    }
    
}
    


//----------------------------------------------------------------------------------------------------
//************************************* ECA 2.8 inch LCD Module **************************************
//----------------------------------------------------------------------------------------------------
// Puts a Farsi Character On The LCD Screen with scaling
// size : Scale factor       size:1,2,3,...
//----------------------------------------------------------------------------------------------------
void lcd_put_bold_char(char character , int size)
{
    int counter_x,counter_y,i,j;
    char letter_length,flag_p;
    

    letter_length = font12x16[character][0]>>12;
     for(counter_y=0;counter_y<16;counter_y++)
        for(counter_x=0;counter_x<letter_length;counter_x++)
            {
                flag_p = font12x16[character][counter_y]>>(counter_x);
                flag_p = flag_p&0x01;
                
                
                if(flag_p)
                {
                    
                    if(effect == 0)
                        for(i=0;i<size;i++)
                            for(j=0;j<size;j++)
                                lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) + i -(x_font+(size*counter_x)),y_font+size*counter_y + j,font_color);
                    // Very good effect (1)
                    else if(effect == 1)
                    {
                        // good for size = 2
                        lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) -(x_font+(size*counter_x)),y_font+size*counter_y,font_color);
                        lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) -(x_font+(size*counter_x)),y_font+size*counter_y - 1,font_color);
                        lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) -(x_font+(size*counter_x)),y_font+size*counter_y + 1,font_color);
                        lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) - 1 -(x_font+(size*counter_x)),y_font+size*counter_y,font_color);
                        lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) + 1 -(x_font+(size*counter_x)),y_font+size*counter_y,font_color);
                    }
                    else if(effect == 2)
                    {
                        // good for size = 2
                        lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) -(x_font+(size*counter_x)),y_font+size*counter_y,font_color);
                        lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) -(x_font+(size*counter_x)),y_font+size*counter_y - 1,font_color);
                        lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) -(x_font+(size*counter_x)),y_font+size*counter_y + 1,font_color);
                        lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) - 1 -(x_font+(size*counter_x)),y_font+size*counter_y + 1,font_color);
                        lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) + 1 -(x_font+(size*counter_x)),y_font+size*counter_y + 1,font_color);
                        lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) - 1 -(x_font+(size*counter_x)),y_font+size*counter_y,font_color);
                        lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) + 1 -(x_font+(size*counter_x)),y_font+size*counter_y,font_color);
                        lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) -(x_font+(size*counter_x)),y_font+size*counter_y + 2,font_color);
                    }
                    else if(effect == 3)
                    {
                        // good for size = 3
                        lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) -(x_font+(size*counter_x)),y_font+size*counter_y,font_color);
                        lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) -(x_font+(size*counter_x)),y_font+size*counter_y - 1,font_color);
                        lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) + 1 -(x_font+(size*counter_x)),y_font+size*counter_y - 1,font_color);
                        lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) - 1 -(x_font+(size*counter_x)),y_font+size*counter_y,font_color);
                        lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) + 1 -(x_font+(size*counter_x)),y_font+size*counter_y,font_color);
                        lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) + 2 -(x_font+(size*counter_x)),y_font+size*counter_y,font_color);
                        lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) -(x_font+(size*counter_x)),y_font+size*counter_y + 1,font_color);
                        lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) + 1 -(x_font+(size*counter_x)),y_font+size*counter_y + 1,font_color);
                    }
                    else if(effect == 4)
                    {
            			// good for size = 3
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) -(x_font+(size*counter_x)),y_font+size*counter_y,font_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) -(x_font+(size*counter_x)),y_font+size*counter_y - 1,font_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) + 1 -(x_font+(size*counter_x)),y_font+size*counter_y - 1,font_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) -(x_font+(size*counter_x)),y_font+size*counter_y + 1,font_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) - 1 -(x_font+(size*counter_x)),y_font+size*counter_y + 1,font_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) + 1 -(x_font+(size*counter_x)),y_font+size*counter_y + 1,font_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) + 2 -(x_font+(size*counter_x)),y_font+size*counter_y + 1,font_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) - 1 -(x_font+(size*counter_x)),y_font+size*counter_y,font_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) + 1 -(x_font+(size*counter_x)),y_font+size*counter_y,font_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) + 2 -(x_font+(size*counter_x)),y_font+size*counter_y,font_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) -(x_font+(size*counter_x)),y_font+size*counter_y + 2,font_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) + 1 -(x_font+(size*counter_x)),y_font+size*counter_y + 2,font_color);
					}
					else if(effect == 5)
					{
						// good for size = 1,3
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) -(x_font+(size*counter_x)),y_font+size*counter_y,font_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) -(x_font+(size*counter_x)),y_font+size*counter_y + 1,font_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) + 1 -(x_font+(size*counter_x)),y_font+size*counter_y,font_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) + 1 -(x_font+(size*counter_x)),y_font+size*counter_y + 1,font_color);
					}
					
					//lcd_draw_circle(TS_SIZE_X - 3 -(x_font+(size*counter_x)),y_font+size*counter_y,size,1,font_color);
					
				}
				else if(highlight)
				{
					
						
					if(effect == 0)
						for(i=0;i<size;i++)
							for(j=0;j<size;j++)
								lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) + i -(x_font+(size*counter_x)),y_font+size*counter_y + j,highlight_color);
					// Very good effect (1)
					else if(effect == 1)
					{
						// good for size = 2
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) -(x_font+(size*counter_x)),y_font+size*counter_y,font_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) -(x_font+(size*counter_x)),y_font+size*counter_y - 1,highlight_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) -(x_font+(size*counter_x)),y_font+size*counter_y + 1,highlight_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) - 1 -(x_font+(size*counter_x)),y_font+size*counter_y,highlight_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) + 1 -(x_font+(size*counter_x)),y_font+size*counter_y,highlight_color);
					}
					else if(effect == 2)
					{
						// good for size = 2
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) -(x_font+(size*counter_x)),y_font+size*counter_y,highlight_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) -(x_font+(size*counter_x)),y_font+size*counter_y - 1,highlight_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) -(x_font+(size*counter_x)),y_font+size*counter_y + 1,highlight_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) - 1 -(x_font+(size*counter_x)),y_font+size*counter_y + 1,highlight_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) + 1 -(x_font+(size*counter_x)),y_font+size*counter_y + 1,highlight_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) - 1 -(x_font+(size*counter_x)),y_font+size*counter_y,highlight_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) + 1 -(x_font+(size*counter_x)),y_font+size*counter_y,highlight_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) -(x_font+(size*counter_x)),y_font+size*counter_y + 2,highlight_color);
					}
					else if(effect == 3)
					{
						// good for size = 3
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) -(x_font+(size*counter_x)),y_font+size*counter_y,highlight_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) -(x_font+(size*counter_x)),y_font+size*counter_y - 1,highlight_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) + 1 -(x_font+(size*counter_x)),y_font+size*counter_y - 1,highlight_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) - 1 -(x_font+(size*counter_x)),y_font+size*counter_y,highlight_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) + 1 -(x_font+(size*counter_x)),y_font+size*counter_y,highlight_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) + 2 -(x_font+(size*counter_x)),y_font+size*counter_y,highlight_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) -(x_font+(size*counter_x)),y_font+size*counter_y + 1,highlight_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) + 1 -(x_font+(size*counter_x)),y_font+size*counter_y + 1,highlight_color);
					}
					else if(effect == 4)
					{
						// good for size = 3
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) -(x_font+(size*counter_x)),y_font+size*counter_y,highlight_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) -(x_font+(size*counter_x)),y_font+size*counter_y - 1,highlight_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) + 1 -(x_font+(size*counter_x)),y_font+size*counter_y - 1,highlight_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) -(x_font+(size*counter_x)),y_font+size*counter_y + 1,highlight_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) - 1 -(x_font+(size*counter_x)),y_font+size*counter_y + 1,highlight_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) + 1 -(x_font+(size*counter_x)),y_font+size*counter_y + 1,highlight_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) + 2 -(x_font+(size*counter_x)),y_font+size*counter_y + 1,highlight_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) - 1 -(x_font+(size*counter_x)),y_font+size*counter_y,highlight_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) + 1 -(x_font+(size*counter_x)),y_font+size*counter_y,highlight_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) + 2 -(x_font+(size*counter_x)),y_font+size*counter_y,highlight_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) -(x_font+(size*counter_x)),y_font+size*counter_y + 2,highlight_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) + 1 -(x_font+(size*counter_x)),y_font+size*counter_y + 2,highlight_color);
					}
					else if(effect == 5)
					{
						// good for size = 1,3
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) -(x_font+(size*counter_x)),y_font+size*counter_y,highlight_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) -(x_font+(size*counter_x)),y_font+size*counter_y + 1,highlight_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) + 1 -(x_font+(size*counter_x)),y_font+size*counter_y,highlight_color);
						lcd_write_pixel(TS_SIZE_X - 3 + italic*(-counter_y+7) + 1 -(x_font+(size*counter_x)),y_font+size*counter_y + 1,highlight_color);
					}
						
						
						
					//lcd_draw_circle(TS_SIZE_X - 3 + italic*(-counter_y+7) -(x_font+(size*counter_x)),y_font+size*counter_y,size,1,highlight_color);
					
					
				}
			}

	x_font += size*letter_length;
	if(x_font > TS_SIZE_X - 1)
	{
		x_font = x_base;
		y_font += size*16;
		if(y_font > TS_SIZE_Y-0)
			y_font = 0;
	}
	
}

//----------------------------------------------------------------------------------------------------
//************************************* ECA 2.8 inch LCD Module **************************************
//----------------------------------------------------------------------------------------------------
// Go to a specific pont for farsi font (x:0..TS_SIZE_X , y:0..TS_SIZE_Y)
//----------------------------------------------------------------------------------------------------
void lcd_goto_xy(int x,int y)
{
	if((x >= TS_SIZE_X) || (x < 0))
	{
		x_font = 0;
		x_base = 0;
	}
	else
	{
		x_font = x;
		x_base = x;
	}
	
	if((y >= TS_SIZE_Y) || (y < 0))
		y_font = 0;
	else
		y_font = y;
}
//----------------------------------------------------------------------------------------------------
//************************************* ECA 2.8 inch LCD Module **************************************
//----------------------------------------------------------------------------------------------------
// Enable Farsi font Highlight
//----------------------------------------------------------------------------------------------------
void lcd_text_highlight_on(void)
{
	highlight = 1;
}
//----------------------------------------------------------------------------------------------------
//************************************* ECA 2.8 inch LCD Module **************************************
//----------------------------------------------------------------------------------------------------
// Disable Farsi font Highlight
//----------------------------------------------------------------------------------------------------
void lcd_text_highlight_off(void)
{
	highlight = 0;
}
//----------------------------------------------------------------------------------------------------
//************************************* ECA 2.8 inch LCD Module **************************************
//----------------------------------------------------------------------------------------------------
// Set Farsi font Highlight color
//----------------------------------------------------------------------------------------------------
void lcd_text_highlight_color(unsigned int color)
{
	highlight_color = color;
}
//----------------------------------------------------------------------------------------------------
//************************************* ECA 2.8 inch LCD Module **************************************
//----------------------------------------------------------------------------------------------------
// Show a farsi-englisg string on the LCD with specific size
// size : Scale factor       size:1,2,3,...
//----------------------------------------------------------------------------------------------------
void lcd_putsf_mix(const unsigned char *string , int size)
{
	unsigned char letter,nt_letter,pr_letter;
	unsigned char CN=0,CP=0,pr_CN=0,nt_CP=0,place=0,flag1=0;
	unsigned char letter_counter=0,letter_count=0,length=0,enter=0;
	unsigned char text_buffer[32];


	flag1 = 0;

	while(*string)
	{
		if(*string > 0x80)
		{
			while(*string > 0x80)
			{
				if (flag1 == 0) 
					pr_letter = 0x20;
				else 
					pr_letter = *(string - 1);

				letter = *string++;

				if (*string == 0) 
					nt_letter = 0x20;
				else 
					nt_letter = *string;
				
				flag1 = 1;

				if(letter > 0x98) letter = letter;
				else if(letter == 0x98) letter = 0xBC;
				else if(letter == 0x90) letter = 0xC0;
				else if(letter == 0x8D) letter = 0xBE;
				else if(letter == 0x81) letter = 0xBD;
				else if(letter == 0x8E) letter = 0xBF;

				if(pr_letter > 0x98) pr_letter = pr_letter;
				else if(pr_letter == 0x98) pr_letter = 0xBC;
				else if(pr_letter == 0x90) pr_letter = 0xC0;
				else if(pr_letter == 0x8D) pr_letter = 0xBE;
				else if(pr_letter == 0x81) pr_letter = 0xBD;
				else if(pr_letter == 0x8E) pr_letter = 0xBF;

				if(nt_letter > 0x98) nt_letter = nt_letter;
				else if(nt_letter == 0x98) nt_letter=0xBC;
				else if(nt_letter == 0x90) nt_letter=0xC0;
				else if(nt_letter == 0x8D) nt_letter=0xBE;
				else if(nt_letter == 0x81) nt_letter=0xBD;
				else if(nt_letter == 0x8E) nt_letter=0xBF;
	  


				if(pr_letter > 0x80)
					pr_CN = ((FAmap[(pr_letter - 0xBC)][5]) == 1);
				else
					pr_CN = 0; 
				
				if(nt_letter > 0x80)
					nt_CP = ((FAmap[(nt_letter - 0xBC)][4]) == 1);
				else
					nt_CP = 0;
				
				if(letter > 0x80)
					CP = ((FAmap[(letter - 0xBC)][4]) == 1);
				else 
					CP = 0; 
				
				if(letter > 0x80)
					CN = ((FAmap[(letter-0xBC)][5]) == 1);
				else
					CN = 0;

				CP = pr_CN && CP;
				CN = CN && nt_CP;
				place = (CP << 1) | CN;	
		
				text_buffer[letter_counter++] = FAmap[(letter - 0xBC)][place];

				length += size*(font12x16 [FAmap[(letter - 0xBC)][place]][1]>>12);
			}
	

	
			if(length < TS_SIZE_X - x_font - 3)
				for(letter_count=0;letter_count<letter_counter;letter_count++)
					lcd_put_bold_char(text_buffer[letter_count],size);
			else
			{
			
				x_font = x_base;
				y_font += size*16;
				if(y_font > TS_SIZE_Y - size*16)
					y_font = 0;
				
				for(letter_count=0;letter_count<letter_counter;letter_count++)
					lcd_put_bold_char(text_buffer[letter_count],size);
			}
			letter_counter = 0;
			length = 0;
		}	 		
		else if(*string == 0x20)   //Space detect
			lcd_put_bold_char(*string++,size);
		else   //English letter & Number & Enter detect
		{	
			if(*string == 0x0D)   //Enter detect
			{
				x_font = x_base;
				y_font += size*16;
				if(y_font > TS_SIZE_Y - size*16)
					y_font = 0;
				
				string += 2;
				goto p1;
			}	
			//letter_counter = 0;
			while((*string < 0x81) && (*(string+1) < 0x81) && (*string != 0x00))
			{

				if(fa_num)
				{
					if((*string > 0x2F) && (*string < 0x3A)  && (*string != 0x00))	
					{
						letter = (*string) - 0x20;
						text_buffer[letter_counter++] = letter;
						string++;
						goto P2;
					} 
				}		
				text_buffer[letter_counter++] = *string++;
				P2:
				if((*string == 0x20) && ((letter_counter * size*8) < (TS_SIZE_X - x_font - 1)))
					flag1 = letter_counter;
	
				if((letter_counter * size*8) > (TS_SIZE_X - x_font - 1))
				{
					string -= (letter_counter - flag1 + 1);
					letter_counter = flag1 - 1;
					enter = 1;

					break;
				}
			
			}
			if((letter_counter * size*8) < (TS_SIZE_X - x_font - 1))
			{
				for(letter_count=(letter_counter);letter_count>0;letter_count--)
					lcd_put_bold_char(text_buffer[letter_count - 1],size);
			
				if(enter)
				{
					enter = 0;
					x_font = x_base;
					y_font += size*16;
					if(y_font > TS_SIZE_Y - size*16)
						y_font = 0;
				}
			}
			p1:
			letter_counter = 0;
			flag1 = 0; 

		}
	}
	flag1 = 0;

}


//----------------------------------------------------------------------------------------------------
//************************************* ECA 2.8 inch LCD Module **************************************
//----------------------------------------------------------------------------------------------------
// Make an ascii string from an unicode string 
//----------------------------------------------------------------------------------------------------
void unicode2ascii(char *uni_str , char *ascii_str)
{
	int counter = 0;
	int Uch = 0;
	char chl,chh;
	
	
	while(*uni_str) 
	{
		chl = *uni_str++; 
		chh = *uni_str++;
		
		Uch = 0;
		Uch = ((Uch | chh) << 8) | chl;
		
		if(Uch > 1574 && Uch < 1591)
			*(ascii_str + counter) = (char)(Uch - 1376);
		else if(Uch > 1590 && Uch < 1595)
			*(ascii_str + counter) = (char)(Uch - 1375);
		else if(Uch > 1600 && Uch < 1603)
			*(ascii_str + counter) = (char)(Uch - 1380);
		else if(Uch == 1705)
			*(ascii_str + counter) = (char)(Uch - 1482);
		else if(Uch == 1604)
			*(ascii_str + counter) = (char)(Uch - 1379);
		else if(Uch > 1604 && Uch < 1609)
			*(ascii_str + counter) = (char)(Uch - 1378);
		else if(Uch == 1740)
			*(ascii_str + counter) = (char)(Uch - 1503);
		else if(Uch == 1574)
			*(ascii_str + counter) = (char)(Uch - 1381);
		else if(Uch == 1662)
			*(ascii_str + counter) = (char)(Uch - 1533);
		else if(Uch == 1670)
			*(ascii_str + counter) = (char)(Uch - 1529);
		else if(Uch == 1688)
			*(ascii_str + counter) = (char)(Uch - 1546);
		else if(Uch == 1711)
			*(ascii_str + counter) = (char)(Uch - 1567);
		else if(Uch == 1570)
			*(ascii_str + counter) = (char)(Uch - 1376);
		else if(Uch > 1631 && Uch < 1642)
			*(ascii_str + counter) = (char)(Uch - 1584);
		else if(Uch == 65536)
			*(ascii_str + counter) = NULL;
		else
			*(ascii_str + counter) = (char) Uch;
		
		
		counter++;
		
	}
	*(ascii_str + counter) = NULL;
	
}


	
	
//----------------------------------------------------------------------------------------------------
//************************************* ECA 2.8 inch LCD Module **************************************
//----------------------------------------------------------------------------------------------------
// Clear The LCD Screen
//----------------------------------------------------------------------------------------------------
void lcd_clear(void)
{
	lcd_fill(WHITE);
}

	
//-----------------------------------------------------------------------	
	// lcd initialization
//-----------------------------------------------------------------------	
void lcd_init(void)
    { 
    LCD_CONTROLPORT_PORT=(1<<LCD_RST_PIN)|(1<<LCD_RS_PIN)|(1<<LCD_CS_PIN)|(1<<LCD_RD_PIN)|(1<<LCD_WR_PIN);
    LCD_CONTROLPORT_DDR=(1<<LCD_RST_PIN)|(1<<LCD_RS_PIN)|(1<<LCD_CS_PIN)|(1<<LCD_RD_PIN)|(1<<LCD_WR_PIN);
    LCD_DATAPORT_OUTPUT;
          
    // reset lcd chipset
    LCD_RST_PORT.LCD_RST_PIN=LOW;
    delay_ms(1);           
    LCD_RST_PORT.LCD_RST_PIN=HIGH;          
    
    lcd_write_index_register(0x00E3);
    lcd_write_wdr(0x3008);                     //set the internal timing
    lcd_write_index_register(0x00E7);
    lcd_write_wdr(0x0012);                     //set the internal timing
    lcd_write_index_register(0x00EF);
    lcd_write_wdr(0x1231);                     //set the internal timing
    lcd_write_index_register(TS_INS_START_OSC);
    lcd_write_wdr(0x0001);                     //start oscillator
    //if(lcd_read_rdr()==0x9325) {DDRB.7=1;PORTB.7=1;}
    delay_ms(50);

    lcd_write_index_register(TS_INS_DRIV_OUT_CTRL);
    lcd_write_wdr(0x0100);                     //set SS, SM
    lcd_write_index_register(TS_INS_DRIV_WAV_CTRL);
    lcd_write_wdr(0x0700);                     //set 1 line inversion
    
    lcd_write_index_register(TS_INS_ENTRY_MOD);
    lcd_write_wdr(TS_VAL_ENTRY_MOD);            //set GRAM write direction, BGR=0

    lcd_write_index_register(TS_INS_RESIZE_CTRL);
    lcd_write_wdr(0x0000);                     //no resizing

    lcd_write_index_register(TS_INS_DISP_CTRL2);
    lcd_write_wdr(0x0202);                     //front & back porch periods = 2
    lcd_write_index_register(TS_INS_DISP_CTRL3);
    lcd_write_wdr(0x0000);                     
    lcd_write_index_register(TS_INS_DISP_CTRL4);
    lcd_write_wdr(0x0000);                     
    lcd_write_index_register(TS_INS_RGB_DISP_IF_CTRL1);
    lcd_write_wdr(0x0000);                     //select system interface                
    lcd_write_index_register(TS_INS_FRM_MARKER_POS);
    lcd_write_wdr(0x0000);                     
    lcd_write_index_register(TS_INS_RGB_DISP_IF_CTRL2);
    lcd_write_wdr(0x0000);                    
    
    lcd_write_index_register(TS_INS_POW_CTRL1);
    lcd_write_wdr(0x0000);
    lcd_write_index_register(TS_INS_POW_CTRL2);
    lcd_write_wdr(0x0007);                     
    lcd_write_index_register(TS_INS_POW_CTRL3);
    lcd_write_wdr(0x0000);
    lcd_write_index_register(TS_INS_POW_CTRL4);
    lcd_write_wdr(0x0000);                     
    delay_ms(200);

    lcd_write_index_register(TS_INS_POW_CTRL1);
    lcd_write_wdr(0x1690);
    lcd_write_index_register(TS_INS_POW_CTRL2);
    lcd_write_wdr(0x0007); //lcd_write_wdr(0x0137);                     
    delay_ms(50);

    lcd_write_index_register(TS_INS_POW_CTRL3);
    lcd_write_wdr(0x001A); //lcd_write_wdr(0x013C);
    delay_ms(50);

    lcd_write_index_register(TS_INS_POW_CTRL4);
    lcd_write_wdr(0x1800); //lcd_write_wdr(0x1400);
    lcd_write_index_register(TS_INS_POW_CTRL7);
    lcd_write_wdr(0x002A); //lcd_write_wdr(0x0007);
    delay_ms(50);

    lcd_write_index_register(TS_INS_GRAM_HOR_AD);
    lcd_write_wdr(0x0000);
    lcd_write_index_register(TS_INS_GRAM_VER_AD);
    lcd_write_wdr(0x0000);

    lcd_write_index_register(TS_INS_GAMMA_CTRL1);
    lcd_write_wdr(0x0000);
    lcd_write_index_register(TS_INS_GAMMA_CTRL2);
    lcd_write_wdr(0x0000);
    lcd_write_index_register(TS_INS_GAMMA_CTRL3);
    lcd_write_wdr(0x0000);
    lcd_write_index_register(TS_INS_GAMMA_CTRL4);
    lcd_write_wdr(0x0000);
    lcd_write_index_register(TS_INS_GAMMA_CTRL5);
    lcd_write_wdr(0x0000);
    lcd_write_index_register(TS_INS_GAMMA_CTRL6);
    lcd_write_wdr(0x0406);
    lcd_write_index_register(TS_INS_GAMMA_CTRL7);
    lcd_write_wdr(0x0006);
    lcd_write_index_register(TS_INS_GAMMA_CTRL8);
    lcd_write_wdr(0x0404);
    lcd_write_index_register(TS_INS_GAMMA_CTRL9);
    lcd_write_wdr(0x0700);
    lcd_write_index_register(TS_INS_GAMMA_CTRL10);
    lcd_write_wdr(0x0A08);

    lcd_write_index_register(TS_INS_HOR_START_AD);
    lcd_write_wdr(0x0000);
    lcd_write_index_register(TS_INS_HOR_END_AD);
    lcd_write_wdr(0x00EF);
    lcd_write_index_register(TS_INS_VER_START_AD);
    lcd_write_wdr(0x0000);
    lcd_write_index_register(TS_INS_VER_END_AD);
    lcd_write_wdr(0x013F);
    lcd_write_index_register(TS_INS_GATE_SCAN_CTRL1);
    lcd_write_wdr(0xA700);
    lcd_write_index_register(TS_INS_GATE_SCAN_CTRL2);
    lcd_write_wdr(0x0001);
    lcd_write_index_register(TS_INS_GATE_SCAN_CTRL3);
    lcd_write_wdr(0x0000);

    lcd_write_index_register(TS_INS_PART_IMG1_DISP_POS);
    lcd_write_wdr(0x0000);
    lcd_write_index_register(TS_INS_PART_IMG1_START_AD);
    lcd_write_wdr(0x0000);
    lcd_write_index_register(TS_INS_PART_IMG1_END_AD);
    lcd_write_wdr(0x0000);
    lcd_write_index_register(TS_INS_PART_IMG2_DISP_POS);
    lcd_write_wdr(0x0000);
    lcd_write_index_register(TS_INS_PART_IMG2_START_AD);
    lcd_write_wdr(0x0000);
    lcd_write_index_register(TS_INS_PART_IMG2_END_AD);
    lcd_write_wdr(0x0000);

    lcd_write_index_register(TS_INS_PANEL_IF_CTRL1);
    lcd_write_wdr(0x0010);
    lcd_write_index_register(TS_INS_PANEL_IF_CTRL2);
    lcd_write_wdr(0x0000);
    lcd_write_index_register(TS_INS_PANEL_IF_CTRL3);
    lcd_write_wdr(0x0003);
    lcd_write_index_register(TS_INS_PANEL_IF_CTRL4);
    lcd_write_wdr(0x0110);
    lcd_write_index_register(TS_INS_PANEL_IF_CTRL5);
    lcd_write_wdr(0x0000);
    lcd_write_index_register(TS_INS_PANEL_IF_CTRL6);
    lcd_write_wdr(0x0000);

    lcd_write_index_register(TS_INS_DISP_CTRL1);
    lcd_write_wdr(0x0133);
    
    lcd_write_index_register(TS_INS_FRM_RATE_COL_CTRL);
    lcd_write_wdr(0x000D);
    
    lcd_clear_screen();
    }
	
//-----------------------------------------------------------------------
	// turn on a pixel on the lcd screen
//-----------------------------------------------------------------------
void lcd_write_pixel(int x,int y,int color)
    { 
    #ifdef LANDSCAPE
    y=239-y;
    #endif
    lcd_write_index_register(TS_INS_GRAM_ADX);
    lcd_write_wdr(x); 
    lcd_write_index_register(TS_INS_GRAM_ADY);
    lcd_write_wdr(y);
    lcd_write_index_register(TS_INS_START_ADX);
    lcd_write_wdr(x);
    lcd_write_index_register(TS_INS_END_ADX);
    lcd_write_wdr(x); 
    lcd_write_index_register(TS_INS_START_ADY);
    lcd_write_wdr(y);
    lcd_write_index_register(TS_INS_END_ADY);
    lcd_write_wdr(y); 
    lcd_write_index_register(TS_INS_RW_GRAM);
    lcd_write_wdr(color);
    }
//-----------------------------------------------------------------------
	// Read A Pixel Color On The LCD Screen
//-----------------------------------------------------------------------
int lcd_read_pixel(int x,int y)
    { 
		int pixel;
    #ifdef LANDSCAPE
    y=239-y;
    #endif
    lcd_write_index_register(TS_INS_GRAM_ADX);
    lcd_write_wdr(x); 
    lcd_write_index_register(TS_INS_GRAM_ADY);
    lcd_write_wdr(y);
    lcd_write_index_register(TS_INS_START_ADX);
    lcd_write_wdr(x);
    lcd_write_index_register(TS_INS_END_ADX);
    lcd_write_wdr(x); 
    lcd_write_index_register(TS_INS_START_ADY);
    lcd_write_wdr(y);
    lcd_write_index_register(TS_INS_END_ADY);
    lcd_write_wdr(y); 
    lcd_write_index_register(TS_INS_RW_GRAM);
	pixel=lcd_read_rdr();
    return pixel;
    }

//-----------------------------------------------------------------------
	// draw a line with x0,y0 and x1,y1 coordinates
//-----------------------------------------------------------------------	
void lcd_draw_line(int x0,int y0,int x1,int y1,int color) 
    {
    int dy=y1-y0;
    int dx=x1-x0;
    int stepx,stepy;
    if(dy<0) {dy=-dy;stepy=-1;} else {stepy=1;}
    if(dx<0) {dx=-dx;stepx=-1;} else {stepx=1;}
    dy<<=1; 
    dx<<=1; 
    lcd_write_pixel(x0,y0,color);
    if(dx>dy) 
      {
      int fraction=dy-(dx>>1); 
      while(x0!=x1) 
        {
        if(fraction>=0) 
          {
          y0+=stepy;
          fraction-=dx; 
          }
        x0+=stepx;
        fraction+=dy; 
        lcd_write_pixel(x0,y0,color);
        }
      } 
    else 
      {
      int fraction=dx-(dy>>1);
      while (y0 != y1) 
        {
        if(fraction>=0) 
          {
          x0+=stepx;
          fraction-=dy;
          }
        y0+=stepy;
        fraction+=dx;
        lcd_write_pixel(x0,y0,color);
        }
      }
    }
//-----------------------------------------------------------------------
	// draw a fill(1) or no fill(0) rectangular with specified color    
//-----------------------------------------------------------------------	
void lcd_draw_rectangle(int x0,int y0,int x1,int y1,char fill,int color)
    { 
    if(fill)
      {
      unsigned int counter_x; 
      unsigned char counter_y; 
      
      lcd_write_index_register(TS_INS_GRAM_ADX);
      lcd_write_wdr(x0);
      lcd_write_index_register(TS_INS_GRAM_ADY);
      lcd_write_wdr(y0);  
      lcd_write_index_register(TS_INS_START_ADX);
      lcd_write_wdr(x0);
      lcd_write_index_register(TS_INS_END_ADX);
      lcd_write_wdr(x1);
      #ifdef PORTRAIT
      lcd_write_index_register(TS_INS_START_ADY);
      lcd_write_wdr(y0);
      lcd_write_index_register(TS_INS_END_ADY);
      lcd_write_wdr(y1); 
      #else
      lcd_write_index_register(TS_INS_START_ADY);
      lcd_write_wdr(239-y1);
      lcd_write_index_register(TS_INS_END_ADY);
      lcd_write_wdr(239-y0);
      #endif  
      lcd_write_index_register(TS_INS_RW_GRAM);
      for(counter_y=y0;counter_y<=y1;counter_y++)
        {
        for(counter_x=x0;counter_x<=x1;counter_x++)
          lcd_write_wdr(color);
        }  
      } 
    else
      {
      lcd_draw_line(x0,y0,x1,y0,color);
      lcd_draw_line(x1,y0,x1,y1,color);
      lcd_draw_line(x1,y1,x0,y1,color); 
      lcd_draw_line(x0,y1,x0,y0,color);
      }
    }
//-----------------------------------------------------------------------
	// draw a fill(1) or no fill(0) circle with specified color 
//-----------------------------------------------------------------------	
void lcd_draw_circle(int x0,int y0,int radius,char fill,int color) 
    { 
    int x_offset,y_offset,error; 
    x_offset=0; 
    y_offset=radius; 
    error=1-radius; 

    do 
      { 
      if(fill) 
        { 
        lcd_draw_line(x0-x_offset,y0+y_offset,x0+x_offset,y0+y_offset,color); 
        lcd_draw_line(x0-x_offset,y0-y_offset,x0+x_offset,y0-y_offset,color); 
        lcd_draw_line(x0-y_offset,y0+x_offset,x0+y_offset,y0+x_offset,color); 
        lcd_draw_line(x0-y_offset,y0-x_offset,x0+y_offset,y0-x_offset,color); 
        } 
      else 
        { 
        lcd_write_pixel(x_offset+x0,y_offset+y0,color); 
        lcd_write_pixel(y_offset+x0,x_offset+y0,color); 
        lcd_write_pixel(x0-x_offset,y_offset+y0,color); 
        lcd_write_pixel(x0-y_offset,x_offset+y0,color); 
        lcd_write_pixel(y_offset+x0,y0-x_offset,color); 
        lcd_write_pixel(x_offset+x0,y0-y_offset,color); 
        lcd_write_pixel(x0-x_offset,y0-y_offset,color); 
        lcd_write_pixel(x0-y_offset,y0-x_offset,color); 
        } 

      if(error<0) 
        error+=(3+(2*(x_offset++))); 
      else 
        error+=(5+(2*((x_offset++)-(y_offset--)))); 
      }while(x_offset<=y_offset); 
    } 

//-----------------------------------------------------------------------
	// Show A Picture On The LCD Screen
//-----------------------------------------------------------------------
void lcd_write_pic(int x,int y,flash unsigned short *pointer)
     {
     unsigned long int counter,compare_value=(unsigned long int)pointer[0]*pointer[1];
     lcd_write_index_register(TS_INS_GRAM_ADX);
     lcd_write_wdr(x); 
     lcd_write_index_register(TS_INS_START_ADX);
     lcd_write_wdr(x);
     lcd_write_index_register(TS_INS_END_ADX);
     lcd_write_wdr(x+pointer[0]-1);   
     #ifdef PORTRAIT
     lcd_write_index_register(TS_INS_GRAM_ADY);
     lcd_write_wdr(y);
     lcd_write_index_register(TS_INS_START_ADY);
     lcd_write_wdr(y);
     lcd_write_index_register(TS_INS_END_ADY);
     lcd_write_wdr(y+pointer[1]-1);
     #else     
     lcd_write_index_register(TS_INS_GRAM_ADY);
     lcd_write_wdr(239-y);
     lcd_write_index_register(TS_INS_START_ADY);
     lcd_write_wdr(239-(y+pointer[1]));
     lcd_write_index_register(TS_INS_END_ADY);
     lcd_write_wdr(239-y);
     #endif 
     lcd_write_index_register(TS_INS_RW_GRAM);  
     for(counter=0,pointer+=2;counter<compare_value;counter++,pointer++)
       lcd_write_wdr(*pointer);
     }





//----------------------------------------------------------------------------------------------------
//************************************* ECA 2.8 inch LCD Module **************************************
//----------------------------------------------------------------------------------------------------
// Puts A Character On The LCD Screen
//----------------------------------------------------------------------------------------------------
void lcd_putchar(char character,int forground_color,char transparent_mode,int background_color)
{  
    int width_counter,length_counter;
    char character_segment_data;
	
    for(length_counter=0;length_counter<16;length_counter++)
    {
      character_segment_data = (char)(font12x16[character][length_counter] & 0xFF);
      for(width_counter=0;width_counter<8;width_counter++)
      {
        if(character_segment_data & (0x80 >> width_counter)) 
          lcd_write_pixel((x_text*8) + width_counter,(y_text*16) + length_counter,forground_color);
		    else
			  {
			    if(!transparent_mode)
						lcd_write_pixel((x_text*8) + width_counter,(y_text*16) + length_counter,background_color);
					else
						lcd_write_pixel((x_text*8) + width_counter,(y_text*16) + length_counter,lcd_read_pixel((x_text*8) + width_counter,(y_text*16) + length_counter));
			  };
			};
    };
    
    if(++x_text >= TS_SIZE_X/8)
    {            
      x_text = 0;
      if(++y_text >= TS_SIZE_Y/16) 
				y_text = 0;
    };
}  


//-----------------------------------------------------------------------	
	// Show A String That Stored In The Flash Memory Of The Microcontroller  
//-----------------------------------------------------------------------	
void lcd_putsf(flash char *string,int forground_color,char background_color_activation,int background_color)
    {
    while(*string)
      lcd_putchar(*string++,forground_color,background_color_activation,background_color);
    }
//-----------------------------------------------------------------------	
	// Show A String That Stored In The SRAM Of The Microcontroller    
//-----------------------------------------------------------------------	
void lcd_puts(char *string,int forground_color,char background_color_activation,int background_color)
    {
    while(*string)
      lcd_putchar(*string++,forground_color,background_color_activation,background_color);
    }





//----------------------------------------------------------------------------------------------------
//************************************* ECA 2.8 inch LCD Module **************************************
//----------------------------------------------------------------------------------------------------
// Draw A Line With X0,Y0(Origin) And d,l,alpha 
// alpha in degree
// distance from origin
// length of line
//----------------------------------------------------------------------------------------------------
void lcd_draw_line2(int x0,int y0,int d,int l,int alpha,int color) 
{
	float alpha1,teta,r;
	int x1,x2,y1,y2;
	
	alpha1 = (float)(360 - alpha) * 3.14 / 180;
	
	teta = atan((float)(l/2)/d);
	r = sqrt(d*d + l*l/4);
	
	x1 = r*cos(alpha1 - teta) + x0;
	y1 = r*sin(alpha1 - teta) + y0;
	x2 = r*cos(alpha1 + teta) + x0;
	y2 = r*sin(alpha1 + teta) + y0;
	
	lcd_draw_line(x1,y1,x2,y2,color);
	
	
}

//----------------------------------------------------------------------------------------------------
//************************************* ECA 2.8 inch LCD Module **************************************
//----------------------------------------------------------------------------------------------------
// Description	: Draws a beveled figure on the screen. 
// Input       	: x0, y0 - coordinate position of the upper left center
//		      		: x1, y1 - coordinate position of the lower right center
//             	: rad    - defines the redius of the circle,
//             	: fill   - fill yes or no
//----------------------------------------------------------------------------------------------------
void lcd_draw_round_rectangle(int x0,int y0,int x1,int y1,int rad,char fill,int color)
{
	signed int a,b,P;

	a = 0;       				// increment by 1
	b = rad;  				// decrement by 1 using P
	P = 1 - rad;


	if (fill)
	{		
		lcd_draw_rectangle(x0,y0+rad,x1,y1-rad,1,color);
		
		do
		{
			lcd_draw_rectangle(x0-a+rad,y0-b+rad,a+x1-rad,y0-b+rad,1,color);	// 8 --> 1
			lcd_draw_rectangle(x0-b+rad,y0-a+rad,b+x1-rad,y0-a+rad,1,color);	// 7 --> 2
			lcd_draw_rectangle(x0-b+rad,a+y1-rad,b+x1-rad,a+y1-rad,1,color);	// 6 --> 3
			lcd_draw_rectangle(x0-a+rad,b+y1-rad,a+x1-rad,b+y1-rad,1,color);	// 5 --> 4

			if(P < 0)
				P+= 3 + 2*a++;
			else	
				P+= 5 + 2*(a++ - b--);
			
		} while(a <= b);
	} //fill
	else
	{
		lcd_draw_rectangle(x0+rad,y0,x1-rad,y0,1,color);	// top
		lcd_draw_rectangle(x0+rad,y1,x1-rad,y1,1,color);	// bottom
		lcd_draw_rectangle(x0,y0+rad,x0,y1-rad,1,color);	// left
		lcd_draw_rectangle(x1,y0+rad,x1,y1-rad,1,color);	// right

		do
		{
			lcd_write_pixel(a+x1-rad,y0-b+rad,color);	// `````` Segment 1
			lcd_write_pixel(b+x1-rad,y0-a+rad,color);	// `````` Segment 2
			
			lcd_write_pixel(b+x1-rad,a+y1-rad,color);	// `````` Segment 3
			lcd_write_pixel(a+x1-rad,b+y1-rad,color);	// `````` Segment 4
			
			lcd_write_pixel(x0-a+rad,b+y1-rad,color);	// `````` Segment 5
			lcd_write_pixel(x0-b+rad,a+y1-rad,color);	// `````` Segment 6
			
			lcd_write_pixel(x0-b+rad,y0-a+rad,color);	// `````` Segment 7
			lcd_write_pixel(x0-a+rad,y0-b+rad,color);	// `````` Segment 8
			
			if(P < 0)
				P += 3 + 2*a++;
			else				
				P += 5 + 2*(a++ - b--);
		} while(a <= b);
	} //no fill
}	//RoundRectangle


//----------------------------------------------------------------------------------------------------
//************************************* ECA 2.8 inch LCD Module **************************************
//----------------------------------------------------------------------------------------------------
// Draw A Fill(1) Or No Fill(0) Elliptic With Specified Color
//----------------------------------------------------------------------------------------------------
void lcd_draw_elliptic(int x0,int y0,int a,int b,char fill,int color)
{
	int x11,x12,x21,x22,y1,y2;
	
	for(y1=y0-b;y1<y0+b;y1++)
	{
		y2 = y1 + 1;
		x11 = x0 - (float)a*sqrt(1.0 - (float)(y1 - y0)*(y1 - y0)/(b*b));
		x12 = x0 - (float)a*sqrt(1.0 - (float)(y2 - y0)*(y2 - y0)/(b*b));
		if((x11 >= 0) && (x11 < TS_SIZE_X) && (x12 >= 0) && (x12 < TS_SIZE_X))
			lcd_draw_line(x11,y1,x12,y2,color);
			
		x21 = x0 + (float)a*sqrt(1.0 - (float)(y1 - y0)*(y1 - y0)/(b*b));
		x22 = x0 + (float)a*sqrt(1.0 - (float)(y2 - y0)*(y2 - y0)/(b*b));
		if((x21 >= 0) && (x21 < TS_SIZE_X) && (x22 >= 0) && (x22 < TS_SIZE_X))
			lcd_draw_line(x21,y1,x22,y2,color);
			
		if(fill)	
			if((x21 >= 0) && (x21 < TS_SIZE_X) && (x22 >= 0) && (x22 < TS_SIZE_X) && (x11 >= 0) && (x11 < TS_SIZE_X) && (x12 >= 0) && (x12 < TS_SIZE_X))
				lcd_draw_rectangle(x11,y1,x22,y2,1,color);
	}
	
}


//----------------------------------------------------------------------------------------------------
//************************************* ECA 2.8 inch LCD Module **************************************
//----------------------------------------------------------------------------------------------------
// init lcd for send a high speed picture
//----------------------------------------------------------------------------------------------------
void init_lcd_for_picture(void)
{
	
  lcd_write_command(TS_INS_START_ADX,0x0000);
  lcd_write_command(TS_INS_END_ADX,0x00EF);
  lcd_write_command(TS_INS_GRAM_ADX,0x0000);

  lcd_write_command(TS_INS_START_ADY,0x0000);
  lcd_write_command(TS_INS_END_ADY,0x013F);
	lcd_write_command(TS_INS_GRAM_ADY,0x0000);
	
	lcd_write_index_register(TS_INS_RW_GRAM);
}
		   
       
//----------------------------------------------------------------------------------------------------
//************************************* ECA 2.8 inch LCD Module **************************************
//----------------------------------------------------------------------------------------------------
// This Functions Goes The Cursor To X And Y Positions
//----------------------------------------------------------------------------------------------------                
void lcd_gotoxy(int x,int y)
{
  if(x >= TS_SIZE_X/8 || y >= TS_SIZE_Y/16) 
  {
    y += x / TS_SIZE_X / 8;
    x %= TS_SIZE_X / 8;
  }
  x_text = x;
  y_text = y;
}



//----------------------------------------------------------------------------------------------------
//************************************* ECA 2.8 inch LCD Module **************************************
//----------------------------------------------------------------------------------------------------
// Show a button with specific string on it 
//---------------------------------------------------------------------------------------------------- 
void lcd_draw_button(int x0,int y0,int x1,int y1,int font_color,char *string)
{
	int width_counter,length_counter,xx=0;
	char character_segment_data,character,s=0;
	
	lcd_draw_rectangle(x0,y0,x1,y0+(y1-y0)/2,1,28|28<<11|55<<5);
	lcd_draw_rectangle(x0,y0+(y1-y0)/2,x1,y1,1,23|23<<11|48<<5);
	lcd_draw_rectangle(x0-1,y0-1,x1+1,y1+1,0,0);
	lcd_draw_rectangle(x0,y0,x1,y1,0,3|18<<11|16<<5);
	lcd_draw_rectangle(x0+1,y0+1,x1-1,y1-1,0,7|27<<11|46<<5);

	
	character = string[0];
	while(character)
	{
		character = string[s];
		s++;
	}
	while(*string)
	{
		character = *string++;
	  for(length_counter=0;length_counter<16;length_counter++)
		{
			character_segment_data = (font12x16[character][length_counter] & 0xFF);
	    for(width_counter=0;width_counter<8;width_counter++)
	      if(character_segment_data & (0x80 >> width_counter))
	        lcd_write_pixel(width_counter + xx + x0 + 4 + ((x1 - x0) - (s*8))/2,length_counter + y0 +((y1 - y0)/2) - 6,font_color);
	  }
		xx += 8;
	}
	
	
	//lcd_goto_xy(((x1 - x0) - (s*8))/2,(y1 - y0)/2);
	
}

//----------------------------------------------------------------------------------------------------
//************************************* ECA 2.8 inch LCD Module **************************************
//----------------------------------------------------------------------------------------------------
// Show Color Pattern
//---------------------------------------------------------------------------------------------------- 
void lcd_pattern(void)
{
	int a,R,G,B,b;
	
	for(b=0;b<160;b++)
		for(a=239;a>=0;a--)
		{
			R = (int)255/160*(160-b)*(239-a)/150;
			G = (int)255/160*(b)*(239-a)/150;
			lcd_write_pixel(a,b,RGB2COL(R,G,0));
		}
	
	for(b=0;b<160;b++)
		for(a=239;a>=0;a--)
		{
			G = (int)255/160*(160-b)*(239-a)/150;
			B = (int)255/160*(b)*(239-a)/150;
			lcd_write_pixel(a,b+160,RGB2COL(0,G,B));
		}
	
}



#pragma used-
