set terminal postscript eps color enhanced "Times-Roman" 52
set size 2.2,2.2
set size square
set xrange [0:1]
set xlabel "X"
set ylabel "T" 
set yrange [0:60]
#set palette defined (-10 "dark-blue", 0 "white", 10 "red")
ub = 0
lb = 1
set cbrange [lb:ub]
set cblabel "M" offset -6.4,8.9 rotate by 0
set xtics 0,0.2,1
set tics out nomirror

list = "16 32 64 128 256 512 1024 2048 4096"

do for [i in list] {
	outfile = sprintf('N=%s_map.eps',i)
    set output outfile
    infile = sprintf('formatted_Biomass_density_Nx1=%s',i)
    plot infile matrix nonuniform with image notitle
}
