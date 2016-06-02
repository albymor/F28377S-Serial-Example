/*
 * HardwareSerial.c
 *
 *  Created on: 02/giu/2016
 *      Author: Alberto
 */

#include "F28x_Project.h"
#include "HardwareSerial.h"

// Test 1,SCIA  DLB, 8-bit word, baud rate 0x000F, default, 1 STOP bit, no parity
void serialInit()
{

	EALLOW;
	//Configure GPIO84 as SCITXDA (Output pin)
	//Configure GPIO85 as SCIRXDA (Input pin)
	GpioCtrlRegs.GPCGMUX2.bit.GPIO84 = 1;
	GpioCtrlRegs.GPCMUX2.bit.GPIO84 = 1;
	GpioCtrlRegs.GPCGMUX2.bit.GPIO85 = 1;
	GpioCtrlRegs.GPCMUX2.bit.GPIO85 = 1;
	// Configure GPIO85 (SCIRXDA) as async pin
	GpioCtrlRegs.GPCQSEL2.bit.GPIO85 = 3;
	EDIS;

	SciaRegs.SCIFFTX.all=0xE040;
	SciaRegs.SCIFFRX.all=0x2044;
	SciaRegs.SCIFFCT.all=0x0;


	EALLOW;
	CpuSysRegs.PCLKCR7.bit.SCI_A = 1;
	ClkCfgRegs.LOSPCP.bit.LSPCLKDIV = 1;
	EDIS;
    // Note: Clocks were turned on to the SCIA peripheral
    // in the InitSysCtrl() function

 	SciaRegs.SCICCR.all =0x0007;   // 1 stop bit,  No loopback
                                   // No parity,8 char bits,
                                   // async mode, idle-line protocol
	SciaRegs.SCICTL1.all =0x0003;  // enable TX, RX, internal SCICLK,
                                   // Disable RX ERR, SLEEP, TXWAKE
	SciaRegs.SCICTL2.all =0x0003;
	SciaRegs.SCICTL2.bit.TXINTENA =1;
	SciaRegs.SCICTL2.bit.RXBKINTENA =1;

    //
    // SCIA at 9600 baud
    // @LSPCLK = 50 MHz (200 MHz SYSCLK) HBAUD = 0x02 and LBAUD = 0x8B.
    // @LSPCLK = 30 MHz (120 MHz SYSCLK) HBAUD = 0x01 and LBAUD = 0x86.
    //
	SciaRegs.SCIHBAUD.all    = 0x02; // (unsigned int)((CPU_FREQ/(ClkCfgRegs.LOSPCP.bit.LSPCLKDIV * 2))/(baud*8)-1)>>8 ;
    SciaRegs.SCILBAUD.all    = 0x8B; // (unsigned int)((CPU_FREQ/(ClkCfgRegs.LOSPCP.bit.LSPCLKDIV * 2))/(baud*8)-1)&0x00FF;

	SciaRegs.SCICTL1.all =0x0023;  // Relinquish SCI from Reset
}

// Transmit a character from the SCI
void scia_xmit(int a)
{
    while (SciaRegs.SCIFFTX.bit.TXFFST != 0) {}
    SciaRegs.SCITXBUF.all =a;
}

void serialWrite(char * msg)
{
    int i;
    i = 0;
    while(msg[i] != '\0')
    {
        scia_xmit(msg[i]);
        i++;
    }
}

int serialAvailable()
{
	return SciaRegs.SCIFFRX.bit.RXFFST;
}

int serialRead()
{
	return SciaRegs.SCIRXBUF.all;
}




