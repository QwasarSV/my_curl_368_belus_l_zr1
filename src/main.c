#include <main_header.h>

int main(int argc, char** argv)
{
    s_parsed* url = NULL;
    url = my_urL_parser(argv[1]);
    perform_get_request(url->domain, url->get_request);

    return EXIT_SUCCESS;
}