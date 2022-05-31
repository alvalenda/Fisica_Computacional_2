reset
set term postscript butt "Helvetica" 10

set term postscript color eps
set output 'E1.eps'

set multiplot

set autoscale
set yrange[0:25000]
set xrange[0:10]
set key below
set xlabel 'Tempo'
set ylabel 'F(x)'

plot 'E1.dat' u 1:2 t 'Simulacao' w l, 'E1.dat' u 1:3 t 'Valor Real' w l

set size 0.45,0.45
set origin 0.2,0.5
set xrange[9.9:10]
set yrange[1000:23000]
unset xlabel
unset ylabel
unset key

plot 'E1.dat' u 1:2 t 'Simulacao' w l, 'E1.dat' u 1:3 t 'Valor Real' w l

unset multiplot

set term x11

!epstopdf E1.eps
!acroread E1.pdf &
