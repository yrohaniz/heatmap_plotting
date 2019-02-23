set terminal postscript eps color enhanced "Times-Roman" 24
set size 2.2,2.2
set size square
set xrange [0:1]
set xlabel "X"
set ylabel "Y" 
set yrange [0:1]
set cbrange [0:1]
set xtics 0,0.1,1
set ytics 0,0.1,1
set tics out nomirror
t = 10

set output "128x128_t".t.".eps"
set title 'Biomass load on the substrate captured at t='.t
plot 'Biomass_density_128x128_xi-0.03_formatted_t'.t matrix nonuniform with image notitle


