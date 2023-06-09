#ifndef __MAIN_HEADERFILE_
#define __MAIN_HEADERFILE_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <resolv.h>
#include <arpa/nameser.h>
#include <errno.h>

// #include <fcntl.h>


#include <my_string.h>
#include <my_parser.h>
#include <my_error_handler.h>

#define ANSWER_BUFFER_SIZE 4096
#define __PORT__ "80"

int perform_get_request(char* domain,  char* get);
int send_get_req(char* get, int sockfd);
void read_socket(int sockfd);
int connect_to_server(int sockfd, struct addrinfo* servinfo);
int check_error_code(int err_code);


#endif