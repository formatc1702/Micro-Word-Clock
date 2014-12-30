#Micro Word Clock v2

##Description
A tiny replica of the famous Word Clock, using only an ATmega microcontroller, a DS1307 Real Time Clock and a few passive components to display the time on an 8x8 LED matrix. The letters have been printed onto a transparent sheet and glued over the LEDs to produce a readable time.
See the YouTube video [here](https://www.youtube.com/watch?v=9ko9CeylUTs).

##Directory structure
- **Arduino** contains the firmware, including pin definitions for the LED matrix and location of the words in each language.
- **EAGLE** contains the schematic and PCB design files for the proejct.
- **Graphics** contains the design for the transparency sheet to place over the LED matrix to form the words, designed in Inkscape. Contributions in more languages are welcome!

##Bill of Materials
Includes part numbers for German supplier [Reichelt](www.reichelt.de)
- IC1: ATmega328P-AU (TQFP-32 package) Reichelt code: ATMEGA 328P-AU
- IC2: DS1307Z+ (SO-8 package) Reichelt code: DS 1307Z
- C1: 220nF ceramic (2012 metric size, 0805 imperial size) Reichelt code: X7R-G0805 0,22µ
- C2: 2.2uF tantalum (3528 metric size, B-case) Reichelt code: SMD TAN.2,2/20
- S1: 6.2x6.5mm SMD push button. Reichelt code: TASTER 9314
- XTAL: 32.768 kHz crystal (3216 metric size, 1206 imperial size) Reichelt code: 32,768 CC7V-12,5
- LED matrix: [GYXM-788ASR](http://eud.dx.com/product/lson-788-8-x-8-red-led-display-dot-matrix-module-black-white-844302671) 20x20mm 8x8 LED matrix. Probably any matrix labeled 788 should work.
- PCB: [OshPark](https://oshpark.com/shared_projects/NkANAgow)

You will require an In-System Programmer (ISP) to write the firmware onto the microcontroller.

##Contributions
Carl Monk has built [his own version](http://fortoffee.org.uk/2014/12/word-clock-with-a-unicorn/) using a [Unicorn HAT](http://shop.pimoroni.com/products/unicorn-hat).

[quistoph](https://github.com/qistoph) has made a Dutch layout.

Tanguy Rewers independently came up with an alternative Dutch layout (labeled as dutch2).

##Featured on
- [Hackaday](http://hackaday.com/2014/11/29/micro-word-clock/)
- [Gizmodo](http://gizmodo.com/build-a-tiny-version-of-those-pricey-word-clocks-on-the-1665134624)
- [The Atmel Blog](http://blog.atmel.com/2014/12/01/build-your-own-micro-word-clock-with-an-atmega328p/)
