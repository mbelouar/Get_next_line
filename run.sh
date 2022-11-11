#!/bin/bash

read n
gcc -fsanitize=address get_next_line.c -D BUFFER_SIZE=$n get_next_line_utils.c

./a.out
