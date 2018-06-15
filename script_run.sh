#!/bin/bash

printf "Compilation... "
make -s all
if [ $? != 0 ]; then
  echo "Echec"
  exit 1
fi

make -s clean
echo "OK"

printf "Execution... "
./graphe
if [ $? != 0 ]; then
  echo "Echec"
  exit 1
fi
echo "OK"

printf "Génération de courbes... "
cd docs
./script_gnuplot.sh
if [ $? != 0 ]; then
  echo "Echec"
  exit 1
fi
echo "OK"
