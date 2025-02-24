all: chess

chess: vars.h *.cpp
	g++ -std=c++17 -pedantic -Wall -Wextra -g -o chess vars.h *.cpp
