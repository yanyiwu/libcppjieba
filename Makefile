all: 
	g++ -o demo -O3 -DLOGGER_LEVEL=LL_WARN -Wall -g -I./include demo.cpp 
cpp11:
	g++ -o demo -std=c++11 -O3 -DLOGGER_LEVEL=LL_WARN -Wall -g -I./include demo.cpp 
clean:
	rm -f *.o *.a demo
