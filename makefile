.PHONY: all compile execute

all: compile execute

compile:
	g++ main.cpp -o exec

execute: 
	./exec
