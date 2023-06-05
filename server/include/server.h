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
     */
    typedef struct zappy_s {
        argv_t *args;
        int socket;
        void *game;
        int port;
        struct sockaddr_in interface;
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

#endif /* !SERVER_H_ */
