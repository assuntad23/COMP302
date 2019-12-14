/*
 * socketproject.c
 *
 *  Created on: Oct 8, 2017
 *      Author: jas5784
 */

//sigaction is not ansi standard
//so you need this define to use sigaction
#define _XOPEN_SOURCE

#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include <arpa/inet.h>
#include <time.h>
#include <signal.h>

//creating a file
FILE *ServerLog;

//declaring perror
void perror(const char *str);

//declare exit
//used to control the signal loop
int Exit;

int CreatingSocket() {
	//Creating and opening a network socket
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);

	return sockfd;
}

int BindingToAddress(int sockfd, int portNumber) {
	//Binding address to the socket
	// declare address variable
	struct sockaddr_in address;

	// set the address to the computer's IP Address
	memset(&address, 0, sizeof(address));
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(portNumber);

	//binding the address to the socket
	int result = bind(sockfd, (struct sockaddr *) &address, sizeof(address));

	return result;

}

char timeStamp() {
	//declared a timer so that we can get the local time
	time_t timer2;
	timer2 = time(NULL);

	char timeStamp[100];
	sprintf(timeStamp, "<p>%s<\p>", asctime(localtime(&timer2)));

	return timeStamp;
}

void writeDateToSocket(int clientfd) {
	//declared a timer so that we can get the local time
	time_t timer;
	timer = time(NULL);

	char timeAndDate[100];
	sprintf(timeAndDate, "<p>%s<\p>", asctime(localtime(&timer)));

	write(clientfd, timeAndDate, strlen(timeAndDate));
}

void writeKernelInfoToSocket(int clientfd) {
	//defining and calling a structure for the kernel information
	struct utsname unameData;
	uname(&unameData);

	// Write a kernel info bfanner
	char kernelInfoHeader[100] = "<h2>***** KERNEL INFO *****</h2>";
	write(clientfd, kernelInfoHeader, strlen(kernelInfoHeader));

	// Create formatted kernel info messages
	char sysName[100], release[100], version[100], machine[100], nodeName[100];
	sprintf(sysName, "System Name: %s<br/>", unameData.sysname);
	sprintf(release, "Release: %s<br/>", unameData.release);
	sprintf(version, "Version: %s<br/>", unameData.version);
	sprintf(machine, "Machine: %s<br/>", unameData.machine);
	sprintf(nodeName, "Node Name: %s<br/><br/>", unameData.nodename);

	// Write kernel information
	write(clientfd, sysName, strlen(sysName));
	write(clientfd, release, strlen(release));
	write(clientfd, version, strlen(version));
	write(clientfd, machine, strlen(machine));
	write(clientfd, nodeName, strlen(nodeName));
}

void writeSystemInfoToSocket(int clientfd) {
	//defining and calling a structure for the system information
	struct sysinfo systemInfo;
	sysinfo(&systemInfo);

	char systemInfoHeader[100] = "<h2>***** SYSTEM INFO *****</h2>";

	// Write system information banner
	write(clientfd, systemInfoHeader, strlen(systemInfoHeader));

	// Format system information messages
	char uptime[100], loadsFive[100], loadsTen[100], loadsFifteen[100],
			totalRam[100], freeRam[100], sharedRam[100], bufferedRam[100],
			totalSwap[100], freeSwap[100], procs[100], totalHigh[100],
			freeHigh[100], memUnit[100];
	sprintf(uptime, "Uptime: %ld</br>", systemInfo.uptime);
	sprintf(loadsFive, "5 Minute Load Average: %ld</br>", systemInfo.loads[0]);
	sprintf(loadsTen, "10 Minute Load Average: %ld</br>", systemInfo.loads[1]);
	sprintf(loadsFifteen, "15 Minute Load Average: %ld</br>",
			systemInfo.loads[2]);
	sprintf(totalRam, "Total RAM: %ld</br>", systemInfo.totalram);
	sprintf(freeRam, "Free RAM: %ld</br>", systemInfo.freeram);
	sprintf(sharedRam, "Shared RAM: %ld</br>", systemInfo.sharedram);
	sprintf(bufferedRam, "Buffered RAM: %ld</br>", systemInfo.bufferram);
	sprintf(totalSwap, "Total Swap: %ld</br>", systemInfo.totalswap);
	sprintf(freeSwap, "Free Swap: %ld</br>", systemInfo.freeswap);
	sprintf(procs, "Processes: %hd</br>", systemInfo.procs);
	sprintf(totalHigh, "Total High Memory: %ld</br>", systemInfo.totalhigh);
	sprintf(freeHigh, "Free High Memory: %ld</br>", systemInfo.freehigh);
	sprintf(memUnit, "Memory Units (in bytes): %d</br>", systemInfo.mem_unit);

	//Writing System Information
	write(clientfd, uptime, strlen(uptime));
	write(clientfd, loadsFive, strlen(loadsFive));
	write(clientfd, loadsTen, strlen(loadsTen));
	write(clientfd, loadsFifteen, strlen(loadsFifteen));
	write(clientfd, totalRam, strlen(totalRam));
	write(clientfd, freeRam, strlen(freeRam));
	write(clientfd, sharedRam, strlen(sharedRam));
	write(clientfd, bufferedRam, strlen(bufferedRam));
	write(clientfd, totalSwap, strlen(totalSwap));
	write(clientfd, freeSwap, strlen(freeSwap));
	write(clientfd, procs, strlen(procs));
	write(clientfd, totalHigh, strlen(totalHigh));
	write(clientfd, freeHigh, strlen(freeHigh));
	write(clientfd, memUnit, strlen(memUnit));
}

