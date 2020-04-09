output1: q1.o
	g++ -std=c++11 q1.o -o output1

output2: q2.o
	g++ -std=c++11 q2.o -o output2

output3: q3.o
	g++ -std=c++11 q2.o -o output3

output4: q4.o
	g++ -std=c++11 q2.o -o output4

q1.o: q1.cpp
	g++ -std=c++11 -c q1.cpp
	
q2.o: q2.cpp
	g++ -std=c++11 -c q2.cpp
	
q3.o: q3.cpp
	g++ -std=c++11 -c q3.cpp
	
q4.o: q4.cpp OrderedMap.h
	g++ -std=c++11 -c q2.cpp
	
clean:
	rm *.o output