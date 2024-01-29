#!/bin/bash
gcc -fPIC -c *.c
gcc -sahred *.o -o liball.so