void writeNetworkInfoToSocket(int clientfd, int portnum) {
	struct in_addr ipAddress;
	char ipMessage[100];
	char portNumMsg[100];
	sprintf(ipMessage, "Client IP Address: %s</br>", inet_ntoa(ipAddress));
	sprintf(portNumMsg, "Port Number: %d", portnum);
	char networkInfoHeader[100] = "<h2>***** CLIENT INFO *****</h2>";
	write(clientfd, networkInfoHeader, strlen(networkInfoHeader));
	write(clientfd, ipMessage, strlen(ipMessage));
	write(clientfd, portNumMsg, strlen(portNumMsg));
}

int AcceptingConnectionsLoop(int result, int sockfd, int portnum) {
	//Setting the socket to listen for incoming messages
	result = listen(sockfd, 5);

	//socket is set up now
	while (1) {
		//Accepting Connections
		// declare a variables for the client address
		struct sockaddr_in client_addr;
		// need to initialize the length or
		// accept may not return all the information
		// in client_addr. use socklen_t as the datatype
		// socklen_t is defined to the size needed in the
		// sys/socket.h header file
		socklen_t client_addr_len = sizeof(client_addr);

		// initialize the client address
		memset(&client_addr, 0, client_addr_len);

		// call accept to get a connection
		int clientfd = accept(sockfd, (struct sockaddr *) &client_addr,
				(unsigned int *) &client_addr_len);

		//connect to the socket from another computer with the IPaddress and socket #
		//connect to the socket from this computer with just the socket #

		if (clientfd == -1) {
			perror("Error");
			fprintf(stderr,
					"The call to accept a connection was not successful. The error number is %d - %s\n",
					errno, strerror(errno));
			fprintf(ServerLog, timeStamp());
			return (1);
		} else {
			fprintf(ServerLog,
					"The call to accept a connection was successful.\nWaiting for a connection.\n");
			fprintf(ServerLog, timeStamp());
		}

		int fflush(FILE *ServerLog);

		//Reading a message from the socket
		// declare variables to use
		char buffer[65535];

		// initialize the buffer
		memset(buffer, 0, sizeof(buffer));

		// read the message
		read(clientfd, buffer, 65534);

		//This is the status message we will be searching the buffer for
		char status_message[20] = "GET /status ";

		fprintf(ServerLog, "Request: \n%s\n", buffer);
		//strstr compares two strings. if "GET /" appears in buffer, this will return a pointer
		//if it does not it will return null. As long as it is not NULL, the user should go to status page
		if (strcasestr(buffer, status_message) != NULL) {
			fprintf(ServerLog,
					"Connection made. Sending user to status page.\n");
			char http[200] = "HTTP/1.1 200 OK\r\n";
			char server[200] = "Server: ADJSWeb v1.0\r\n";
			char content[200] = "Content-Type: text/html\r\n";
			char ret[200] = "\r\n";
			char htmlStart[1000] =
					"<html><head><title>Status Page</title></head><body><h1>Status:</h1>";
			char htmlEnd[1000] = "</body></html>";
			write(clientfd, http, strlen(http));
			write(clientfd, server, strlen(server));
			write(clientfd, content, strlen(content));
			write(clientfd, ret, strlen(ret));
			write(clientfd, htmlStart, strlen(htmlStart));

			writeDateToSocket(clientfd);
			writeKernelInfoToSocket(clientfd);
			writeSystemInfoToSocket(clientfd);
			writeNetworkInfoToSocket(clientfd, portnum);

			write(clientfd, htmlEnd, strlen(htmlEnd));
		} else {
			fprintf(ServerLog,
					"Connection made, but not for status page. Sending user to 404 error page\n");
			char http[200] = "HTTP/1.1 404 Not Found\r\n";
			char server[200] = "Server: ADJSDWeb v1.0\r\n";
			char content[200] = "Content-Type: text/html\r\n";
			char ret[200] = "\r\n";
			char html[1000] =
					"<html><head><title>Error Page</title></head><body><h1>ERROR</h1><h3>404 Error Not Found<h3></body></html>";
			write(clientfd, http, strlen(http));
			write(clientfd, server, strlen(server));
			write(clientfd, content, strlen(content));
			write(clientfd, ret, strlen(ret));
			write(clientfd, html, strlen(html));
		}

		result = close(clientfd);
		int fflush(FILE *ServerLog);
	}
	return (result);
}

