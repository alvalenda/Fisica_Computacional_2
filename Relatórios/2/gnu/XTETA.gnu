reset
set term postscript butt "Helvetica" 10

set term postscript color eps
set output 'XTETA.eps'

set autoscale

set key below
set xlabel 'TETA'
set ylabel 'Eixo X'

plot 'XTETA.dat' u 2:3 t 'Alcance' w l

set term x11

!epstopdf XTETA.eps
!acroread XTETA.pdf &
