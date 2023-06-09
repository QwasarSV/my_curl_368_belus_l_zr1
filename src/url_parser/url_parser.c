#include <main_header.h>

/*
################ create_get_request #################
# Creates a GET request for the provided path and domain.
# @return {char*} A pointer to the newly created GET request string.
*/
char* create_get_request(char* path, char* domain, int total_str_len)
{
  if (path == NULL || domain == NULL, total_str_len == 0)
  {
    perror("Error: Get request imcomplete");
    return NULL;
  }
  int len_req = BASE_LENGTH + total_str_len;
  char* new_req = malloc(sizeof(char) * len_req + 1);
  my_bzero(new_req, len_req + 1);
  my_strcat(new_req, GET_MSG_P1);
  my_strcat(new_req, path);
  my_strcat(new_req, GET_MSG_P2);
  my_strcat(new_req, domain);
  my_strcat(new_req, GET_MSG_P3);
  return new_req;
}

/*
################ my_urL_parser #################
# Parses a URL into its domain and path components, and then creates a GET request.
# @return {s_parsed*} A pointer to the parsed URL structure, which contains the domain, path, and GET request.
*/
s_parsed* my_urL_parser(char* url_list)
{
  s_parsed* url = malloc(sizeof(s_parsed));
  char* ptr_doma = NULL;
  char* ptr_path = NULL;
  ptr_doma  = my_strstr(url_list, "://");
  ptr_path = my_strchr(&ptr_doma[3],'/');
  int len_dom = (int)(ptr_path - &ptr_doma[3]);
  int len_path = my_strlen(ptr_path);
  int len = len_dom + len_path;
  url->domain = malloc(sizeof(char)*len_dom + 1);
  my_bzero(url->domain, len_dom + 1);
  my_memcpy(url->domain, &ptr_doma[3], len_dom);
  url->path = malloc(sizeof(char)*len_path + 1);
  my_bzero(url->path, len_path + 1);
  my_memcpy(url->path, ptr_path, len_path);
  url->get_request = create_get_request(url->path, url->domain, len);
  if (url->get_request == NULL)
  {
    return NULL;
  }
  return url;
}

void free_url_struct(s_parsed* url)
{
  free(url->domain);
  free(url->path);
  free(url->get_request);
  free(url);
}