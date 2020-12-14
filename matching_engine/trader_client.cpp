/* chat_client.c --- client program of matching engine
 * 
 * 
 * Author: Robert F. Carangelo III
 * Created: Wed Nov 25 18:48:52 2020 (-0500)
 * Version: 
 * 
 * Description: Opens a TCP socket with a market venue server. Is able to input market and limit order
 * trades to the market that will be processed by the order book on the market server
 * 
 * usage: <market/limit> <bid/ask/buy/sell> <quanitity> <price (optional)>
 * d to display book on server
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <inttypes.h>
#include <unistd.h>

int main(void) {
	int sockfd;
	struct sockaddr_in serv_addr;
	char buffer[256];
	char input[256];
	
	//create socket
	if((sockfd = socket(AF_INET,SOCK_STREAM, 0)) < 0) {
		printf("Error creating socket\n");
		exit(EXIT_FAILURE);
	}

	//set up the server address
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(9002);
	serv_addr.sin_addr.s_addr = INADDR_ANY;

	//connect to server
	if((connect(sockfd,(struct sockaddr*) &serv_addr, sizeof(serv_addr))) != 0) {
		printf("Error connecting to server\n");
		exit(EXIT_FAILURE);
	}

	// display initial message from server
	read(sockfd,buffer,sizeof(buffer));
	printf("From server: %s",buffer);

	//take in queries from user and write to server
	//memset initializes all bytes
	memset(&input, 0, sizeof(input));
	while(fgets(input,1000,stdin) != NULL) {
		write(sockfd,input,sizeof(input));
		printf("> ");
		memset(&input, 0, sizeof(input));
	}
	
	close(sockfd);
	
	exit(EXIT_SUCCESS);
}
