/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** event
*/

#ifndef EVENT_H_
    #define EVENT_H_
    #include "client.h"
    #include "server.h"

    /**
     * @brief Event struct
     *
     * @param request
     * @param client
     * @return event_t
     */
    typedef struct event_s {
        char *request;
        client_t *client;
        LIST_ENTRY(event_s) next;
    } event_t;

    /**
     * @brief Create event
     *
     * @param request
     * @param client
     * @return event_t
     */
    event_t *create_event(char *request, client_t *client);

    /**
     * @brief Destroy event
     *
     * @param event
     */
    void destroy_event(event_t *event);

#endif /* !EVENT_H_ */
