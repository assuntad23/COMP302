/*
 * SocketProject.c
 *
 *  Created on: Sep 26, 2017
 *      Author: adesanto
 */

#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {

	//Creating and opening a network socket
	int sockfd = socket( AF_INET, SOCK_STREAM, 0 );


	//Binding address to the socket
	// declare address variable
	struct sockaddr_in    address;

	//setting port number to 25000 - first couple thousand ports are reserved
	int portnum = 25000;

	// set the address to the computer's IP Address
	memset( &address, 0 , sizeof( address ) );
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons( portnum );

	//binding the address to the socket
	int result = bind( sockfd, (struct sockaddr *) &address, sizeof( address ) );


	//Setting the socket to listen for incoming messages
	result = listen(sockfd, 5);

	//socket is set up now

	//Accepting Connections
	// declare variables for the client address
	struct sockaddr_in      client_addr;
	int                     client_addr_len;

	// initialize the client address
	memset( &client_addr, 0, sizeof( client_addr ) );

	// call accept to get a connection
	int clientfd = accept( sockfd, (struct sockaddr *) &client_addr, (unsigned int *) &client_addr_len );

	//connect to the socket from another computer with the IPaddress and socket #
	//connect to the socket from this computer with just the socket #

	//Reading a message from the socket
	// declare variables to use
	char    buffer[255];
	int     bytes_read;

	//TODO read /status message >use if statement. send to status page (write) if T, send to error page (write) if F;
	//when done go back to Accepting Connections


	// initialize the buffer
	memset( buffer, 0, sizeof( buffer ) );

	// read the message
	bytes_read = read( clientfd, buffer, 254 );



	//Writing a message to the socket
	// declare variables to use
	int         bytes_written;

	// copy in a message
	strcpy( buffer, "Hello World!" );

	// write the message
	bytes_written = write( clientfd, buffer, strlen( buffer ) );

	//printing Error number
	printf("%d", errno);

	//Closing the socket
	result = close(clientfd);

	return (result);
}


