// LED matrix pin control
#define FOR_ALLCOLS for(int c=0;c<8;c++)
#define FOR_ALLROWS for(int r=0;r<8;r++) 
#define COL_OFF HIGH
#define COL_ON LOW
#define ROW_OFF LOW
#define ROW_ON HIGH
// Refresh rate for each row
#define row_rate refresh_rate/8
#define pixel_rate row_rate/8

//  (sysclock) / (freq*prescaler)
#define SYSCLOCK 8000000 // Hz
#define PRESCALER0 64
#define T0_COMPARE SYSCLOCK / (FREQ_DISPLAY * PRESCALER0)

#define PRESCALER1 64
#define T1_COMPARE SYSCLOCK / (FREQ_TIMEUPDATE * PRESCALER1)

