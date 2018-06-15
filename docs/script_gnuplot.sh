#!/bin/bash

gnuplot -persist <<-EOFMarker
set terminal png
set output "courbes.png"
set xlabel "nombre d'arêtes"
set ylabel "temps en μs"
set key left top
plot "data_Gabow.txt" using 1:2 with lines title "algorithme de Gabow" lt rgb "#FF1493",\
 "data_Tarjan.txt" using 1:2 with lines title "algorithme de Tarjan" lt rgb "#9ACD32",\
 "data_Kosaraju.txt" using 1:2 with lines title "algorithme de Kosaraju" lt rgb "#00BFFF"
EOFMarker

exit 0
