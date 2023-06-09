#include <main_header.h>

int main(int argc, char** argv)
{
    s_parsed* url = NULL;
    url = my_urL_parser(argv[1]);

    if (url == NULL)
    {
        return EXIT_FAILURE;
    }

    if(perform_get_request(url->domain, url->get_request))
    {
        return EXIT_FAILURE;
    };
    
    free_url_struct(url);
    return EXIT_SUCCESS;
}