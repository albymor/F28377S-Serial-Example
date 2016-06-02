//###########################################################################
// FILE:   blinky_cpu01.c
// TITLE:  LED Blink Example for F2837xS.
//
//! \addtogroup cpu01_example_list
//! <h1> Blinky </h1>
//!
//! This example blinks LED X
//
//###########################################################################
// $TI Release: F2837xS Support Library v180 $
// $Release Date: Fri Nov  6 16:27:58 CST 2015 $
// $Copyright: Copyright (C) 2014-2015 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#include "F28x_Project.h"     // Device Headerfile and Examples Include File
#include "HardwareSerial.h"

int character;


void main(void)
{
// Step 1. Initialize System Control:
// PLL, WatchDog, enable Peripheral Clocks
// This example function is found in the F2837xS_SysCtrl.c file.
    InitSysCtrl();

// Step 2. Initialize GPIO:
// This example function is found in the F2837xS_Gpio.c file and
// illustrates how to set the GPIO to it's default state.
    InitGpio();
    GPIO_SetupPinMux(13, GPIO_MUX_CPU1, 0);
    GPIO_SetupPinOptions(13, GPIO_OUTPUT, GPIO_PUSHPULL);

// Step 3. Clear all interrupts and initialize PIE vector table:
// Disable CPU interrupts
    DINT;

// Initialize the PIE control registers to their default state.
// The default state is all PIE interrupts disabled and flags
// are cleared.
// This function is found in the F2837xS_PieCtrl.c file.
    InitPieCtrl();

// Disable CPU interrupts and clear all CPU interrupt flags:
    IER = 0x0000;
    IFR = 0x0000;

// Initialize the PIE vector table with pointers to the shell Interrupt
// Service Routines (ISR).
// This will populate the entire table, even if the interrupt
// is not used in this example.  This is useful for debug purposes.
// The shell ISR routines are found in F2837xS_DefaultIsr.c.
// This function is found in F2837xS_PieVect.c.
    InitPieVectTable();

// Enable global Interrupts and higher priority real-time debug events:
    EINT;  // Enable Global interrupt INTM
    ERTM;  // Enable Global realtime interrupt DBGM

    serialInit();

// Step 6. IDLE loop. Just sit and loop forever (optional):
    for(;;)
    {
        //
        // Turn on LED
        //
    	GPIO_WritePin(13, 0);
        //
        // Delay for a bit.
        //
    	DELAY_US(1000*500);
    	serialWrite("Test \r\n\0");

    	if(serialAvailable()){
    		character = serialRead();
    	}

        //
        // Turn off LED
        //
    	GPIO_WritePin(13, 1);
        //
        // Delay for a bit.
        //
    	DELAY_US(1000*500);
    }
}
