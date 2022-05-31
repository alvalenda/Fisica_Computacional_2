reset
set term postscript butt "Helvetica" 10

set term postscript color eps
set output 'HTETA.eps'

set autoscale

set key below
set xlabel 'Altura Inicial'
set ylabel 'TETA'

plot 'HTETA.dat' u 1:3 t 'TETA maximo' w l

set term x11

!epstopdf HTETA.eps
!acroread HTETA.pdf &
