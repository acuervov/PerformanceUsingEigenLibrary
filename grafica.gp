set title "CPU vs Tamaño Matriz"
set log y
set log x
set term pdf
set out 'grafica.pdf'
plot "resultados.txt"  w l

