/*
 * timer_drives.h
 *
 * Created: 01/09/2023 03:56:32 م
 *  Author: handsa
 */ 


#ifndef TIMER_DRIVES_H_
#define TIMER_DRIVES_H_
void timer_ctc_init(void);
volatile unsigned int timer_count=0;
void pwm_ctc(unsigned short freq,unsigned short prescaller);
void timer2_ovf_sec_init(void);
unsigned short icu_rising_edge(void);
unsigned short icu_falling_edge(void);
#endif /* TIMER_DRIVES_H_ */