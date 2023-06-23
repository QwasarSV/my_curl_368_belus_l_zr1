#include <main_header.h>

uri_s_t init_my_curl(uri_s_t  uri, char* user_arg)
{
    uri.type_uri = 0;
    if (is_not_url(user_arg))
    {
        /* placeHolder to handle URI */
        return uri;
    }
    else
    {
        if (get_protocol_from_url(user_arg))
        {
            /* placeHolder to handle HTTPS or unknow protocols */
            return uri;
        }
        else
        {
            uri.type_uri = URL;
            uri.uri_union.url = my_url_parser(user_arg);
            return uri;
        }
    }
    return uri;
}


int my_curl(uri_s_t  uri)
{
    int exit_status = 1;
    
    if (uri.type_uri == 0)
    {
        return EXIT_FAILURE;
    }
    if (uri.type_uri == URL)
    {
        url_p_s_t* url_s = uri.uri_union.url;
        exit_status = perform_get_request(url_s->domain, url_s->get_request);
        return exit_status;
    }
    return EXIT_FAILURE;
}

int clean_my_curl(uri_s_t  uri)
{
    if (uri.type_uri == 0)
    {
        return EXIT_FAILURE;
    }
    else if (uri.type_uri == URL)
    {
        url_p_s_t* url_s = uri.uri_union.url;
        free_url_struct(url_s);
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}


int main(int argc, char** argv)
{
    uri_s_t uri;
    int exit_status = 0;
    uri = init_my_curl(uri, argv[1]);
    url_p_s_t* url_s = uri.uri_union.url;
    if (my_curl(uri))
    {
        return EXIT_FAILURE;
    }
    clean_my_curl(uri);
    return EXIT_SUCCESS;
}