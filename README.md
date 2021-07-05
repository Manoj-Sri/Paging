# Paging simulator
Simulator of paging of memory management.This is a simulator which allocates the virtual_memory to executable processes according to available memory and process memory.Paging is used to allocate processes to memory.

## Inputs:
We prompted user for memory size(multiples of 100),size of page/frame (any of 100/200/400) and an input file containing processes memory and timing information.

## Processing:
In this simulator,a list containg all processes,an input queue which tracks waiting processes and a memory frame list are used.

Input queue takes in processes which are arrived but not yet allocated memory. Memory Manger keeps track of memory frame list and if the frame list is free to accomodate a waiting process,it allocates required memory to the process. And in a similar way,if life time of the process completed, memory manager pops the process out of the frame list and free's the frames.

A certain process has to wait until memory manager can accomodate its requirement. Thus a program whose total adress space more than memory size are ignored.

Memory Manager allocates new process in top down manner, so that free frames(if present) are always at the bottom of frame list(as much as possible).

## Order:
Order of job activity to be taken into account when multiples jobs perform multiple actions is as follows:


1. Take in the newly arrived process (To be admitted to free frames)
2. Pop out completed process from memory frame list(To free the space)
3. Admit the waiting process to be taken into memory.

this order is followed so as to make sure of not wasting time.

## Output:
Each and every activity of every process is listed to keep track of memory management.
Average turn_around_time of all the processes is displayed at last.





## !!!compilation!!!

Use  _'make'_  command to compile the project and run and the same time.

If only compilation is neede use _'g++ main.cpp -o exec'_ (g++ of version 7.5.0 and above should be fine).

And for only execution of compiled proect use _'./exec'_ .

## !!!Giving Inputs!!!

1.Give 'memory size' in the multiples of '100'.

2.Choose any one of the three options for 'page size' 1/2/3 (make sure that 'memory size' should be a multiple of 'page size').

3.Give 'file name' as the format 'inputs/1' or 'inputs/2' (only 2 input files are provided).If you want to try it with your own custom input, keep your input file in inputs folder and give input in the format 'inputs/file_name'(where file name is your own custom input file name).














