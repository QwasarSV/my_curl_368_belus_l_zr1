#include <main_header.h>
/*
################ check_error_code #################
# This function checks if an error code was received. 
# @param err_code {int} Error code to check.
# @return {int} EXIT_FAILURE if an error occurred, else EXIT_SUCCESS.
*/
int check_error_code(int err_code, char* domain)
{
  if (err_code)
  {
    if(err_code == -2)
    {
      resolve_host_error(domain);
      return EXIT_FAILURE;
    }
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

void resolve_host_error(char* domain)
{
  int len = my_strlen(domain) + ERESOLVEHOST_SIZE + 1;
  char str[len];
  my_bzero(str, len);
  my_strcpy(str, ERESOLVEHOST);
  my_strcat(str, domain);
  write(STDERR_FILENO, str, len);
  printf("%s", str);
}