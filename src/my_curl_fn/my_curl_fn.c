#include <main_header.h>

/*
################ perform_get_request #################
# Performs a GET request on the specified domain with the provided GET request string.
# The response from the server is printed to the standard output.
# @return {int} Returns 0 after successfully executing the function.
*/
int perform_get_request(char* domain,  char* get)
{
  int sockfd;
  struct addrinfo hints, *servinfo;
  my_memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  getaddrinfo(domain, __PORT__, &hints, &servinfo);
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen);
  freeaddrinfo(servinfo);
  int len = my_strlen(get);
  send(sockfd, get, len, 0);
  char buffer[2048];
  my_memset(buffer, 0, sizeof(buffer));
  while (read(sockfd, buffer, sizeof(buffer)-1) > 0)
  {
    write(STDOUT_FILENO, buffer, sizeof(buffer)-1);
    my_memset(buffer, 0, sizeof(buffer));
  }
  close(sockfd);
  return 0;
}