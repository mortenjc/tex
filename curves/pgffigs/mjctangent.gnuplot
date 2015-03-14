set terminal dumb; set table "pgffigs/mjctangent.table"; set format "%.5f"
set samples 25; plot [x=0:3.1416] sin(3*x)/(x**2 +1)
