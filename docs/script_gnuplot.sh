#!/bin/bash

gnuplot -persist <<-EOFMarker
set terminal png
set output "courbes_listes.png"
set xlabel "nombre d'arêtes"
set ylabel "temps en μs"
plot "data_Gabow.txt" using 1:2 with lines title "algorithme de Gabow" lt rgb "#7F7F7F",\
 "data_Tarjan.txt" using 1:2 with lines title "algorithme de Tarjan" lt rgb "#FFD700",\
 "data_Kosaraju.txt" using 1:2 with lines title "algorithme de Kosaraju" lt rgb "#FF6347"
EOFMarker

exit 0
