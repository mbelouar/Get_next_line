#!/bin/bash

read n
gcc -fsanitize=address get_next_line.c -D BUFFER_SIZE=$n Memd/libmemd.a get_next_line_utils.c

./a.out
