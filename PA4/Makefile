output1: q1.o
	g++ -std=c++11 q1.o -o output1

output2_1: q2_1.o
	g++ -std=c++11 q2_1.o -o output2

output2_3: q2_3.o
	g++ -std=c++11 q2_3.o -o output3

q1.o: q1.cpp
	g++ -std=c++11 -c q1.cpp
	
q2.o: q2_1.cpp
	g++ -std=c++11 -c q2_1.cpp
	
q3.o: q2_3.cpp
	g++ -std=c++11 -c q2_3.cpp
	
clean:
	rm *.o output