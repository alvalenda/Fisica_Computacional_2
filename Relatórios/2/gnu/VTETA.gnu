reset
set term postscript butt "Helvetica" 10

set term postscript color eps
set output 'VTETA.eps'

set autoscale

set key below
set xlabel 'Velocidade Inicial'
set ylabel 'TETA'

plot 'VTETA.dat' u 1:3 t 'TETA maximo' w l

set term x11

!epstopdf VTETA.eps
!acroread VTETA.pdf &
