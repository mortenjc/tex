set terminal dumb; set table "pgffigs/mjccircle.table"; set format "%.5f"
set samples 25; set parametric; plot [t=-3.141:3.141] 1.5+cos(t),1.25+sin(t)
