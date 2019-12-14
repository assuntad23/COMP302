/*
 * socketproject.c
 *
 *  Created on: Oct 8, 2017
 *		Author: adesanto
 *		Author: jas5784
 *
 */
#define _XOPEN_SOURCE
#define _DEFAULT_SOURCE

#include <signal.h>
#include <unistd.h>
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
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <locale.h>
#include <langinfo.h>
#include <stdint.h>
#include <fcntl.h>

FILE *ServerLog;

// global variable to control the loop
int Exit;

//this loop sets up the Strings that will be logged in the file so that they print nicely.
void printingToFile(char StringForLog[]) {
	//declared a timer so that we can get the local time
	time_t rawtime;
	struct tm * timeEntrySt;
	char timeEntry[80];
	time(&rawtime);
	timeEntrySt = localtime(&rawtime);

	//using strftime so that I can format it on the same line.
	strftime(timeEntry, 80, "%c", timeEntrySt);

	//LogEntry will hold the time and the string being passed to the method
	char LogEntry[300];
	sprintf(LogEntry, "%s - ", timeEntry);
	strcat(LogEntry, StringForLog);

	if (errno != 0) {
		char errorEntry[300];
		sprintf(errorEntry, "The error number is %d - %s.\n", errno,
				strerror(errno));
	}

	//printing to file
	fprintf(ServerLog, LogEntry);

	//flushing so that it actually appears in file.
	fflush(ServerLog);
}

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

void writeDateToSocket(int clientfd) {
	//declared a timer so that we can get the local time
	time_t timer;
	timer = time(NULL);

	//printing timer to String timeAndDate
	char timeAndDate[100];
	sprintf(timeAndDate, "<p>%s</p>", asctime(localtime(&timer)));

	//writing it to the socket.
	write(clientfd, timeAndDate, strlen(timeAndDate));
}

void writeKernelInfoToSocket(int clientfd) {
	//defining and calling a structure for the kernel information
	struct utsname unameData;
	uname(&unameData);

	// Write a kernel info banner
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
	//declaring structure for ipAddress
	struct in_addr ipAddress;

	//declaring Strings
	char ipMessage[100];
	char portNumMsg[100];

	//turning ipAddress and port number into strings
	sprintf(ipMessage, "Client IP Address: %s</br>", inet_ntoa(ipAddress));
	sprintf(portNumMsg, "Port Number: %d", portnum);

	//declaring networkInfoHeader
	char networkInfoHeader[100] = "<h2>***** CLIENT INFO *****</h2>";

	//writing to socket
	write(clientfd, networkInfoHeader, strlen(networkInfoHeader));
	write(clientfd, ipMessage, strlen(ipMessage));
	write(clientfd, portNumMsg, strlen(portNumMsg));

	//Since this is where the structure for ipAddress is, I'm printing it to the file here.
	char accessAddress[100];
	sprintf(accessAddress, "%s accessed the sever.\n", inet_ntoa(ipAddress));
	printingToFile(accessAddress);
}

//signal handler
void sigHandler(int signal) {

	//stops the loop
	Exit = 1;
	printingToFile("The server has shutdown.\n");
	return;
}

//method to handle signals
int handlingSignals() {
	//declare sigaction structure
	struct sigaction sa;

	//clear memory to prevent possible errors
	memset(&sa, 0, sizeof(sa));

	//handler call the sigHandler function
	sa.sa_handler = sigHandler;
	sigemptyset(&sa.sa_mask);

	if (sigaction(SIGINT, &sa, NULL) == -1) {
		printingToFile("Error assigning the handler for SIGINT\n");
		perror("Error");
		return (1);
	}
	if (sigaction(SIGTERM, &sa, NULL) == -1) {
		printingToFile("Error assigning the handler for SIGTERM\n");
		perror("Error");
		return (1);
	}

}

int okHTTP(int clientfd) {

	//HTTP information
	char http[200] = "HTTP/1.1 200 OK\r\n";
	char server[200] = "Server: ADJSWeb v1.0\r\n";
	char content[200] = "Content-Type: text/html\r\n";
	char ret[200] = "\r\n";
	//writing beginning information to socket
	write(clientfd, http, strlen(http));
	write(clientfd, server, strlen(server));
	write(clientfd, content, strlen(content));
	write(clientfd, ret, strlen(ret));
}

