#include <main_header.h>





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
