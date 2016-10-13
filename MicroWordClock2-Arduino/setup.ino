void setup() {
  for(int i=0;i<8;i++) {
    disp[i] = testdisp[i];

    // Set normal pins as outputs
    pinMode(cols[i],OUTPUT);
    pinMode(rows[i],OUTPUT);
    digitalWrite(cols[i],COL_OFF);
    digitalWrite(rows[i],ROW_OFF);  

    // Set A6/A7 (XTAL pins) separately
    if(cols[i] == A6) {
      DDRB |= B01000000;
      if(COL_OFF == true)
        PORTB |= B01000000;
      else
        PORTB &=~ B01000000;
    }
    else if(cols[i] == A7) {
      DDRB |= B10000000;
      if(COL_OFF == true)
        PORTB |= B10000000;
      else
        PORTB &=~ B10000000;
    }
    if(rows[i] == A6) {
      DDRB |= B01000000;
      if(ROW_OFF == true)
        PORTB |= B01000000;
      else
        PORTB &=~ B01000000;
    }
    else if(rows[i] == A7) {
      DDRB |= B10000000;
      if(ROW_OFF == true)
        PORTB |= B10000000;
      else
        PORTB &=~ B10000000;
    }
  }

  // Set up pins 0 and 1 to set time
  pinMode(PIN_BUTTON,INPUT_PULLUP);


  TCCR2A = 0;
  TCCR2B = 0;
  TCNT2  = 0;
  // set compare match register to match frequency
  OCR2A = T0_COMPARE;// = (sysclock)/(freq*prescaler)-1  (must be <256)
  // turn on CTC mode
  TCCR2A |= (1 << WGM21);
  // Set prescaler
  TCCR2B |= (1 << CS21);   
  // enable timer compare interrupt
  TIMSK2 |= (1 << OCIE2A);

  // Uncomment following line to keep all LEDs on forever
  if(digitalRead(PIN_BUTTON) == LOW)
    while(true);

  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  TCNT1  = 0;// initialize counter value to 0
  // set compare match register for 2hz increments
  OCR1A = T1_COMPARE;// = (sysclock)/(freq*prescaler)-1 (must be <65536)
  // turn on CTC mode
  TCCR1A |= (1 << WGM12);
  // Set CS12 and CS10 bits for prescaler
  TCCR1B |= (1 << CS11) | (1 << CS10);  
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);


  Wire.begin();
  rtc.begin();
  if (!rtc.isrunning() || false) {
    //clockmode = NOT_SET;
    rtc.adjust(DateTime(__DATE__, __TIME__));
  }
  //  //  Serial.begin(115200);
}



