/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** server
*/

#ifndef SERVER_H_
    #define SERVER_H_

    #define QUEUE_SIZE 10

    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <netinet/in.h>
    #include <sys/select.h>

    #include "client.h"
    #include "response.h"

    /**
     * @brief Structure containing the server's arguments
     * @param port The port the server will listen on
     * @param width The width of the map
     * @param height The height of the map
     * @param names The names of the teams
     * @param clientsNb The number of clients allowed per team
     * @param freq The frequency of the server (in time units per second)
     */
    typedef struct argv_s {
        int port;
        int width;
        int height;
        char **names;
        int clientsNb;
        int freq;
    } argv_t;

    /**
     * @brief Structure containing the server's data
     * @param args The server's arguments
     * @param socket The server's socket
     * @param game The game's data
     * @param port The port the server will listen on
     * @param interface The server's interface
     * @param readfds The fd_set used by select
     * @param timeout The timeout used by select
     * @param responses The queue of responses
     */
    typedef struct zappy_s {
        argv_t *args;
        int socket;
        void *game;
        int port;
        struct sockaddr_in interface;
        fd_set readfds;
        struct timeval timeout;
        LIST_HEAD(response_list, response_s) responses;
        LIST_HEAD(client_list, client_s) clients;
    } zappy_t;

    /**
     * @brief Checks if the arguments are valid, and fills the argv_t structure
     *
     * @param ac the number of arguments
     * @param av the arguments
     * @param args the structure to fill
     * @return true if the arguments are valid
     * @return false if the arguments are invalid
     */
    bool parse_args(int ac, char **av, argv_t *args);

    /**
      * @brief Prints the usage of the program
    **/
    void print_usage(void);

    /**
     * @brief Gets the port from the arguments
     *
     * @param av the arguments
     * @return int the port
     */
    int get_port(char **av);

    /**
     * @brief Gets the width from the arguments
     *
     * @param av the arguments
     * @return int the width
     */
    int get_width(char **av);

    /**
     * @brief Gets the height from the arguments
     *
     * @param av the arguments
     * @return int the height
     */
    int get_height(char **av);

    /**
     * @brief Gets the number of clients per team from the arguments
     *
     * @param av the arguments
     * @return int the number of clients per team
     */
    int get_nb_client(char **av);

    /**
     * @brief Gets the frequency from the arguments
     *
     * @param av the arguments
     * @return int the frequency
     */
    int get_freq(char **av);

    /**
     * @brief Gets the names of the teams from the arguments
     *
     * @param ac the number of arguments
     * @param av the arguments
     * @return char** the names of the teams
     */
    char **get_names(int ac, char **av);

    /**
     * @brief Builds the server
     *
     * @param ac from the command line
     * @param av from the command line
     * @return ** zappy_t* the server or NULL if an error occured
     */
    zappy_t *build_server(int ac, char **av);

    /**
     * @brief Displays a log message
     *
     * @param format the format of the message
     * @param ... the arguments of the message
     */
    void display_log(const char* format, ...);

    /**
     * @brief Runs the server
     *
     * @param zappy the server
     * @details The server will run until the running variable is set to false
     * (by ctrl+c for example)
     * during the run, the server will accept new clients and listen to the
     * clients that are already connected
     * it will create a queue of event for the game to handle
     * finally, the server will free all the memory allocated
        @return int 0 if the server ran successfully, 84 otherwise
     */
    int run(zappy_t *zappy);

    /**
     * @brief Handles the activity of the clients
     * @details If a client is trying to connect, it will accept the connection
     * and add the client to the list of clients
     * If a client is already connected, it will read the data sent by the
     * client and add it to the queue of events
     * @param zappy the server
     * @return int 0 if the activity was handled successfully, 84 otherwise
     */
    int handle_activity(zappy_t *zappy);

    /**
     * @brief Initializes the fd_set, and listens to the sockets
     *
     * @details The fd_set will contain the server's socket and the clients'
     * sockets
     * @param zappy the server
     * @return ** int the number of sockets that are ready to be read
     */
    int listen_sockets(zappy_t *zappy);

    /**
     * @brief Initializes the fd_set, and prepares it to be used by select
     *
     * @param readfds the fd_set to initialize
     * @param zappy the server
     * @return ** void
     */
    void update_fd_set(fd_set *readfds, zappy_t *zappy);

#endif /* !SERVER_H_ */
