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
  int err_code;
  struct addrinfo hints, *servinfo;
  my_memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  err_code = getaddrinfo(domain, __PORT__, &hints, &servinfo);
  if (err_code)
  {
    perror(gai_strerror(err_code));
    return EXIT_FAILURE;
  }
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen) == -1)
  {
    perror("Error: could not connect socket");
    freeaddrinfo(servinfo);
    close(sockfd);
    return EXIT_FAILURE;
  }
  freeaddrinfo(servinfo);
  int len = my_strlen(get);
  err_code = send(sockfd, get, len, 0);
  if (err_code == -1)
  {
    perror("Error: could not send get request");
    printf("errcode: %d", errno);
  }
  char buffer[2048];
  my_memset(buffer, 0, sizeof(buffer));
  while (read(sockfd, buffer, sizeof(buffer)-1) > 0)
  {
    write(STDOUT_FILENO, buffer, sizeof(buffer)-1);
    my_memset(buffer, 0, sizeof(buffer));
  }
  close(sockfd);
  return EXIT_SUCCESS;
}