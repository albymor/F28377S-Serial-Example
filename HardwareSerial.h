/*
 * HardareSerial.h
 *
 *  Created on: 02/giu/2016
 *      Author: Alberto
 */

#ifndef HARDWARESERIAL_H_
#define HARDWARESERIAL_H_

void serialInit(void);
void scia_xmit(int);
void serialWrite(char*);
int serialAvailable(void);
int serialRead(void);



#endif /* HARDWARESERIAL_H_ */