//signal handler
void sigHandler(int signal) {
	//check to see if its working
	printf("In sigHandler with signal %d/n, signal");

	//stops the loop
	Exit = 1;

	return;
}

int main(int argc, char **argv) {
	ServerLog = fopen("ServerLog.txt", "w");

	//error message to console if the file doesn't open
	if ( NULL == ServerLog) {
		printf("File not opened\n");
		return (1);
	}

	int fflush(FILE *ServerLog);

	//errors if there is less than or more than 2 arguments
	if (argc < 2) {
		fprintf(ServerLog, "Not enough arguments passed to the program.");
		return (1);
	}
	if (argc > 2) {
		fprintf(ServerLog, "Too many arguments passed to the program.");
		return (1);
	}

	int fflush(FILE *ServerLog);

	int sockfd = CreatingSocket();
	//print to ServerLog if the socket was created or not
	if (sockfd == -1) {
		fprintf(ServerLog, "The socket was not created.");
		perror("Error");
		fprintf(stderr, "The error number is %d - %s", errno, strerror(errno));
		fprintf(ServerLog, timeStamp());
		return (1);
	} else {
		fprintf(ServerLog, "Socket created successfully.");
		fprintf(ServerLog, timeStamp());
	}

	int fflush(FILE *ServerLog);

	// Element 0 is the program name
	// Get the first program argument, the port number
	int portnum = atoi(argv[1]);
	if (portnum < 0 || portnum > 65355) {
		fprintf(ServerLog, "Port number must be between 0 and 65355");
		return (1);
	}

	int result = BindingToAddress(sockfd, portnum);
	if (result == -1) {
		perror("Error");
		fprintf(stderr,
				"The address did not bind to the socket successfully. The error number is %d - %s\n",
				errno, strerror(errno));
		fprintf(ServerLog, timeStamp());
		return (1);
	} else {
		fprintf(ServerLog,
				"The address was bound to the socket successfully.\n");
		fprintf(ServerLog, timeStamp());
	}

	int fflush(FILE *ServerLog);

	AcceptingConnectionsLoop(result, sockfd, portnum);

	//declare sigaction strcuture
	struct sigaction sa;

	//clear memory to prevent possible errors
	memset(&sa, 0, sizeof(sa));

	//handler call the sigHandler function
	sa.sa_handler = sigHandler;
	sigemptyset(&sa.sa_mask);

	if (sigaction(SIGINT, &sa, NULL) == -1) {
		fprintf(ServerLog, "Error assigning the handler for SIGINT\n");
		return (1);
	}
	if (sigaction(SIGTERM, &sa, NULL) == -1) {
		fprintf(ServerLog, "Error assigning the handler for SIGTERM\n");
		return (1);
	}

	Exit = 0;
	while (Exit == 0) {
		fprintf(ServerLog, "Working...\n");

		sleep(1);
	}

	fprintf(ServerLog, "The program has ended\n");

	fclose(ServerLog);

	return (0);
}
