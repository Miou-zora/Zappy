#!/bin/bash
##
## EPITECH PROJECT, 2023
## Zappy-Mirror
## File description:
## supervisor
##

#Colors :
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color
BLUE='\033[0;34m'

#Test 1 :
printf "BUILD TESTS: \n"
printf "Building the project... "

make re > temp
if [ $? -eq 0 ]
then
    printf "${GREEN}OK${NC}\n"
else
    printf "${RED}KO${NC}\n"
    exit 1
fi
printf "${GREEN}"
printf "####################################################################\n"
printf "                 Ready for tests on 127.0.0.1:$1\n"
printf "####################################################################\n\n"
printf "${NC}"

printf "Lauching server...\n"
./zappy_server -p $1 -x 10 -y 10 -n bigT bigG -c 10 -f 4 > serverlog &
server_pid=$!
sleep 1
touch temp
ps -a | grep $server_pid |
python3 ./server/tests/server/client.py "127.0.0.1" $1

printf "Killing server... "
kill $server_pid &> temp
if [ $? -eq 0 ]
then
    printf "${GREEN}OK${NC}\n"
else
    printf "${RED}KO Server already down${NC}\n"
fi

printf "Cleaning up...\n"
make fclean > temp
printf "Serverlog: \n"
cat serverlog
rm temp serverlog
