#ifndef __MAIN_HEADERFILE_
#define __MAIN_HEADERFILE_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>

#include <my_string.h>
#include <my_error_handler.h>
#include <my_linkedlist.h>
#include <my_parser.h>

#ifndef URI_ENUM
#define URI_ENUM
enum uri_type_enum
{
    URI = 1,
    URL
};
typedef enum uri_type_enum uri_enum_t;
#endif

#ifndef URI_STRUCT
#define URI_STRUCT
struct uri_struct
{
    uri_enum_t type_uri;
    union {
        // uri_p_s_t* uri;
        url_p_s_t* url;
    } uri_union;
};
typedef struct uri_struct uri_s_t;
#endif

#define ANSWER_BUFFER_SIZE 4096
#define __PORT__ "80"

int     perform_get_request(char* domain,  char* get);
int     send_get_req(char* get, int sockfd);
int     connect_to_server(int sockfd, struct addrinfo* servinfo);
int     r_socket_w_out(int sockfd);

#endif