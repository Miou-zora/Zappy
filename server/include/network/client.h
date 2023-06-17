/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** client
*/

#ifndef CLIENT_H_
    #define CLIENT_H_

    #include <stdbool.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    #include <sys/queue.h>
    #include <stdlib.h>

    typedef struct trantorian_s trantorian_t;

    /**
     * @brief Structure containing the client's data
     * @param ip The client's ip
     * @param port The client's port
     * @param fd The client's file descriptor
     * @param info The client's info
     * @param is_connected Is the client connected
     * @param is_logged Is the client logged
     * @param is_graphic Is the client a graphic client
     * @param next The next client in the linked list
     */
    typedef struct client_s {
        char *ip;
        int port;
        int fd;
        struct sockaddr_in info;
        bool is_connected;
        bool is_logged;
        bool is_graphic;
        trantorian_t *trantorian;
        LIST_ENTRY(client_s) next; //this is for the linked list
    } client_t;

    /**
     * @brief Create a client object
     *
     * @param info of the client
     * @param fd of the client
     *  This function will create a client object and return it
     *  The client will be connected, and it will not be logged
     *  The client will not be a graphic client
     *  The server will send "WELCOME\n" to the client
     * @return ** client_t* or NULL if error
     */
    client_t *create_client(struct sockaddr_in info, int fd);

    /**
     * @brief Connect a client
     *
     * @param fd of the server
     * @param info of the server
     * @param client to connect
     * @return ** int 0 if success or -1 if error
     */
    int connect_client(int fd, struct sockaddr_in info, client_t *client);

    /**
     * @brief Disconnect a client and free it
     *
     * @param client to disconnect
     * @return ** void nothing
     */
    void destroy_client(client_t *client);
#endif /* !CLIENT_H_ */
