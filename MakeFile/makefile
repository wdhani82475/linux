
test:main.o	max.o min.o
	g++ -o test main.o max.o min.o
main.o:main.cpp
	g++ -o main.o -g  main.cpp
max.o:max.cpp
	g++ -o max.o -g  max.cpp
min.o:	min.cpp
	g++ -o min.o -g  min.cpp
clean:
	rm *.o test
