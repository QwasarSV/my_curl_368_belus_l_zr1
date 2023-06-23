#ifndef __PARSER_HEADERFILE_
#define __PARSER_HEADERFILE_

#include <main_header.h>

#define MAX_INPUT_TOKENS  1000
#define GET_MSG_P1        "GET "
#define GET_MSG_P2        " HTTP/1.1\r\nHost:"
#define GET_MSG_P3        "\r\nConnection: close\r\n\r\n"
#define BASE_LENGTH       42
#define PROTOCOL_SEP      "://"
#define _HTTPS__          "https://"
#define _HTTPS_LEN_       8
#define _HTTP__           "http://"
#define _HTTP_LEN_        7
#define PATH_SEP          '/'

#ifndef PROTOCOL_ENUM
#define PROTOCOL_ENUM
enum protocol
{
    PROTOCOL_HTTP,
    PROTOCOL_HTTPS,
    PROTOCOL_UNKNOWN,
};
typedef enum protocol protocol_enum;
#endif

#ifndef PARSED_URL
#define PARSED_URL
struct parsed_url_struct
{
  char* domain;
  char* path;
  char* get_request;
};
typedef struct parsed_url_struct url_p_s_t;
#endif


#ifndef PARSED_URI
#define PARSED_URI
typedef struct parsed_uri_struct
{
    char* scheme;
    char* authority;
    char* path;
    char* query;
    char* fragment;
};
typedef struct parsed_uri_struct uri_p_s_t;
#endif


char* set_var(char* src, int len);
char* create_get_request(char* path, char* domain, int total_str_len);
url_p_s_t* my_url_parser(char* url);
void free_url_struct(url_p_s_t* url);
protocol_enum get_protocol_from_url(char* url);


int token_array_size(char** resp_tokens);
char* set_response_code(char* response);

char* init_my_readline();
char* my_readline(int fd);
void flush_buffer();

#endif