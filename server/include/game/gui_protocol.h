/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gui_protocol
*/

#pragma once
#include "server.h"


/** GUI protocol utils function
 *
 * It will be mostly some getter
 *
 *
 *
 *********************************************/

/**
 * @brief Get the trantorian by id object
 *
 * @param zappy
 * @param id
 * @return ** trantorian_t* or NULL if not found
 */
trantorian_t *get_trantorian_by_id(zappy_t *zappy, int id);

/**
 * @brief handle the GUI client event
 *
 * @param event  the event generated by the GUI client
 * @param zappy  the struct containing all the informations about the server
 * @return true  if the event was handled
 * @return false if the event was not handled
 */
bool handle_gui_event(event_t *event, zappy_t *zappy);


/** All GUI notification about player actions
 *
 * it's mostly the same as the client protocol
 * but the message is sent to all GUI clients
 *
 * ********************************************/

/**
 * @brief notifie all GUI clients of a new player connection
 *
 * @param new_client the new client
 * @param zappy the struct containing all the informations about the server
 * @return ** void
 */
void  notifie_gui_pnw(client_t *new_client, zappy_t *zappy);

/**
 * @brief notifie all GUI clients of the player's position
 * must be called when the player moves
 * the message: ppo n X Y O\n
 * @param player the player
 * @param zappy the struct containing all the informations about the server
 * @return ** void
 */
void notifie_gui_ppo(trantorian_t *player, zappy_t *zappy);


/**
 * @brief handle the GUI client request about the player's position
 * must be called when the GUI client sends "ppo n\n"
 * @param event generated by the GUI client
 * @param zappy the struct containing all the informations about the server
 * @return ** void
 */
void handle_gui_ppo(event_t *event, zappy_t *zappy);

/**
 * @brief notifie all GUI clients of the player's level
 * must be called when the player levels up
 * the message: plv n L\n
 * @param player the player
 * @param zappy the struct containing all the informations about the server
 * @param client the GUI client
 * @return ** void
 */
void notifie_gui_plv(trantorian_t *player, zappy_t *zappy, client_t *client);

/**
 * @brief handle the GUI client request about the player's level
 *
 * @param event generated by the GUI client
 * @param zappy the struct containing all the informations about the server
 * @return ** void
 */
void handle_gui_plv(event_t *event, zappy_t *zappy);

/**
 * @brief notifie all GUI clients of the player's inventory
 * must be called when the player picks up or drops a resource
 * the message: pin n X Y q0 q1 q2 q3 q4 q5 q6\n
 * @param player the player
 * @param zappy the struct containing all the informations about the server
 * @return ** void
 */
void notifie_gui_pin(trantorian_t *player, zappy_t *zappy);

/**
 * @brief notifie all GUI clients of the player's broadcast
 * must be called when the player broadcasts a message
 * the message: pbc n message\n
 * @param player the player
 * @param zappy the struct containing all the informations about the server
 * @param message the message broadcasted
 * @return ** void
 */
void notifie_gui_pbc(trantorian_t *player, zappy_t *zappy, char *message);

/**
 * @brief notifie all GUI clients when the player start an incantation
 * must be called when the player starts an incantation,
 * but only for the one who started it
 * the message: pic X Y L n1 n2 n3 ... n\n
 * @param player the player
 * @param zappy the struct containing all the informations about the server
 * @return ** void
 */
void notifie_gui_pic(trantorian_t *player, zappy_t *zappy);

/**
 * @brief notifie all GUI clients when the incantation is over
 * must be called when the incantation is over
 * the message: pie X Y R\n
 * @param result the result of the incantation
 * @param x the x position of the incantation
 * @param y the y position of the incantation
 * @param zappy the struct containing all the informations about the server
 * @return ** void
 */
void notifie_gui_pie(int result, int x, int y, zappy_t *zappy);

/**
 * @brief notifie all GUI clients when the drops an egg
 * must be called when the player drops an egg
 * the message: enw e n X Y\n
 * @param player the player
 * @param zappy the struct containing all the informations about the server
 * @return ** void
 */
void notifie_gui_pfk(trantorian_t *player, zappy_t *zappy);

/**
 * @brief notifie all GUI when a client drops an resource
 * must be called when the player drops a resource
 * the message: pdr n i\n
 * @param player the player
 * @param zappy the struct containing all the informations about the server
 * @param resource the resource dropped
 * @return ** void
 */
void notifie_gui_pdr(trantorian_t *player, zappy_t *zappy, int resource);

/**
 * @brief notifie all GUI when a client takes a resource
 * must be called when the player takes a resource
 * the message: pgt n i\n
 * @param player the player
 * @param zappy the struct containing all the informations about the server
 * @param resource the resource taken
 * @return ** void
 */
void notifie_gui_pgt(trantorian_t *player, zappy_t *zappy, int resource);

/**
 * @brief notifie all GUI when a player dies
 * must be called when the player dies
 * the message: pdi n\n
 * @param player the player
 * @param zappy the struct containing all the informations about the server
 * @return ** void
 */
void notifie_gui_pdi(trantorian_t *player, zappy_t *zappy);


/** All GUI notification about egg actions
 *
 * it will send a message to all GUI clients
 * about the egg (connection, death)
 *
 **********************************************/

/**
 * @brief notifie all GUI when a client is connecting for an egg
 * must be called when the player is connecting for an egg
 * the message: ebo e\n
 * @param egg the egg
 * @param zappy the struct containing all the informations about the server
 * @return ** void
 */
void notifie_gui_ebo(egg_t *egg, zappy_t *zappy);

/**
 * @brief notifie all GUI when a egg dies
 * must be called when the egg dies
 * the message: edi e\n
 * @param egg the egg
 * @param zappy the struct containing all the informations about the server
 * @return ** void
 */
