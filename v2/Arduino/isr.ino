volatile byte isr_col = 0;
volatile byte isr_row = 0;

ISR(TIMER1_COMPA_vect){
  updatenow = true;
}

ISR(TIMER2_COMPA_vect){
  // DISABLE CURRENT COL ///////////////////////////////
  if(cols[isr_col] == A6) {
    if(COL_OFF == true) 
      PORTB |= B01000000;
    else
      PORTB &=~ B01000000;
  } 
  else if(cols[isr_col] == A7) {
    if(COL_OFF == true) 
      PORTB |= B10000000;
    else
      PORTB &=~ B10000000;
  } 
  else {
    digitalWrite(cols[isr_col],COL_OFF);    
  }
  // END DISABLE CURRENT COL ///////////////////////////////

  // DISABLE CURRENT ROW ///////////////////////////////
  if(rows[isr_row] == A6) {
    if(ROW_OFF == true) 
      PORTB |= B01000000;
    else
      PORTB &=~ B01000000;
  } 
  else if(rows[isr_row] == A7) {
    if(ROW_OFF == true) 
      PORTB |= B10000000;
    else
      PORTB &=~ B10000000;
  } 
  else {
    digitalWrite(rows[isr_row],ROW_OFF);    
  }
  // END DISABLE CURRENT ROW ///////////////////////////////

//  do {
    if(++isr_col == 8) {
      isr_col = 0;
      if(++isr_row == 8) {
        isr_row = 0;
      }
    }
//  } 
//  while((disp[isr_row] << isr_col) & B10000000 == false);



  // ENABLE CURRENT ROW ///////////////////////////////
  if(rows[isr_row] == A6) {
    if(ROW_ON == true) 
      PORTB |= B01000000;
    else
      PORTB &=~ B01000000;
  } 
  else if(rows[isr_row] == A7) {
    if(ROW_ON == true) 
      PORTB |= B10000000;
    else
      PORTB &=~ B10000000;
  } 
  else {
    digitalWrite(rows[isr_row],ROW_ON);    
  }
  // END ENABLE CURRENT ROW ///////////////////////////////

  if((disp[isr_row] << isr_col) & B10000000) {
    if(cols[isr_col] == A6) {
      if(COL_ON == true) 
        PORTB |= B01000000;
      else
        PORTB &=~ B01000000;
    } 
    else if(cols[isr_col] == A7) {
      if(COL_ON == true) 
        PORTB |= B10000000;
      else
        PORTB &=~ B10000000;
    } 
    else {
      digitalWrite(cols[isr_col],COL_ON);    
    }
  } 
  // END ENABLE CURRENT COL ///////////////////////////////

}






