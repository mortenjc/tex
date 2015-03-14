set terminal dumb; set table "pgffigs/mjcparabola2.table"; set format "%.5f"
set samples 25; set parametric; plot [t=1:2.25] t,(t-1)**2
