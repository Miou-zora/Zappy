# Welcome to the Zappy

Zappy is an Epitech project involving the development of a network game.
Several teams compete on a field containing resources. These resources are used to gain levels. The winning team is the one with at least 6 players who have reached the maximum level. A.I.s make up the teams and embody the players.

* The server has been entirely developed in C using Linux system libraries.
* The AIs were developed using Python 3.
* The graphical client was created in C++ using the [RayLib](https://www.raylib.com/) library.

This project was carried out in a group of 6 people over 5 weeks.

# Usage
Clone repository then run `make install` then `make`
### Server
Run the following command to execute the server:
```console
./zappy_server -p [WIDTH] -y [HEIGHT] -n [TEAM1] [TEAM2] [...] -c [CLIENTS_NB] -f [FREQ]
```
More information about [server](https://github.com/Queng123/Zappy-Mirror/wiki/Server).

### Graphical Client
Run the following command to execute the graphical client:
```console
 ./zappy_ai -p [PORT] -h [HOST]
```
More information about [graphical](https://github.com/Queng123/Zappy-Mirror/wiki/Graphical).

### AI Client
Run the following command to execute the AI client:
```console
./zappy_ai -p [PORT] -n [TEAM_NAME] -h [HOST]
```
More information about [AI](https://github.com/Queng123/Zappy-Mirror/wiki/AI).

# Collaborators
* [Quentin Bréjoin](https://github.com/Queng123/)
* [Alexandre Franquet](https://github.com/Miou-zora)
* [Lylian Hay](https://github.com/lhay9)
* [Mathis Evain](https://github.com/Kibatsu03)
* [Timothée Lesellier](https://github.com/bigt-dev)
* [Guylain Thomas](https://github.com/Jibea)
