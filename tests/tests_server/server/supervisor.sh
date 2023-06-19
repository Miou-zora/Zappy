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



if [ $# -ne 2 ]
then
    printf "${RED}KO${NC}\n"
    printf "Usage: ./supervisor.sh [port] [number of clients]\n"
    exit 1
fi

#Test 1 :
printf "BUILD TESTS: \n"
printf "Building the project... "

make debug -C server  > temp.ignore
mv server/zappy_server .
if [ $? -eq 0 ]
then
    printf "${GREEN}OK${NC}\n"
else
    printf "${RED}KO${NC}\n"
    exit 1
fi
printf "${GREEN}"
printf "####################################################################\n"
printf "####################################################################\n"
printf "                 Ready for tests on 127.0.0.1:$1\n"
printf "####################################################################\n"
printf "####################################################################\n\n"
printf "${NC}"

printf "Lauching server...\n"
valgrind ./zappy_server -p $1 -x 10 -y 10 -n bigT bigG -c 10 -f 4 > serverlog.ignore 2> valgrindlog.ignore &
server_pid=$!
sleep 1
ps -a | grep $server_pid |
printf "${BLUE}"
printf "####################################################################\n"
printf "Starting Heavy Load Test...\n"
printf "####################################################################\n\n"
printf "${NC}"
python3 ./server/tests/server/HeavyLoad.py "127.0.0.1" $1 $2 serverlog.ignore
printf "${BLUE}"
printf "####################################################################\n"
printf "Starting Quick Fire Requests Test...\n"
printf "####################################################################\n\n"
printf "${NC}"
python3 ./tests/tests_server/server/QuickFireRequest.py "127.0.0.1" $1 $2 serverlog.ignore 2> temp.ignore

printf "Killing server... \n"
kill -INT $server_pid &> temp.ignore

printf "${BLUE}"
printf "####################################################################\n"
printf "Starting Memory Management Test...\n"
printf "####################################################################\n\n"
printf "${NC}"
sleep 1
python3 tests/tests_server/server/MemoryManagement.py valgrindlog.ignore

printf "${BLUE}"
printf "END OF TESTS\n\n"
if [ $? -eq 0 ]
then
    printf "${GREEN}OK${NC}\n"
else
    printf "${RED}KO Server already down${NC}\n"
fi
rm temp.ignore