void notifie_gui_edi(egg_t *egg, zappy_t *zappy);


/** All GUI notification for utils
 *
 * it will send a message to all GUI clients
 * about the map size, the time unit, the end of the game
 * it can handle the GUI client request about the different informations
 *
 *********************************************/

/**
 * @brief respond to the GUI client with the wanted tile
 * should be called when the GUI client sends "bct X Y\n"
 * @param event generated by the GUI client
 * @param zappy the struct containing all the informations about the server
 * @return ** void
 */
void handle_gui_bct(event_t *event, zappy_t *zappy);

/**
 * @brief respond to the GUI client with the current map
 * should be called when the GUI client sends "mct\n"
 * will be used on connection to send the map
 * @param event generated by the GUI client
 * @param zappy the struct containing all the informations about the server
 * @return ** void
 */
void handle_gui_mct(event_t *event, zappy_t *zappy);

/**
 * @brief respond to the GUI client with the map size
 * should be called when the GUI client sends "msz\n"
 *
 * @param event generated by the GUI client
 * @param zappy the struct containing all the informations about the server
 * @return ** void
 */
void handle_gui_msz(event_t *event, zappy_t *zappy);

/**
 * @brief notifie the GUI client with the map size
 * must be called when the GUI client connects
 * @param client the GUI client
 * @param zappy the struct containing all the informations about the server
 * @return ** void
 */
void notifie_gui_msz(client_t *client, zappy_t *zappy);

/**
 * @brief respond to the GUI client with the time unit
 * must be called when the GUI client sends "sgt\n"
 *
 * @param event generated by the GUI client
 * @param zappy the struct containing all the informations about the server
 * @return ** void
 */
void handle_gui_sgt(event_t *event, zappy_t *zappy);

/**
 * @brief notifie the GUI client with the time unit
 * must be called when the GUI client connects
 * @param client the GUI client
 * @param zappy the struct containing all the informations about the server
 * @return ** void
 */
void notifie_gui_sgt(client_t *client, zappy_t *zappy);

/**
 * @brief modify the time unit based on the GUI client request
 * must be called when the GUI client sends "sst T\n"
 * @param event generated by the GUI client
 * @param zappy the struct containing all the informations about the server
 * @return ** void
 */
void handle_gui_sst(event_t *event, zappy_t *zappy);

/**
 * @brief notifie all GUI clients with the new time unit
 * must be called when the time unit is modified
 * the message: sst T\n
 * @param new_unit the new time unit
 * @param zappy the struct containing all the informations about the server
 * @return ** void
 */
void notifie_gui_sst(int new_unit, zappy_t *zappy);

/**
 * @brief notifie all GUI clients of the end of the game
 * must be called when the game is over
 * the message: seg N\n
 * @param zappy the struct containing all the informations about the server
 * @param team_name the name of the winning team
 * @return ** void
 */
void notifie_gui_seg(zappy_t *zappy, char *team_name);

/**
 * @brief notifie all GUI clients of a message from the server
 * must be called when the server sends a message
 * the message: smg M\n
 * @param zappy the struct containing all the informations about the server
 * @param message the message sent
 * @return ** void
 */
void notifie_gui_smg(zappy_t *zappy, char *message);

/**
 * @brief notifie the GUI client with a unknown command
 *
 * @param client who send the command
 * @param zappy the struct containing all the informations about the server
 * @return ** void
 */
void notifie_gui_suc(client_t *client, zappy_t *zappy);

/**
 * @brief notifie the GUI client with a command parameter
 *
 * @param client who send the command
 * @param zappy the struct containing all the informations about the server
 * @return ** void
 */
void notifie_gui_sbp(client_t *client, zappy_t *zappy);

/**
 * @brief handle the GUI client request about the team names
 * must be called when the GUI client sends "tna\n"
 * @param event generated by the GUI client
 * @param zappy the struct containing all the informations about the server
 * @return ** void
 */
void handle_gui_tna(event_t *event, zappy_t *zappy);

/**
 * @brief notifie the GUI client with the team names
 * must be called when the GUI client connects
 * @param client the GUI client
 * @param zappy the struct containing all the informations about the server
 * @return ** void
 */
void notifie_gui_tna(client_t *client, zappy_t *zappy);

void handle_gui_pin(event_t *event, zappy_t *zappy);

/**
 * @brief send the inventory to the gui
 *
 * @param tran
 * @param zappy
 */
void send_gui_pin(trantorian_t *tran, client_t *client, zappy_t *zappy);

/**
 * @brief send the death of a player to the gui
 *
 * @param trantorian
 * @param zappy
 */
void send_death_to_gui(trantorian_t *trantorian, zappy_t *zappy);

/**
 * @brief return the gui_client
 *
 * @param client list
 */
client_t *get_gui_client(struct client_list *clients);

/**
 * @brief notifie gui pex for explusion
 *
 * @param trantorian is struct
 * @param server is zappy
 * @param client is client
 */
void notifie_gui_pex(trantorian_t *trantorian, zappy_t *server,
    client_t *client);

/**
* @brief send the pgt information to gui
 *
 * @param client
 * @param zappy
 * @param param
 */
void send_gui_pgt(client_t *client, zappy_t *zappy, char *param);

/**
 * @brief send the pgt information to gui
 *
 * @param client_t
 * @param zappy_t
 */
void send_gui_pfk(client_t *client, zappy_t *zappy);

/**
 * @brief send the pdr information to gui
 * @param client_t client
 * @param zappy_t zappy
 * @param char *param
 */
void send_gui_pdr(client_t *client, zappy_t *zappy, char *param);
