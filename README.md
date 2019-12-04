# ili9325_MMC
Run a SD card and a Graphic Display to show Pictures using AVR microcontrollers. 


- **Microcontroller : ATmega32**

- **Display: ili9325**

- **External Memory: MMC_SD card**


To those who want to assemble the project before understanding the codes and stuff:

*Requirements*: 

- Two BreadBoards

- One AVR ATmega32 Microcontroller

- One 16MHz Crystal

- One ili9325 (2.8") Display (Nokia N96 screen)

- One SD Card module

- some wire
    
Assemble the circuit as shown in the schematic file.
And also there is a picture of the assembled project to know how it would be like.


<img src="https://github.com/Dehghanni/ili9325_MMC/blob/master/Assembled.jpg" alt="Schematic" width="400" height="300" border="10" /><img src="https://github.com/Dehghanni/ili9325_MMC/blob/master/Schematic.png" alt="Schematic" width="400" height="300" border="10" />

Finally you can program the microcontroller by the provided hex file and put your pictures on the SD card and hook it up. (Notice that you have to format your memory card in __fat32__)

Some dependencies are included that are licensed under different terms:

http://elm-chan.org/fsw/ff/00index_e.html

You can download the pff library files from here:

http://soran111.persiangig.com/document/SD_Driver.rar/dl

Turn it on and enjoy ;)
