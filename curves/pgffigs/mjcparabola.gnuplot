set terminal dumb; set table "pgffigs/mjcparabola.table"; set format "%.5f"
set samples 25; set parametric; plot [t=0:2.5] t,(t-1)**2
