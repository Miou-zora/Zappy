/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** response
*/

#ifndef RESPONSE_H_
    #define RESPONSE_H_
    #include <stdlib.h>
    #include <stddef.h>
    #include <sys/queue.h>
    #include <string.h>

    typedef struct client_s client_t;
    typedef struct zappy_s zappy_t;

    /**
     * @brief Response object
     * @param content char* content of the response
     * @param clients client_t* list of clients that will receive the response
     * @param next response_t* next response
     */
    typedef struct response_s {
        char *content;
        LIST_HEAD(, client_s) clients;
        LIST_ENTRY(response_s) next;
    } response_t;

    /**
     * @brief Create a response object
     *
     * @param response **char
     * @return ** response_t* response or NULL
     */
    response_t *create_response(char *response);

    /**
     * @brief Add a client to a response
     *
     * @param response **response_t
     * @param client **client_t
     * @return int 0 if success or 84
     */
    int add_client_to_response(response_t *response, client_t *client);

    /**
     * @brief Remove a client from a response
     *
     * @param response **response_t
     * @param client **client_t
     * @return int 0 if success or 84
     */
    int remove_client_from_response(response_t *response, client_t *client);

    /**
     * @brief Destroy a response object
     *
     * @param response **response_t
     * @return int 0 if success or 84
     */
    int destroy_response(response_t *response);

    /**
     * @brief Add a response to the list of responses
     * the response will be added at the end of the list
     *
     * @param response **response_t
     * @param zappy_s **zappy_t
     */
    void add_response_to_list(response_t *response, zappy_t *zappy_s);

#endif /* !RESPONSE_H_ */
