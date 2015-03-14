set table "pgffigs/mjcpar_test.table"; set format "%.5f"
set samples 25; set parametric; plot [t=-3.141:3.141] 2+t*cos(t),1+t*sin(t)
