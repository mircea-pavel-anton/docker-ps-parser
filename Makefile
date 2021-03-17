all: build execute clean

build: compile link

compile:
	@ mkdir build -p
	@ cd build && g++ -c ../src/main.cpp

link:
	@ g++ ./build/* -o dps

execute:
	@ ./dps

clean:
	@ rm -rf build
	@ rm dps
