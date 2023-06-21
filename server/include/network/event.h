/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** event
*/

#ifndef EVENT_H_
    #define EVENT_H_
    #include "client.h"

    typedef struct zappy_s zappy_t;

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

    /**
     * @brief Add event to list
     * the event is added at the end of the list
     * @param event
     * @param zappy_s
     */
    void add_event_to_list(event_t *event, zappy_t *zappy_s);

#endif /* !EVENT_H_ */
