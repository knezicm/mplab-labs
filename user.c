/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

/* Device header file */
#if defined(__XC16__)
    #include <xc.h>
#elif defined(__C30__)
    #if defined(__dsPIC33E__)
    	#include <p33Exxxx.h>
    #elif defined(__dsPIC33F__)
    	#include <p33Fxxxx.h>
    #endif
#endif

#include <stdint.h>          /* For uint16_t definition                       */
#include <stdbool.h>         /* For true/false definition                     */
#include "user.h"            /* variables/params used by user.c               */

#include <timer.h>

/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

/* <Initialize variables in user.h and insert code for user algorithms.> */

void InitApp(void)
{
    uint16_t match_value;
    
    /* Setup analog functionality and port direction */
    TRISD = 0;
    TRISBbits.TRISB0 = 1;   /* start/stop timer */
    TRISBbits.TRISB1 = 1;   /* change blinking mode */
    
    /* Initialize peripherals */
    LATDbits.LATD0 = 1;     /* turn on LED on RD0 */
    LATDbits.LATD1 = 0;     /* turn off LED on RD1 */
    
    /* Enable Timer1 Interrupt and Priority to "1" */
    ConfigIntTimer1(T1_INT_PRIOR_1 & T1_INT_ON);
    WriteTimer1(0);
    match_value = 250;
    OpenTimer1(T1_ON & T1_GATE_OFF & T1_IDLE_STOP &
               T1_PS_1_64 & T1_SYNC_EXT_OFF &
               T1_SOURCE_INT, match_value);
}
