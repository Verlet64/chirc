#include <string.h> // memset
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdlib.h>

#include "main.h"

struct sockaddr_in *get_addr_info (int addr_family, unsigned short int port);

struct server *init (char *port, char *password) {
    int sock_fd = socket(
        // Define the protocol family which is used for the communication as AF_INET, i.e IPv4 internet protocols
        AF_INET,
        // Define the type of connection as a reliable two way connection based service
        SOCK_STREAM,
        // Use the default protocol
        0
    );

    struct sockaddr_in *addr_info = get_addr_info(AF_INET, 9000);
    
    // sockaddr_in is a struct specific to IP based communication, but bind wants the generic sockaddr descriptor for any kind of socket operation, therefore cast the pointer to sockaddr_in to sockaddr
    bind(sock_fd, (struct sockaddr *) addr_info, sizeof(struct sockaddr));
}

struct sockaddr_in *get_addr_info (int addr_family, unsigned short int port) {
    struct sockaddr_in *sock_fd_addr = malloc(sizeof(struct sockaddr_in));

    sock_fd_addr->sin_family = addr_family;
    sock_fd_addr->sin_port = port;
    sock_fd_addr->sin_addr.s_addr = INADDR_ANY;
    memset(&(sock_fd_addr->sin_zero), '\0', 8);
    
    if (
        &sock_fd_addr->sin_family == NULL ||
        &sock_fd_addr->sin_port == NULL ||
        &sock_fd_addr->sin_addr.s_addr == NULL
    )  {
        free(sock_fd_addr);
        return NULL;
    }

    return sock_fd_addr;
}