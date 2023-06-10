#include <main_header.h>
/*
################ check_error_code #################
# This function checks if an error code was received. 
# @param err_code {int} Error code to check.
# @return {int} EXIT_FAILURE if an error occurred, else EXIT_SUCCESS.
*/
int check_error_code(int err_code)
{
  if (err_code)
  {
    perror(gai_strerror(err_code));
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

/*################ is_request_complete #################
# This function checks if the HTTP GET request parameters are complete. 
# @return {int} EXIT_FAILURE if an error occurred, else EXIT_SUCCESS.
*/
int is_request_complete(char* path, char* domain, int len)
{
    if (path == NULL || domain == NULL || len == 0)
    {
        perror(EINCOMPLREQ);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}