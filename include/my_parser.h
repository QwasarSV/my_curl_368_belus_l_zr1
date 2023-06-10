#ifndef __PARSER_HEADERFILE_
#define __PARSER_HEADERFILE_

#include <main_header.h>

#define MAX_INPUT_TOKENS 20
#define GET_MSG_P1 "GET "
#define GET_MSG_P2 " HTTP/1.1\r\nHost:"
#define GET_MSG_P3 "\r\nConnection: close\r\n\r\n"
#define BASE_LENGTH 42
#define PROTOCOL_SEP "://"
#define PATH_SEP '/'

#ifndef PARSED_URL
#define PARSED_URL
struct parsed_url_struct
{
  char* domain;
  char* path;
  char* get_request;
};
typedef struct parsed_url_struct s_parsed;
#endif
char* set_var(char* src, int len);
char* create_get_request(char* path, char* domain, int total_str_len);
s_parsed* my_urL_parser(char* url_list);
void free_url_struct(s_parsed* url);

#endif