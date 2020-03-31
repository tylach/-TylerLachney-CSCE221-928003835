output1: q1.o
	g++ -std=c++11 q1.o -o output

output2: q2.o
	g++ -std=c++11 q2.o -o output2
	
q1.o: q1.cpp
	g++ -std=c++11 -c q1.cpp
	
q2.o: q2.cpp BinarySearchTree.h dsexceptions.h
	g++ -std=c++11 -c q2.cpp
	
clean:
	rm *.o output