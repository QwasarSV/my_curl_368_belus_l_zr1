#include <main_header.h>


int find_ch(char* str, char ch)
{
    int index = 0;
    while (str[index] != ch && str[index] != '\0')
    {
      index += 1;
    }
    return index;
}


char** my_strtok(char* str, char ch)
{
    char** tokens = malloc(sizeof(char*) * MAX_INPUT_TOKENS);
    char* start = str;
    char* end;
    int index = 1;
    int pos = 0;
    while ((end = my_strchr(start, ch)) != NULL)
    {
        pos = find_ch(start, ch);
        start[pos] = '\0';
        // printf("index is : %i \n", index);
        tokens[index] = start;
        // printf("token is : %s \n", tokens[index]);
        index += 1;
        start = end + 1;
    }
    tokens[index] = start;
    index += 1;
    tokens[index] = NULL;
    return tokens;
}


int token_array_size(char** resp_tokens)
{
    int index = 0;
    while (resp_tokens[index] != NULL)
    {
        index += 1;
    }
    return index - 1;
}


char* set_response_code(char* response)
{
    int len = my_strlen(response);
    char* str_cpy = malloc(sizeof(char) * len + 1);
    my_bzero(str_cpy, len + 1);
    my_memcpy(str_cpy, &response[7], len + 1);
    char** tokens = my_strtok(str_cpy, '\n');
    int len_code = my_strlen(&tokens[1][2]);
    char* result = malloc(sizeof(char) * len_code + 1);
    my_memcpy(result, &tokens[1][2], len_code + 1);
    // printf("result is : %s\n", result);
    free(tokens);
    free(str_cpy);
    // printf("result is : %s\n", result);
    return result;
}
