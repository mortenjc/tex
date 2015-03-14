set terminal dumb; set table "pgffigs/mjcintersect.table"; set format "%.5f"
set samples 25; set parametric; plot [t=-3.141:3.141] 1.5+t*cos(t)/2,0.75+t*sin(t)/2
