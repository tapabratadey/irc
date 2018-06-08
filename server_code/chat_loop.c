#include "includes/server.h"

void chat_loop(t_server *server)
{
    int                 tsocket;
    struct sockaddr_in  tsockinfo;
    fd_set              status;
    fd_set              current;
}