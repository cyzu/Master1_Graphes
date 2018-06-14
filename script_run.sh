#!/bin/bash

printf "Compilation... "
make -s all
make -s clean
echo "OK"

printf "Execution... "
./graphe
echo "OK"
