all:grafica.pdf

main.x:main.cpp
	g++ -ftree-vectorize -o main.x main.cpp

resultados.txt:main.x
	./main.x

grafica.pdf:grafica.gp resultados.txt
	gnuplot grafica.gp


