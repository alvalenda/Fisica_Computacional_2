reset
set term postscript butt "Helvetica" 10

set term postscript color eps
set output 'Delta.eps'


set autoscale
set xrange[0:10]
set key below
set xlabel 'Tempo'
set ylabel 'Delta X'

plot 'Ce4.dat' u 1:4 t 'Euler Centrado' w l, 'Ee4.dat' u 1:4 t 'Euler' w l



set term x11

!epstopdf Delta.eps
!acroread Delta.pdf &
