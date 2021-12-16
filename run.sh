#/usr/bin/env bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=${1} main.c get_next_line.c get_next_line_utils.c
./a.out ${2} ${3}
