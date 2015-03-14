set terminal table; set output "functions.parab.table"; set format "%.5f"
set samples 25; plot [x=0:4] -x**2 +4*x -2
