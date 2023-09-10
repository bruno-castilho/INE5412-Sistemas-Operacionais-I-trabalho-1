CPP = gcc
CPPFLAGS = -c -W -Wall -ansi -pedantic -std=c++11

all: main

main: main.o file.o scheduling.o process.o time_diagram.o fcfs.o sjf.o roundrobin.o bypriority.o cpu.o
	$(CPP) -o main main.o file.o scheduling.o process.o time_diagram.o fcfs.o sjf.o roundrobin.o bypriority.o cpu.o -lstdc++
	rm -rf *.o 

main.o: src/main.cpp src/class/File.h src/class/Process.h src/class/scheduling/FCFS.h src/class/scheduling/SJF.h src/class/scheduling/RoundRobin.h src/class/scheduling/ByPriority.h
	$(CPP) -o main.o src/main.cpp $(CPPFLAGS)

file.o: src/class/File.cpp src/class/File.h src/class/Process.h
	$(CPP) -o file.o src/class/File.cpp $(CPPFLAGS)

scheduling.o: src/class/scheduling/Scheduling.cpp src/class/scheduling/Scheduling.h src/class/Process.h src/class/TimeDiagram.h
	$(CPP) -o scheduling.o src/class/scheduling/Scheduling.cpp $(CPPFLAGS)

process.o: src/class/Process.cpp src/class/Process.h src/structures/Registers.h
	$(CPP) -o process.o src/class/Process.cpp $(CPPFLAGS)

time_diagram.o: src/class/TimeDiagram.cpp src/class/TimeDiagram.h src/class/Process.h
	$(CPP) -o time_diagram.o src/class/TimeDiagram.cpp $(CPPFLAGS)

fcfs.o: src/class/scheduling/FCFS.cpp src/class/scheduling/FCFS.h src/class/scheduling/Scheduling.h
	$(CPP) -o fcfs.o src/class/scheduling/FCFS.cpp  $(CPPFLAGS)

sjf.o: src/class/scheduling/SJF.cpp src/class/scheduling/SJF.h src/class/scheduling/Scheduling.h
	$(CPP) -o sjf.o src/class/scheduling/SJF.cpp  $(CPPFLAGS)

roundrobin.o: src/class/scheduling/RoundRobin.cpp src/class/scheduling/RoundRobin.h src/class/scheduling/Scheduling.h
	$(CPP) -o roundrobin.o src/class/scheduling/RoundRobin.cpp  $(CPPFLAGS)
	
bypriority.o: src/class/scheduling/ByPriority.cpp src/class/scheduling/ByPriority.h src/class/scheduling/Scheduling.h
	$(CPP) -o bypriority.o src/class/scheduling/ByPriority.cpp  $(CPPFLAGS)

cpu.o: src/class/CPU.cpp src/class/CPU.h src/structures/Registers.h
	$(CPP) -o cpu.o src/class/CPU.cpp  $(CPPFLAGS)

clean:
	rm -rf *.o *~ main