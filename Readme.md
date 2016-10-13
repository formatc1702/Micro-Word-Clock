#Micro Word Clock v2

##Description
A tiny replica of the famous Word Clock, using only an ATmega microcontroller, a DS1307 Real Time Clock and a few passive components to display the time on an 8x8 LED matrix. The letters have been printed onto a transparent sheet and glued over the LEDs to produce a readable time.
See the YouTube video [here](https://www.youtube.com/watch?v=9ko9CeylUTs).

##Directory structure
- **MicroWordClock2-Arduino** contains the firmware, including pin definitions for the LED matrix and location of the words in each language.
- **EAGLE** contains the schematic and PCB design files for the proejct.
- **Graphics** contains the design for the transparency sheet to place over the LED matrix to form the words, designed in Inkscape. Contributions in more languages are welcome!

##Bill of Materials
|            | Part name          | Package size                 | [Reichelt](www.reichelt.de) part number                                                                                       |   |
|------------|--------------------|------------------------------|-------------------------------------------------------------------------------------------------------------------------------|---|
| IC1        | ATmega328P-AU      | TQFP-32                      | ATMEGA 328P-AU                                                                                                                |   |
| IC2        | DS1307Z+           |                              | DS 1307Z                                                                                                                      |   |
| C1         | 220nF ceramic      | 2012 metric / 0805 imperial  | X7R-G0805 0,22µ                                                                                                               |   |
| C2         | 2.2uF tantalum     | 3528 metric / B-case         | SMD TAN.2,2/20                                                                                                                |   |
| S1         | SMD push button    | 6.2x6.5mm                    | TASTER 9314                                                                                                                   |   |
| XTAL       | 32.768 kHz crystal | 3216 metric / 1206 imperial  | 32,768 CC7V-12,5                                                                                                              |   |
<<<<<<< HEAD
| LED matrix |  8x8 matrix        | 20x20mm                      | [GYXM-788ASR](http://eud.dx.com/product/lson-788-8-x-8-red-led-display-dot-matrix-module-black-white-844302671) (DealExtreme) |   |
| PCB        |                    |                              | [OshPark](https://oshpark.com/shared_projects/NkANAgow)                                                                       |   |
=======
| LED matrix |  8x8 matrix        | 20x20mm                      | [GYXM-788ASR](http://eud.dx.com/product/lson-788-8-x-8-red-led-display-dot-matrix-module-black-white-844302671)* (DealExtreme) |   |
| PCB        |                    |                              | [OshPark](https://oshpark.com/shared_projects/NkANAgow)                                                                       |   |
* Probably any LED matrix labeled 788 should work.

>>>>>>> cleanup
You will require an In-System Programmer (ISP) to write the firmware onto the microcontroller.

##Burning the bootloader and uploading the sketch
Please read these two tutorials if you are unfamiliar with burning a bootloader:
- http://arduino.cc/en/Tutorial/ArduinoISP
- http://arduino.cc/en/Tutorial/ArduinoToBreadboard

The required procedure is the one described as "AVR on a breadboard" and "Minimal circuit", respectively, as there is no external crystal attached to the microcontroller.

Please download Carlos Rodrigues' Barebones ATmega Chips board configuration file:
https://github.com/carlosefr/atmega (instructions inside)

The ICSP header on the Micro Word Clock PCB is the standard layout described [here](http://www.atmel.com/images/doc0943.pdf) (Fig. 2).

##Contributions
Carl Monk has built [his own version](http://fortoffee.org.uk/2014/12/word-clock-with-a-unicorn/) using a [Unicorn HAT](http://shop.pimoroni.com/products/unicorn-hat).

[quistoph](https://github.com/qistoph) has made a Dutch layout.

Tanguy Rewers independently came up with an alternative Dutch layout (labeled as dutch2).

##Featured on
- [Hackaday](http://hackaday.com/2014/11/29/micro-word-clock/)
- [Gizmodo](http://gizmodo.com/build-a-tiny-version-of-those-pricey-word-clocks-on-the-1665134624)
- [The Atmel Blog](http://blog.atmel.com/2014/12/01/build-your-own-micro-word-clock-with-an-atmega328p/)

##License
This project (both software and hardware) is published under a [Creative Commons BY-SA 3.0 License](http://creativecommons.org/licenses/by-sa/3.0/).
