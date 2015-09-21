#ifndef TRANSMITTER_H
#define TRANSMITTER_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

/* ASCII Const */ 
#define SOH 1 /* Start of Header Character */
#define STX 2 /* Start of Text Character */
#define ETX 3 /* End of Text Character */ 
#define ENQ 5 /* Enquiry Character */ 
#define ACK 6 /* Acknowledgement */ 
#define BEL 7 /* Message Error Warning */ 
#define CR 13 /* Carriage Return */
#define LF 10 /* Line Feed */ 
#define NAK 21 /* Negative Acknowledgement */
#define Endfile 26 /* End of file character */
#define ESC 27 /* ESC key */ 

/* XON/XOFF protocol */ 
#define XON (0x11) 
#define XOFF (0x13) 

/* Const */ 
#define BYTESIZE 256 /* The maximum value of a byte */
#define MAXLEN 1024 /* Maximum messages length */ 
#define BUFMAX 1	/* Maximum size of buffer that can be sent */

int isXON = 1;		// flag for XON/XOFF sent
int isSocketOpen;	// flag to indicate if connection from socket is done

struct sockaddr_in receiverAddr;			// receiver host information
int receiverAddrLen = sizeof(receiverAddr);

FILE *tFile;		// file descriptor
char *receiverIP;	// buffer for Host IP address
char buf[BUFMAX];	// buffer for character to send
char xbuf[BUFMAX+1];	// buffer for receiving XON/XOFF characters


#endif