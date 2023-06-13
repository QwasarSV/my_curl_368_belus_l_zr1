#ifndef __ERROR_HANDLER_
#define __ERROR_HANDLER_

#include <main_header.h>

#define ESENDREQUEST         "Error: could not send get request"
#define EINCOMPLREQ          "Error: Get request incomplete"

int check_error_code(int err_code);
int is_request_complete(char* path, char* domain, int len);
int is_success_code(char* code_str);

#endif