int statusHTTP(int clientfd, int portnum) {
	okHTTP(clientfd);
	char htmlStart[1000] =
			"<html><head><title>Status Page</title></head><body><h1>Status:</h1>";
	char htmlEnd[1000] = "</body></html>";

	//writing beginning information to socket
	write(clientfd, htmlStart, strlen(htmlStart));

	//writing to socket
	writeDateToSocket(clientfd);
	writeKernelInfoToSocket(clientfd);
	writeSystemInfoToSocket(clientfd);
	writeNetworkInfoToSocket(clientfd, portnum);

	//closing html tags
	write(clientfd, htmlEnd, strlen(htmlEnd));
}

int errorNotFoundHTTP(int clientfd) {
	//declaring http & html information
	char http[200] = "HTTP/1.1 404 Not Found\r\n";
	char server[200] = "Server: ADJSDWeb v1.0\r\n";
	char content[200] = "Content-Type: text/html\r\n";
	char ret[200] = "\r\n";
	char html[1000] =
			"<html><head><title>Error Page</title></head><body><h1>ERROR</h1><h3>404 Error Not Found<h3></body></html>";
	//writing to socket
	write(clientfd, http, strlen(http));
	write(clientfd, server, strlen(server));
	write(clientfd, content, strlen(content));
	write(clientfd, ret, strlen(ret));
	write(clientfd, html, strlen(html));
}

int errorPermissionDeniedHTTP(int clientfd) {
	//declaring http & html information
	char http[200] = "HTTP/1.1 403 Forbidden\r\n";
	char server[200] = "Server: ADJSDWeb v1.0\r\n";
	char content[200] = "Content-Type: text/html\r\n";
	char ret[200] = "\r\n";
	char html[1000] =
			"<html><head><title>Error Page</title></head><body><h1>FORBIDDEN</h1><h3>403 Forbidden<h3></body></html>";
	//writing to socket
	write(clientfd, http, strlen(http));
	write(clientfd, server, strlen(server));
	write(clientfd, content, strlen(content));
	write(clientfd, ret, strlen(ret));
	write(clientfd, html, strlen(html));
}

int scanDirect(int clientfd, char* buffer, int portnum) {
	//declaring html start and end strings
	char htmlStart[1000] =
			"<html><head><title>Directory</title></head><body><h1>Directory:</h1>";
	char htmlEnd[1000] = "</body></html>";

	//create structure for the directory array
	struct dirent **dirList;
	struct stat statbuf;
	struct tm *tm;

	char datestring[256];
	char fileSize[256];
	char dirCheck[256];
	char addPath[512];
	char direct[512];
	char newAddPath[512];


	// Clear out to prevent getting stuck in current directory
	memset(direct, 0, sizeof(direct));

	//create a request for the file path
	//i = 8 to ignore "GET /dir" and skip right to path
	for (int i = 8; i < sizeof(direct) - 1; i++) {
		//skips the rest of the address once it reads the HTTP in buffer
		if (strncmp(&buffer[i], " HTTP/", 6) == 0) {
			strncpy(direct, buffer + 8, i - 8);
			break;
		}
	}

	//putting the path request into addPath
	sprintf(addPath, "%s", direct);

	//if there is no add path typed after /dir, automatically go to home directory
	if (strcmp(addPath, "") == 0) {
		sprintf(addPath, "/home/");
	}

	//n set to number of files in directory.
	int n = scandir(addPath, &dirList, NULL, alphasort);
	//error if n == -1
	if (n == -1) {
		perror("Error");
		// File or directory does not exist
		if (errno == 2) {
			errorNotFoundHTTP(clientfd);
		}
		// Permission denied
		else if (errno == 13) {
			errorPermissionDeniedHTTP(clientfd);
		}

	} else {
		//necessary HTTP and html info
		okHTTP(clientfd);
		write(clientfd, htmlStart, strlen(htmlStart));
		write(clientfd, "<table>", 7);

		while (n--) {
			char path[200];
			sprintf(path, "%s/%s", addPath, dirList[n]->d_name);
			int retVal = stat(path, &statbuf);
			sprintf(fileSize, " %9jd ", (intmax_t) statbuf.st_size);
			//Getting the last modified time
			tm = localtime(&statbuf.st_mtime);
			//Get localized date string
			strftime(datestring, sizeof(datestring), nl_langinfo(D_T_FMT), tm);

			//if file is a regular file, print it without a hyperlink
			if (S_ISREG(statbuf.st_mode)) {
				char fileString[200];
				sprintf(fileString, "<tr> <td>%s</td>", dirList[n]->d_name);

				write(clientfd, fileString, strlen(fileString));

				char fsAndDs[200];
				sprintf(fsAndDs, "<td> %s </td><td> %s </td></tr>", fileSize,
						datestring);
				write(clientfd, fsAndDs, strlen(fsAndDs));
				sprintf(dirCheck, "%s is a file\n", dirList[n]->d_name);
			} //if file is a directory, print it with hyperlink so that you can access it
			else if (S_ISDIR(statbuf.st_mode)) {

				char directoryString[200];
				sprintf(directoryString, "<tr> <td><a href=\"%s/\">%s</a></td>",
						dirList[n]->d_name, dirList[n]->d_name);

				write(clientfd, directoryString, strlen(directoryString));

				char fsAndDs[200];
				sprintf(fsAndDs, "<td> %s </td><td> %s </td></tr>", fileSize,
						datestring);
				write(clientfd, fsAndDs, strlen(fsAndDs));
				sprintf(dirCheck, "%s is a directory\n", dirList[n]->d_name);
				printingToFile(dirCheck);
			}

			//updates the current file stats
			sprintf(newAddPath, "%s/%s", addPath, dirList[n]->d_name);

			//free each individual n
			free(dirList[n]);
		}
		//free the entire array

		//closing table
		write(clientfd, "</table>", 8);
		//closing html tags
		write(clientfd, htmlEnd, strlen(htmlEnd));
		//free the whole list
		free(dirList);
	}

}

