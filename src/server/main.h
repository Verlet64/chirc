typedef struct server {
    int socket;
    char password;
} server;

struct server *init (char *port, char *password);