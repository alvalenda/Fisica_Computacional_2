reset
set term postscript butt "Helvetica" 10

set term postscript color eps
set output 'Emil.eps'

set multiplot

set autoscale
set yrange[0:2500000]
set xrange[0:1000]
set key below
set xlabel 'Tempo'
set ylabel 'F(x)'

plot 'Ee4.dat' u 1:2 t 'Simulacao' w l, 'Ee4.dat' u 1:3 t 'Valor Real' w l

set size 0.45,0.45
set origin 0.2,0.5
set xrange[9900:1000]
set yrange[19000:23000]
unset xlabel
unset ylabel
unset key

plot 'Ee4.dat' u 1:2 t 'Simulacao' w l, 'Ee4.dat' u 1:3 t 'Valor Real' w l

unset multiplot

set term x11

!epstopdf Ee4.eps
!acroread Ee4.pdf &
