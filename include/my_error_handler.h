#ifndef __ERROR_HANDLER_
#define __ERROR_HANDLER_

#include <main_header.h>

#define ESENDREQUEST         "Error: could not send get request"
#define EINCOMPLREQ          "Error: Get request incomplete"
#define ERESOLVEHOST         "could not resolve host: "
#define ERESOLVEHOST_SIZE    24

int check_error_code(int err_code, char* user_arg);
int is_request_complete(char* path, char* domain, int len);
void resolve_host_error(char* user_arg);

#endif