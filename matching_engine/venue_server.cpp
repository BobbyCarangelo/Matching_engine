/* chat_server.c --- first version of server in berkley sockets, market chat project
 * 
 * 
 * Author: Robert F. Carangelo III
 * Created: Tue Dec  1 21:07:03 2020 (-0500)
 * Version: 
 * 
 * Description: opens a TCP socket, binds to an IP and port, listens, accepts trader clients, 
 * compiles market and limit orders from client and executes trades when appropriate
 * 
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
#include "Order_book.h"
#include "Order.h"

int main(void) {
	int server_sock, client_sock;
	struct sockaddr_in server_addr;
	char buffer[1000] = "You have successfully connected to market venue server\n Press d to display orderbook to server screen\n Otherwise, input trade: <market/limit> <side> <quantity> <price(optional)>\n";
	char message[256];
	Order_book ob1;

	//create server socket
	if((server_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("Error creating socket\n");
		exit(EXIT_FAILURE);
	}

	//ititialize server address
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(9002);
	server_addr.sin_addr.s_addr = INADDR_ANY;

	//bind address and port to socket
	if((bind(server_sock,(struct sockaddr*) &server_addr, sizeof(server_addr))) != 0) {
		printf("Error binding socket to port\n");
		exit(EXIT_FAILURE);
	}

	//listen for clients
	if((listen(server_sock,5)) != 0) {
		printf("Error listening\n");
		exit(EXIT_FAILURE);
	}

	//accept socket from client
	if((client_sock = accept(server_sock, NULL, NULL)) < 0) {
		printf("Error accepting\n");
		exit(EXIT_FAILURE);
	}

	//write initial message to client
	write(client_sock,buffer,sizeof(buffer));

	//read in messages from client and print to screen
	while((read(client_sock,message,sizeof(message))) > 0) {
		printf("Client message: %s",message);
		if(strcmp(message,"d") == 0) {
			ob1.print_book();
		} else {
			ob1.handle_order(message,client_sock);
		}
		
	}

	ob1.print_book();
	close(server_sock);
	
	return 0;
}
