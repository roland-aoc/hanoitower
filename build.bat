g++ -g -c main.cpp
g++ -g -c 02/rps.cpp
g++ -o Main.exe ^
  main.o ^
  rps.o

rm ^
  main.o ^
  rps.o
