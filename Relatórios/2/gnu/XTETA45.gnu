reset
set term postscript butt "Helvetica" 10

set term postscript color eps
set output 'XVX.eps'

set autoscale
set yrange[0:30]
set xrange[0:2]
set key below
set xlabel 'Tempo'
set ylabel 'Eixo X'

plot 'TETA45.dat' u 1:4 t 'Posicao em X' w l, 'TETA45.dat' u 1:5 t 'Velociade em X' w l

set term x11

!epstopdf XVX.eps
!acroread XVX.pdf &
