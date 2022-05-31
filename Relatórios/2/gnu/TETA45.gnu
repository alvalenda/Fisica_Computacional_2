reset
set term postscript butt "Helvetica" 10

set term postscript color eps
set output 'YVY.eps'

set autoscale
set yrange[0:16]
set xrange[0:2]
set key below
set xlabel 'Tempo'
set ylabel 'Eixo Y'

plot 'TETA45.dat' u 1:2 t 'Posicao em Y' w l, 'TETA45.dat' u 1:3 t 'Velociade em Y' w l

set term x11

!epstopdf YVY.eps
!acroread YVY.pdf &
