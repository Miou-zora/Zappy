/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** network
*/

#ifndef NETWORK_H_
    #define NETWORK_H_

    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h>

    #include "server.h"

    #define BUFFER_SIZE 2048

    /**
     * @brief it will read the client socket
     * while using the circular buffer
     * The message will be malloced
     * @param fd to read
     * @return ** char* the message
     */
    char *read_client(int fd);

    /**
     * @brief it will send the message to the client
     * it will look with a select if the client is ready to be written
     * if not, it will read the client socket with read_client
     * append the message to the queue of events
     * then send the message
     * @param server
     * @param fd to send
     * @param msg to send
     * @return int 0 if success, else 84
     */
    int send_client(zappy_t *server, client_t *client, char *msg);

    /**
     * @brief it will look for a '\n' in the buffer
     *
     * @param buffer to look in
     * @return ** int -1 if not found, else the index of the backslash n
     */
    int is_buffer_valid(char *buffer);

    /**
     * @brief it will check if the socket is ready to be written
     * using select
     * @param fd to check
     * @return ** int 1 if valid, else 0 if there is data to read, else -1 for error
     */
    int is_socket_ready(int fd);
#endif /* !NETWORK_H_ */