int AcceptingConnectionsLoop(int result, int sockfd, int portnum) {
	//Setting the socket to listen for incoming messages
	result = listen(sockfd, 5);

	//socket is set up now

	//setting exit to 0, so that loop keeps on looking for connections
	//if exit != 0, loop will exit and server will close (see sigHandler)
	Exit = 0;
	while (Exit == 0) {
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
			printingToFile(
					"The call to accept a connection was not successful.");
			perror("Error");
			return (1);
		} else {
			printingToFile(
					"The call to accept a connection was successful. Waiting for a connection.\n");
		}

		//Reading a message from the socket
		// declare variables to use
		char buffer[65535];

		// initialize the buffer
		memset(buffer, 0, sizeof(buffer));

		// read the message
		read(clientfd, buffer, 65534);

		//This is the status message we will be searching the buffer for
		char status_message[20] = "GET /status ";
		char dir_message[20] = "GET /dir";

		//strstr compares two strings. if "GET /" appears in buffer, this will return a pointer
		//if it does not it will return null. As long as it is not NULL, the user should go to either status page or directory
		if (strcasestr(buffer, status_message) != NULL) {
			printingToFile("Connection made for Status page.\n");
			statusHTTP(clientfd, portnum);
		} else if (strcasestr(buffer, dir_message) != NULL) {
			printingToFile("Connection made for Directory.\n");
			scanDirect(clientfd, buffer, portnum);
		} else {
			printingToFile(
					"Connection not for Status or Directory. Page not found. Sending user to Error Page\n");
			errorNotFoundHTTP(clientfd);
		}

		result = close(clientfd);
	}

	return (result);
}

int main(int argc, char **argv) {

	ServerLog = fopen("ServerLog.txt", "w");

	if (NULL == ServerLog) {
		printf("File not opened\n");
		perror("Error");
		return (1);
	}

	if (argc < 2) {
		printingToFile("Not enough arguments passed to the program.\n");
		perror("Error");
		return (1);
	}
	if (argc > 2) {
		printingToFile("Too many arguments passed to the program.\n");
		perror("Error");
		return (1);
	}

	handlingSignals();

	int sockfd = CreatingSocket();
	if (sockfd == -1) {
		printingToFile("The socket was not created.");
		perror("Error");
		return (1);
	} else {
		printingToFile("Socket created successfully.\n");
	}

	// Element 0 is the program name
	// Get the first program argument, the port number
	int portnum = atoi(argv[1]);
	if (portnum < 0 || portnum > 65355) {
		printingToFile("Port number must be between 0 and 65355.\n");
		perror("Error");
		return (1);
	}

	int result = BindingToAddress(sockfd, portnum);
	if (result == -1) {
		printingToFile("The address did not bind to the socket successfully.");
		perror("Error");
		return (1);
	} else {
		printingToFile("The address was bound to the socket successfully.\n");
	}

	AcceptingConnectionsLoop(result, sockfd, portnum);

	fclose(ServerLog);

	return (0);
}
